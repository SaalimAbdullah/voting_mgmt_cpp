#pragma once

using namespace std;

struct CandidateInfo
{
	short int constituency_num;

	string name;
	string address;
	string party;
	string symbol;


};

struct NatAssembly
{

	vector<CandidateInfo> candidates;



	void add() {
		CandidateInfo temp_candidate;

		cout << "\nEnter Name: ";
		getline(cin, temp_candidate.name);
		cout << "Enter Address: ";
		getline(cin, temp_candidate.address);
		cout << "Enter Party: ";
		getline(cin, temp_candidate.party);
		cout << "Enter Symbol: ";
		getline(cin, temp_candidate.symbol);
		cout << "Enter Constituency #: ";
		cin >> temp_candidate.constituency_num;


		candidates.push_back(temp_candidate);
		cout << "\nCandidate Added!\n";
	}

	void view() {

		cout << "\n" << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');
		cout << setw(8) << left << "|" 
			<< setw(12) << left << "SN #"
			<< setw(24) << left << "Name"
			<< setw(48) << left << "Address"
			<< setw(18) << left << "Party"
			<< setw(22) << left << "Symbol" 
			<< setw(12) << left << "CNSTY #"
			<< "|" << "\n";

		

		cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

		for (int i = 0; i < candidates.size(); i++)
		{
			cout <<setw(8) <<left<<"|"
				<< setw(12) << left << i + 1
				<< setw(24) << left << candidates[i].name
				<< setw(48) << left << candidates[i].address
				<< setw(18) << left << candidates[i].party
				<< setw(22) << left << candidates[i].symbol
				<< setw(5) << right << candidates[i].constituency_num
				<< setw(8) <<right <<"|" << "\n";
				
		}

		cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

	}

	void search() {
		int search_key;
		cout << "\nEnter Candidate Serial #: ";
		cin >> search_key;

		if (search_key <= 0 || search_key > candidates.size()) {
			cout << "\nCandidate does not exist\n";
		}
		else
		{
			search_key -= 1;

			cout << "\n" << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');
			cout << setw(8) << left << "|"
				<< setw(12) << left << "SN #"
				<< setw(24) << left << "Name"
				<< setw(48) << left << "Address"
				<< setw(18) << left << "Party"
				<< setw(22) << left << "Symbol"
				<< setw(12) << left << "CNSTY #"
				<< "|" << "\n";



			cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');

			cout << setw(8) << left << "|"
				<< setw(12) << left << search_key+1
				<< setw(24) << left << candidates[search_key].name
				<< setw(48) << left << candidates[search_key].address
				<< setw(18) << left << candidates[search_key].party
				<< setw(22) << left << candidates[search_key].symbol
				<< setw(5) << right << candidates[search_key].constituency_num
				<< setw(8) << right << "|" << "\n";


			cout << setfill('-') << setw(144) << left << "+" << "+" << "\n" << setfill(' ');
		}
	}

	void save() {
		
		ofstream fout("NA_Candidates.txt");

		for (int i = 0; i < candidates.size(); i++)
		{
			fout << candidates[i].name << "\n"
				<< candidates[i].address << "\n"
				<< candidates[i].party << "\n"
				<< candidates[i].symbol << "\n"
				<< candidates[i].constituency_num << "\n";
		}
		fout.close();
		
	}

	void load() {

		CandidateInfo temp_candidate;

		ifstream fin("NA_Candidates.txt");
		if (!fin) {
			throw runtime_error("\nError loading data from NA_Candidates.txt");
		}
		while (getline(fin, temp_candidate.name)) {
			
			getline(fin, temp_candidate.address);
			getline(fin, temp_candidate.party);
			getline(fin, temp_candidate.symbol);
			fin >> temp_candidate.constituency_num;
			
			fin.ignore();

			candidates.push_back(temp_candidate);
		}
		fin.close();
	}

	
	void menu() {
		while (true)
		{
			cout << "\n\n";
			cout << "--------------------------------------------\n";
			cout << "\tNational Assembly Candidates\n";
			cout << "--------------------------------------------\n";

			cout << " 1. Add Candidate\n 2. View Candidates\n 3. Search Candidate\n 4. Back\n";
			int option = 0;
			cin >> option;
			cin.ignore();

			switch (option) {
			case 1:
				cout << "\n[Add Candidate]\n";
				add();
				break;

			case 2:
				cout << "\n[View Candidates]\n\n";
				view();
				break;

			case 3:
				cout << "\n[Search Candidate]\n";
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
