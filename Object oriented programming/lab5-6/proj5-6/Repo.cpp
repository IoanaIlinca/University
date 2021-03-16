#define _CRT_SECURE_NO_WARNINGS
#include "Repo.h"
#include <fstream>
#include <windows.h>

using namespace std;

Repo::Repo()
{
	/*
	PieceOfEvidence piece("12sd23", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece2("16", "21", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece3("1223", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece4("30", "21", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece5("salata de boeuf", "177", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece6("60", "23X12X10", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece7("88", "ana", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece8("14", "ana", 0.2452, 16, "MyPic.jpg");
	PieceOfEvidence piece9("mere", "23X12X10", 0.2452, 13, "DSC13241.jpg");
	PieceOfEvidence piece10("133", "ana", 0.2452, 16, "MyPic.jpg");
	//Evidence.print();
	*/
}

void Repo::SavePath(string& path)
{
	
	//file = "fileLocation E:\\Faculta\\sem 2\\oop\\lab5-6\\proj5-6\\Evidence.txt";
	file = path;
	//cout << file;
}

vector<PieceOfEvidence> Repo::ReadFromFile()
{
	//cout << file << "***";
	ifstream fin(file, ios::in);
	//cout << fin.is_open() << ' ';
	string id = "0", measurement = "0", photograph = "0";
	double imageClarityLevel = 0;
	int quantity = 0;
	PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);
	vector<PieceOfEvidence> Evidence;
	string command;
	while (fin >> piece)
	{
		//cout << piece;
		
		/*
		

		int currentComma = 0, lastComma = 0;

		currentComma = command.find(",");

		id = command.substr(0, currentComma);
		command.erase(0, currentComma + 2);
		currentComma = command.find(",");

		measurement = command.substr(0, currentComma);
		command.erase(0, currentComma + 2);

		currentComma = command.find(",");

		imageClarityLevel = stod(command.substr(0, currentComma));

		command.erase(0, currentComma + 2);
		currentComma = command.find(",");

		quantity = stoi(command.substr(0, currentComma));

		command.erase(0, currentComma + 2);

		currentComma = command.find(",");

		photograph = command;
		//command.erase(0, currentComma + 2);
		*/
		
		Evidence.push_back(piece);
	}

	fin.close();
	return Evidence;
}


void Repo::AddPiece(PieceOfEvidence newPiece)
{
	//cout << file << "pwp";
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	if (GetElement(newPiece.GetId()) != piece2)
	{
		throw ValidationException("Id already exists");
		return;
	}
	Evidence.push_back(newPiece);
	ofstream fout;
	fout.open(file, ios::out);

	for (PieceOfEvidence piece : Evidence)
		fout << piece;

	fout.close();
}

void Repo::DeletePiece(PieceOfEvidence oldPiece)
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	int iterator = 0;
	for (auto piece : Evidence)
	{
		if (piece == oldPiece)
		{
			//cout << oldPiece;
			Evidence.erase(Evidence.begin() + iterator);
			break;
		}
		iterator++;
	}

	ofstream fout;
	fout.open(file, ios::out);

	for (PieceOfEvidence piece : Evidence)
		fout << piece;

	fout.close();
}

void Repo::UpdatePiece(PieceOfEvidence newPiece)
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	if (GetElement(newPiece.GetId()) == piece2)
	{
		throw ValidationException("Id does not exist");
		return;
	}
	int iterator = 0;
	for (auto piece : Evidence)
	{
		if (piece == newPiece)
		{
			Evidence.emplace(Evidence.begin() + iterator, newPiece);
			Evidence.erase(Evidence.begin() + iterator + 1);
			
		}
		iterator++;
	}

	ofstream fout;
	fout.open(file, ios::out);

	for (PieceOfEvidence piece : Evidence)
		fout << piece;

	fout.close();
}

int Repo::GetSize()
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	return Evidence.size();
}

PieceOfEvidence Repo::GetElement(string id)
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	for (auto piece : Evidence)
	{
		if (piece.GetId() == id)
			return piece;
	}
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	return piece2;
}

PieceOfEvidence Repo::Next()
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	position++;
	if (position >= Evidence.size())
		position = 0;
	return Evidence[position];
}

PieceOfEvidence Repo::Current()
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	if (position == -1)
		position = 0;
	return Evidence[position];
}

PieceOfEvidence Repo::Begin()
{
	vector<PieceOfEvidence> Evidence = ReadFromFile();
	return Evidence[0];
}


