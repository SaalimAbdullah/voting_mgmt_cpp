#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "naCandidates.h"
#include "paCandidates.h"
#include "voters.h"

using namespace std;

NatAssembly natAssembly;
ProvAssembly provAssembly;
Voters voters;

void mainMenu();
void save();
void load();





int main()
{
	load();
	mainMenu();
	save();
}

void mainMenu() {
	while (true)
	{
		cout << "\n\n";
		cout << "------------------------------------------------------\n";
		cout << "\t\tVoting Mangement System\n";
		cout << "------------------------------------------------------\n";


		cout << " 1. NA Candidates\n 2. PA Candidates\n 3. Voters\n 4. Exit\n";
		int option = 0;
		cin >> option;

		switch (option) {
		case 1:
			cout << "\n[NA Candidates]\n";
			natAssembly.menu();
			break;

		case 2:
			cout << "\n[PA Candidates]\n\n";
			provAssembly.menu();
			break;

		case 3:
			cout << "\n[Voters]\n";
			voters.menu();
			break;

		case 4:
			cout << "\nExiting\n";
			return;

		default:
			cout << "invalid option\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	}
}

void save() {
	natAssembly.save();
	provAssembly.save();
	voters.save();
}

void load() {
	try {
		natAssembly.load();
		provAssembly.load();
		voters.load();
	}
	catch (runtime_error& e) {
		cout << "ERROR! " << e.what();
	}
}