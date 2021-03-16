#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class PieceOfEvidence
{
private:
	string id, measurement, photograph;
	int quantity;
	double imageClarityLevel;
public:

	/* Constructor with parameters */
	PieceOfEvidence(string constrId, string constrMeasurement, double constrImageClarityLevel, int constrQuantity, string constrPhotograph) // parametrized constructor
	{
		id = constrId;
		imageClarityLevel = constrImageClarityLevel;
		measurement = constrMeasurement;
		photograph = constrPhotograph;
		quantity = constrQuantity;
	}

	/* Constructor without parameters */
	PieceOfEvidence() // constructor
	{
		id = "";
		imageClarityLevel = 0;
		measurement = "";
		photograph = "";
		quantity = 0;
	}

	PieceOfEvidence(const PieceOfEvidence& piece)
	{
		this->id = piece.id;
		this->imageClarityLevel = piece.imageClarityLevel;
		this->measurement = piece.measurement;
		this->photograph = piece.photograph;
		this->quantity = piece.quantity;
	}

	/* Destructor */
	~PieceOfEvidence() 
	{
		id.~basic_string();
		measurement.~basic_string();
		photograph.~basic_string();
	}

	/* Getter - returns the id */
	const string GetId()
	{
		return string(id);
	}

	/* Getter - returns the measurement */
	const string GetMeasurement()
	{
		return string(measurement);
	}

	/* Getter - returns the photograph */
	const string GetPhotograph()
	{
		return string(photograph);
	}

	/* Getter - returns the quantityt */
	const int GetQuantity()
	{
		return quantity;
	}

	/* Getter - returns the quality */
	const double GetImageClarityLevel()
	{
		return imageClarityLevel;
	}

	/* Getter - sets the new measurement */
	void SetMeasurement(string newMeasurement)
	{
		measurement = newMeasurement;
	}

	/* Getter - sets the new photo */
	void SetPhotograph(string newPhotograph)
	{
		photograph = newPhotograph;
	}

	/* Getter - sets the new quantity */
	void SetQuantity(int newQuantity)
	{
		quantity = newQuantity;
	}

	/* Getter - sets the new clarity */
	void SetImageClarityLevel(double newImageClarityLevel)
	{
		imageClarityLevel = newImageClarityLevel;
	}

	/* Overwrites the << operator */
	friend ostream& operator<<(ostream& output, const PieceOfEvidence& piece)
	{
		output << piece.id << "," << piece.measurement << "," << piece.imageClarityLevel << "," << piece.quantity << "," << piece.photograph << '\n';
		return output;
	}

	/* Overwrites the >> operator */
	friend istream& operator>>(istream& input, PieceOfEvidence& piece)
	{
		string command;
		getline(input, command);
		if (command == "") // it doesn't contain anything
		{
			//cout << "Not enough arguments (command)!\n";
			return input;
		}
		string id = "0", measurement = "0", photograph = "0";
		double imageClarityLevel = 0;
		int quantity = 0;

		int currentComma = 0, lastComma = 0;

		currentComma = command.find(",");

		if (currentComma == string::npos) // it finishes after id
		{
			cout << "Not enough arguments!\n";
			return input;
		}
		id = command.substr(0, currentComma);
		command.erase(0, currentComma + 1);
		currentComma = command.find(",");

		if (currentComma == string::npos) // it finishes after id
		{
			cout << "Not enough arguments!\n";
			return input;
		}
		measurement = command.substr(0, currentComma);
		command.erase(0, currentComma + 1);

		currentComma = command.find(",");

		if (currentComma == string::npos) // it finishes after id
		{
			cout << "Not enough arguments!\n";
			return input;
		}
		try
		{
			imageClarityLevel = stod(command.substr(0, currentComma));
		}
		catch (exception ex)
		{
			cout << "Wrong type, image clarity must be double\n";
			return input;
		}

		command.erase(0, currentComma + 1);
		currentComma = command.find(",");

		if (currentComma == string::npos) // it finishes after id
		{
			cout << "Not enough arguments 2!\n";
			return input;
		}
		try
		{
			quantity = stoi(command.substr(0, currentComma));
		}
		catch (exception ex)
		{
			cout << "Wrong type, quantity must be integer\n";
			return input;
		}

		command.erase(0, currentComma + 1);

		currentComma = command.find(",");

		if (currentComma != string::npos) // it finishes after id
		{
			cout << "Too many arguments!\n";
			return input;
		}
		photograph = command;
		
		piece.id = id;
		piece.imageClarityLevel = imageClarityLevel;
		piece.measurement = measurement;
		piece.quantity = quantity;
		piece.photograph = photograph;
		//cout << piece << "***";
		return input;
	}

	/* Overwrites the == operator */
	friend bool operator== (const PieceOfEvidence& piece1, const PieceOfEvidence& piece2)
	{
		return (piece1.id == piece2.id);
	}

	friend bool operator!= (const PieceOfEvidence& piece1, const PieceOfEvidence& piece2)
	{
		return (piece1.id != piece2.id);
	}

	/* Overwrites the = operator */
	PieceOfEvidence& operator= (const PieceOfEvidence& piece)
	{
		if (this == &piece)
			return *this;

		this->id = piece.id;
		this->imageClarityLevel = piece.imageClarityLevel;
		this->measurement = piece.measurement;
		this->photograph = piece.photograph;
		this->quantity = piece.quantity;
		return *this;
	}
	/*
	string str()
	{
		ostringstream ss;
		ss << this;
		return ss.str();
	}*/
};



