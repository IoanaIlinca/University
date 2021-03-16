#include "Validator.h"

ValidationException::ValidationException(string message)
{
	this->message = message;
}

const char* ValidationException::what() const noexcept
{
	return this->message.c_str();
}

void ValidatorStatue::validate(const GuardianStatue& statue)
{
	string errors;
	if (statue.GetMaterial() == "")errors += string("Material can't be null!\n");
	if (statue.GetAge() < 0)errors += string("Age can't be a negative number!\n");
	if (statue.GetCorporealForm() == "")errors += string("Corporeal form can't be null!\n");

	if (errors.size() > 0)
		throw ValidationException(errors);
}
