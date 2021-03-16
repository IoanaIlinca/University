#include "chart.h"
#include "service.h"
#include "teacherwindow.h"
#include "teacherwindomodel.h"
#include <qdir.h>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Service serv;
    //Chart w(serv);
    //w.show();

    // Test add star
    assert(serv.AddStar("", "", 1, 2, 3) == "You need to write a name!\n");
    assert(serv.AddStar("Andromeda", "", 1, 2, 3) == "There already is a star with this name!\n");
    assert(serv.AddStar("Inna", "", 1, 2, 0) == "The diameter needs to be positive!\n");
    

    vector<Astronomer> astronomers = serv.getAstronomers();
    QList<TeacherWindow*> windows;
    QList<teacherWindoModel*> models;


    for (int i = 0; i < astronomers.size(); i++)
       {
           teacherWindoModel* model = new teacherWindoModel(serv, astronomers[i], true);
           models.append(model);
           TeacherWindow* newWindow = new TeacherWindow{ serv, model, astronomers[i]};
           newWindow->setWindowTitle(QString::fromStdString(astronomers[i].getName()));
           windows.append(newWindow);
           windows[i]->show();
       }

    return a.exec();
}
