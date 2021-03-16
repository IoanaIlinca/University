#include "Vegetables.h"
#include "service.h"
#include "GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service<Vegetable> serv;

    /*
    list<string> parts;
    parts.push_back("fruit");
    Vegetable veggie("maria", "Ioana", parts);
    serv.ServiceAdd(veggie);*/
    GUI gui{ serv };
    gui.resize(500, 500);
    gui.show();

    return a.exec();
}
