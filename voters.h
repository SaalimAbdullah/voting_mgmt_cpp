#pragma once

using namespace std;


struct VoterInfo
{
	long long int cnic;
	short int household_num;
	short int na_Constituency_num;
	short int pa_Constituency_num;
	string name;
	string poll_station;
};

struct Voters {
	vector<VoterInfo> voters;

	void add() {
		VoterInfo temp_voter;

		cout << "\nEnter CNIC: ";
		cin >> temp_voter.cnic;
		cin.ignore();
		cout << "\nEnter Name: ";
		getline(cin, temp_voter.name);
		cout << "\nEnter Polling Station: ";
		getline(cin, temp_voter.poll_station);
		cout << "\nEnter Household #: ";
		cin >> temp_voter.household_num;
		cout << "\nEnter National Assembly Constituency #: ";
		cin >> temp_voter.na_Constituency_num;
		cout << "\nEnter Provincial Assembly Constituency #: ";
		cin >> temp_voter.pa_Constituency_num;

		voters.push_back(temp_voter);
		cout << "\nVoter Added!\n";
	}

	void view() {
		cout << "\n" << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');
		cout << setw(8) << left << "|"
			<< setw(12) << left << "CNIC"
			<< setw(24) << left << "Name"
			<< setw(48) << left << "Polling Stn."
			<< setw(18) << left << "HH #"
			<< setw(22) << left << "NA CNSTY #"
			<< setw(12) << left << "PA CNSTY #"
			<< "|" << "\n";

		cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

		for (int i = 0; i < voters.size(); i++)
		{
			cout << setw(4) << left << "|"
				<< setw(16) << left << voters[i].cnic
				<< setw(24) << left << voters[i].name
				<< setw(48) << left << voters[i].poll_station
				<< setw(18) << left << voters[i].household_num
				<< setw(22) << left << voters[i].na_Constituency_num
				<< setw(5) << right << voters[i].pa_Constituency_num
				<< setw(8) << right << "|" << "\n";

		}

		cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');


	}

	void search() {
		int searchKey, foundIndex = -1;
		bool found = false;
		cout << "\nEnter CNIC: ";
		cin >> searchKey;

		for (int i = 0; i < voters.size(); i++)
		{
			if (searchKey == voters.at(i).cnic) {
				found = true;
				foundIndex = i;
			}
		}
		if (found)
		{
			cout << "\n" << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');
			cout << setw(8) << left << "|"
				<< setw(12) << left << "CNIC"
				<< setw(24) << left << "Name"
				<< setw(48) << left << "Polling Stn."
				<< setw(18) << left << "HH #"
				<< setw(22) << left << "NA CNSTY #"
				<< setw(12) << left << "PA CNSTY #"
				<< "|" << "\n";

			cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

			cout << setw(4) << left << "|"
				<< setw(16) << left << voters[foundIndex].cnic
				<< setw(24) << left << voters[foundIndex].name
				<< setw(48) << left << voters[foundIndex].poll_station
				<< setw(18) << left << voters[foundIndex].household_num
				<< setw(22) << left << voters[foundIndex].na_Constituency_num
				<< setw(5) << right << voters[foundIndex].pa_Constituency_num
				<< setw(8) << right << "|" << "\n";


			cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

		}
		else
		{
			cout << "ID not found\n";
		}
	}

	void save() {
		ofstream fout("voters.txt");

		for (int i = 0; i < voters.size(); i++)
		{
			fout << voters[i].cnic << "\n"
				<< voters[i].name << "\n"
				<< voters[i].poll_station << "\n"
				<< voters[i].household_num << "\n"
				<< voters[i].na_Constituency_num << "\n"
				<< voters[i].pa_Constituency_num << "\n";
		}
		fout.close();
	}

	void load() {
		VoterInfo temp_voter;

		ifstream fin("voters.txt");
		if (!fin) {
			throw runtime_error("\nError loading data from voters.txt");
		}
		while (fin>>temp_voter.cnic)
		{
			fin.ignore();
			getline(fin, temp_voter.name);
			getline(fin, temp_voter.poll_station);
			fin >> temp_voter.household_num;
			fin >> temp_voter.na_Constituency_num;
			fin >> temp_voter.pa_Constituency_num;

			voters.push_back(temp_voter);		
		}
		
		fin.close();
	}

	void menu() {
		while (true)
		{
			cout << "\n\n";
			cout << "--------------------------------------------\n";
			cout << "\t\tVoters\n";
			cout << "--------------------------------------------\n";

			cout << " 1. Add Voter\n 2. View Voters\n 3. Search Voter\n 4. Back\n";
			int option = 0;
			cin >> option;
			cin.ignore();

			switch (option) {
			case 1:
				cout << "\n[Add Voter]\n";
				add();
				break;

			case 2:
				cout << "\n[View Voters]\n\n";
				view();
				break;

			case 3:
				cout << "\n[Search Voter]\n";
				search();
				break;

			case 4:
				cout << "\nGoing Back\n";
				return;

			default:
				cout << "invalid option\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}


		}
	}

};
