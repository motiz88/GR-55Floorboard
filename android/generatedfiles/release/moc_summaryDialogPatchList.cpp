/****************************************************************************
** Meta object code from reading C++ file 'summaryDialogPatchList.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/summaryDialogPatchList.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'summaryDialogPatchList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_summaryDialogPatchList_t {
    QByteArrayData data[12];
    char stringdata[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_summaryDialogPatchList_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_summaryDialogPatchList_t qt_meta_stringdata_summaryDialogPatchList = {
    {
QT_MOC_LITERAL(0, 0, 22), // "summaryDialogPatchList"
QT_MOC_LITERAL(1, 23, 15), // "setStatusSymbol"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "value"
QT_MOC_LITERAL(4, 46, 17), // "setStatusProgress"
QT_MOC_LITERAL(5, 64, 16), // "setStatusMessage"
QT_MOC_LITERAL(6, 81, 7), // "message"
QT_MOC_LITERAL(7, 89, 16), // "updatePatchNames"
QT_MOC_LITERAL(8, 106, 4), // "name"
QT_MOC_LITERAL(9, 111, 6), // "cancel"
QT_MOC_LITERAL(10, 118, 9), // "printFile"
QT_MOC_LITERAL(11, 128, 6) // "saveAs"

    },
    "summaryDialogPatchList\0setStatusSymbol\0"
    "\0value\0setStatusProgress\0setStatusMessage\0"
    "message\0updatePatchNames\0name\0cancel\0"
    "printFile\0saveAs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_summaryDialogPatchList[] = {

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
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   58,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,
      10,    0,   62,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void summaryDialogPatchList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        summaryDialogPatchList *_t = static_cast<summaryDialogPatchList *>(_o);
        switch (_id) {
        case 0: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->updatePatchNames((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->cancel(); break;
        case 5: _t->printFile(); break;
        case 6: _t->saveAs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (summaryDialogPatchList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogPatchList::setStatusSymbol)) {
                *result = 0;
            }
        }
        {
            typedef void (summaryDialogPatchList::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogPatchList::setStatusProgress)) {
                *result = 1;
            }
        }
        {
            typedef void (summaryDialogPatchList::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&summaryDialogPatchList::setStatusMessage)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject summaryDialogPatchList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_summaryDialogPatchList.data,
      qt_meta_data_summaryDialogPatchList,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *summaryDialogPatchList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *summaryDialogPatchList::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_summaryDialogPatchList.stringdata))
        return static_cast<void*>(const_cast< summaryDialogPatchList*>(this));
    return QWidget::qt_metacast(_clname);
}

int summaryDialogPatchList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void summaryDialogPatchList::setStatusSymbol(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void summaryDialogPatchList::setStatusProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void summaryDialogPatchList::setStatusMessage(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
