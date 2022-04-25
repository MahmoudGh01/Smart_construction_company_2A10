#include "gestion_stock.h"
#include "ui_gestion_stock.h"
#include "stockp.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QMessageBox>
#include <QSqlQueryModel>
#include<QTextDocument>
#include<QDebug>
#include<QPrinter>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include<QPrintDialog>
#include <QDate>
#include <QSqlQuery>
#include "qrcode.h"
#include "histomod.h"
#include "historique.h"
#include "histosupp.h"

using namespace qrcodegen;
using namespace std;

gestion_stock::gestion_stock(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_stock)
{
    ui->setupUi(this);
    show_table();

}

gestion_stock::~gestion_stock()
{
    delete ui;
}
void gestion_stock::show_table(){
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(tmp.afficher());

 //pour la recherche
    //proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tableView->setModel(proxy);

}


void gestion_stock::on_pushButton_2_clicked()
{
    int idh=ui->lineEdit_2->text().toInt();
    int prixh=ui->lineEdit_3->text().toInt();
    QString nom_produith=ui->lineEdit->text();


      int id=ui->lineEdit_2->text().toInt();
      int prix=ui->lineEdit_3->text().toInt();
      QString nom_produit=ui->lineEdit->text();
      Stockp S(id,prix,nom_produit);
      historique tm(idh , prixh , nom_produith );
      bool test=S.ajouter();
      if(test)
      {
          // actualiser
          tm.ajouter();

          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Ajout effectué\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tableView->setModel(Stmp.afficher());
          ui->tab_his->setModel(tm.afficher());
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                      QObject::tr("Ajout non effectuè.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion_stock::on_pushButton_3_clicked()
{
    int id =ui->lineEdit_4->text().toInt();
     int idhs =ui->lineEdit_4->text().toInt();


    bool test=Stmp.supprimer(id);
    histosupp ts (idhs);
    if(test)
    {
        ts.ajoutSupp();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Stmp.afficher());
        ui->hist_supp->setModel(ts.affichSupp());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("suppression non effectuè.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_stock::on_modif_button_clicked()
{
    int id1 =ui->id_modif->text().toInt();
     QString nom1=ui->nom_modif->text();
      int prix1 =ui->prix_modif->text().toInt();

      int idhm =ui->id_modif->text().toInt();
       QString nom_produithm=ui->nom_modif->text();
        int prixhm =ui->prix_modif->text().toInt();
    bool test=Stmp.modifier(id1 , nom1 , prix1);
    histomod hm (idhm , prixhm , nom_produithm );
    if(test)
    {
        hm.ajouter();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("modification effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Stmp.afficher());
        ui->hist_mod->setModel(hm.afficher());
    }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("Not ok"),
                    QObject::tr("modification non effectuè.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }
}

void gestion_stock::on_lineEdit_rech_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}


void gestion_stock::on_comboBox_currentTextChanged(const QString &arg1)
{
    sel_col=ui->comboBox->currentIndex()-1;
    proxy->setFilterKeyColumn(sel_col);
}

void gestion_stock::on_pushButton_Imprimer_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tableView->model()->rowCount();
                         const int columnCount = ui->tableView->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> LISTE DES  PRODUITS "+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableView->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableView->isColumnHidden(column)) {
                                     QString data =ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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


void gestion_stock::on_pushButton_4_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique salaire");
  s->choix_pie();
  s->show();
}


void gestion_stock::on_pushButton_PDF_clicked()
{
    Stockp p;
    p.creerpdf();
}


void gestion_stock::on_qrCode_clicked()
{
    int tabeq=ui->tableView->currentIndex().row();
               QVariant idd=ui->tableView->model()->data(ui->tableView->model()->index(tabeq,0));
               QString id=idd.toString();
              // QString code=idd.toSTring();
               QSqlQuery qry;
               qry.prepare("select * from STOCKP where code=:code");
               qry.bindValue(":code",id);
               qry.exec();

                QString nom_produit;//attributs
                int prix;


              while(qry.next()){

                  id=qry.value(1).toString();
                  prix=qry.value(2).toInt();

                    nom_produit=qry.value(3).toInt();



               }
               id=QString(id);
                      id="CODE:\t" +id+ "prix\t:" +prix+ "nom_produit:\t" +nom_produit;
               QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

               // Read the black & white pixels
               QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
               for (int y = 0; y < qr.getSize(); y++) {
                   for (int x = 0; x < qr.getSize(); x++) {
                       int color = qr.getModule(x, y);  // 0 for white, 1 for black

                       // You need to modify this part
                       if(color==0)
                           im.setPixel(x, y,qRgb(254, 254, 254));
                       else
                           im.setPixel(x, y,qRgb(0, 0, 0));
                   }
               }
               im=im.scaled(200,200);
              ui->qr_code->setPixmap(QPixmap::fromImage(im));
}

void gestion_stock::on_pushButton_clicked()
{
    close();
    MainWindow *ga;
    ga = new MainWindow();
    ga->show();
}
