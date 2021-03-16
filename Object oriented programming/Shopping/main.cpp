#include "Shopping.h"
#include "service.h"
#include "tests.h"
#include "GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service<People> serv;

    /*
    list<string> parts;
    parts.push_back("fruit");
    People veggie("maria", "Ioana", parts);
    serv.ServiceAdd(veggie);*/
    GUI gui{ serv };
    gui.resize(500, 500);
    gui.show();
    TestAll();

    return a.exec();
}
