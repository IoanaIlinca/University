#include "Validator.h"

using namespace std;

ValidationException::ValidationException(std::string _message) : message{ _message }
{

}

std::string ValidationException::getMessage() const
{
	return this->message;
}

void PieceValidator::validate(PieceOfEvidence piece)
{
	string errors = "";
	if (piece.GetId().size() < 1)
		errors += string("The id cannot be less than 1 character!\n");
	if (piece.GetMeasurement().size() < 1)
		errors += string("The measurement cannot be less than 1 character!\n");
	if (piece.GetPhotograph().size() < 1)
		errors += string("The photograph cannot be less than 1 character!\n");
	if (piece.GetImageClarityLevel() <= 0)
		errors += string("The clqarity level cannot be negative\n");
	if (piece.GetQuantity() < 0)
		errors += string("The quantity cannot be negative\n");
	if (errors.size())
		throw ValidationException(errors);
}