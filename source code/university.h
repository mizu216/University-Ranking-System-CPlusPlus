#include<iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct UniNode {
	int count;
	string rank;
	string name;
	string loc;
	string location;
	string ars;
	string arr;
	string ers;
	string err;
	string fsrs;
	string fsrr;
	string cpfs;
	string cpfr;
	string ifrs;
	string ifrr;
	string isrs;
	string isrr;
	string irns;
	string irnr;
	string gers;
	string gerr;
	string score;
	UniNode* NextAdd;
	UniNode* PrevAdd;
}*unitail, * unihead;

int size = 0;

UniNode* CreateNewUni(string rank, string name, string loc, string location, string ars, string arr, string ers, string err, string fsrs,
	string fsrr, string cpfs, string cpfr, string ifrs, string ifrr, string isrs, string isrr, string irns, string irnr, string gers,
	string gerr, string score) {
	UniNode* newnode = new UniNode;
	newnode->count = 0;
	newnode->rank = rank;
	newnode->name = name;
	newnode->loc = loc;
	newnode->location = location;
	newnode->ars = ars;
	newnode->arr = arr;
	newnode->ers = ers;
	newnode->err = err;
	newnode->fsrs = fsrs;
	newnode->fsrr = fsrr;
	newnode->cpfs = cpfs;
	newnode->cpfr = cpfr;
	newnode->ifrs = ifrs;
	newnode->ifrr = ifrr;
	newnode->isrs = isrs;
	newnode->isrr = isrr;
	newnode->irns = irns;
	newnode->irnr = irnr;
	newnode->gers = gers;
	newnode->gerr = gerr;
	newnode->score = score;
	newnode->NextAdd = NULL;
	newnode->PrevAdd = NULL;
	return newnode;
}

void InsertToEndUni(string rank, string name, string loc, string location, string ars, string arr, string ers, string err, string fsrs,
	string fsrr, string cpfs, string cpfr, string ifrs, string ifrr, string isrs, string isrr, string irns, string irnr, string gers,
	string gerr, string score) {
	UniNode* newnode = CreateNewUni(rank, name, loc, location, ars, arr, ers, err, fsrs, fsrr, cpfs, cpfr, ifrs, ifrr, isrs, isrr,
		irns, irnr, gers, gerr, score);
	if (unihead == NULL) {
		unihead = unitail = newnode;
	}
	else {
		newnode->PrevAdd = unitail;
		unitail->NextAdd = newnode;
		unitail = newnode;
	}
	::size++;
}

void DisplayUniFromFront() {
	UniNode* current = unihead;
	cout << string(50, '-') << endl;
	cout << "World University Ranking" << endl;
	cout << string(50, '-') << endl;
	while (current != NULL) {
		cout << "Rank: " << current->rank << endl;
		cout << "Institution: " << current->name << endl;
		cout << "Location Code: " << current->loc << endl;
		cout << "Location: " << current->location << endl;
		cout << "Ar Score: " << current->ars << endl;
		cout << "Ar Rank: " << current->arr << endl;
		cout << "Er Score: " << current->ers << endl;
		cout << "Er Rank: " << current->err << endl;
		cout << "Fsr Score: " << current->fsrs << endl;
		cout << "Fsr Rank: " << current->fsrr << endl;
		cout << "Cpf Score: " << current->cpfs << endl;
		cout << "Cpf Rank: " << current->cpfr << endl;
		cout << "Ifr Score: " << current->ifrs << endl;
		cout << "Ifr Rank: " << current->ifrr << endl;
		cout << "Isr Score: " << current->isrs << endl;
		cout << "Isr Rank: " << current->isrr << endl;
		cout << "Irn Score: " << current->irns << endl;
		cout << "Irn Rank: " << current->irnr << endl;
		cout << "Ger Score: " << current->gers << endl;
		cout << "Ger Rank: " << current->gerr << endl;
		cout << "Score: " << current->score << endl << endl;
		current = current->NextAdd;
	}
	cout << "List ended here!" << endl;
	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}

//_________________________________________________________MERGE SORT___________________________________________________//
UniNode* Merge(UniNode* a, UniNode* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	else if (a->name < b->name) {
		a->NextAdd = Merge(a->NextAdd, b);
		a->NextAdd->PrevAdd = a;
		a->PrevAdd = NULL;
		return a;
	}
	else {
		b->NextAdd = Merge(a, b->NextAdd);
		b->NextAdd->PrevAdd = b;
		b->PrevAdd = NULL;
		return b;
	}
}

