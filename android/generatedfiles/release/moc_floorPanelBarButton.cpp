/****************************************************************************
** Meta object code from reading C++ file 'floorPanelBarButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../grfloorboard/floorPanelBarButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'floorPanelBarButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_floorPanelBarButton_t {
    QByteArrayData data[5];
    char stringdata[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_floorPanelBarButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_floorPanelBarButton_t qt_meta_stringdata_floorPanelBarButton = {
    {
QT_MOC_LITERAL(0, 0, 19), // "floorPanelBarButton"
QT_MOC_LITERAL(1, 20, 14), // "collapseSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "setCollapseState"
QT_MOC_LITERAL(4, 53, 9) // "collapsed"

    },
    "floorPanelBarButton\0collapseSignal\0\0"
    "setCollapseState\0collapsed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_floorPanelBarButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,

       0        // eod
};

void floorPanelBarButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        floorPanelBarButton *_t = static_cast<floorPanelBarButton *>(_o);
        switch (_id) {
        case 0: _t->collapseSignal(); break;
        case 1: _t->setCollapseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (floorPanelBarButton::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&floorPanelBarButton::collapseSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject floorPanelBarButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_floorPanelBarButton.data,
      qt_meta_data_floorPanelBarButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *floorPanelBarButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *floorPanelBarButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_floorPanelBarButton.stringdata))
        return static_cast<void*>(const_cast< floorPanelBarButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int floorPanelBarButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void floorPanelBarButton::collapseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
