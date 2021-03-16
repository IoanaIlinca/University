#include "Actions.h"

ActionAdd::ActionAdd(unique_ptr<Repository> Rep, const Song& s)
{
	this->Repo = std::move(Rep);
	this->addedSong = s;
}

void ActionAdd::executeUndo()
{
	Repo->removeSong(addedSong);
}

void ActionAdd::executeRedo()
{
	Repo->addSong(addedSong);
}

ActionRemove::ActionRemove(unique_ptr<Repository> Rep, const Song& s)
{
	this->Repo = std::move(Rep);
	this->deletedSong = s;
}

void ActionRemove::executeUndo()
{
	Repo->addSong(deletedSong);
}

void ActionRemove::executeRedo()
{
	Repo->removeSong(deletedSong);
}


ActionUpdate::ActionUpdate(unique_ptr<Repository> Rep, const Song& oldSong, const Song& newSong)
{
	this->Repo = std::move(Rep);
	this->oldSong = oldSong;
	this->newSong = newSong;
}

void ActionUpdate::executeUndo()
{

}

void ActionUpdate::executeRedo()
{

}