#pragma once

struct ProvAssembly:NatAssembly
{
	void save() {

		ofstream fout("PA_Candidates.txt");

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

		ifstream fin("PA_Candidates.txt");
		if (!fin) {
			throw runtime_error("\nError loading data from PA_Candidates.txt");
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
			cout << "\tProvincial Assembly Candidates\n";
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