UniNode* MergeAr(UniNode* a, UniNode* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	else if (a->ars > b->ars) {
		a->NextAdd = MergeAr(a->NextAdd, b);
		a->NextAdd->PrevAdd = a;
		a->PrevAdd = NULL;
		return a;
	}
	else {
		b->NextAdd = MergeAr(a, b->NextAdd);
		b->NextAdd->PrevAdd = b;
		b->PrevAdd = NULL;
		return b;
	}
}

UniNode* MergeEr(UniNode* a, UniNode* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	else if (a->ers > b->ers) {
		a->NextAdd = MergeEr(a->NextAdd, b);
		a->NextAdd->PrevAdd = a;
		a->PrevAdd = NULL;
		return a;
	}
	else {
		b->NextAdd = MergeEr(a, b->NextAdd);
		b->NextAdd->PrevAdd = b;
		b->PrevAdd = NULL;
		return b;
	}
}

UniNode* MergeFsr(UniNode* a, UniNode* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	else if (a->fsrs > b->fsrs) {
		a->NextAdd = MergeFsr(a->NextAdd, b);
		a->NextAdd->PrevAdd = a;
		a->PrevAdd = NULL;
		return a;
	}
	else {
		b->NextAdd = MergeFsr(a, b->NextAdd);
		b->NextAdd->PrevAdd = b;
		b->PrevAdd = NULL;
		return b;
	}
}

UniNode* MergeSort(UniNode* unihead) {
	if (unihead == NULL || unihead->NextAdd == NULL) {
		return unihead;
	}
	UniNode* slow = unihead;
	UniNode* fast = unihead->NextAdd;
	while (fast != NULL && fast->NextAdd != NULL) {
		slow = slow->NextAdd;
		fast = fast->NextAdd->NextAdd;
	}
	UniNode* secondhalf = slow->NextAdd;
	slow->NextAdd = NULL;

	UniNode* left = MergeSort(unihead);
	UniNode* right = MergeSort(secondhalf);

	UniNode* sorted = Merge(left, right);
	return sorted;
}

UniNode* MergeSortAr(UniNode* unihead) {
	if (unihead == NULL || unihead->NextAdd == NULL) {
		return unihead;
	}
	UniNode* slow = unihead;
	UniNode* fast = unihead->NextAdd;
	while (fast != NULL && fast->NextAdd != NULL) {
		slow = slow->NextAdd;
		fast = fast->NextAdd->NextAdd;
	}
	UniNode* secondhalf = slow->NextAdd;
	slow->NextAdd = NULL;

	UniNode* left = MergeSortAr(unihead);
	UniNode* right = MergeSortAr(secondhalf);

	UniNode* sorted = MergeAr(left, right);
	return sorted;
}

UniNode* MergeSortEr(UniNode* unihead) {
	if (unihead == NULL || unihead->NextAdd == NULL) {
		return unihead;
	}
	UniNode* slow = unihead;
	UniNode* fast = unihead->NextAdd;
	while (fast != NULL && fast->NextAdd != NULL) {
		slow = slow->NextAdd;
		fast = fast->NextAdd->NextAdd;
	}
	UniNode* secondhalf = slow->NextAdd;
	slow->NextAdd = NULL;

	UniNode* left = MergeSortEr(unihead);
	UniNode* right = MergeSortEr(secondhalf);

	UniNode* sorted = MergeEr(left, right);
	return sorted;
}

UniNode* MergeSortFsr(UniNode* unihead) {
	if (unihead == NULL || unihead->NextAdd == NULL) {
		return unihead;
	}
	UniNode* slow = unihead;
	UniNode* fast = unihead->NextAdd;
	while (fast != NULL && fast->NextAdd != NULL) {
		slow = slow->NextAdd;
		fast = fast->NextAdd->NextAdd;
	}
	UniNode* secondhalf = slow->NextAdd;
	slow->NextAdd = NULL;

	UniNode* left = MergeSortFsr(unihead);
	UniNode* right = MergeSortFsr(secondhalf);

	UniNode* sorted = MergeFsr(left, right);
	return sorted;
}
UniNode* MergeCount(UniNode* a, UniNode* b) {
	if (a == NULL) {
		return b;
	}
	else if (b == NULL) {
		return a;
	}
	else if (a->count > b->count) {
		a->NextAdd = MergeCount(a->NextAdd, b);
		a->NextAdd->PrevAdd = a;
		a->PrevAdd = NULL;
		return a;
	}
	else {
		b->NextAdd = MergeCount(a, b->NextAdd);
		b->NextAdd->PrevAdd = b;
		b->PrevAdd = NULL;
		return b;
	}
}

