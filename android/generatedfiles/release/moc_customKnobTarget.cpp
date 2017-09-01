/****************************************************************************
** Meta object code from reading C++ file 'customKnobTarget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customKnobTarget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customKnobTarget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customKnobTarget_t {
    QByteArrayData data[14];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customKnobTarget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customKnobTarget_t qt_meta_stringdata_customKnobTarget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "customKnobTarget"
QT_MOC_LITERAL(1, 17, 12), // "updateSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "updateDisplayTarget"
QT_MOC_LITERAL(4, 51, 4), // "text"
QT_MOC_LITERAL(5, 56, 16), // "updateDisplayMin"
QT_MOC_LITERAL(6, 73, 16), // "updateDisplayMax"
QT_MOC_LITERAL(7, 90, 12), // "updateTarget"
QT_MOC_LITERAL(8, 103, 6), // "hexMsb"
QT_MOC_LITERAL(9, 110, 4), // "hex2"
QT_MOC_LITERAL(10, 115, 6), // "hexLsb"
QT_MOC_LITERAL(11, 122, 9), // "updateHex"
QT_MOC_LITERAL(12, 132, 12), // "valueChanged"
QT_MOC_LITERAL(13, 145, 10) // "knobSignal"

    },
    "customKnobTarget\0updateSignal\0\0"
    "updateDisplayTarget\0text\0updateDisplayMin\0"
    "updateDisplayMax\0updateTarget\0hexMsb\0"
    "hex2\0hexLsb\0updateHex\0valueChanged\0"
    "knobSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customKnobTarget[] = {

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
      12,    4,   78,    2, 0x0a /* Public */,
      13,    3,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

       0        // eod
};

void customKnobTarget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customKnobTarget *_t = static_cast<customKnobTarget *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplayTarget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateDisplayMin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updateDisplayMax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateTarget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->updateHex((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 6: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 7: _t->knobSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customKnobTarget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customKnobTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateDisplayTarget)) {
                *result = 1;
            }
        }
        {
            typedef void (customKnobTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateDisplayMin)) {
                *result = 2;
            }
        }
        {
            typedef void (customKnobTarget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateDisplayMax)) {
                *result = 3;
            }
        }
        {
            typedef void (customKnobTarget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateTarget)) {
                *result = 4;
            }
        }
        {
            typedef void (customKnobTarget::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customKnobTarget::updateHex)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject customKnobTarget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customKnobTarget.data,
      qt_meta_data_customKnobTarget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customKnobTarget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customKnobTarget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customKnobTarget.stringdata))
        return static_cast<void*>(const_cast< customKnobTarget*>(this));
    return QWidget::qt_metacast(_clname);
}

int customKnobTarget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void customKnobTarget::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customKnobTarget::updateDisplayTarget(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customKnobTarget::updateDisplayMin(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void customKnobTarget::updateDisplayMax(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void customKnobTarget::updateTarget(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void customKnobTarget::updateHex(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
