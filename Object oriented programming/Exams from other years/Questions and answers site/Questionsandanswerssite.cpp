#include "Questionsandanswerssite.h"

Questionsandanswerssite::Questionsandanswerssite(Service& s, QWidget *parent)
    : QMainWindow(parent), serv{s}
{
    ui.setupUi(this);
}
