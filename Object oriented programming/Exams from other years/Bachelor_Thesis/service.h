#ifndef SERVICE_H
#define SERVICE_H
#include "repo.h"

class Service
{
private:
    RepoAstronomer astronomers;
    RepoStar stars;
public:
    Service();
    vector<Star> getStars();
    void ReadFromFiles();
    /* The function adds a star, if the name isn't empty, if the name isn't already taken and if the diamater >= 
        If any of the above conditions are not met, the function will return a string with error messages and the star won't be added
        Otherwise, a star is created and added to the repository.
    */
    string AddStar(string name, string constellation, int rightAscension, int declination, double diameter);
    vector<string> tokenize(string inputString, string separator);
    vector<Astronomer> getAstronomers();
    vector<Star> search(string text);
    vector<Star> getStarsForConstellation(string constellation);
    void WriteToFile();

    ~Service() {
        WriteToFile();
    }

};

#endif // SERVICE_H
