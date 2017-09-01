/****************************************************************************
** Meta object code from reading C++ file 'soundSource_modeling_bass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/soundSource_modeling_bass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundSource_modeling_bass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_soundsource_modeling_bass_t {
    QByteArrayData data[3];
    char stringdata[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_soundsource_modeling_bass_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_soundsource_modeling_bass_t qt_meta_stringdata_soundsource_modeling_bass = {
    {
QT_MOC_LITERAL(0, 0, 25), // "soundsource_modeling_bass"
QT_MOC_LITERAL(1, 26, 12), // "updateSignal"
QT_MOC_LITERAL(2, 39, 0) // ""

    },
    "soundsource_modeling_bass\0updateSignal\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_soundsource_modeling_bass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void soundsource_modeling_bass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        soundsource_modeling_bass *_t = static_cast<soundsource_modeling_bass *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject soundsource_modeling_bass::staticMetaObject = {
    { &soundSource::staticMetaObject, qt_meta_stringdata_soundsource_modeling_bass.data,
      qt_meta_data_soundsource_modeling_bass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *soundsource_modeling_bass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *soundsource_modeling_bass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_soundsource_modeling_bass.stringdata))
        return static_cast<void*>(const_cast< soundsource_modeling_bass*>(this));
    return soundSource::qt_metacast(_clname);
}

int soundsource_modeling_bass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = soundSource::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
