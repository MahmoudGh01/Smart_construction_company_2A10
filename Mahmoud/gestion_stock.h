#ifndef GESTION_STOCK_H
#define GESTION_STOCK_H

#include <QMainWindow>
#include "stockp.h"
#include "stat_combo.h"
#include "histomod.h"
#include "historique.h"
#include "histosupp.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
namespace Ui {
class gestion_stock;
}

class gestion_stock : public QMainWindow
{
    Q_OBJECT
    Stockp tmp;

public:
    explicit gestion_stock(QWidget *parent = nullptr);
    ~gestion_stock();
    QSortFilterProxyModel *proxy;
    void show_table();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modif_button_clicked();



    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_Imprimer_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_PDF_clicked();

    void on_qrCode_clicked();

    void on_pushButton_clicked();

private:
    Ui::gestion_stock *ui;
    Stockp Stmp;
    int sel_col=-1;
    QString selected="";
    stat_combo *s;
historique tm;
histomod hm;
histosupp ts;
};

#endif // GESTION_STOCK_H
