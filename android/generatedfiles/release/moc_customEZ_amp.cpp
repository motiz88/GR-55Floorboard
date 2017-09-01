/****************************************************************************
** Meta object code from reading C++ file 'customEZ_amp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customEZ_amp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customEZ_amp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customEZ_amp_t {
    QByteArrayData data[12];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customEZ_amp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customEZ_amp_t qt_meta_stringdata_customEZ_amp = {
    {
QT_MOC_LITERAL(0, 0, 12), // "customEZ_amp"
QT_MOC_LITERAL(1, 13, 13), // "y_axisChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "iy_axis"
QT_MOC_LITERAL(4, 36, 13), // "x_axisChanged"
QT_MOC_LITERAL(5, 50, 7), // "ix_axis"
QT_MOC_LITERAL(6, 58, 12), // "updateSignal"
QT_MOC_LITERAL(7, 71, 9), // "setY_axis"
QT_MOC_LITERAL(8, 81, 9), // "setX_axis"
QT_MOC_LITERAL(9, 91, 10), // "updateSlot"
QT_MOC_LITERAL(10, 102, 5), // "hex_1"
QT_MOC_LITERAL(11, 108, 5) // "hex_2"

    },
    "customEZ_amp\0y_axisChanged\0\0iy_axis\0"
    "x_axisChanged\0ix_axis\0updateSignal\0"
    "setY_axis\0setX_axis\0updateSlot\0hex_1\0"
    "hex_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customEZ_amp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   51,    2, 0x0a /* Public */,
       8,    1,   54,    2, 0x0a /* Public */,
       9,    2,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,

       0        // eod
};

void customEZ_amp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customEZ_amp *_t = static_cast<customEZ_amp *>(_o);
        switch (_id) {
        case 0: _t->y_axisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->x_axisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateSignal(); break;
        case 3: _t->setY_axis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setX_axis((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customEZ_amp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customEZ_amp::y_axisChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (customEZ_amp::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customEZ_amp::x_axisChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (customEZ_amp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customEZ_amp::updateSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject customEZ_amp::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_customEZ_amp.data,
      qt_meta_data_customEZ_amp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customEZ_amp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customEZ_amp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customEZ_amp.stringdata))
        return static_cast<void*>(const_cast< customEZ_amp*>(this));
    return QFrame::qt_metacast(_clname);
}

int customEZ_amp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void customEZ_amp::y_axisChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void customEZ_amp::x_axisChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customEZ_amp::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
