/****************************************************************************
** Meta object code from reading C++ file 'pecinha.h'
**
** Created: Thu Aug 13 15:43:25 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pecinha.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pecinha.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tab__Pecinha[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tab__Pecinha[] = {
    "Tab::Pecinha\0\0moveEu(Tab::XyView)\0"
};

const QMetaObject Tab::Pecinha::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tab__Pecinha,
      qt_meta_data_Tab__Pecinha, 0 }
};

const QMetaObject *Tab::Pecinha::metaObject() const
{
    return &staticMetaObject;
}

void *Tab::Pecinha::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tab__Pecinha))
        return static_cast<void*>(const_cast< Pecinha*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tab::Pecinha::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveEu((*reinterpret_cast< Tab::XyView(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
