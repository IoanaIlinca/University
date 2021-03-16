#ifndef CHART_H
#define CHART_H

#include <QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "service.h"
#include "teacherwindow.h"

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Chart; }
QT_END_NAMESPACE

class Chart : public QMainWindow
{
    Q_OBJECT
    friend class TeacherWindow;
public:
    Chart(Service& s, QWidget *parent = nullptr);
    ~Chart();

private:
    Ui::Chart *ui;
    Service& serv;
    QPieSeries *series;
    QPieSlice *slice;
    QChart *chart;
    QChartView *chartView;
    void InitChart();

};
#endif // CHART_H