ostream& operator<<(ostream& output, const Repo& rep)
{
	ifstream fin(rep.file, ios::in);
	//cout << fin.is_open() << ' ';


	vector<PieceOfEvidence> Evidence;
	string command;
	while (getline(fin, command))
	{
		string id = "0", measurement = "0", photograph = "0";
		double imageClarityLevel = 0;
		int quantity = 0;

		int currentComma = 0, lastComma = 0;

		currentComma = command.find(",");

		id = command.substr(0, currentComma);
		command.erase(0, currentComma + 1);
		currentComma = command.find(",");

		measurement = command.substr(0, currentComma);
		command.erase(0, currentComma + 1);

		currentComma = command.find(",");

		imageClarityLevel = stod(command.substr(0, currentComma));

		command.erase(0, currentComma + 1);
		currentComma = command.find(",");

		quantity = stoi(command.substr(0, currentComma));

		command.erase(0, currentComma + 1);

		currentComma = command.find(",");

		photograph = command;
		//command.erase(0, currentComma + 2);

		PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);
		Evidence.push_back(piece);
	}

	fin.close();

	//for (int iterator = 0; iterator < m_size; iterator++)
	for (auto piece : Evidence)
		output << piece;
	return output;
}

Repo::~Repo()
{
	
}

RepoB::RepoB() 
{

}

RepoB::~RepoB()
{

}

vector<PieceOfEvidence> RepoHTML::ReadFromFile(string file)
{
	ifstream fin(file, ios::in);
	vector<PieceOfEvidence> MyList;
	string entry;
	string id = "0", measurement = "0", photograph = "0";
	double imageClarityLevel = 0;
	int quantity = 0;
	while (getline(fin, entry))
	{
		bool entireEntry = false;
		if (entry.find("<!--") == 0)
		{
			entry.erase(0, 4);
			if (entry.find("1") == 0)
			{
				entry.erase(0, 4);
				id = entry;
			}
			if (entry.find("2") == 0)
			{
				entry.erase(0, 4);
				measurement = entry;
			}
			if (entry.find("3") == 0)
			{
				entry.erase(0, 4);
				imageClarityLevel = stof(entry);
			}
			if (entry.find("4") == 0)
			{
				entry.erase(0, 4);
				quantity = stoi(entry);
			}
			if (entry.find("5") == 0)
			{
				entry.erase(0, 4);
				photograph = entry;
				entireEntry = true;
			}
		}

		if (entireEntry)
		{
			PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);
			MyList.push_back(piece);
		}
	}

	fin.close();
	return MyList;
}

vector<PieceOfEvidence> RepoCSV::ReadFromFile(string file)
{
	ifstream fin(file, ios::in);
	vector<PieceOfEvidence> MyList;
	string id = "0", measurement = "0", photograph = "0";
	double imageClarityLevel = 0;
	int quantity = 0;
	PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);

	string command;
	while (fin >> piece)
	{

		MyList.push_back(piece);
	}

	fin.close();
	return MyList;
}

vector<PieceOfEvidence> RepoB::ReadFromFile()
{
	//cout << file << "***";
	//cout << fin.is_open() << ' ';
	if (fileType == "csv" || fileType == "txt")
	{
		return RepoCSV::ReadFromFile(file);
		
	}
	else
	{
		return RepoHTML::ReadFromFile(file);
		
	}
}

void RepoHTML::OpenTag(ostream& fout, string tag)
{
	fout << "<" << tag << ">\n";
}

void RepoHTML::CloseTag(ostream& fout, string tag)
{
	fout << "</" << tag << ">\n";
}

void RepoCSV::WriteToFile(string file, vector<PieceOfEvidence> MyList)
{
	ofstream fout;
	fout.open(file, ios::out);
	for (PieceOfEvidence piece : MyList)
		fout << piece;
	fout.close();
}

void RepoHTML::WriteToFile(string file, vector<PieceOfEvidence> MyList)
{
	ofstream fout;
	fout.open(file, ios::out);

	OpenTag(fout, "!DOCTYPE html");
	OpenTag(fout, "html");

	OpenTag(fout, "head");

	OpenTag(fout, "title");
	fout << "Evidence\n";
	CloseTag(fout, "title");

	CloseTag(fout, "head");

	OpenTag(fout, "body");

	OpenTag(fout, "table border=\"1\"");
	OpenTag(fout, "tr");

	OpenTag(fout, "td style =\"font-weight: bold; \"");
	fout << "Id\n";
	CloseTag(fout, "td");

	OpenTag(fout, "td style =\"font-weight: bold; \"");
	fout << "Measurement\n";
	CloseTag(fout, "td");

	OpenTag(fout, "td style =\"font-weight: bold; \"");
	fout << "ImageClarityLevel\n";
	CloseTag(fout, "td");

	OpenTag(fout, "td style =\"font-weight: bold; \"");
	fout << "Quantity\n";
	CloseTag(fout, "td");

	OpenTag(fout, "td style =\"font-weight: bold; \"");
	fout << "Photograph\n";
	CloseTag(fout, "td");

	CloseTag(fout, "tr");
	for (PieceOfEvidence piece : MyList)
	{
		OpenTag(fout, "tr");

		OpenTag(fout, "td");
		fout << "<!--1-->" << piece.GetId() << '\n';
		CloseTag(fout, "td");

		OpenTag(fout, "td");
		fout << "<!--2-->" << piece.GetMeasurement() << '\n';
		CloseTag(fout, "td");

		OpenTag(fout, "td");
		fout << "<!--3-->" << piece.GetImageClarityLevel() << '\n';
		CloseTag(fout, "td");

		OpenTag(fout, "td");
		fout << "<!--4-->" << piece.GetQuantity() << '\n';
		CloseTag(fout, "td");

		OpenTag(fout, "td");
		fout << "<!--5-->" << piece.GetPhotograph() << '\n';
		CloseTag(fout, "td");

		CloseTag(fout, "tr");
	}
	CloseTag(fout, "table");

	CloseTag(fout, "body");

	CloseTag(fout, "html");
	fout.close();

}

