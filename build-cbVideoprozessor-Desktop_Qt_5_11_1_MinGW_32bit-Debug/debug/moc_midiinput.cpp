/****************************************************************************
** Meta object code from reading C++ file 'midiinput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drumstick/midiinput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midiinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_drumstick__rt__MIDIInput_t {
    QByteArrayData data[20];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drumstick__rt__MIDIInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drumstick__rt__MIDIInput_t qt_meta_stringdata_drumstick__rt__MIDIInput = {
    {
QT_MOC_LITERAL(0, 0, 24), // "drumstick::rt::MIDIInput"
QT_MOC_LITERAL(1, 25, 11), // "midiNoteOff"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "chan"
QT_MOC_LITERAL(4, 43, 4), // "note"
QT_MOC_LITERAL(5, 48, 3), // "vel"
QT_MOC_LITERAL(6, 52, 10), // "midiNoteOn"
QT_MOC_LITERAL(7, 63, 15), // "midiKeyPressure"
QT_MOC_LITERAL(8, 79, 5), // "value"
QT_MOC_LITERAL(9, 85, 14), // "midiController"
QT_MOC_LITERAL(10, 100, 7), // "control"
QT_MOC_LITERAL(11, 108, 11), // "midiProgram"
QT_MOC_LITERAL(12, 120, 7), // "program"
QT_MOC_LITERAL(13, 128, 19), // "midiChannelPressure"
QT_MOC_LITERAL(14, 148, 13), // "midiPitchBend"
QT_MOC_LITERAL(15, 162, 9), // "midiSysex"
QT_MOC_LITERAL(16, 172, 4), // "data"
QT_MOC_LITERAL(17, 177, 16), // "midiSystemCommon"
QT_MOC_LITERAL(18, 194, 6), // "status"
QT_MOC_LITERAL(19, 201, 18) // "midiSystemRealtime"

    },
    "drumstick::rt::MIDIInput\0midiNoteOff\0"
    "\0chan\0note\0vel\0midiNoteOn\0midiKeyPressure\0"
    "value\0midiController\0control\0midiProgram\0"
    "program\0midiChannelPressure\0midiPitchBend\0"
    "midiSysex\0data\0midiSystemCommon\0status\0"
    "midiSystemRealtime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drumstick__rt__MIDIInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,
       6,    3,   71,    2, 0x06 /* Public */,
       7,    3,   78,    2, 0x06 /* Public */,
       9,    3,   85,    2, 0x06 /* Public */,
      11,    2,   92,    2, 0x06 /* Public */,
      13,    2,   97,    2, 0x06 /* Public */,
      14,    2,  102,    2, 0x06 /* Public */,
      15,    1,  107,    2, 0x06 /* Public */,
      17,    1,  110,    2, 0x06 /* Public */,
      19,    1,  113,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   10,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void drumstick::rt::MIDIInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MIDIInput *_t = static_cast<MIDIInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->midiNoteOff((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->midiNoteOn((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 2: _t->midiKeyPressure((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 3: _t->midiController((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 4: _t->midiProgram((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 5: _t->midiChannelPressure((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 6: _t->midiPitchBend((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 7: _t->midiSysex((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->midiSystemCommon((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->midiSystemRealtime((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MIDIInput::*)(const int , const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiNoteOff)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiNoteOn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiKeyPressure)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiController)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiProgram)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiChannelPressure)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiPitchBend)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiSysex)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiSystemCommon)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MIDIInput::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MIDIInput::midiSystemRealtime)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject drumstick::rt::MIDIInput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_drumstick__rt__MIDIInput.data,
      qt_meta_data_drumstick__rt__MIDIInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *drumstick::rt::MIDIInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drumstick::rt::MIDIInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_drumstick__rt__MIDIInput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int drumstick::rt::MIDIInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void drumstick::rt::MIDIInput::midiNoteOff(const int _t1, const int _t2, const int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void drumstick::rt::MIDIInput::midiNoteOn(const int _t1, const int _t2, const int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void drumstick::rt::MIDIInput::midiKeyPressure(const int _t1, const int _t2, const int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void drumstick::rt::MIDIInput::midiController(const int _t1, const int _t2, const int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void drumstick::rt::MIDIInput::midiProgram(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void drumstick::rt::MIDIInput::midiChannelPressure(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void drumstick::rt::MIDIInput::midiPitchBend(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void drumstick::rt::MIDIInput::midiSysex(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void drumstick::rt::MIDIInput::midiSystemCommon(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void drumstick::rt::MIDIInput::midiSystemRealtime(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
