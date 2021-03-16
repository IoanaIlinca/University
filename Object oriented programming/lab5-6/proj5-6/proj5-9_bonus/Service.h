#pragma once
#include "Repo.h"
#include "Validator.h"
#include "Actions.h"
#include <stack>
using namespace std;

class Service
{
protected:
	Repo repository;
	PieceValidator validator;
	stack<unique_ptr<Action>> actionsUndo;
	stack<unique_ptr<Action>> actionsRedo;

public:
	/* Constructor, no parameters */
	Service();
	/* Destructor, no parameters */
	~Service();

	string Undo();
	string Redo();

	/*Makes sure the path exists, and passes to repo*/
	void ServicePath(string& path);

	/*  Creates a piece and adds it to the repository
		returns true if successful, false otherwise */
	string ServiceAdd(string id, string measurement, double imageClarityLevel, int quantity, string photograph);

	/* Creates a new piece with the new values and replaces the old one in te repository
		returns true if successful, false otherwise */
	string ServiceUpdate(string id, string newMeasurement, double newImageClarityLevel, int newQuantity, string newPhotograph);

	/* Deletes a piece with a given id form the repository
		returns true if successful, false otherwise */
	string ServiceDelete(string id);

	/* Getter
		returns a copy of the repository */
	Repo GetRepository();

	vector<PieceOfEvidence> GetEvidence();

	/* Getter
		it gets an id and returns a PieceOfEvidence (with id -1 if it hasn't been found ) */
	PieceOfEvidence ServiceElement(string id);

	/* Overwrites the << operator */
	friend ostream& operator<<(ostream& output, const Service& serv);

	/* Returns the size of the repository */
	int GetSize();
};

class ServiceB : public Service /*Protected?*/{
protected:
	RepoB repositoryMyList;

public:
	ServiceB();
	~ServiceB();

	/*Saves a piece to MyList*/
	bool SaveIdToMyList(string id);

	/* Overwrites the << operator */
	friend ostream& operator<<(ostream& output, const ServiceB& serv);

	/*Gets the size of MyList*/
	int GetSizeMyList();

	/*Returns the next element*/
	PieceOfEvidence Next();

	/*Returns the next element with a certain measurement*/
	PieceOfEvidence Next(string measurement);

	/*Returns the current element*/
	PieceOfEvidence Current();

	/*Returns the first element*/
	PieceOfEvidence Begin();

	/*Passed the path to repoB*/
	void ServicePathB(string& path);

	/*Gets the elements with a certain measurement and a greater or equal quantity with the parameter*/
	vector<PieceOfEvidence> GetElements(string measurement, int quantity);
};