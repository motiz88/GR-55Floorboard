/****************************************************************************
** Meta object code from reading C++ file 'floorPanelBar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/floorPanelBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'floorPanelBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_floorPanelBar_t {
    QByteArrayData data[12];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_floorPanelBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_floorPanelBar_t qt_meta_stringdata_floorPanelBar = {
    {
QT_MOC_LITERAL(0, 0, 13), // "floorPanelBar"
QT_MOC_LITERAL(1, 14, 12), // "resizeSignal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "newValue"
QT_MOC_LITERAL(4, 37, 14), // "collapseSignal"
QT_MOC_LITERAL(5, 52, 13), // "collapseState"
QT_MOC_LITERAL(6, 66, 9), // "collapsed"
QT_MOC_LITERAL(7, 76, 11), // "showDragBar"
QT_MOC_LITERAL(8, 88, 6), // "newpos"
QT_MOC_LITERAL(9, 95, 11), // "hideDragBar"
QT_MOC_LITERAL(10, 107, 6), // "setPos"
QT_MOC_LITERAL(11, 114, 6) // "newPos"

    },
    "floorPanelBar\0resizeSignal\0\0newValue\0"
    "collapseSignal\0collapseState\0collapsed\0"
    "showDragBar\0newpos\0hideDragBar\0setPos\0"
    "newPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_floorPanelBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,
       9,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   11,

       0        // eod
};

void floorPanelBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        floorPanelBar *_t = static_cast<floorPanelBar *>(_o);
        switch (_id) {
        case 0: _t->resizeSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->collapseSignal(); break;
        case 2: _t->collapseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showDragBar((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: _t->hideDragBar(); break;
        case 5: _t->setPos((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (floorPanelBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBar::resizeSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (floorPanelBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBar::collapseSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (floorPanelBar::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBar::collapseState)) {
                *result = 2;
            }
        }
        {
            typedef void (floorPanelBar::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBar::showDragBar)) {
                *result = 3;
            }
        }
        {
            typedef void (floorPanelBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBar::hideDragBar)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject floorPanelBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_floorPanelBar.data,
      qt_meta_data_floorPanelBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *floorPanelBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *floorPanelBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_floorPanelBar.stringdata))
        return static_cast<void*>(const_cast< floorPanelBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int floorPanelBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void floorPanelBar::resizeSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void floorPanelBar::collapseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void floorPanelBar::collapseState(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void floorPanelBar::showDragBar(QPoint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void floorPanelBar::hideDragBar()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
