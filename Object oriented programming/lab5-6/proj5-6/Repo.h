#pragma once
#include "PieceOfEvidence.h"
#include "Validator.h"
#include <vector>
using namespace std;

class Repo
{
protected:
	int position = -1;
	//char file[1001];
	string file = "";

public:
	/* Constructor, no parameters */
	Repo();

	/* Destructor, no parameters */
	~Repo();

	/*Saves the path of the file*/
	void SavePath(string& path);

	/*Reads the evidence from a text file*/
	vector<PieceOfEvidence> ReadFromFile();

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
	friend ostream& operator<<(ostream& output, const Repo& rep);

	/*Returns the next element*/
	PieceOfEvidence Next();

	/*Returns the current element*/
	PieceOfEvidence Current();

	/*Returns the first element*/
	PieceOfEvidence Begin();
};

class RepoHTML {
public:
	/*Opens a tag to write in a html file*/
	void OpenTag(ostream& fout, string tag);

	/*Closes a tag to write in a html file*/
	void CloseTag(ostream& fout, string tag);

	/*Reads from a file*/
	vector<PieceOfEvidence> ReadFromFile(string file);

	/*Writes to a file*/
	void WriteToFile(string file, vector<PieceOfEvidence> MyList);
};

class RepoCSV {
public:
	/*Reads from a file*/
	vector<PieceOfEvidence> ReadFromFile(string file);

	/*Writes to a file*/
	void WriteToFile(string file, vector<PieceOfEvidence> MyList);
};

class RepoB : public RepoHTML, public RepoCSV {
private:
	//vector<PieceOfEvidence> MyList;
	string file = "";
	string fileType = "";

public:
	/*Constructor*/
	RepoB();

	/*Destructor*/
	~RepoB();

	/*Saves a piece to MyList*/
	void SavePiece(PieceOfEvidence newPiece);

	/*Gets an element from MyList given its id*/
	PieceOfEvidence GetElement(string id);

	/* Overwrites the << operator */
	friend ostream& operator<<(ostream& output, const RepoB& rep);

	/*Reads from a file*/
	vector<PieceOfEvidence> ReadFromFile();

	/*Writes to a file*/
	void WriteToFile(vector<PieceOfEvidence> MyList);

	/*Saves the path of the file*/
	void SavePathMyList(string & path);

	/*Gets the size of MyList*/
	int GetSizeMyList();
};
