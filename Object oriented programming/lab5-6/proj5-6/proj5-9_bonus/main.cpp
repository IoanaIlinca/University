#include "mainwindow.h"
#include "Service.h"
#include "tests.h"
#include "GUI.h"
#include <vector>
#include <map>
#include <QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Service serv;
    string path = "File.txt";
    //string path = "Evidence.txt";
    serv.ServicePath(path);
    serv.ServiceAdd("12sd23","23X12X10",0.2452,3,"DSC13241.jpg");
    serv.ServiceAdd("16","21",0.2452,6,"MyPic.jpg");
    serv.ServiceAdd("1223", "23X12X10", 0.2452, 13, "DSC13241.jpg");
    serv.ServiceAdd("30", "21", 0.2452, 16, "MyPic.jpg");
    serv.ServiceAdd("salata de boeuf", "177", 0.2452, 13, "DSC13241.jpg");
    serv.ServiceAdd("60", "23X12X10", 0.2452, 16, "MyPic.jpg");
    serv.ServiceAdd("88", "ana", 0.2452, 13, "DSC13241.jpg");
    serv.ServiceAdd("14", "ana", 0.2452, 16, "MyPic.jpg");
    serv.ServiceAdd("mere", "23X12X10", 0.2452, 13, "DSC13241.jpg");
    serv.ServiceAdd("133", "ana", 0.2452, 16, "MyPic.jpg");
    map<string, vector<QBarSet*>> set;
    int i = 0;
    string strings[10];
    int measurementNumber = 0;
    for(auto p : serv.GetEvidence())
    {
        QBarSet* ptr = new QBarSet(QString::fromStdString(p.GetId()));
        int currentNumber = -1;
        for (i = 0; i < measurementNumber; i++)
            if(strings[i] == p.GetMeasurement())
                currentNumber = i;
        if (currentNumber == -1)
        {
            currentNumber = measurementNumber;
            strings[measurementNumber] = p.GetMeasurement();
            measurementNumber++;
        }
        for(i = 0; i < currentNumber; i++)
            *ptr << 0;
        *ptr << p.GetQuantity();
        set[p.GetMeasurement()].push_back(ptr);
    }


    QBarSeries *series = new QBarSeries();

    for (auto p : serv.GetEvidence())
        for(i = 0; i < set[p.GetMeasurement()].size(); i++)
            series->append(set[p.GetMeasurement()][i]);


    QChart *chart = new QChart();


    chart->addSeries(series);

    chart->setTitle("Quantity");
    chart->setAnimationOptions(QChart::AllAnimations);
     QStringList categories;
     string str;
     for (auto p : serv.GetEvidence())
     {
         if (str.find(p.GetMeasurement()) == string::npos)
         {
            categories << QString::fromStdString(p.GetMeasurement());
            str+=p.GetMeasurement();
         }
     }


     QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(categories);
     chart->createDefaultAxes();

     chart->setAxisX(axis, series);
     chart->legend()->setVisible(true);
     chart->legend()->setAlignment(Qt::AlignBottom);


     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);


     QPalette pal = qApp->palette();


     pal.setColor(QPalette::Window, QRgb(0xffffff));
     pal.setColor(QPalette::WindowText, QRgb(0x404040));

     qApp->setPalette(pal);

     QMainWindow window;
     window.setCentralWidget(chartView);
     window.resize(720, 400);
     window.show();


    /*
    GUI gui{serv};
    gui.resize(500, 500);
    gui.show();*/
    return a.exec();
}
