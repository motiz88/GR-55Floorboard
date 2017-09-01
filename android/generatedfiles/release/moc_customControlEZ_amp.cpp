/****************************************************************************
** Meta object code from reading C++ file 'customControlEZ_amp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlEZ_amp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlEZ_amp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlEZ_amp_t {
    QByteArrayData data[11];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlEZ_amp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlEZ_amp_t qt_meta_stringdata_customControlEZ_amp = {
    {
QT_MOC_LITERAL(0, 0, 19), // "customControlEZ_amp"
QT_MOC_LITERAL(1, 20, 12), // "updateSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 17), // "graphUpdateSignal"
QT_MOC_LITERAL(4, 52, 5), // "hex_1"
QT_MOC_LITERAL(5, 58, 5), // "hex_2"
QT_MOC_LITERAL(6, 64, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(7, 83, 13), // "y_axisChanged"
QT_MOC_LITERAL(8, 97, 7), // "iy_axis"
QT_MOC_LITERAL(9, 105, 13), // "x_axisChanged"
QT_MOC_LITERAL(10, 119, 7) // "ix_axis"

    },
    "customControlEZ_amp\0updateSignal\0\0"
    "graphUpdateSignal\0hex_1\0hex_2\0"
    "dialogUpdateSignal\0y_axisChanged\0"
    "iy_axis\0x_axisChanged\0ix_axis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlEZ_amp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    2,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void customControlEZ_amp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlEZ_amp *_t = static_cast<customControlEZ_amp *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->graphUpdateSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->dialogUpdateSignal(); break;
        case 3: _t->y_axisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->x_axisChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlEZ_amp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlEZ_amp::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlEZ_amp::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlEZ_amp::graphUpdateSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject customControlEZ_amp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlEZ_amp.data,
      qt_meta_data_customControlEZ_amp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlEZ_amp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlEZ_amp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlEZ_amp.stringdata))
        return static_cast<void*>(const_cast< customControlEZ_amp*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlEZ_amp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void customControlEZ_amp::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlEZ_amp::graphUpdateSignal(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
