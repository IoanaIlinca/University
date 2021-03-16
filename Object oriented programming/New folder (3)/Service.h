#pragma once
#include"domain.h"
#include"RepositoryFile.h"
#include"RepositoryCsv.h"
#include"RepositoryHtml.h"
#include "Validator.h"
#include "Validator.h"

template <typename typeFile>
class Service {
private:
	RepoFile* Repository;
	ValidatorStatue validatorStatue;
	typeFile* MyList;
	
	
public:
	//constructor
	Service(RepoFile* Repository,ValidatorStatue validatorStatue,RepoFile* MyList) :Repository(Repository),validatorStatue(validatorStatue),MyList(MyList){}
	Service(RepoFile* Repository,ValidatorStatue validatorStatue,RepoCsv* MyList) :Repository(Repository),validatorStatue(validatorStatue),MyList(MyList){}
	Service(RepoFile* Repository,ValidatorStatue validatorStatue,RepoHtml* MyList) :Repository(Repository),validatorStatue(validatorStatue),MyList(MyList){}
	
	/*input- PowerWordName-string,Material-string,age-integer,CorporealForm-string
	 output-creates a guardian statue with that data and adds it to the array.*/
	void addGuardainStatue(std::string PowerWordName, std::string Material, int age, std::string CorporealForm);
	/*input- guardianSTatue-GuardianStatue
	output-adds to the new array the object
	*/
	void saveGuardianStatue(std::string PowerWordName);
	
	/*input- PowerWordName-string
	 output- finds the guardian statue with the guiven power word name and removes it from the array.*/
	void deleteGuardianStatue(std::string PowerWordName);
	/*input- PowerWordName-string,NewMaterial-string,NewAge-integer,NewCorporealForm-string
	 output-finds the guardian statue with the guiven power word name and removes it from the array.
	*/
	void updateGuardianStatue(std::string PowerWordName, std::string NewMaterial, int NewAge, std::string NewCorporealForm);
	vector<GuardianStatue> Get_Statues() {
		return this->Repository->GetStatues();
	}
	int GetNumberStatues() {
		return this->Repository->GetSizeRepo();
	}
	vector<GuardianStatue> GetSavedStatues() {
		return this->MyList->GetStatues();
	}
	void open() {
		this->MyList->open();
	}
	
	
	GuardianStatue Next();
	/*Finds the statue with a given Power word name.
	  input - PowerWordName-string
	  output - the statue.*/

	GuardianStatue searchStatueWithPowerWordName(std::string PowerWordName);
	//GuardianStatue next();
	

};

template <class typeFile>
void Service<typeFile>::addGuardainStatue(std::string PowerWordName, std::string Material, int age, std::string CorporealForm)
{
	GuardianStatue newGuardianSttaue{ PowerWordName,Material,age,CorporealForm };
	this->validatorStatue.validate(newGuardianSttaue);
	this->Repository->add_repo(newGuardianSttaue);
}
template <class typeFile>
void Service<typeFile>::saveGuardianStatue(std::string PowerWordName)
{
	GuardianStatue savedStatue(PowerWordName, "", 0, "");

	GuardianStatue searched = this->Repository->search_repo(savedStatue);
	this->MyList->add_repo(searched);

}

template <class typeFile>
void Service<typeFile>::deleteGuardianStatue(std::string PowerWordName)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,"",0,"" };
	this->Repository->delete_repo(searchedGuardianStatue);

}
template <class typeFile>
void Service<typeFile>::updateGuardianStatue(std::string PowerWordName, std::string NewMaterial, int NewAge, std::string NewCorporealForm)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,NewMaterial,NewAge,NewCorporealForm };
	this->Repository->update_repo(searchedGuardianStatue);

}





template <class typeFile>
GuardianStatue Service<typeFile>::Next()
{
	GuardianStatue nextStatue = this->Repository->get_current();
	this->Repository->next_repo();
	return nextStatue;
}
template <class typeFile>
GuardianStatue Service<typeFile>::searchStatueWithPowerWordName(std::string PowerWordName)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,"",0,"" };
	return this->Repository->search_repo(searchedGuardianStatue);
}





