/****************************************************************************
** Meta object code from reading C++ file 'fileDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/fileDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fileDialog_t {
    QByteArrayData data[7];
    char stringdata[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_fileDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_fileDialog_t qt_meta_stringdata_fileDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "fileDialog"
QT_MOC_LITERAL(1, 11, 10), // "patchIndex"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "value"
QT_MOC_LITERAL(4, 29, 12), // "valueChanged"
QT_MOC_LITERAL(5, 42, 11), // "highlighted"
QT_MOC_LITERAL(6, 54, 6) // "cancel"

    },
    "fileDialog\0patchIndex\0\0value\0valueChanged\0"
    "highlighted\0cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fileDialog[] = {

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
       4,    1,   37,    2, 0x0a /* Public */,
       5,    1,   40,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void fileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fileDialog *_t = static_cast<fileDialog *>(_o);
        switch (_id) {
        case 0: _t->patchIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->highlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (fileDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&fileDialog::patchIndex)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject fileDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fileDialog.data,
      qt_meta_data_fileDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *fileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_fileDialog.stringdata))
        return static_cast<void*>(const_cast< fileDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int fileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void fileDialog::patchIndex(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
