/****************************************************************************
** Meta object code from reading C++ file 'customTargetListMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customTargetListMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customTargetListMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customTargetListMenu_t {
    QByteArrayData data[14];
    char stringdata[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customTargetListMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customTargetListMenu_t qt_meta_stringdata_customTargetListMenu = {
    {
QT_MOC_LITERAL(0, 0, 20), // "customTargetListMenu"
QT_MOC_LITERAL(1, 21, 12), // "updateSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "updateDisplay"
QT_MOC_LITERAL(4, 49, 4), // "text"
QT_MOC_LITERAL(5, 54, 19), // "currentIndexChanged"
QT_MOC_LITERAL(6, 74, 5), // "index"
QT_MOC_LITERAL(7, 80, 12), // "updateTarget"
QT_MOC_LITERAL(8, 93, 4), // "hex1"
QT_MOC_LITERAL(9, 98, 4), // "hex2"
QT_MOC_LITERAL(10, 103, 4), // "hex3"
QT_MOC_LITERAL(11, 108, 12), // "valueChanged"
QT_MOC_LITERAL(12, 121, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(13, 140, 8) // "valueStr"

    },
    "customTargetListMenu\0updateSignal\0\0"
    "updateDisplay\0text\0currentIndexChanged\0"
    "index\0updateTarget\0hex1\0hex2\0hex3\0"
    "valueChanged\0dialogUpdateSignal\0"
    "valueStr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customTargetListMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       7,    3,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   58,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void customTargetListMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customTargetListMenu *_t = static_cast<customTargetListMenu *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateTarget((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->dialogUpdateSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customTargetListMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customTargetListMenu::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customTargetListMenu::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customTargetListMenu::updateDisplay)) {
                *result = 1;
            }
        }
        {
            typedef void (customTargetListMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customTargetListMenu::currentIndexChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (customTargetListMenu::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customTargetListMenu::updateTarget)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject customTargetListMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customTargetListMenu.data,
      qt_meta_data_customTargetListMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customTargetListMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customTargetListMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customTargetListMenu.stringdata))
        return static_cast<void*>(const_cast< customTargetListMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int customTargetListMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void customTargetListMenu::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customTargetListMenu::updateDisplay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customTargetListMenu::currentIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void customTargetListMenu::updateTarget(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
