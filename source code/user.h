#include<iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct userNode {
	int id;
	string username;
	string password;
	string email;
	string address;
	string phonenum;
	bool status;
	UniNode* favunihead;
	userNode* prevAddress;
	userNode* nextAddress;

	userNode() {
		favunihead = NULL;
	}
}*usertail, * userhead, * currentUser;

int userSize = 0;

userNode* createnewuser(string username, string password, string email, string address, string phonenum, bool status) {
	userNode* newuser = new userNode;
	newuser->id = userSize + 1;
	newuser->username = username;
	newuser->password = password;
	newuser->email = email;
	newuser->address = address;
	newuser->phonenum = phonenum;
	newuser->status = status;
	newuser->prevAddress = NULL;
	newuser->nextAddress = NULL;
	return newuser;
}

void InsertToFrontUser(string username, string password, string email, string address, string phonenum, bool status) {
	userNode* newuser = createnewuser(username, password, email, address, phonenum, status);
	if (userhead == NULL) {
		userhead = usertail = newuser;
	}
	else {
		newuser->nextAddress = userhead;
		userhead->prevAddress = newuser;
		userhead = newuser;
	}
	userSize++;
}

void DisplayUser()
{
	userNode* current = userhead;
	while (current != NULL)
	{
		cout << "ID: " << current->id << endl;
		cout << "Username: " << current->username << endl;
		cout << "Email: " << current->email << endl;
		cout << "Address: " << current->address << endl;
		cout << "Phone Number: " << current->phonenum << endl;
		cout << "Status: " << current->status << endl << endl;
		cout << string(50, '=') << endl;
		current = current->nextAddress;
	}
}

void DeleteFromEnd()
{
	if (userhead == NULL)
	{
		return;
	}

	userNode* current = usertail;
	usertail = usertail->prevAddress;
	if (usertail != NULL)
	{
		usertail->nextAddress = NULL;
	}
	else
	{
		userhead = NULL;
	}
	delete current;
}

void deleteFromFront()
{
	if (userhead == NULL)
	{
		return;
	}
	userNode* current = userhead;
	userhead = userhead->nextAddress;
	if (userhead != NULL)
	{
		userhead->prevAddress = NULL;
	}
	else
	{
		usertail = NULL;
	}
}

void deleteuser(int id)
{
	userNode* dummy = userhead;

	if (id == 1)
	{
		deleteFromFront();
	}
	else if (id == userSize)
	{
		DeleteFromEnd();
	}
	else if (id > 1 && id < userSize)
	{
		while (dummy->id != id)
		{
			dummy = dummy->nextAddress;
		}

		dummy->prevAddress->nextAddress = dummy->nextAddress;
		dummy->nextAddress->prevAddress = dummy->prevAddress;

	}
	else
	{
		cout << "Invalid Input" << endl;
	}

	cout << dummy->username << " is deleted" << endl << endl;
	cout << string(50, '=') << endl;
	delete(dummy);
	DisplayUser();
}

userNode* linear_search(int id)
{
	userNode* current = userhead;
	while (current != NULL)
	{
		if (current->id == id) {
			break;
		}
		current = current->nextAddress;
	}
	return current;
}

bool DisplayInactive()
{
	//check for inactive user 
	//call deleteUser once inactive user is found	
	userNode* current = userhead;
	bool active = false;
	while (current != NULL && !current->status)
	{
		active = true;
		cout << endl;
		cout << string(50, '-') << endl;
		cout << "ID: " << current->id << endl;
		cout << "Username: " << current->username << endl;
		cout << "Email: " << current->email << endl;
		cout << "Address: " << current->address << endl;
		cout << "Phone Number: " << current->phonenum << endl;
		cout << "Status: " << current->status << endl << endl;
		cout << string(50, '-') << endl;
		cout << endl;
		cout << string(50, '=') << endl;
		current = current->nextAddress;
	}
	if (!active)
	{
		cout << endl;
		cout << string(50, '-') << endl;
		cout << "No inactive user found!" << endl;
		cout << string(50, '-') << endl;
		cout << endl;
	}

	return active;

}

