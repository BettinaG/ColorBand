/****************************************************************************
** Meta object code from reading C++ file 'midioutput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drumstick/midioutput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midioutput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_drumstick__rt__MIDIOutput_t {
    QByteArrayData data[19];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drumstick__rt__MIDIOutput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drumstick__rt__MIDIOutput_t qt_meta_stringdata_drumstick__rt__MIDIOutput = {
    {
QT_MOC_LITERAL(0, 0, 25), // "drumstick::rt::MIDIOutput"
QT_MOC_LITERAL(1, 26, 11), // "sendNoteOff"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "chan"
QT_MOC_LITERAL(4, 44, 4), // "note"
QT_MOC_LITERAL(5, 49, 3), // "vel"
QT_MOC_LITERAL(6, 53, 10), // "sendNoteOn"
QT_MOC_LITERAL(7, 64, 15), // "sendKeyPressure"
QT_MOC_LITERAL(8, 80, 5), // "value"
QT_MOC_LITERAL(9, 86, 14), // "sendController"
QT_MOC_LITERAL(10, 101, 7), // "control"
QT_MOC_LITERAL(11, 109, 11), // "sendProgram"
QT_MOC_LITERAL(12, 121, 7), // "program"
QT_MOC_LITERAL(13, 129, 19), // "sendChannelPressure"
QT_MOC_LITERAL(14, 149, 13), // "sendPitchBend"
QT_MOC_LITERAL(15, 163, 9), // "sendSysex"
QT_MOC_LITERAL(16, 173, 4), // "data"
QT_MOC_LITERAL(17, 178, 13), // "sendSystemMsg"
QT_MOC_LITERAL(18, 192, 6) // "status"

    },
    "drumstick::rt::MIDIOutput\0sendNoteOff\0"
    "\0chan\0note\0vel\0sendNoteOn\0sendKeyPressure\0"
    "value\0sendController\0control\0sendProgram\0"
    "program\0sendChannelPressure\0sendPitchBend\0"
    "sendSysex\0data\0sendSystemMsg\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drumstick__rt__MIDIOutput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       6,    3,   66,    2, 0x0a /* Public */,
       7,    3,   73,    2, 0x0a /* Public */,
       9,    3,   80,    2, 0x0a /* Public */,
      11,    2,   87,    2, 0x0a /* Public */,
      13,    2,   92,    2, 0x0a /* Public */,
      14,    2,   97,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,   10,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    8,
    QMetaType::Void, QMetaType::QByteArray,   16,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void drumstick::rt::MIDIOutput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MIDIOutput *_t = static_cast<MIDIOutput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendNoteOff((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->sendNoteOn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->sendKeyPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->sendController((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->sendProgram((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->sendChannelPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->sendPitchBend((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->sendSysex((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->sendSystemMsg((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject drumstick::rt::MIDIOutput::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_drumstick__rt__MIDIOutput.data,
      qt_meta_data_drumstick__rt__MIDIOutput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *drumstick::rt::MIDIOutput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drumstick::rt::MIDIOutput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_drumstick__rt__MIDIOutput.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int drumstick::rt::MIDIOutput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
