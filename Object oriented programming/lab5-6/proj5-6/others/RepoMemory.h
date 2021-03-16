#pragma once
#include "DynamicArray.h"
#include "PieceOfEvidence.h"
#include <vector>

class RepoMemory
{
protected:
	vector<PieceOfEvidence> Evidence;
	int position = 0;

public:
	/* Constructor, no parameters */
	RepoMemory();

	/* Destructor, no parameters */
	//~RepoMemory();

	/* Getter - retunrs a copy of the array */
	vector<PieceOfEvidence> GetEvidence();

	/* Getter - returns an element with a give id*/
	PieceOfEvidence GetElement(string id);

	/* Getter - returns the size of the repository */
	int GetSize();

	/*  Adds a piece in the array of pieces */
	void AddPiece(PieceOfEvidence newPiece);

	/*  Deletes a piece in the array of pieces*/
	void DeletePiece(PieceOfEvidence);

	/* Updates a piece in the array of pieces */
	void UpdatePiece(PieceOfEvidence newPiece);

	/* Overwrites the << operator */
	//friend ostream& operator<<(ostream& output, const RepoMemory& rep);

	/*Returns the next element*/
	PieceOfEvidence Next();

	/*Returns the current element*/
	PieceOfEvidence Current();

	/*Returns the first element*/
	PieceOfEvidence Begin();
};

class RepoBMemory {
private:
	vector<PieceOfEvidence> MyList;

public:
	/*Constructor*/
	//RepoBMemory();

	/*Destructor*/
	//~RepoBMemory();

	/*Saves a piece to MyList*/
	void SavePiece(PieceOfEvidence newPiece);

	/*Gets an element from MyList given its id*/
	PieceOfEvidence GetElement(string id);

	/* Overwrites the << operator */
	//friend ostream& operator<<(ostream& output, const RepoBMemory& rep);

	/*Gets the size of MyList*/
	int GetSizeMyList();

	vector<PieceOfEvidence> GetMyList() 
	{
		return MyList; 
	}
};
