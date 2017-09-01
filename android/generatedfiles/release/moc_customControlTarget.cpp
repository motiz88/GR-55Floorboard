/****************************************************************************
** Meta object code from reading C++ file 'customControlTarget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlTarget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlTarget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlTarget_t {
    QByteArrayData data[14];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlTarget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlTarget_t qt_meta_stringdata_customControlTarget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "customControlTarget"
QT_MOC_LITERAL(1, 20, 12), // "updateSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "updateDisplayTarget"
QT_MOC_LITERAL(4, 54, 4), // "text"
QT_MOC_LITERAL(5, 59, 16), // "updateDisplayMin"
QT_MOC_LITERAL(6, 76, 16), // "updateDisplayMax"
QT_MOC_LITERAL(7, 93, 12), // "updateTarget"
QT_MOC_LITERAL(8, 106, 6), // "hexMsb"
QT_MOC_LITERAL(9, 113, 4), // "hex2"
QT_MOC_LITERAL(10, 118, 6), // "hexLsb"
QT_MOC_LITERAL(11, 125, 9), // "updateHex"
QT_MOC_LITERAL(12, 135, 10), // "knobSignal"
QT_MOC_LITERAL(13, 146, 18) // "dialogUpdateSignal"

    },
    "customControlTarget\0updateSignal\0\0"
    "updateDisplayTarget\0text\0updateDisplayMin\0"
    "updateDisplayMax\0updateTarget\0hexMsb\0"
    "hex2\0hexLsb\0updateHex\0knobSignal\0"
    "dialogUpdateSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlTarget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    1,   58,    2, 0x06 /* Public */,
       6,    1,   61,    2, 0x06 /* Public */,
       7,    3,   64,    2, 0x06 /* Public */,
      11,    3,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    3,   78,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void customControlTarget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlTarget *_t = static_cast<customControlTarget *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplayTarget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateDisplayMin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateDisplayMax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateTarget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->updateHex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->knobSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->dialogUpdateSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlTarget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateDisplayTarget)) {
                *result = 1;
            }
        }
        {
            typedef void (customControlTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateDisplayMin)) {
                *result = 2;
            }
        }
        {
            typedef void (customControlTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateDisplayMax)) {
                *result = 3;
            }
        }
        {
            typedef void (customControlTarget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateTarget)) {
                *result = 4;
            }
        }
        {
            typedef void (customControlTarget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlTarget::updateHex)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject customControlTarget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlTarget.data,
      qt_meta_data_customControlTarget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlTarget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlTarget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlTarget.stringdata))
        return static_cast<void*>(const_cast< customControlTarget*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlTarget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void customControlTarget::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlTarget::updateDisplayTarget(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customControlTarget::updateDisplayMin(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void customControlTarget::updateDisplayMax(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void customControlTarget::updateTarget(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void customControlTarget::updateHex(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
