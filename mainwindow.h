#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stockp.h"
#include "stat_combo.h"

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Stockp tmp;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;
    void show_table();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_modif_button_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_Imprimer_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_PDF_clicked();

    void on_qrCode_clicked();

private:
    Ui::MainWindow *ui;
    Stockp Stmp;
    int sel_col=-1;
    QString selected="";
    stat_combo *s;
};

#endif // MAINWINDOW_H
