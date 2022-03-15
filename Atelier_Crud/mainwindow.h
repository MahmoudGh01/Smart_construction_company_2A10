#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "batiment.h"


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Batiments b;
};

#endif // MAINWINDOW_H