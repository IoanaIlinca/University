#include "Proj59_gui.h"
#include "Service.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//TestAll();
	/*
	ifstream fin("config.txt");
	string  message;
	bool type = false;
	while (getline(fin, message))
	{
		if (message.find("file") != string::npos)
			break;
		if (message.find("inMemory") != string::npos)
			type = true;
	}
	if (type == false)
	{
		
	}
	else
	{
		//ServiceB<RepoBMemory> serv;
		//Proj59_gui gui{ serv };
		//gui.show();
	}*/
	

	ServiceB serv;
	string path = "Evidence.txt";
	string mylistPath = "MyList.txt";
	serv.ServicePath(path);
	serv.ServicePathB(mylistPath);
	MyListViewModel* model = new MyListViewModel{ serv.GetRepoMyList() };
	Proj59_gui gui{ serv, model };
	
	gui.show();
	//GUI gui{serv};
	//gui.resize(500, 500);
	//gui.show();
	//w.show();
	
	
	
	return a.exec();
}
