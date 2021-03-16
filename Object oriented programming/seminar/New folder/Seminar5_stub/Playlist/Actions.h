#pragma once
#include "Song.h"
#include "Repository.h"
using namespace std;



class Action {
public:
	virtual void executeUndo();
	virtual void executeRedo();

};

class ActionAdd {
private:
	Song addedSong;
	unique_ptr<Repository> Repo;
public:
	ActionAdd(unique_ptr<Repository> Rep, const Song& s);

	void executeUndo();
	void executeRedo();
};

class ActionRemove {
private:
	Song deletedSong;
	unique_ptr<Repository> Repo;

public:
	ActionRemove(unique_ptr<Repository> Rep, const Song& s);

	void executeUndo();
	void executeRedo();

};

class ActionUpdate {
private:
	Song oldSong;
	Song newSong;
	unique_ptr<Repository> Repo;

public:
	ActionUpdate(unique_ptr<Repository> Rep, const Song& oldSong, const Song& newSong);

	void executeUndo();
	void executeRedo();
};
