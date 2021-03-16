#pragma once
#include <string>
#include "PieceOfEvidence.h"

class ValidationException
{
private:
	std::string message;
public:
	ValidationException(std::string _message);
	std::string getMessage() const;
};

class PieceValidator
{
public:
	static void validate(PieceOfEvidence piece);
};