UniNode* MergeSortCount(UniNode* unihead) {
	if (unihead == NULL || unihead->NextAdd == NULL) {
		return unihead;
	}
	UniNode* slow = unihead;
	UniNode* fast = unihead->NextAdd;
	while (fast != NULL && fast->NextAdd != NULL) {
		slow = slow->NextAdd;
		fast = fast->NextAdd->NextAdd;
	}
	UniNode* secondhalf = slow->NextAdd;
	slow->NextAdd = NULL;

	UniNode* left = MergeSortCount(unihead);
	UniNode* right = MergeSortCount(secondhalf);

	UniNode* sorted = MergeCount(left, right);
	return sorted;
}

//_________________________________________________________QUICK SORT___________________________________________________//
void swap(int* c, int* d) {
	int temp = *c;
	*c = *d;
	*d = temp;
}

UniNode* Partition(UniNode* unihead, UniNode* unitail) {
	string pivot = unitail->name;
	UniNode* i = unihead->PrevAdd;
	string pivotRank = unitail->rank;
	for (UniNode* j = unihead; j != unitail; j = j->NextAdd) {
		if (j->name.compare(pivot) <= 0) {
			i = (i == NULL) ? unihead : i->NextAdd;
			swap(i->name, j->name);
			swap(i->rank, j->rank);
			swap(i->loc, j->loc);
			swap(i->location, j->location);
			swap(i->ars, j->ars);
			swap(i->arr, j->arr);
			swap(i->ers, j->ers);
			swap(i->err, j->err);
			swap(i->fsrs, j->fsrs);
			swap(i->fsrr, j->fsrr);
			swap(i->cpfs, j->cpfs);
			swap(i->cpfr, j->cpfr);
			swap(i->ifrs, j->ifrs);
			swap(i->ifrr, j->ifrr);
			swap(i->isrs, j->isrs);
			swap(i->isrr, j->isrr);
			swap(i->irns, j->irns);
			swap(i->irnr, j->irnr);
			swap(i->gers, j->gers);
			swap(i->gerr, j->gerr);
			swap(i->score, j->score);
		}
	}
	i = (i == NULL) ? unihead : i->NextAdd;
	swap(i->name, unitail->name);
	swap(i->rank, unitail->rank);
	swap(i->loc, unitail->loc);
	swap(i->location, unitail->location);
	swap(i->ars, unitail->ars);
	swap(i->arr, unitail->arr);
	swap(i->ers, unitail->ers);
	swap(i->err, unitail->err);
	swap(i->fsrs, unitail->fsrs);
	swap(i->fsrr, unitail->fsrr);
	swap(i->cpfs, unitail->cpfs);
	swap(i->cpfr, unitail->cpfr);
	swap(i->ifrs, unitail->ifrs);
	swap(i->ifrr, unitail->ifrr);
	swap(i->isrs, unitail->isrs);
	swap(i->isrr, unitail->isrr);
	swap(i->irns, unitail->irns);
	swap(i->irnr, unitail->irnr);
	swap(i->gers, unitail->gers);
	swap(i->gerr, unitail->gerr);
	swap(i->score, unitail->score);
	return i;
}

void QuickSort(UniNode* unihead, UniNode* unitail) {
	if (unitail != NULL && unihead != unitail && unihead != unitail->NextAdd) {
		UniNode* pivot = Partition(unihead, unitail);
		QuickSort(unihead, pivot->PrevAdd);
		QuickSort(pivot->NextAdd, unitail);
	}
}


//_________________________________________________________SEARCH___________________________________________________//
void searchrank() {
	string crank;
	cout << endl << "Welcome to search using rank!" << endl;
	cout << "Enter rank to search: ";
	cin.ignore(); // Ignore any remaining newline characters
	getline(cin, crank); // Read the entire line of input

	//auto start = high_resolution_clock::now();
	if (unihead == NULL) {
		cout << "The list is empty." << endl;
		return;
	}

	UniNode* current = unihead;
	bool foundLinear = false;

	while (current != NULL) {
		if (current->rank == crank) {
			// Print the details of the matching institution
			cout << endl << "Rank: " << current->rank << endl;
			cout << "Institution: " << current->name << endl;
			cout << "Location Code: " << current->loc << endl;
			cout << "Location: " << current->location << endl;
			cout << "ArScore: " << current->ars << endl;
			cout << "ArRank: " << current->arr << endl;
			cout << "ErScore: " << current->ers << endl;
			cout << "ErRank: " << current->err << endl;
			cout << "FsrScore: " << current->fsrs << endl;
			cout << "FsrRank: " << current->fsrr << endl;
			cout << "CpfScore: " << current->cpfs << endl;
			cout << "CpfRank: " << current->cpfr << endl;
			cout << "IfrScore: " << current->ifrs << endl;
			cout << "IfrRank: " << current->ifrr << endl;
			cout << "IsrScore: " << current->isrs << endl;
			cout << "IsrRank: " << current->isrr << endl;
			cout << "IrnScore: " << current->irns << endl;
			cout << "IrnRank: " << current->irnr << endl;
			cout << "GerScore: " << current->gers << endl;
			cout << "GerRank: " << current->gerr << endl;
			cout << "ScoreScaled: " << current->score << endl;

			foundLinear = true;
		}
		current = current->NextAdd;
	}

	cout << "Institute \"" << crank << "\" found using linear search." << endl;

	if (!foundLinear) {
		cout << "Institute \"" << crank << "\" is not available in the list!" << endl;
	}

	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<microseconds>(stop - start);
	//cout << "Time taken by linear search algorithm: ";
	//cout << duration.count() << " microseconds. " << endl;
}

