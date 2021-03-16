#include "repo.h"
#include "domain.h"
#include "service.h"
#include "Ui.h"
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	Service serv;
	serv.Add("ana", 0.2);
	serv.Add("maria", 12.3, 14.2);
	//vector<shared_ptr<Client>> vector = serv.GetClients();
	//for (auto i : vector)
		//i->Display(cout);

	serv.AddDwelling("lala", 13, true);
	vector<Dwelling> dw = serv.GetDwellings("lala");
	//for (auto i : dw)
		//i.Display(cout);

	Menu();

	return 0;
}