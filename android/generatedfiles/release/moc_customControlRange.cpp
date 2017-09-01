/****************************************************************************
** Meta object code from reading C++ file 'customControlRange.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlRange.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlRange.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlRange_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlRange_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlRange_t qt_meta_stringdata_customControlRange = {
    {
QT_MOC_LITERAL(0, 0, 18), // "customControlRange"
QT_MOC_LITERAL(1, 19, 12), // "updateSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "updateDisplayMin"
QT_MOC_LITERAL(4, 50, 4), // "text"
QT_MOC_LITERAL(5, 55, 16), // "updateDisplayMax"
QT_MOC_LITERAL(6, 72, 18) // "dialogUpdateSignal"

    },
    "customControlRange\0updateSignal\0\0"
    "updateDisplayMin\0text\0updateDisplayMax\0"
    "dialogUpdateSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlRange[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    1,   38,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void customControlRange::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlRange *_t = static_cast<customControlRange *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplayMin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateDisplayMax((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->dialogUpdateSignal(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlRange::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlRange::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlRange::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlRange::updateDisplayMin)) {
                *result = 1;
            }
        }
        {
            typedef void (customControlRange::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlRange::updateDisplayMax)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject customControlRange::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlRange.data,
      qt_meta_data_customControlRange,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlRange::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlRange::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlRange.stringdata))
        return static_cast<void*>(const_cast< customControlRange*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlRange::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void customControlRange::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlRange::updateDisplayMin(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customControlRange::updateDisplayMax(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
