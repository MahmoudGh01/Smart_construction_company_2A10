/****************************************************************************
** Meta object code from reading C++ file 'gestion_stock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Mahmoud/gestion_stock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestion_stock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gestion_stock_t {
    QByteArrayData data[13];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gestion_stock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gestion_stock_t qt_meta_stringdata_gestion_stock = {
    {
QT_MOC_LITERAL(0, 0, 13), // "gestion_stock"
QT_MOC_LITERAL(1, 14, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(4, 63, 23), // "on_modif_button_clicked"
QT_MOC_LITERAL(5, 87, 28), // "on_lineEdit_rech_textChanged"
QT_MOC_LITERAL(6, 116, 4), // "arg1"
QT_MOC_LITERAL(7, 121, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(8, 152, 30), // "on_pushButton_Imprimer_clicked"
QT_MOC_LITERAL(9, 183, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(10, 207, 25), // "on_pushButton_PDF_clicked"
QT_MOC_LITERAL(11, 233, 17), // "on_qrCode_clicked"
QT_MOC_LITERAL(12, 251, 21) // "on_pushButton_clicked"

    },
    "gestion_stock\0on_pushButton_2_clicked\0"
    "\0on_pushButton_3_clicked\0"
    "on_modif_button_clicked\0"
    "on_lineEdit_rech_textChanged\0arg1\0"
    "on_comboBox_currentTextChanged\0"
    "on_pushButton_Imprimer_clicked\0"
    "on_pushButton_4_clicked\0"
    "on_pushButton_PDF_clicked\0on_qrCode_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gestion_stock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gestion_stock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gestion_stock *_t = static_cast<gestion_stock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_2_clicked(); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_modif_button_clicked(); break;
        case 3: _t->on_lineEdit_rech_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_Imprimer_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushButton_PDF_clicked(); break;
        case 8: _t->on_qrCode_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject gestion_stock::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gestion_stock.data,
      qt_meta_data_gestion_stock,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gestion_stock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gestion_stock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gestion_stock.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gestion_stock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
