/****************************************************************************
** Meta object code from reading C++ file 'door.h'
**
** Created: Sat Dec 5 03:55:37 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "door.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'door.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_door[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x08,
      45,   25,   25,   25, 0x08,
      64,   25,   25,   25, 0x08,
      83,   25,   25,   25, 0x08,
     102,   25,   25,   25, 0x08,
     121,   25,   25,   25, 0x08,
     140,   25,   25,   25, 0x08,
     159,   25,   25,   25, 0x08,
     178,   25,   25,   25, 0x08,
     197,   25,   25,   25, 0x08,
     216,   25,   25,   25, 0x08,
     237,   25,   25,   25, 0x08,
     257,   25,   25,   25, 0x08,
     278,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_door[] = {
    "door\0door_reset_timers()\0\0on_btn_1_clicked()\0"
    "on_btn_2_clicked()\0on_btn_3_clicked()\0"
    "on_btn_4_clicked()\0on_btn_5_clicked()\0"
    "on_btn_6_clicked()\0on_btn_7_clicked()\0"
    "on_btn_8_clicked()\0on_btn_9_clicked()\0"
    "on_btn_0_clicked()\0on_btn_cls_clicked()\0"
    "on_btn_bs_clicked()\0on_btn_bck_clicked()\0"
    "on_btn_cfm_clicked()\0"
};

void door::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        door *_t = static_cast<door *>(_o);
        switch (_id) {
        case 0: _t->door_reset_timers(); break;
        case 1: _t->on_btn_1_clicked(); break;
        case 2: _t->on_btn_2_clicked(); break;
        case 3: _t->on_btn_3_clicked(); break;
        case 4: _t->on_btn_4_clicked(); break;
        case 5: _t->on_btn_5_clicked(); break;
        case 6: _t->on_btn_6_clicked(); break;
        case 7: _t->on_btn_7_clicked(); break;
        case 8: _t->on_btn_8_clicked(); break;
        case 9: _t->on_btn_9_clicked(); break;
        case 10: _t->on_btn_0_clicked(); break;
        case 11: _t->on_btn_cls_clicked(); break;
        case 12: _t->on_btn_bs_clicked(); break;
        case 13: _t->on_btn_bck_clicked(); break;
        case 14: _t->on_btn_cfm_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData door::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject door::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_door,
      qt_meta_data_door, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &door::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *door::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *door::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_door))
        return static_cast<void*>(const_cast< door*>(this));
    return QWidget::qt_metacast(_clname);
}

int door::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void door::door_reset_timers()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
