#pragma once

//#include "PieceOfEvidence.h"

class Tests {
private:
	

public:

	Tests();
	~Tests();
	/*Tests the piece of evidence class*/
	void TestPieceOfEvidence();


	/*Tests the Add function*/
	void TestAdd();

	/*Tests the delete function*/
	void TestDelete();

	/*Tests the update function*/
	void TestUpdate();

	/*Tests the saveId function*/
	void TestSaveId();

	/*Tests the iterator functions*/
	void TestIterator();
};

/*Calls the test functions*/
void TestAll();
