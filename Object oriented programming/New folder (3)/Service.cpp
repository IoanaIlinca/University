/*
#include "Service.h"
#include "Validator.h"
template <class T>
void Service<T>::addGuardainStatue(std::string PowerWordName, std::string Material, int age, std::string CorporealForm)
{
	GuardianStatue newGuardianSttaue{ PowerWordName,Material,age,CorporealForm };
	this->validatorStatue.validate(newGuardianSttaue);
	this->Repository->add_repo(newGuardianSttaue);
}
template <class T>
void Service<T>::saveGuardianStatue(std::string PowerWordName)
{
	GuardianStatue savedStatue(PowerWordName, "", 0, "");

	GuardianStatue searched=this->Repository->search_repo(savedStatue);
	this->MyList->add_repo(searched);
	
}

template <class T>
void Service<T>::deleteGuardianStatue(std::string PowerWordName)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,"",0,"" };
	this->Repository->delete_repo(searchedGuardianStatue);

}
template <class T>
void Service<T>::updateGuardianStatue(std::string PowerWordName, std::string NewMaterial, int NewAge, std::string NewCorporealForm)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,NewMaterial,NewAge,NewCorporealForm };
	this->Repository->update_repo(searchedGuardianStatue);

}






GuardianStatue Service<void>::Next()
{
	GuardianStatue nextStatue = this->Repository->get_current();
	this->Repository->next_repo();
	return nextStatue;
}

GuardianStatue Service<void>::searchStatueWithPowerWordName(std::string PowerWordName)
{
	GuardianStatue searchedGuardianStatue{ PowerWordName,"",0,"" };
	return this->Repository->search_repo(searchedGuardianStatue);
}


*/