void ModifyUser()
{
	int id = 0;
	string success = "success!";
	cout << string(50, '=') << endl;
	cout << "*****Modify User Details*****" << endl;
	DisplayUser();
	cout << "Which user details do you want to modify?" << endl;
	cout << "Enter the ID: ";
	cin >> id;
	//use linear search to find the user
	userNode* u = new userNode;
	u = linear_search(id);
	if (u == NULL) {
		cout << "user not found" << endl;
		string choice;
		cout << endl << "Press any key to continue. ";
		cin >> choice;
		return;
	}
	else {
		cout << u->username << endl;

		//user found
		int choice = 0;
		string newName, newAddress, newEmail, newPhone;
		cout << "What do you want to modify? " << endl;
		cout << "1. Name" << endl;
		cout << "2. Address " << endl;
		cout << "3. Email " << endl;
		cout << "4. Phone Number " << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (choice)
		{
		case 1:
			cout << "Enter new name: ";
			getline(cin, newName);

			u->username = newName;
			cout << u->username << endl;
			return;
		case 2:
			cout << "Enter new address: ";
			getline(cin, newAddress);

			u->address = newAddress;
			cout << u->address << endl;
			return;
		case 3:
			cout << "Enter new email: ";
			getline(cin, newEmail);

			u->email = newEmail;
			cout << u->email << endl;
			return;
		case 4:
			cout << "Enter new phone number: ";
			getline(cin, newPhone);

			u->phonenum = newPhone;
			cout << u->phonenum << endl;
			return;
		default:
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Invalid Input!!" << endl;
				system("pause");
			}
			system("cls");
			ModifyUser();
		}
	}

}

userNode* check_user(string username) {
	userNode* found = NULL;
	userNode* current = userhead;
	while (current != NULL) {
		if (current->username == username) {
			found = current;
			break;
		}
		current = current->nextAddress;
	}
	return found;
}

void FavUni(userNode* currentuser) {
	int ans;
	UniNode* current = unihead;
	cout << endl << "Select a university to add to favorites: " << endl;
	for (int i = 1; i <= ::size; i++) {
		cout << i << ". " << current->name << endl;
		current = current->NextAdd;
	}
	cout << "Enter your choice: ";
	cin >> ans;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid Input!!" << endl;
		system("pause");
		cout << "Enter your choice: ";
		cin >> ans;
	}

	//Find the selected uni
	UniNode* selecteduni = unihead;
	for (int i = 1; i < ans && selecteduni != NULL; i++) {
		selecteduni = selecteduni->NextAdd;
	}

	// Save the selected university as favorite
	if (selecteduni != NULL) {
		UniNode* fav = CreateNewUni(selecteduni->rank, selecteduni->name, selecteduni->loc, selecteduni->location, selecteduni->ars,
			selecteduni->arr, selecteduni->ers, selecteduni->err, selecteduni->fsrs, selecteduni->fsrr, selecteduni->cpfs,
			selecteduni->cpfr, selecteduni->ifrs, selecteduni->ifrr, selecteduni->isrs, selecteduni->isrr, selecteduni->irns,
			selecteduni->irnr, selecteduni->gers, selecteduni->gerr, selecteduni->score);

		if (currentuser->favunihead == NULL) {
			currentuser->favunihead = fav;
		}
		else {
			UniNode* currentfav = currentuser->favunihead;
			while (currentfav->NextAdd != NULL) {
				currentfav = currentfav->NextAdd;
			}
			currentfav->NextAdd = fav;
		}
		cout << "University saved as favorite!" << endl;
	}
	else {
		cout << "Invalid university choice!" << endl;
	}
}

void DisplayFavUni(userNode* currentuser) {
	cout << "Favorite Universities: " << endl;
	cout << string(50, '-') << endl;
	UniNode* current = currentuser->favunihead;
	if (current == NULL) {
		cout << "No favorite universities saved!" << endl;
	}
	else {
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
	}
	cout << "List ended here!" << endl;

	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}