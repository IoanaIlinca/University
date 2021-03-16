#include "student.h"

string Star::getConstellation() const
{
    return constellation;
}

void Star::setConstellation(const string &value)
{
    constellation = value;
}

int Star::getRightAscension() const
{
    return rightAscension;
}

void Star::setRightAscension(int value)
{
    rightAscension = value;
}

int Star::getDeclination() const
{
    return declination;
}

void Star::setDeclination(int value)
{
    declination = value;
}

double Star::getDiameter() const
{
    return diameter;
}

void Star::setDiameter(double value)
{
    diameter = value;
}

string Star::getName() const
{
    return name;
}

void Star::setName(const string &value)
{
    name = value;
}

string Astronomer::getConstelation() const
{
    return constelation;
}

void Astronomer::setConstelation(const string &value)
{
    constelation = value;
}

string Astronomer::getName() const
{
    return name;
}

void Astronomer::setName(const string &value)
{
    name = value;
}
