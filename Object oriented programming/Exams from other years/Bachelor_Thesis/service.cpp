#include "service.h"
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <time.h>
#include <string>
using namespace std;

Service::Service()
{
    ReadFromFiles();
}

vector<Star> Service::getStars()
{
    return stars.getStars();
}


void Service::ReadFromFiles()
{
    string line;
    vector<string> splitted;
    ifstream fin;
    fin.open("Stars.txt");
    while (getline(fin, line))
            {
                splitted = tokenize(line, ",");
                string name, constellation;
                int rightAscension, declination;
                double diameter;
                name = splitted[0];
                constellation = splitted[1];
                try {
                    rightAscension = stoi(splitted[2]);
                }
                catch (exception ex) {
                    rightAscension = 0;
                }

                try {
                    declination = stoi(splitted[3]);
                }
                catch (exception ex) {
                    declination = 0;
                }

                try {
                    diameter = stod(splitted[4]);
                }
                catch (exception ex) {
                    diameter = 0.0;
                }

                Star st( name, constellation, rightAscension, declination, diameter);

                stars.RepoAdd(st);
            }
    //vector<Student> stu = students.getStudents();
    //assert(stu.size() == 5);
   // assert(stu[2].getCoordinator() == "");
    //assert(stu[0].getTitle() == "No title");

    fin.close();
    fin.open("Astronomers.txt");
    //assert(fin.is_open() == true);
    while (getline(fin, line))
            {
                splitted = tokenize(line, ",");
                string name, constellation;
                name = splitted[0];
                constellation = splitted[1];
                Astronomer astr(name, constellation);
                astronomers.RepoAdd(astr);

            }
    //teachers.RepoAdd("Marcel");
    fin.close();
}

string Service::AddStar(string name, string constellation, int rightAscension, int declination, double diameter)
{
    string messages = "";
    if (name == "")
    {
        messages += "You need to write a name!\n";
    }
    for (auto st : this->getStars())
    {
        if (st.getName() == name)
        {
            messages += "There already is a star with this name!\n";
            break;
        }
    }
    if (diameter <= 0)
    {
        messages += "The diameter needs to be positive!\n";
    }
    if(messages != "")
        return messages;
    Star st(name, constellation, rightAscension, declination, diameter);
    stars.RepoAdd(st);
    return "";
}

vector<string> Service::tokenize(string inputString, string separator)
{
    string currentWord;
    vector<string> tokens{};
    int endOfWord = 0;
    while (inputString.find_first_of(separator) != string::npos) {
                endOfWord = inputString.find_first_of(separator);
                currentWord = inputString.substr(0, endOfWord);
                //while (currentWord.substr(1) == " ")
                    //currentWord.erase(0, 1);
                //while (currentWord.substr(currentWord.size() - 1, 1) == " ")
                    //currentWord.pop_back();
                tokens.push_back(currentWord);
                inputString.erase(0, endOfWord + separator.size() + 1);
                //inputString.erase(remove_if(inputString.begin(), inputString.end(), isspace), inputString.end());
                //cout << tokens.back()<<'\n';
            }
            tokens.push_back(inputString);
            return tokens;
}

vector<Astronomer> Service::getAstronomers()
{
    return astronomers.getAstronomers();
}

vector<Star> Service::search(string text)
{
    vector<Star> final;
    for(auto st : this->getStars())
    {
        if(st.getName().find(text) != string::npos)
            final.push_back(st);
    }
    return final;
}

vector<Star> Service::getStarsForConstellation(string constellation)
{
    vector<Star> final;
    for (auto st : this->getStars())
    {
        if (st.getConstellation() == constellation)
            final.push_back(st);
    }
    return final;
}

void Service::WriteToFile()
{
    ofstream fout("Stars.txt");
    vector<Star> sorted;
    for (auto st : stars.getStars())
    {
        sorted.push_back(st);
    }
    
    sort(sorted.begin(), sorted.end(), [](const Star& a, const Star& b) -> bool
        {
            return a.getConstellation() < b.getConstellation();
        });
    for (auto st : sorted)
    {
        fout << st.getName() << ", " << st.getConstellation() << ", " << st.getRightAscension() << ", " << st.getDeclination() << ", " << st.getDiameter ()<< "\n";
    }
    fout.close();
}


