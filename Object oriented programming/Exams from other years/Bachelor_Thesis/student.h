#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Star
{
private:
    string name, constellation;
    int rightAscension, declination;
    double diameter;
public:
    Star() {}
    Star(string name, string constellation, int rightAscension, int declination, double diameter) :name{name}, constellation{constellation}, rightAscension{rightAscension}, declination{declination}, diameter{diameter} {}string getName() const;
    void setName(const string &value);
    string getConstellation() const;
    void setConstellation(const string &value);
    int getRightAscension() const;
    void setRightAscension(int value);
    int getDeclination() const;
    void setDeclination(int value);
    double getDiameter() const;
    void setDiameter(double value);
};

class Astronomer {
private:
    string name, constelation;
public:
    Astronomer(string name, string constelation) : name{name}, constelation{constelation} {}
    string getName() const;
    void setName(const string &value);
    string getConstelation() const;
    void setConstelation(const string &value);
};

#endif // STUDENT_H
