#include "repo.h"

vector<Astronomer> RepoAstronomer::getAstronomers() const
{
    return Astronomers;
}

void RepoAstronomer::RepoAdd(Astronomer astro)
{
    Astronomers.push_back(astro);
}

void RepoStar::RepoAdd(Star st)
{
    Stars.push_back(st);
}


vector<Star> RepoStar::getStars() const
{
    return Stars;
}
