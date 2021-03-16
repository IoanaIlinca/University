#ifndef REPO_H
#define REPO_H
#include "student.h"
#include <vector>
using namespace std;

class RepoAstronomer
{
private:
    vector<Astronomer> Astronomers;
public:
    RepoAstronomer() {}
    void RepoAdd(Astronomer astro);

    vector<Astronomer> getAstronomers() const;
};

class RepoStar
{
private:
    vector<Star> Stars;
public:
    RepoStar() {};
    void RepoAdd(Star st);

    vector<Star> getStars() const;
};

#endif // REPO_H
