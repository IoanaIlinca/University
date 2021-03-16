#include "tests.h"
#include "Service.h"
#include <assert.h>


void Tests::TestPieceOfEvidence()
{
	PieceOfEvidence piece("12sd23", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	assert(piece.GetMeasurement() == "23X12X10");
	assert(piece.GetId() == "12sd23");
	assert(piece.GetImageClarityLevel() == 0.2452);
	assert(piece.GetQuantity() == 13);
	assert(piece.GetPhotograph() == "DSC13241.jpg");
	piece = piece;
	piece.SetMeasurement("blabla");
	piece.SetImageClarityLevel(1.23);
	piece.SetQuantity(16);
	piece.SetPhotograph("NewPhoto.jpg");
	assert(piece.GetMeasurement() == "blabla");
	assert(piece.GetQuantity() == 16);
	assert(piece.GetPhotograph() == "NewPhoto.jpg");
	assert(piece.GetImageClarityLevel() == 1.23);
	//cout << p;
	piece.~PieceOfEvidence();
}


void Tests::TestAdd()
{
	Service serv;
	string file = "TestFile.txt";
	serv.ServicePath(file);
	assert(serv.GetSize() == 0);
	serv.ServiceAdd("balala", "23212", 0.2, 12, "anne.nef");
	assert(serv.ServiceAdd("balala", "23212", 0.2, 12, "anne.nef") == "Id already exists");
	assert(serv.GetSize() == 1);
	assert(serv.ServiceDelete("balala") == "");
}

void Tests::TestDelete()
{
	Service serv;
	string file = "TestFile.txt";
	serv.ServicePath(file);
	//assert(serv.GetSize() == 10);
	//assert(serv.ServiceDelete("balala") == false);
	serv.ServiceAdd("balala", "23212", 0.2, 12, "anne.nef");
	assert(serv.GetSize() == 1);
	//rep.GetEvidence()->print();
	assert(serv.ServiceDelete("balala") == "");
	//cout << serv;
	assert(serv.GetSize() == 0);
	assert(serv.ServiceDelete("balala") == "Id does not exist");
	//rep.GetEvidence()->print();
}

void Tests::TestUpdate()
{
	Service serv;
	string file = "TestFile.txt";
	serv.ServicePath(file);
	assert(serv.GetSize() == 0);
	assert(serv.ServiceUpdate("balala", "23212", 0.2, 12, "anne.nef") == "Id does not exist");
	serv.ServiceAdd("balala", "23212", 0.2, 12, "anne.nef");
	assert(serv.GetSize() == 1);
	serv.ServiceUpdate("balala", "23212", 0.2, 14, "anne.nef");  
	assert((serv.ServiceElement("balala")).GetQuantity() == 14);

	assert(serv.ServiceDelete("balala") == "");
	//cout << serv;
	assert(serv.GetSize() == 0);
	//serv.GetRepository().GetEvidence().print();
	//rep.GetEvidence()->print();
}

void Tests::TestIterator()
{
	ServiceB serv;
	string file = "Evidence_og.txt";
	serv.ServicePath(file);
	assert(serv.GetSize() == 10);
	serv.ServiceAdd("balala", "23212", 0.2, 12, "anne.nef");
	assert(serv.GetSize() == 11);
	serv.ServiceUpdate("balala", "23212", 0.2, 14, "anne.nef");
	assert((serv.ServiceElement("balala")).GetQuantity() == 14);
	assert(serv.Begin().GetId() == "12sd23");
	assert(serv.Current().GetId() == "12sd23");
	assert(serv.Next().GetId() == "16");
	assert(serv.Next("ana").GetId() == "88");
	//assert(serv.GetRepository().Begin().GetId() == "12sd23");
	//assert(serv.ServiceElementMyList("12sd23").GetMeasurement() == "23X12X10");
	vector<PieceOfEvidence> result = serv.GetElements("ana", 12);
	//cout << result;
	assert(result[0].GetMeasurement() == "ana");
	assert(result[0].GetQuantity() >= 12);
	PieceOfEvidence piece("-1", "", 0, 0, "");
	assert(serv.Next("balala") == piece);


	assert(serv.ServiceDelete("balala") == "");
	//cout << serv;
	assert(serv.GetSize() == 10);
	//cout << serv.GetRepository();
	//serv.GetRepository().GetEvidence().print();
	//rep.GetEvidence()->print();
}

void Tests::TestSaveId()
{
	ServiceB serv;
	string file = "Evidence_og.txt";
	serv.ServicePath(file);
	serv.SaveIdToMyList("mere");
	assert(serv.SaveIdToMyList("balala") == false);
	assert(serv.GetSizeMyList() == 1);
	serv.SaveIdToMyList("mere");
	assert(serv.GetSizeMyList() == 1);
}

void TestAll()
{
	Tests test;
	test.TestPieceOfEvidence();
	//test.TestDynamicArray();
	test.TestAdd();
	test.TestDelete();
	test.TestUpdate();
	//test.TestSaveId();
	test.TestIterator();
}

Tests::Tests()
{

}

Tests::~Tests()
{

}