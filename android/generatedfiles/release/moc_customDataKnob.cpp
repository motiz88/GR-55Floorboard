/****************************************************************************
** Meta object code from reading C++ file 'customDataKnob.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customDataKnob.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customDataKnob.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customDataKnob_t {
    QByteArrayData data[6];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customDataKnob_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customDataKnob_t qt_meta_stringdata_customDataKnob = {
    {
QT_MOC_LITERAL(0, 0, 14), // "customDataKnob"
QT_MOC_LITERAL(1, 15, 12), // "updateSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "updateDisplay"
QT_MOC_LITERAL(4, 43, 4), // "text"
QT_MOC_LITERAL(5, 48, 12) // "valueChanged"

    },
    "customDataKnob\0updateSignal\0\0updateDisplay\0"
    "text\0valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customDataKnob[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    4,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

       0        // eod
};

void customDataKnob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customDataKnob *_t = static_cast<customDataKnob *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customDataKnob::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customDataKnob::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customDataKnob::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customDataKnob::updateDisplay)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject customDataKnob::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customDataKnob.data,
      qt_meta_data_customDataKnob,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customDataKnob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customDataKnob::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customDataKnob.stringdata))
        return static_cast<void*>(const_cast< customDataKnob*>(this));
    return QWidget::qt_metacast(_clname);
}

int customDataKnob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void customDataKnob::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customDataKnob::updateDisplay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
