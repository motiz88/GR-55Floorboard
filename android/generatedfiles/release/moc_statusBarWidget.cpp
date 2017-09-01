/****************************************************************************
** Meta object code from reading C++ file 'statusBarWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/statusBarWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statusBarWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_statusBarWidget_t {
    QByteArrayData data[9];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_statusBarWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_statusBarWidget_t qt_meta_stringdata_statusBarWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "statusBarWidget"
QT_MOC_LITERAL(1, 16, 16), // "setStatusMessage"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "message"
QT_MOC_LITERAL(4, 42, 20), // "setStatusdBugMessage"
QT_MOC_LITERAL(5, 63, 4), // "dBug"
QT_MOC_LITERAL(6, 68, 17), // "setStatusProgress"
QT_MOC_LITERAL(7, 86, 5), // "value"
QT_MOC_LITERAL(8, 92, 15) // "setStatusSymbol"

    },
    "statusBarWidget\0setStatusMessage\0\0"
    "message\0setStatusdBugMessage\0dBug\0"
    "setStatusProgress\0value\0setStatusSymbol"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_statusBarWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void statusBarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        statusBarWidget *_t = static_cast<statusBarWidget *>(_o);
        switch (_id) {
        case 0: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setStatusdBugMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setStatusProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setStatusSymbol((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject statusBarWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_statusBarWidget.data,
      qt_meta_data_statusBarWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *statusBarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *statusBarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_statusBarWidget.stringdata))
        return static_cast<void*>(const_cast< statusBarWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int statusBarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
