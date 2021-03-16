#include "RepoMemory.h"

RepoMemory::RepoMemory()
{
	PieceOfEvidence piece("12sd23", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece2("16", "21", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece3("1223", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece4("30", "21", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece5("salata de boeuf", "177", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece6("60", "23X12X10", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece7("88", "ana", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece8("14", "ana", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece9("mere", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece10("133", "ana", 0.2452, 16, "MyPic.jpg");
	Evidence.push_back(piece);
	Evidence.push_back(piece2);
	Evidence.push_back(piece3);
	Evidence.push_back(piece4);
	Evidence.push_back(piece5);
	Evidence.push_back(piece6);
	Evidence.push_back(piece7);
	Evidence.push_back(piece8);
	Evidence.push_back(piece9);
	Evidence.push_back(piece10);
	position = 0;
	//Evidence.print();
}

vector<PieceOfEvidence> RepoMemory::GetEvidence()
{
	return Evidence;
}

void RepoMemory::AddPiece(PieceOfEvidence newPiece)
{
	Evidence.push_back(newPiece);
}

void RepoMemory::DeletePiece(PieceOfEvidence oldPiece)
{
	/*
	for (int iterator = 0; iterator < Evidence.size(); iterator++)
	{
		PieceOfEvidence piece = Evidence.get(iterator);
		if (piece == oldPiece)
		{
			//cout << oldPiece;
			Evidence.del(piece, iterator);
			break;
		}
			
	}*/
	int iterator = 0;
	for (auto piece : Evidence)
	{
		if (piece == oldPiece)
		{
			//cout << oldPiece;
			Evidence.erase(Evidence.begin() + iterator);
			break;
		}
		iterator++;
	}

}

void RepoMemory::UpdatePiece(PieceOfEvidence newPiece)
{
	/*
	for (int iterator = 0; iterator < Evidence.size(); iterator++)
	{
		PieceOfEvidence piece = Evidence.get(iterator);
		if (piece == newPiece)
		{
			Evidence.set(iterator, newPiece);
		}
	}*/
	int iterator = 0;
	for (auto piece : Evidence)
	{
		if (piece == newPiece)
		{
			Evidence.emplace(Evidence.begin() + iterator, newPiece);
			Evidence.erase(Evidence.begin() + iterator + 1);

		}
		iterator++;
	}
}

int RepoMemory::GetSize()
{
	return Evidence.size();
}

PieceOfEvidence RepoMemory::GetElement(string id)
{
	/*
	for (int iterator = 0; iterator < Evidence.size(); iterator++)
	{
		PieceOfEvidence piece = Evidence.get(iterator);
		if (piece.GetId() == id)
			return piece;
	}
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	return piece2;*/
	for (auto piece : Evidence)
	{
		if (piece.GetId() == id)
			return piece;
	}
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	return piece2;
}

PieceOfEvidence RepoMemory::Next()
{
	position++;
	if (position >= Evidence.size())
		position = 0;
	return Evidence[position];
}

PieceOfEvidence RepoMemory::Current()
{
	if (position == -1)
		position = 0;
	return Evidence[position];
}

PieceOfEvidence RepoMemory::Begin()
{
	return Evidence[0];
}

/*
ostream& operator<<(ostream& output, const RepoMemory& rep)
{

	//for (int iterator = 0; iterator < m_size; iterator++)
	output << rep.Evidence;
	return output;
}
*/


void RepoBMemory::SavePiece(PieceOfEvidence newPiece)
{
	MyList.push_back(newPiece);
}

int RepoBMemory::GetSizeMyList()
{
	return MyList.size();
}


PieceOfEvidence RepoBMemory::GetElement(string id)
{
	for (int iterator = 0; iterator < MyList.size(); iterator++)
	{
		PieceOfEvidence piece = MyList[iterator];
		if (piece.GetId() == id)
			return piece;
	}
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	return piece2;
}
/*
ostream& operator<<(ostream& output, const RepoBMemory& rep)
{

	//for (int iterator = 0; iterator < m_size; iterator++)
	output << rep.MyList;
	return output;
}*/