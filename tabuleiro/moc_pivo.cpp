/****************************************************************************
** Meta object code from reading C++ file 'pivo.h'
**
** Created: Thu Aug 13 15:43:26 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pivo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pivo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tab__Pivo[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   10,   10,   10, 0x0a,
      42,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tab__Pivo[] = {
    "Tab::Pivo\0\0mudou(Tab::XyView)\0rotaciona()\0"
    "desce()\0"
};

const QMetaObject Tab::Pivo::staticMetaObject = {
    { &Tab::Pecinha::staticMetaObject, qt_meta_stringdata_Tab__Pivo,
      qt_meta_data_Tab__Pivo, 0 }
};

const QMetaObject *Tab::Pivo::metaObject() const
{
    return &staticMetaObject;
}

void *Tab::Pivo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tab__Pivo))
        return static_cast<void*>(const_cast< Pivo*>(this));
    typedef Tab::Pecinha QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int Tab::Pivo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef Tab::Pecinha QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mudou((*reinterpret_cast< Tab::XyView(*)>(_a[1]))); break;
        case 1: rotaciona(); break;
        case 2: desce(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Tab::Pivo::mudou(Tab::XyView _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
