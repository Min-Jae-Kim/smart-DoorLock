/****************************************************************************
** Meta object code from reading C++ file 'lcd_show.h'
**
** Created: Sat Dec 5 10:25:10 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "lcd_show.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lcd_show.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_lcd_show[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,   34,   34,   34, 0x08,
      35,   34,   34,   34, 0x08,
      46,   34,   34,   34, 0x08,
      68,   34,   34,   34, 0x08,
      91,   34,   34,   34, 0x08,
     110,  139,   34,   34, 0x08,
     143,   34,   34,   34, 0x08,
     160,   34,   34,   34, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_lcd_show[] = {
    "lcd_show\0on_btn_message_clicked()\0\0"
    "on_timer()\0on_btn_door_clicked()\0"
    "on_btn_check_clicked()\0on_thread_update()\0"
    "on_thread_error(const char*)\0str\0"
    "on_reset_timer()\0on_pushButton_clicked()\0"
};

void lcd_show::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        lcd_show *_t = static_cast<lcd_show *>(_o);
        switch (_id) {
        case 0: _t->on_btn_message_clicked(); break;
        case 1: _t->on_timer(); break;
        case 2: _t->on_btn_door_clicked(); break;
        case 3: _t->on_btn_check_clicked(); break;
        case 4: _t->on_thread_update(); break;
        case 5: _t->on_thread_error((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 6: _t->on_reset_timer(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData lcd_show::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject lcd_show::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_lcd_show,
      qt_meta_data_lcd_show, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &lcd_show::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *lcd_show::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *lcd_show::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_lcd_show))
        return static_cast<void*>(const_cast< lcd_show*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int lcd_show::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
