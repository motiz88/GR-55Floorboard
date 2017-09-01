/****************************************************************************
** Meta object code from reading C++ file 'customControlEZ_Patch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/customControlEZ_Patch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customControlEZ_Patch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customControlEZ_Patch_t {
    QByteArrayData data[10];
    char stringdata[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customControlEZ_Patch_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customControlEZ_Patch_t qt_meta_stringdata_customControlEZ_Patch = {
    {
QT_MOC_LITERAL(0, 0, 21), // "customControlEZ_Patch"
QT_MOC_LITERAL(1, 22, 12), // "updateSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13), // "updateDisplay"
QT_MOC_LITERAL(4, 50, 4), // "text"
QT_MOC_LITERAL(5, 55, 18), // "dialogUpdateSignal"
QT_MOC_LITERAL(6, 74, 12), // "valueChanged"
QT_MOC_LITERAL(7, 87, 11), // "tone_select"
QT_MOC_LITERAL(8, 99, 16), // "variation_select"
QT_MOC_LITERAL(9, 116, 12) // "select_patch"

    },
    "customControlEZ_Patch\0updateSignal\0\0"
    "updateDisplay\0text\0dialogUpdateSignal\0"
    "valueChanged\0tone_select\0variation_select\0"
    "select_patch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customControlEZ_Patch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       5,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   54,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void customControlEZ_Patch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customControlEZ_Patch *_t = static_cast<customControlEZ_Patch *>(_o);
        switch (_id) {
        case 0: _t->updateSignal(); break;
        case 1: _t->updateDisplay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->dialogUpdateSignal(); break;
        case 3: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->tone_select((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->variation_select((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->select_patch(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customControlEZ_Patch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlEZ_Patch::updateSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (customControlEZ_Patch::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlEZ_Patch::updateDisplay)) {
                *result = 1;
            }
        }
        {
            typedef void (customControlEZ_Patch::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customControlEZ_Patch::dialogUpdateSignal)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject customControlEZ_Patch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customControlEZ_Patch.data,
      qt_meta_data_customControlEZ_Patch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customControlEZ_Patch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customControlEZ_Patch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customControlEZ_Patch.stringdata))
        return static_cast<void*>(const_cast< customControlEZ_Patch*>(this));
    return QWidget::qt_metacast(_clname);
}

int customControlEZ_Patch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void customControlEZ_Patch::updateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customControlEZ_Patch::updateDisplay(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void customControlEZ_Patch::dialogUpdateSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
