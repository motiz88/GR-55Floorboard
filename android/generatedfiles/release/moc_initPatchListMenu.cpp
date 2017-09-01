/****************************************************************************
** Meta object code from reading C++ file 'initPatchListMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/initPatchListMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'initPatchListMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_initPatchListMenu_t {
    QByteArrayData data[8];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_initPatchListMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_initPatchListMenu_t qt_meta_stringdata_initPatchListMenu = {
    {
QT_MOC_LITERAL(0, 0, 17), // "initPatchListMenu"
QT_MOC_LITERAL(1, 18, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 12), // "updateSignal"
QT_MOC_LITERAL(5, 58, 13), // "loadInitPatch"
QT_MOC_LITERAL(6, 72, 18), // "highLightInitPatch"
QT_MOC_LITERAL(7, 91, 8) // "setIndex"

    },
    "initPatchListMenu\0currentIndexChanged\0"
    "\0index\0updateSignal\0loadInitPatch\0"
    "highLightInitPatch\0setIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_initPatchListMenu[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       7,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void initPatchListMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        initPatchListMenu *_t = static_cast<initPatchListMenu *>(_o);
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateSignal(); break;
        case 2: _t->loadInitPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->highLightInitPatch((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (initPatchListMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&initPatchListMenu::currentIndexChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (initPatchListMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&initPatchListMenu::updateSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject initPatchListMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_initPatchListMenu.data,
      qt_meta_data_initPatchListMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *initPatchListMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *initPatchListMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_initPatchListMenu.stringdata))
        return static_cast<void*>(const_cast< initPatchListMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int initPatchListMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void initPatchListMenu::currentIndexChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void initPatchListMenu::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
