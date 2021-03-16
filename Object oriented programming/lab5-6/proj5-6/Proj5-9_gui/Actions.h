#pragma once
#include "PieceOfEvidence.h"
#include "Repo.h"
using namespace std;



class Action {
public:
	virtual void executeUndo() {}
	virtual void executeRedo() {}

	virtual ~Action() {}
};

class ActionAdd : public virtual Action {
private:
	PieceOfEvidence addedPiece;
	unique_ptr<Repo> Repository;
public:
	ActionAdd(unique_ptr<Repo> Rep, const PieceOfEvidence& p);

	void executeUndo();
	void executeRedo();
};

class ActionRemove : public virtual Action {
private:
	PieceOfEvidence deletedPiece;
	unique_ptr<Repo> Repository;

public:
	ActionRemove(unique_ptr<Repo> Rep, const PieceOfEvidence& p);

	void executeUndo();
	void executeRedo();

};

class ActionUpdate : public virtual Action {
private:
	PieceOfEvidence oldPiece;
	PieceOfEvidence newPiece;
	unique_ptr<Repo> Repository;

public:
	ActionUpdate(unique_ptr<Repo> Rep, const PieceOfEvidence& oldPiece, const PieceOfEvidence& newPiece);

	void executeUndo();
	void executeRedo();
};

class ActionSave : public virtual Action {
private:
	PieceOfEvidence savedPiece;
	unique_ptr<RepoB> Repository;
public:
	ActionSave(unique_ptr<RepoB> Rep, const PieceOfEvidence& p);

	void executeUndo();
	void executeRedo();
};