#include "Exam3.h"
#include "service.h"
#include "GUI.h"
#include "tests.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service<Person> serv;

    /*
    list<string> parts;
    parts.push_back("fruit");
    Person veggie("maria", "Ioana", parts);
    serv.ServiceAdd(veggie);*/
    TestAll();
    GUI gui{ serv };
    gui.resize(500, 500);
    gui.show();

    return a.exec();
}
