/****************************************************************************
** Meta object code from reading C++ file 'customControlListMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlListMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlListMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlListMenu_t {
    QByteArrayData data[10];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlListMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlListMenu_t qt_meta_stringdata_customControlListMenu = {
    {
QT_MOC_LITERAL(0, 0, 21), // "customControlListMenu"
QT_MOC_LITERAL(1, 22, 12), // "updateSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "updateDisplay"
QT_MOC_LITERAL(4, 50, 4), // "text"
QT_MOC_LITERAL(5, 55, 19), // "currentIndexChanged"
QT_MOC_LITERAL(6, 75, 5), // "index"
QT_MOC_LITERAL(7, 81, 12), // "valueChanged"
QT_MOC_LITERAL(8, 94, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(9, 113, 9) // "set_index"

    },
    "customControlListMenu\0updateSignal\0\0"
    "updateDisplay\0text\0currentIndexChanged\0"
    "index\0valueChanged\0dialogUpdateSignal\0"
    "set_index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlListMenu[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   51,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void customControlListMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlListMenu *_t = static_cast<customControlListMenu *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->dialogUpdateSignal(); break;
        case 5: _t->set_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlListMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlListMenu::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlListMenu::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlListMenu::updateDisplay)) {
                *result = 1;
            }
        }
        {
            typedef void (customControlListMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlListMenu::currentIndexChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject customControlListMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlListMenu.data,
      qt_meta_data_customControlListMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlListMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlListMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlListMenu.stringdata))
        return static_cast<void*>(const_cast< customControlListMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlListMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void customControlListMenu::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlListMenu::updateDisplay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customControlListMenu::currentIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
