#include "Actions.h"

ActionAdd::ActionAdd(unique_ptr<Repo> Rep, const PieceOfEvidence& p)
{
	this->Repository = std::move(Rep);
	this->addedPiece = p;
}

void ActionAdd::executeUndo()
{
	Repository->DeletePiece(addedPiece);
}

void ActionAdd::executeRedo()
{
	Repository->AddPiece(addedPiece);
}

ActionRemove::ActionRemove(unique_ptr<Repo> Rep, const PieceOfEvidence& s)
{
	this->Repository = std::move(Rep);
	this->deletedPiece = s;
}

void ActionRemove::executeUndo()
{
	Repository->AddPiece(deletedPiece);
}

void ActionRemove::executeRedo()
{
	Repository->DeletePiece(deletedPiece);
}


ActionUpdate::ActionUpdate(unique_ptr<Repo> Rep, const PieceOfEvidence& oldP, const PieceOfEvidence& newP)
{
	this->Repository = std::move(Rep);
	this->oldPiece = oldP;
	this->newPiece = newP;
}

void ActionUpdate::executeUndo()
{
	Repository->UpdatePiece(oldPiece);
}

void ActionUpdate::executeRedo()
{
	Repository->UpdatePiece(newPiece);
}