#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "batiment.h"


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


private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();



    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Batiments b;
    int sel_col=-1;
};

#endif // MAINWINDOW_H
