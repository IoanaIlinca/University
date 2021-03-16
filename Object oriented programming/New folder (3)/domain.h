#pragma once
#include<iostream>

class GuardianStatue
{
private:
	std::string powerWordName;
	std::string Material;
	int age;
	std::string CorporealForm;
public:
	/*Default constructor*/
	GuardianStatue() :powerWordName(""), Material(""), age(0), CorporealForm("") {}
	GuardianStatue(const std::string& powerWordName, const std::string& Material, int age, const std::string& CorporealForm) :
		powerWordName(powerWordName), Material(Material), age(age), CorporealForm(CorporealForm) {}
	/*gets the power word name of a statue*/
	std::string GetPowerWordName()const { return powerWordName; }
	/* gets the material of a statue*/
	std::string GetMaterial()const { return Material; }
	/*gets the age of a statue*/
	int GetAge()const { return age; }
	/*gets the corporeal form of a statue*/
	std::string GetCorporealForm()const { return CorporealForm; }
	/*The assignment operator*/
	GuardianStatue operator=(const GuardianStatue& otherStatue);
	/*The equality operator
		input- otherStatue-GuardianStatue object
		output- true if they are equal,false otherwise*/
	GuardianStatue(const GuardianStatue& otherStatue);
	/*Copy consructor.*/
	bool operator==(const GuardianStatue& otherStatue);
	/*output: string containing the guardian statue data*/
	std::string toString();
	friend std::istream& operator>>(std::istream& is, GuardianStatue& statue);
	friend std::ostream& operator<<(std::ostream& os, const GuardianStatue& statue);
};
