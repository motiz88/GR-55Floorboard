/****************************************************************************
** Meta object code from reading C++ file 'customPanelButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customPanelButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customPanelButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customPanelButton_t {
    QByteArrayData data[9];
    char stringdata[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customPanelButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customPanelButton_t qt_meta_stringdata_customPanelButton = {
    {
QT_MOC_LITERAL(0, 0, 17), // "customPanelButton"
QT_MOC_LITERAL(1, 18, 12), // "valueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "value"
QT_MOC_LITERAL(4, 38, 4), // "hex1"
QT_MOC_LITERAL(5, 43, 4), // "hex2"
QT_MOC_LITERAL(6, 48, 4), // "hex3"
QT_MOC_LITERAL(7, 53, 8), // "setValue"
QT_MOC_LITERAL(8, 62, 5) // "blink"

    },
    "customPanelButton\0valueChanged\0\0value\0"
    "hex1\0hex2\0hex3\0setValue\0blink"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customPanelButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       1,    1,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   46,    2, 0x0a /* Public */,
       8,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void customPanelButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customPanelButton *_t = static_cast<customPanelButton *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->blink(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customPanelButton::*_t)(bool , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customPanelButton::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (customPanelButton::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customPanelButton::valueChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject customPanelButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customPanelButton.data,
      qt_meta_data_customPanelButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customPanelButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customPanelButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customPanelButton.stringdata))
        return static_cast<void*>(const_cast< customPanelButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int customPanelButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void customPanelButton::valueChanged(bool _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void customPanelButton::valueChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
