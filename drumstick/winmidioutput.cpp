/*
    Drumstick RT Windows Backend
    Copyright (C) 2009-2014 Pedro Lopez-Cabanillas <plcl@users.sf.net>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include <QDebug>
#include <QStringList>
#include <QByteArray>
#include <QVarLengthArray>
#include <qmath.h>
#include <windows.h>
#include <mmsystem.h>
#include "midioutput.h"

namespace drumstick {
namespace rt {

    union WinMIDIPacket {
        WinMIDIPacket() : dwPacket(0) {}
        DWORD dwPacket;
        quint8 data[sizeof(DWORD)];
    };

    static QLatin1Literal DEFAULT_PUBLIC_NAME = QLatin1Literal("MIDI Out");

    void CALLBACK midiCallback( HMIDIOUT hmo,
                                UINT wMsg,
                                DWORD_PTR dwInstance,
                                DWORD_PTR dwParam1,
                                DWORD_PTR dwParam2);

    class MIDIOutput::MIDIOutputPrivate {
    public:
        HMIDIOUT m_handle;
        bool m_clientFilter;
        QString m_publicName;
        QString m_currentOutput;
        QMap<int,QString> m_outputDevices;
        MIDIHDR m_midiSysexHdr;
        QByteArray m_sysexBuffer;
        QStringList m_excludedNames;

        MIDIOutputPrivate():
            m_handle(0),
            m_clientFilter(true),
            m_publicName(DEFAULT_PUBLIC_NAME)
        {
            reloadDeviceList(true);
        }

        void reloadDeviceList(bool advanced)
        {
            MMRESULT res;
            MIDIOUTCAPS deviceCaps;
            QString devName;
            unsigned int dev, max = midiOutGetNumDevs();
            m_outputDevices.clear();
            m_clientFilter = !advanced;

            for ( dev = 0; dev < max; ++dev) {
                res = midiOutGetDevCaps( dev, &deviceCaps, sizeof(MIDIOUTCAPS));
                if (res != MMSYSERR_NOERROR)
                    break;
                if (m_clientFilter && (deviceCaps.wTechnology == MOD_MAPPER))
                    continue;
    #if defined(UNICODE)
                devName = QString::fromWCharArray(deviceCaps.szPname);
    #else
                devName = QString::fromLocal8Bit(deviceCaps.szPname);
    #endif
                m_outputDevices[dev] = devName;
            }
            if (!m_clientFilter) {
                dev = MIDI_MAPPER;
                res = midiOutGetDevCaps( dev, &deviceCaps, sizeof(MIDIOUTCAPS));
                if (res == MMSYSERR_NOERROR) {
    #if defined(UNICODE)
                    devName = QString::fromWCharArray(deviceCaps.szPname);
    #else
                    devName = QString::fromLocal8Bit(deviceCaps.szPname);
    #endif
                    m_outputDevices[dev] = devName;
                }
            }
        }

        void setPublicName(QString name)
        {
            if (m_publicName != name) {
                m_publicName = name;
            }
        }

        int deviceIndex( const QString& newOutputDevice )
        {
            int index = -1;
            QMap<int,QString>::ConstIterator it;
            for( it = m_outputDevices.constBegin();
                 it != m_outputDevices.constEnd(); ++it ) {
                if (it.value() == newOutputDevice) {
                    index = it.key();
                    break;
                }
            }
            return index;
        }

        void open(QString name)
        {
            MMRESULT res;
            int dev = -1;

            if (m_handle != 0)
                close();
            reloadDeviceList(!m_clientFilter);
            dev = deviceIndex(name);
            if (dev > -1) {
                res = midiOutOpen( &m_handle, dev, (DWORD_PTR) midiCallback, (DWORD_PTR) this, CALLBACK_FUNCTION);
                if (res != MMSYSERR_NOERROR)
                    qDebug() << "midiStreamOpen() err:" << mmErrorString(res);
            }
        }

        void close()
        {
            MMRESULT res;
            if (m_handle != 0) {
                res = midiOutReset( m_handle );
                if (res != MMSYSERR_NOERROR)
                    qDebug() << "midiOutReset() err:" << mmErrorString(res);
                res = midiOutClose( m_handle );
                if (res != MMSYSERR_NOERROR)
                    qDebug() << "midiStreamClose() err:" << mmErrorString(res);
                m_handle = 0;
            }
        }

        void doneHeader( LPMIDIHDR lpMidiHdr )
        {
            MMRESULT res;
            res = midiOutUnprepareHeader( m_handle, lpMidiHdr, sizeof(MIDIHDR) );
            if (res != MMSYSERR_NOERROR)
                qDebug() << "midiOutUnprepareHeader() err:" << mmErrorString(res);
            if ((lpMidiHdr->dwFlags & MHDR_ISSTRM) == 0)
                return; // sysex header?
        }

        void sendShortMessage(WinMIDIPacket &packet)
        {
            MMRESULT res;
            res = midiOutShortMsg( m_handle, packet.dwPacket );
            if ( res != MMSYSERR_NOERROR )
                qDebug() << "midiOutShortMsg() err:" << mmErrorString(res);
        }

        void sendSysexEvent(const QByteArray& data)
        {
            MMRESULT res;
            m_sysexBuffer = data;
            m_midiSysexHdr.lpData = (LPSTR) m_sysexBuffer.data();
            m_midiSysexHdr.dwBufferLength = m_sysexBuffer.size();
            m_midiSysexHdr.dwBytesRecorded = m_sysexBuffer.size();
            m_midiSysexHdr.dwFlags = 0;
            m_midiSysexHdr.dwUser = 0;
            res = midiOutPrepareHeader( m_handle, &m_midiSysexHdr, sizeof(MIDIHDR) );
            if (res != MMSYSERR_NOERROR)
                qDebug() << "midiOutPrepareHeader() err:" << mmErrorString(res);
            else {
                res = midiOutLongMsg( m_handle, &m_midiSysexHdr, sizeof(MIDIHDR) );
                if (res != MMSYSERR_NOERROR)
                    qDebug() << "midiOutLongMsg() err:" << mmErrorString(res);
            }
        }

        QString mmErrorString(MMRESULT err)
        {
            QString errstr;
    #ifdef UNICODE
            WCHAR buffer[1024];
            midiOutGetErrorText(err, &buffer[0], sizeof(buffer));
            errstr = QString::fromUtf16((const ushort*)buffer);
    #else
            char buffer[1024];
            midiOutGetErrorText(err, &buffer[0], sizeof(buffer));
            errstr = QString::fromLocal8Bit(buffer);
    #endif
            return errstr;
        }
    };


    void CALLBACK midiCallback( HMIDIOUT hmo,
                                UINT wMsg,
                                DWORD_PTR dwInstance,
                                DWORD_PTR dwParam1,
                                DWORD_PTR dwParam2)
    {
        Q_UNUSED(hmo)
        Q_UNUSED(dwParam2)

        MIDIOutput::MIDIOutputPrivate* obj = (MIDIOutput::MIDIOutputPrivate*) dwInstance;
        switch( wMsg ) {
        case MOM_DONE:
            obj->doneHeader( (LPMIDIHDR) dwParam1 );
            break;
        case MOM_OPEN:
            qDebug() << "Open";
            break;
        case MOM_CLOSE:
            qDebug() << "Close";
            break;
        default:
            qDebug() << "unknown:" << hex << wMsg;
            break;
        }
    }

    MIDIOutput::MIDIOutput(QObject *parent) :
       QObject(parent), d(new MIDIOutputPrivate)
    { }

    MIDIOutput::~MIDIOutput()
    {
        delete d;
    }

    void MIDIOutput::initialize(QSettings *settings)
    {
        Q_UNUSED(settings)
    }

    QString MIDIOutput::backendName()
    {
        return "Windows MM";
    }

    QString MIDIOutput::publicName()
    {
        return d->m_publicName;
    }

    void MIDIOutput::setPublicName(QString name)
    {
        d->setPublicName(name);
    }

    QStringList MIDIOutput::connections(bool advanced)
    {
        d->reloadDeviceList(advanced);
        return d->m_outputDevices.values();
    }

    void MIDIOutput::setExcludedConnections(QStringList conns)
    {
        d->m_excludedNames = conns;
    }

    void MIDIOutput::open(QString name)
    {
        d->open(name);
    }

    void MIDIOutput::close()
    {
        d->close();
    }

    QString MIDIOutput::currentConnection()
    {
        return d->m_currentOutput;
    }

    void MIDIOutput::sendNoteOn(int chan, int note, int vel)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_NOTEON | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = note;
        packet.data[2] = vel;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendNoteOff(int chan, int note, int vel)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_NOTEOFF | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = note;
        packet.data[2] = vel;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendController(int chan, int control, int value)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_CONTROLCHANGE | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = control;
        packet.data[2] = value;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendKeyPressure(int chan, int note, int value)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_KEYPRESURE | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = note;
        packet.data[2] = value;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendProgram(int chan, int program)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_PROGRAMCHANGE | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = program;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendChannelPressure(int chan, int value)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_CHANNELPRESSURE | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = value;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendPitchBend(int chan, int value)
    {
        WinMIDIPacket packet;
        packet.data[0] = MIDI_STATUS_PITCHBEND | (chan & MIDI_CHANNEL_MASK);
        packet.data[1] = MIDI_LSB(value);
        packet.data[2] = MIDI_MSB(value);
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendSystemMsg(const int status)
    {
        WinMIDIPacket packet;
        packet.data[0] = status;
        d->sendShortMessage(packet);
    }

    void MIDIOutput::sendSysex(const QByteArray &data)
    {
        d->sendSysexEvent(data);
    }

}}
