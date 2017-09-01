/****************************************************************************
** Meta object code from reading C++ file 'renameDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/renameDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renameDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_renameDialog_t {
    QByteArrayData data[7];
    char stringdata[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_renameDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_renameDialog_t qt_meta_stringdata_renameDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "renameDialog"
QT_MOC_LITERAL(1, 13, 11), // "nameChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "name"
QT_MOC_LITERAL(4, 31, 13), // "addRightArrow"
QT_MOC_LITERAL(5, 45, 12), // "addLeftArrow"
QT_MOC_LITERAL(6, 58, 9) // "emitValue"

    },
    "renameDialog\0nameChanged\0\0name\0"
    "addRightArrow\0addLeftArrow\0emitValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_renameDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   37,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void renameDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        renameDialog *_t = static_cast<renameDialog *>(_o);
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addRightArrow(); break;
        case 2: _t->addLeftArrow(); break;
        case 3: _t->emitValue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (renameDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&renameDialog::nameChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject renameDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_renameDialog.data,
      qt_meta_data_renameDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *renameDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *renameDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_renameDialog.stringdata))
        return static_cast<void*>(const_cast< renameDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int renameDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void renameDialog::nameChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
