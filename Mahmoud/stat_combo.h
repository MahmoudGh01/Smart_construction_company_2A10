#ifndef STAT_COMBO_H
#define STAT_COMBO_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_combo;
}

class stat_combo : public QDialog
{
    Q_OBJECT

public:
    explicit stat_combo(QWidget *parent = nullptr);
    ~stat_combo();

    QChartView *chartView ;
    void choix_bar();
    void choix_pie();

private:
    Ui::stat_combo *ui;
};

#endif // STAT_COMBO_H