void searchinstitution() {
	string cint;
	cout << endl << "Welcome to search using institution!" << endl;
	cout << "Enter institution to search: ";
	cin.ignore(); // Ignore any remaining newline characters
	getline(cin, cint); // Read the entire line of input

	if (unihead == NULL) {
		cout << "The list is empty." << endl;
		return;
	}

	//Linear Search
	UniNode* current = unihead;
	bool foundLinear = false;

	while (current != NULL) {
		if (current->name == cint) {
			// Print the details of the matching institution
			cout << endl << "Rank: " << current->rank << endl;
			cout << "Institution: " << current->name << endl;
			cout << "Location Code: " << current->loc << endl;
			cout << "Location: " << current->location << endl;
			cout << "ArScore: " << current->ars << endl;
			cout << "ArRank: " << current->arr << endl;
			cout << "ErScore: " << current->ers << endl;
			cout << "ErRank: " << current->err << endl;
			cout << "FsrScore: " << current->fsrs << endl;
			cout << "FsrRank: " << current->fsrr << endl;
			cout << "CpfScore: " << current->cpfs << endl;
			cout << "CpfRank: " << current->cpfr << endl;
			cout << "IfrScore: " << current->ifrs << endl;
			cout << "IfrRank: " << current->ifrr << endl;
			cout << "IsrScore: " << current->isrs << endl;
			cout << "IsrRank: " << current->isrr << endl;
			cout << "IrnScore: " << current->irns << endl;
			cout << "IrnRank: " << current->irnr << endl;
			cout << "GerScore: " << current->gers << endl;
			cout << "GerRank: " << current->gerr << endl;
			cout << "ScoreScaled: " << current->score << endl;

			foundLinear = true;
		}
		current = current->NextAdd;
	}
	//cout << "Institute \"" << cint << "\" found using linear search." << endl;

	if (!foundLinear) {
		cout << "Institute \"" << cint << "\" is not available in the list!" << endl;
	}
}

void searchlocation() {
	string cloca;
	cout << endl << "Welcome to search using location!" << endl;
	cout << "Enter location to search: ";
	cin.ignore(); // Ignore any remaining newline characters
	getline(cin, cloca); // Read the entire line of input

	if (unihead == NULL) {
		cout << "The list is empty." << endl;
		return;
	}

	UniNode* current = unihead;
	bool foundLinear = false;

	while (current != NULL) {
		if (current->location == cloca) {
			// Print the details of the matching institution
			cout << endl << "Rank: " << current->rank << endl;
			cout << "Institution: " << current->name << endl;
			cout << "Location Code: " << current->loc << endl;
			cout << "Location: " << current->location << endl;
			cout << "ArScore: " << current->ars << endl;
			cout << "ArRank: " << current->arr << endl;
			cout << "ErScore: " << current->ers << endl;
			cout << "ErRank: " << current->err << endl;
			cout << "FsrScore: " << current->fsrs << endl;
			cout << "FsrRank: " << current->fsrr << endl;
			cout << "CpfScore: " << current->cpfs << endl;
			cout << "CpfRank: " << current->cpfr << endl;
			cout << "IfrScore: " << current->ifrs << endl;
			cout << "IfrRank: " << current->ifrr << endl;
			cout << "IsrScore: " << current->isrs << endl;
			cout << "IsrRank: " << current->isrr << endl;
			cout << "IrnScore: " << current->irns << endl;
			cout << "IrnRank: " << current->irnr << endl;
			cout << "GerScore: " << current->gers << endl;
			cout << "GerRank: " << current->gerr << endl;
			cout << "ScoreScaled: " << current->score << endl;

			foundLinear = true;
		}
		current = current->NextAdd;
	}

	//cout << "Location \"" << cloca << "\" found using linear search." << endl;

	if (!foundLinear) {
		cout << "Location \"" << cloca << "\" is not available in the list!" << endl;
	}
}
