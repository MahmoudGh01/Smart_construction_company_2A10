#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gestion_batiment.h"
#include "gestion_stock.h"
#include "connection.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Connection c;
};
#endif // MAINWINDOW_H
