INCLUDEPATH += ../drumstick

HEADERS += \
    ../drumstick/midiinput.h \
    ../drumstick/midioutput.h


win32 {
    SOURCES += \
        ../drumstick/winmidiinput.cpp \
        ../drumstick/winmidioutput.cpp
    LIBS += -lwinmm
}
macx {
    HEADERS += ../drumstick/maccommon.h # ../drumstick/macmidiinput.h ../drumstick/macmidioutput.h
    SOURCES += \
        ../drumstick/macmidiinput.cpp \
        ../drumstick/macmidioutput.cpp \
        ../drumstick/maccommon.cpp

    LIBS += -framework CoreMidi -framework CoreFoundation
}
