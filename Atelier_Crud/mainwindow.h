#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "batiment.h"
#include "stat_combo.h"
#include "arduino.h"


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
    Batiments tmp;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSortFilterProxyModel *proxy;
    void show_table();
    void fill_form(QString selected );
    void clear_form( );

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_tab_batiment_clicked(const QModelIndex &index);

    void on_tab_batiment_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();



    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_pushButton_PDF_clicked();
    void update_label();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Batiments b;
    int sel_col=-1;
    QString selected="";
    stat_combo *s;
    QByteArray data;

    int alert=0;

    Arduino A;
};

#endif // MAINWINDOW_H
