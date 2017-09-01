/****************************************************************************
** Meta object code from reading C++ file 'menuPage_system.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/menuPage_system.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menuPage_system.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_menuPage_system_t {
    QByteArrayData data[3];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_menuPage_system_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_menuPage_system_t qt_meta_stringdata_menuPage_system = {
    {
QT_MOC_LITERAL(0, 0, 15), // "menuPage_system"
QT_MOC_LITERAL(1, 16, 12), // "updateSignal"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "menuPage_system\0updateSignal\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_menuPage_system[] = {

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

void menuPage_system::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        menuPage_system *_t = static_cast<menuPage_system *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject menuPage_system::staticMetaObject = {
    { &menuPage::staticMetaObject, qt_meta_stringdata_menuPage_system.data,
      qt_meta_data_menuPage_system,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *menuPage_system::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *menuPage_system::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_menuPage_system.stringdata))
        return static_cast<void*>(const_cast< menuPage_system*>(this));
    return menuPage::qt_metacast(_clname);
}

int menuPage_system::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = menuPage::qt_metacall(_c, _id, _a);
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
