/****************************************************************************
** Meta object code from reading C++ file 'dragBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/dragBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dragBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dragBar_t {
    QByteArrayData data[7];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dragBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dragBar_t qt_meta_stringdata_dragBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "dragBar"
QT_MOC_LITERAL(1, 8, 11), // "showDragBar"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "newpos"
QT_MOC_LITERAL(4, 28, 11), // "hideDragBar"
QT_MOC_LITERAL(5, 40, 16), // "setCollapseState"
QT_MOC_LITERAL(6, 57, 5) // "state"

    },
    "dragBar\0showDragBar\0\0newpos\0hideDragBar\0"
    "setCollapseState\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dragBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void dragBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dragBar *_t = static_cast<dragBar *>(_o);
        switch (_id) {
        case 0: _t->showDragBar((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->hideDragBar(); break;
        case 2: _t->setCollapseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject dragBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dragBar.data,
      qt_meta_data_dragBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dragBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dragBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dragBar.stringdata))
        return static_cast<void*>(const_cast< dragBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int dragBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
