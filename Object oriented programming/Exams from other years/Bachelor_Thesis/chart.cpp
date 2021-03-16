#include "chart.h"
#include "ui_chart.h"
#include <qmessagebox.h>

Chart::Chart(Service& s, QWidget *parent)
    : QMainWindow(parent), serv(s)
    , ui(new Ui::Chart)
{
    ui->setupUi(this);
    this->InitChart();
    //QEvent* eve = new QEvent{ QEvent::MouseButtonPress	};

}

void Chart::InitChart()
{
    /*
    series = new QPieSeries();
    vector<string> vect = serv.getTeachers();
    int sum = 0;
    int totalStudents = serv.getStudents().size();
    for (int i = 0; i < vect.size(); i++)
    {
        int numberOfStudents = serv.getStudentsForTeacher(vect[i]).size();
        sum += numberOfStudents;
        series->append(QString::fromStdString(vect[i]), numberOfStudents);

    }
    series->append("No coordinator", totalStudents - sum);
    for(int i = 0; i < vect.size(); i++)
    {
        slice = series->slices().at(i);
        int numberOfStudents = serv.getStudentsForTeacher(vect[i]).size();
        if(numberOfStudents > 0)
            slice->setLabelVisible();
    }
    slice = series->slices().at(vect.size());
    if((totalStudents - sum) > 0)
        slice->setLabelVisible();

        chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Students and teachers");
        //chart->legend()->hide();

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);*/
}

Chart::~Chart()
{
    delete ui;
}

