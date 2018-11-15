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

#ifndef MIDIOUTPUT_H
#define MIDIOUTPUT_H

#include <QObject>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QSettings>

#define MIDI_CHANNELS               16
#define MIDI_GM_DRUM_CHANNEL        (10-1)
#define MIDI_CTL_MSB_MAIN_VOLUME    0x07
#define MIDI_CTL_ALL_SOUNDS_OFF     0x78
#define MIDI_CTL_ALL_NOTES_OFF      0x7b
#define MIDI_CTL_RESET_CONTROLLERS  0x79

#define MIDI_STATUS_NOTEOFF         0x80
#define MIDI_STATUS_NOTEON          0x90
#define MIDI_STATUS_KEYPRESURE      0xa0
#define MIDI_STATUS_CONTROLCHANGE   0xb0
#define MIDI_STATUS_PROGRAMCHANGE   0xc0
#define MIDI_STATUS_CHANNELPRESSURE 0xd0
#define MIDI_STATUS_PITCHBEND       0xe0
#define MIDI_STATUS_SYSEX           0xf0
#define MIDI_STATUS_ENDSYSEX        0xf7
#define MIDI_STATUS_REALTIME        0xf8

#define MIDI_STATUS_MASK            0xf0
#define MIDI_CHANNEL_MASK           0x0f

#define MIDI_COMMON_QTRFRAME        0xF1
#define MIDI_COMMON_SONGPP          0xF2
#define MIDI_COMMON_SONSELECT       0xF3
#define MIDI_COMMON_TUNEREQ         0xF6

#define MIDI_REALTIME_CLOCK         0xF8
#define MIDI_REALTIME_START         0xFA
#define MIDI_REALTIME_CONTINUE      0xFB
#define MIDI_REALTIME_STOP          0xFC
#define MIDI_REALTIME_SENSING       0xFE
#define MIDI_REALTIME_RESET         0xFF

#define MIDI_LSB(x) (x % 0x80)
#define MIDI_MSB(x) (x / 0x80)

namespace drumstick {
namespace rt {

    class MIDIOutput : public QObject
    {
        Q_OBJECT

    public:
        class MIDIOutputPrivate;

        explicit MIDIOutput(QObject *parent = 0);
        virtual ~MIDIOutput();

        // MIDIOutput interface
        virtual void initialize(QSettings* settings);
        virtual QString backendName();
        virtual QString publicName();
        virtual void setPublicName(QString name);
        virtual QStringList connections(bool advanced);
        virtual void setExcludedConnections(QStringList conns);
        virtual void open(QString name);
        virtual void close();
        virtual QString currentConnection();

    public slots:
        virtual void sendNoteOff(int chan, int note, int vel);
        virtual void sendNoteOn(int chan, int note, int vel);
        virtual void sendKeyPressure(int chan, int note, int value);
        virtual void sendController(int chan, int control, int value);
        virtual void sendProgram(int chan, int program);
        virtual void sendChannelPressure(int chan, int value);
        virtual void sendPitchBend(int chan, int value);
        virtual void sendSysex(const QByteArray &data);
        virtual void sendSystemMsg(const int status);

    private:
        MIDIOutputPrivate * const d;
    };

}}

#endif // MIDIOUTPUT_H
