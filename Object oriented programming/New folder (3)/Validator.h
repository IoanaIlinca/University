#pragma once
#include <string>
#include "domain.h"
using namespace std;

class ValidationException : public exception
{	private:
		string message;
	public:
		ValidationException(string message);
		const char* what() const noexcept override;

};

class ValidatorStatue
{
	public:
		static void validate(const GuardianStatue& statue);
};