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

#ifndef MIDIINPUT_H
#define MIDIINPUT_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSettings>
#include "midioutput.h"

namespace drumstick {
namespace rt {

    class MIDIInput: public QObject
    {
        Q_OBJECT

    public:
        class MIDIInputPrivate;

        explicit MIDIInput(QObject *parent = 0);
        virtual ~MIDIInput();

        // MIDIInput interface
    public:
        virtual void initialize(QSettings* settings);
        virtual QString backendName();
        virtual QString publicName();
        virtual void setPublicName(QString name);
        virtual QStringList connections(bool advanced);
        virtual void setExcludedConnections(QStringList conns);
        virtual void open(QString name);
        virtual void close();
        virtual QString currentConnection();
        virtual void setMIDIThruDevice(MIDIOutput *device);
        virtual void enableMIDIThru(bool enable);
        virtual bool isEnabledMIDIThru();
    signals:
        /**
         * @brief midiNoteOff 0x8
         * @param chan
         * @param note
         * @param vel
         */
        void midiNoteOff(const int chan, const int note, const int vel);

        /**
         * @brief midiNoteOn 0x9
         * @param chan
         * @param note
         * @param vel
         */
        void midiNoteOn(const int chan, const int note, const int vel);

        /**
         * @brief midiKeyPressure 0xA
         * @param chan
         * @param note
         * @param value
         */
        void midiKeyPressure(const int chan, const int note, const int value);

        /**
         * @brief midiController 0xB
         * @param chan
         * @param control
         * @param value
         */
        void midiController(const int chan, const int control, const int value);

        /**
         * @brief midiProgram 0xC
         * @param chan
         * @param program
         */
        void midiProgram(const int chan, const int program);

        /**
         * @brief midiChannelPressure 0xD
         * @param chan
         * @param value
         */
        void midiChannelPressure(const int chan, const int value);

        /**
         * @brief midiPitchBend 0xE
         * @param chan
         * @param value
         */
        void midiPitchBend(const int chan, const int value);

        /**
         * @brief midiSysex
         * @param data 0xF0 ... 0xF7
         */
        void midiSysex(const QByteArray &data);

        /**
         * @brief midiSystemCommon
         * @param status 0xF (1..6)
         */
        void midiSystemCommon(const int status);

        /**
         * @brief midiSystemRealtime
         * @param status 0xF (8..F)
         */
        void midiSystemRealtime(const int status);
    private:
        MIDIInputPrivate * const d;
    };

}}
#endif // MIDIINPUT_H
