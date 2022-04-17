#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "batiment.h"
#include "exportexcelobject.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include<QTextDocument>
#include<QDebug>
#include<QPrinter>

#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>

#include <QDate>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//ui->tab_batiment->setModel(b.afficher());
show_table();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::show_table(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tab_batiment->setModel(proxy);

}
void MainWindow::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from BATIMENT where ID= :ID");
    query.bindValue(":ID", selected);
    query.exec();
    while(query.next()){

  ui->lineEdit_ID->setText(query.value(0).toString()); //line edit
  ui->lineEdit_responsable->setText(query.value(1).toString());
  ui->lineEdit_Adresse->setText(query.value(3).toString());
  ui->spinBox_budget->setValue(query.value(4).toInt());
   ui->lineEdit_type->setCurrentText(query.value(2).toString()); //combobox


    }

}
void MainWindow::clear_form( ) {

    ui->lineEdit_ID->clear();
     ui->lineEdit_responsable->clear();
    ui->lineEdit_type->setCurrentIndex(0);
    ui->lineEdit_Adresse->clear();
    ui->spinBox_budget->setValue(0);

}


void MainWindow::on_pb_ajouter_clicked()
{
    QString id= ui->lineEdit_ID->text();
    QString responsable= ui->lineEdit_responsable->text();
    QString type= ui->lineEdit_type->currentText();
    QString adresse= ui->lineEdit_Adresse->text();
    QString budget= ui->spinBox_budget->text();
    Batiments b(id,responsable,type,adresse,budget) ;
    bool test=b.ajouter();
    if (test)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        show_table();
        clear_form();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Ajout échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
   }

void MainWindow::on_pb_supprimer_clicked()
{
    Batiments B1; B1.setid(ui->lineEdit_ID->text());
    bool test=B1.supprimer(B1.get_id());
    if (test)
    { QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        show_table();
        clear_form();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Suppression échoué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{

    QString id= ui->lineEdit_ID->text();
    QString responsable= ui->lineEdit_responsable->text();
    QString type= ui->lineEdit_type->currentText();
    QString adresse= ui->lineEdit_Adresse->text();
     QString budget= ui->spinBox_budget->text();



    Batiments B(id,responsable,type,adresse,budget);


bool ok = B.modifier();
if(ok)
{

    QMessageBox::information(nullptr, QObject::tr("succes"),
                QObject::tr(" modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    show_table();
    clear_form();


}
else
    QMessageBox::critical(nullptr, QObject::tr("fail"),
                QObject::tr(" non modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tab_batiment);

    //colums to export
    obj.addField(0, "ID", "char(20)");
    obj.addField(1, "RESPONSABLE", "char(20)");
    obj.addField(2, "TYPE", "char(20)");
    obj.addField(3, "ADRESSE", "char(20)");
    obj.addField(4, "BUDGET", "char(20)");




    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tab_batiment->model()->rowCount();
                         const int columnCount = ui->tab_batiment->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  BATIMENTS ******\n"+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tab_batiment->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tab_batiment->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_batiment->isColumnHidden(column)) {
                                     QString data =ui->tab_batiment->model()->data(ui->tab_batiment->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;

}
//rechercher
void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    sel_col=ui->comboBox->currentIndex();
    proxy->setFilterKeyColumn(sel_col); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}
//selection
void MainWindow::on_tab_batiment_clicked(const QModelIndex &index)
{
    selected=ui->tab_batiment->model()->data(index).toString();
}

void MainWindow::on_tab_batiment_doubleClicked(const QModelIndex &index)
{
    fill_form(selected);
}

void MainWindow::on_pushButton_2_clicked()
{
    clear_form();
}

void MainWindow::on_commandLinkButton_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique salaire");
  s->choix_pie();
  s->show();
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique type");
  s->choix_bar();
  s->show();
}

void MainWindow::on_pushButton_PDF_clicked()
{
    Batiments p;
    p.creerpdf();
}
