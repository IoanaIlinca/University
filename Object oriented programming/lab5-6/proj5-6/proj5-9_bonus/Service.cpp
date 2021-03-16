#include "Service.h"
#include <fstream>
using namespace std;

void Service::ServicePath(string& path)
{
	fstream file;
	file.open(path, ios::in);
	//cout << file.is_open() << ' ';
	if (!file.is_open())
		file.open(path, ios::out | ios::app); // makes sure the file exists, if it doesn't, it creates a new one

	file.close();

	repository.SavePath(path);
}

string Service::Undo()
{
	if (actionsUndo.empty() == true)
		return "No actions to undo";
	unique_ptr<Action> thisAction = move(actionsUndo.top());
	thisAction->executeUndo();
	actionsRedo.emplace(move(thisAction));
	actionsUndo.pop();
}

string Service::Redo()
{
	if (actionsRedo.empty() == true)
		return "No actions to redo";
	unique_ptr<Action> thisAction = move(actionsRedo.top());
	thisAction->executeRedo();
	actionsUndo.emplace(move(thisAction));
	actionsRedo.pop();
}

string Service::ServiceAdd(string id, string measurement, double imageClarityLevel, int quantity, string photograph)
{
	PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);

		try {
			validator.validate(piece);
		}
		catch (ValidationException exception) {
			return exception.getMessage();
		}
		try {
			repository.AddPiece(piece);
		}
		catch (ValidationException exception) {
			return exception.getMessage();
		}
	//unique_ptr<Repo> ptr = make_unique<Repo>(repository);
	//repository.AddPiece(piece);
	unique_ptr<Repo> ptr = make_unique<Repo>(repository);
	unique_ptr<ActionAdd> thisAction = make_unique<ActionAdd>(move(ptr), piece);
	actionsUndo.emplace(move(thisAction));
	return "";
}


string Service::ServiceUpdate(string id, string newMeasurement, double newImageClarityLevel, int newQuantity, string newPhotograph)
{
	PieceOfEvidence piece(id, newMeasurement, newImageClarityLevel, newQuantity, newPhotograph);
	PieceOfEvidence oldPiece;
	oldPiece = repository.GetElement(id);
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	try {
		validator.validate(piece);
	}
	catch (ValidationException exception) {
		return exception.getMessage();
	}
	try {
		repository.UpdatePiece(piece);
	}
	catch (ValidationException exception) {
		return exception.getMessage();
	}
	
	//ActionUpdate thisAction(make_unique<Repo>(repository), oldPiece, piece);
	//actionsUndo.emplace(thisAction);
	unique_ptr<Repo> ptr = make_unique<Repo>(repository);
	unique_ptr<ActionUpdate> thisAction = make_unique<ActionUpdate>(move(ptr), oldPiece, piece);
	actionsUndo.emplace(move(thisAction));
	return "";
	
}


string Service::ServiceDelete(string id)
{
	PieceOfEvidence piece = repository.GetElement(id);
	unique_ptr<Repo> ptr = make_unique<Repo>(repository);
	unique_ptr<ActionRemove> thisAction = make_unique<ActionRemove>(move(ptr), piece);
	actionsUndo.emplace(move(thisAction));
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	if (piece == piece2)
		return "Id does not exist";
	else
	{
		repository.DeletePiece(piece);
		return "";
	}

	//ActionRemove thisAction(make_unique<Repo>(repository), piece);
	//actionsUndo.emplace(thisAction);
	
}

Repo Service::GetRepository()
{
	return repository;
}

vector<PieceOfEvidence> Service::GetEvidence()
{
	return repository.ReadFromFile();
}

PieceOfEvidence Service::ServiceElement(string id)
{
	return repository.GetElement(id);
}

int Service::GetSize()
{
	return repository.GetSize();
}

ostream& operator<<(ostream& output, const Service& serv)
{

	//for (int iterator = 0; iterator < m_size; iterator++)
	output << serv.repository;
	return output;
}


Service::Service()
{

}

Service::~Service()
{

}
/*
PieceOfEvidence ServiceB::ServiceElementMyList(string id)
{
	return repositoryMyList.GetElement(id);
}*/

bool ServiceB::SaveIdToMyList(string id)
{
	PieceOfEvidence piece = ServiceElement(id);
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	if (repository.GetElement(id) == piece2) // id does not exist, the item can't be added to myList
	{
		return false;
	}


	if (repositoryMyList.GetElement(id) == piece2) // if the element is not already in the list, we add it
		repositoryMyList.SavePiece(piece);
	return true;
}

int ServiceB::GetSizeMyList()
{
	return repositoryMyList.GetSizeMyList();
}

PieceOfEvidence ServiceB::Next()
{
	return repository.Next();
}

PieceOfEvidence ServiceB::Next(string measurement)
{
	for (int i = 0; i <= repository.GetSize(); i++)
	{
		if (repository.Next().GetMeasurement() == measurement)
			return repository.Current();
	}
	PieceOfEvidence piece("-1", "", 0, 0, "");
	return piece;
}

PieceOfEvidence ServiceB::Current()
{
	return repository.Current();
}

PieceOfEvidence ServiceB::Begin()
{
	return repository.Begin();
}

vector<PieceOfEvidence> ServiceB::GetElements(string measurement, int quantity)
{
	vector<PieceOfEvidence> result;
	for (int i = 0; i < repository.GetSize(); i++)
	{
		PieceOfEvidence piece = repository.Next();
		if (piece.GetMeasurement() == measurement && piece.GetQuantity() >= quantity)
		{
			result.push_back(piece);
		}
			
	}
	return result;
}

void ServiceB::ServicePathB(string& path)
{
	fstream file;
	file.open(path, ios::in);
	//cout << file.is_open() << ' ';
	if (!file.is_open())
		file.open(path, ios::out | ios::app); // makes sure the file exists, if it doesn't, it creates a new one

	file.close();

	repositoryMyList.SavePathMyList(path);
}

ostream& operator<<(ostream& output, const ServiceB& serv)
{

	//for (int iterator = 0; iterator < m_size; iterator++)
	output << serv.repositoryMyList;
	return output;
}

ServiceB::ServiceB()
{

}

ServiceB::~ServiceB()
{

}