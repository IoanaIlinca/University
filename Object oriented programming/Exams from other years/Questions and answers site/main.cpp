#include "Questionsandanswerssite.h"
#include "UsersWindow.h"
#include "Service.h"
#include "listViewQuestionsModel.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service serv;
    //GUI gui;
    
    Questionsandanswerssite w{ serv };
   // QPieSeries* series = new QPieSeries{&w};
    listViewQuestionsModel* model = new listViewQuestionsModel{ serv };
    w.setWindowTitle("Main Window");
    w.show();
    vector<string> users = serv.GetUsers();
    QList<UsersWindow*> windows;
   
    for (int i = 0; i < users.size(); i++)
    {
        UsersWindow* newWindow = new UsersWindow{ serv, model };
        newWindow->setWindowTitle(QString::fromStdString(users[i]));
        windows.append(newWindow);
        windows[i]->show();
    }
    
    
    return a.exec();
}