void RepoB::WriteToFile(vector<PieceOfEvidence> MyList)
{
	ofstream fout;
	fout.open(file, ios::out);
	if (fileType == "csv" || fileType == "txt")
	{
		RepoCSV::WriteToFile(file, MyList);
	}
	else
	{
		RepoHTML::WriteToFile(file, MyList);
	}

	
}

void RepoB::SavePiece(PieceOfEvidence newPiece)
{
	vector<PieceOfEvidence> MyList = ReadFromFile();
	MyList.push_back(newPiece);
	WriteToFile(MyList);
}

int RepoB::GetSizeMyList()
{
	vector<PieceOfEvidence> MyList = ReadFromFile();
	return MyList.size();

}


PieceOfEvidence RepoB::GetElement(string id)
{
	vector<PieceOfEvidence> MyList = ReadFromFile();
	for (auto piece : MyList)
	{
		if (piece.GetId() == id)
			return piece;
	}
	PieceOfEvidence piece2("-1", "", 0, 0, "");
	return piece2;
}

void RepoB::SavePathMyList(string& path)
{
	file = path;
	if (file.find(".html") != string::npos)
		fileType = "html";
	if (file.find(".txt") != string::npos)
		fileType = "txt";
	if (file.find(".csv") != string::npos)
		fileType = "csv";
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

ostream& operator<<(ostream& output, const RepoB& rep)
{
	ifstream fin(rep.file, ios::in);
	//cout << fin.is_open() << ' ';


	vector<PieceOfEvidence> MyList;
	string command;
	if (rep.fileType == "csv" || rep.fileType == "txt")
	{
		while (getline(fin, command))
		{
			string id = "0", measurement = "0", photograph = "0";
			double imageClarityLevel = 0;
			int quantity = 0;

			int currentComma = 0, lastComma = 0;

			currentComma = command.find(",");

			id = command.substr(0, currentComma);
			command.erase(0, currentComma + 1);
			currentComma = command.find(",");

			measurement = command.substr(0, currentComma);
			command.erase(0, currentComma + 1);

			currentComma = command.find(",");

			imageClarityLevel = stod(command.substr(0, currentComma));

			command.erase(0, currentComma + 1);
			currentComma = command.find(",");

			quantity = stoi(command.substr(0, currentComma));

			command.erase(0, currentComma + 1);

			currentComma = command.find(",");

			photograph = command;
			//command.erase(0, currentComma + 2);

			PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);
			MyList.push_back(piece);
		}
	}
	else
	{
		string entry;
		string id = "0", measurement = "0", photograph = "0";
		double imageClarityLevel = 0;
		int quantity = 0;
		while (getline(fin, entry))
		{
			bool entireEntry = false;
			if (entry.find("<!--") == 0)
			{
				entry.erase(0, 4);
				if (entry.find("1") == 0)
				{
					entry.erase(0, 4);
					id = entry;
				}
				if (entry.find("2") == 0)
				{
					entry.erase(0, 4);
					measurement = entry;
				}
				if (entry.find("3") == 0)
				{
					entry.erase(0, 4);
					imageClarityLevel = stof(entry);
				}
				if (entry.find("4") == 0)
				{
					entry.erase(0, 4);
					quantity = stoi(entry);
				}
				if (entry.find("5") == 0)
				{
					entry.erase(0, 4);
					photograph = entry;
					entireEntry = true;
				}
			}

			if (entireEntry)
			{
				PieceOfEvidence piece(id, measurement, imageClarityLevel, quantity, photograph);
				MyList.push_back(piece);
			}
		}
	}
	

	fin.close();

	
	if (rep.fileType == "html")
	{
		std::wstring stemp = s2ws(rep.file);
		LPCWSTR result = stemp.c_str();
		//ShellExecute(NULL, L"open", L"E:\Faculta\sem 2\oop\lab5 - 6\proj5 - 6\MyList.html", NULL, NULL, SW_SHOW);
		ShellExecute(NULL, L"open", result, NULL, NULL, SW_SHOWNORMAL);

		//system("chrome.exe");
	}
	if (rep.fileType == "csv")
	{
		std::wstring stemp = s2ws(rep.file);
		LPCWSTR result = stemp.c_str();
		//ShellExecute(NULL, L"open", L"E:\Faculta\sem 2\oop\lab5 - 6\proj5 - 6\MyList.html", NULL, NULL, SW_SHOW);
		ShellExecute(NULL, L"open", result, NULL, NULL, SW_SHOWNORMAL);
	}

	for (auto piece : MyList)
		output << piece;
	return output;
}