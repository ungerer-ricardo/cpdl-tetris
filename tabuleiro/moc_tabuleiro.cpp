/****************************************************************************
** Meta object code from reading C++ file 'tabuleiro.h'
**
** Created: Thu Aug 13 15:43:24 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tabuleiro.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabuleiro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tabuleiro[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      31,   21,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   10,   10,   10, 0x0a,
      70,   61,   10,   10, 0x0a,
     102,   85,   10,   10, 0x0a,
     130,  125,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tabuleiro[] = {
    "Tabuleiro\0\0encaixe()\0pontuacao\0"
    "gameover(int)\0rotacionapeca()\0_direcao\0"
    "movepeca(bool)\0descendo,proxima\0"
    "startjogo(qint8,qint8)\0nova\0novapeca(qint8)\0"
};

const QMetaObject Tabuleiro::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tabuleiro,
      qt_meta_data_Tabuleiro, 0 }
};

const QMetaObject *Tabuleiro::metaObject() const
{
    return &staticMetaObject;
}

void *Tabuleiro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tabuleiro))
        return static_cast<void*>(const_cast< Tabuleiro*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tabuleiro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: encaixe(); break;
        case 1: gameover((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: rotacionapeca(); break;
        case 3: movepeca((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: startjogo((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< qint8(*)>(_a[2]))); break;
        case 5: novapeca((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Tabuleiro::encaixe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Tabuleiro::gameover(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
