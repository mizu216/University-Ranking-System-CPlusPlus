#include "feedback.h"
#include "university.h"
#include "user.h"
#include<iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;


class Admin
{
	string username = "admin";
	string password = "123";

public:
	string getUsernmane()
	{
		return username;
	}
	string getPassword()
	{
		return password;
	}
};

void DeleteUser()
{
	system("cls");
	fflush(stdin);
	int user, choice;
	bool del = true;
	cout << string(50, '=') << endl;
	cout << "*****Delete User Page*****" << endl;
	cout << "1. Display All User" << endl;
	cout << "2. Display Inactive User" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		DisplayUser();
	}
	else if (choice == 2)
	{
		del = DisplayInactive();
	}
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("pause");
		system("cls");
		cout << string(15, '*') << endl << endl;
		cout << "Invalid Input! (" << choice << ")" << endl;
		cout << "Please enter a valid choice" << endl;
		cout << string(15, '*') << endl << endl;
		DeleteUser();
	}
	if (del)
	{
		cout << "Which user do you want to delete? " << endl;
		cout << "Please enter your choice: ";
		cin >> user;
		userNode* u = new userNode;
		u = linear_search(user);
		if (u == NULL) {
			cout << "user not found" << endl;
			string choice;
			cout << endl << "Press any key to continue. ";
			cin >> choice;
			return;
		}
		else {
			deleteuser(user);
		}
	}
	else
	{
		DeleteUser();
	}
}

void FeedbackPage()
{
	system("cls");
	fflush(stdin);
	int choice = 0;
	int i = 1;
	string reply;
	while (choice != 9 && feedbackSize != 0) {
		DisplayFromFrontList(i);
		cout << "1 for next page" << endl << "2 for prev page:" << endl << "3 for reply feedback" << endl << "4. Quit" << endl << "Enter Your Choice:";
		cin >> choice;
		if (choice == 1 && i < feedbackSize) {
			i++;
		}
		else if (choice == 2 && i > 1) {
			i--;
		}
		else if (choice == 3) {
			cout << "Enter Reply:";
			cin >> reply;
			replyFeedback(reply, i);
		}
		else if (choice == 4)
		{
			return;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
			cout << "Action Not Available" << endl;
		}
		system("cls");
	}
}

void SummaryPage()
{
	UniNode* current = unihead;



	cout << string(50, '-') << endl;
	cout << "*****Summary Page*****" << endl;



	UniNode* sort = MergeSortCount(current);
	int i = 0;
	while (i < 10)
	{
		if (sort->count != 0)
		{
			cout << i + 1 << ". " << sort->name << "  " << sort->count << endl;
		}
		i++;
		sort = sort->NextAdd;
	}
	return;
}

void AdminPage() {
	while (true) {
		system("cls");
		fflush(stdin);
		int choice;
		string choice1;
		cout << string(50, '-') << endl;
		cout << "Hi ,you are now in admin page." << endl;
		cout << string(50, '-') << endl << endl;
		cout << "** MENU **" << endl;
		cout << "1. Display Users" << endl << "2. Modify Users" << endl << "3. Delete Users" << endl << "4. Feedbacks" << endl << "5. Summary" << endl << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			DisplayUser();
			cout << endl << "Press any key to continue. ";
			cin >> choice1;
			continue;
		case 2:
			ModifyUser();
			continue;
		case 3:
			DeleteUser();
			continue;
		case 4:
			FeedbackPage();
			continue;
		case 5:
			SummaryPage();
			continue;
		case 6:
			break;
		default:
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Invalid Input!!" << endl;
				system("pause");
			}
			system("cls");
			AdminPage();
		}
		system("cls");
		fflush(stdin);
		break;
	}
}

void AdminLogin() {
	Admin admin;
	string username;
	string password;
	cout << string(50, '-') << endl;
	cout << "*****Admin Login Page*****" << endl;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;
	cout << endl;
	cout << string(50, '-') << endl;
	while (username.compare(admin.getUsernmane()) != 0 || password.compare(admin.getPassword()) != 0)
	{
		cout << "*****Invalid Credentials*****" << endl;
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;

	}
	AdminPage();
}


void SortUniBy() {
	int ans;
	cout << endl << "Sort univevrsity By: " << endl;
	cout << endl << "1. Name" << endl << "2. Academic Reputation Score" << endl << "3. Faculty/Student Ratio Score" << endl << "4. Employer Reputation Score" << endl << "5. Back" << endl;
	cout << "Enter your choice: ";
	cin >> ans;
	switch (ans) {
	case 1:
		unihead = MergeSort(unihead);
		DisplayUniFromFront();
		break;
	case 2:
		unihead = MergeSortAr(unihead);
		DisplayUniFromFront();
		break;
	case 3:
		unihead = MergeSortFsr(unihead);
		DisplayUniFromFront();
		break;
	case 4:
		unihead = MergeSortEr(unihead);
		DisplayUniFromFront();
		break;
	case 5:
		return;
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid Input!!" << endl;
			system("pause");
		}
	}
}

void SortUni() {
	auto start = high_resolution_clock::now();
	//Merge Sort
	unihead = MergeSort(unihead);
	DisplayUniFromFront();

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by merge sort algorithm: ";
	cout << duration.count() << " microseconds" << endl;

	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}

void SearchUni() {
	int searchchoice;
	cout << endl << "Welcome to Search for University" << endl;
	cout << "Choose for the categories to search." << endl << "1. Rank" << endl << "2. Institution" << endl << "3. Location" << endl << "Choice: ";
	cin >> searchchoice;
	switch (searchchoice) {
	case 1:
		searchrank();
		break;
	case 2:
		searchinstitution();
		break;
	case 3:
		searchlocation();
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid Input!!" << endl;
		}
	}
	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}

void UserPage() {
	while (true) {
		system("cls");
		fflush(stdin);
		int choice;
		cout << string(50, '-') << endl;
		cout << endl << "Hi " << currentUser->username << " ,you are now in user page." << endl;
		cout << string(50, '-') << endl << endl;
		cout << "** MENU **" << endl;
		cout << "1. Display University" << endl << "2. Sort University" << endl << "3. Search University" << endl << "4. Save Favourites" << endl;
		cout << "5. Display Favourites" << endl << "6. Make Feedback" << endl << "7. Display Feedback" << endl << "8. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			DisplayUniFromFront();
			continue;
		case 2:
			SortUniBy();
			continue;
		case 3:
			SearchUni();
			continue;
		case 4:
			FavUni(currentUser);
			continue;
		case 5:
			DisplayFavUni(currentUser);
			continue;
		case 6:
			userMakeFeedback(currentUser->username);
			continue;
		case 7:
			userViewFeedback(currentUser->username);
			continue;
		case 8:
			break;
		default:
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Invalid Input!!" << endl;
				system("pause");
			}
			system("cls");
			continue;
		}
		system("cls");
		fflush(stdin);
		break;
	}
}

void Register() {
	string username;
	string password;
	string email;
	string address;
	string phonenum;
	bool status;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl << "Welcome to Register Page!" << endl << (50, '-') << endl;
	cout << "Name: ";
	getline(cin, username);
	if (check_user(username) != NULL) {
		cout << "this username has been used" << endl;
	}
	else {
		cout << endl << "Password: ";
		getline(cin, password);
		cout << endl << "Email: ";
		getline(cin, email);
		cout << endl << "Address: ";
		getline(cin, address);
		cout << endl << "Phone Number: ";
		getline(cin, phonenum);
		status = true;
		cout << endl << "Registration Successful!!" << endl;
		InsertToFrontUser(username, password, email, address, phonenum, status);
		cout << "Account created!!!!" << endl;
	}
	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}

void UserLogin() {
	string username;
	string password;
	cout << endl << "Enter Username: ";
	cin >> username;
	cout << endl << "Enter Password: ";
	cin >> password;
	if (check_user(username) == NULL || check_user(username)->password != password) {
		cout << "Invalid User Credential" << endl;
		string choice;
		cout << endl << "Press any key to continue. ";
		cin >> choice;
	}
	else {
		currentUser = check_user(username);
		UserPage();
	}
}
void LoginPage();
void GuestPage() {
	while (true) {
		//system("cls");
		//fflush(stdin);
		int choice;
		currentUser = NULL;
		cout << string(50, '-') << endl;
		cout << "Hi, you are now in guest page." << endl;
		cout << string(50, '-') << endl << endl;
		cout << "** MENU **" << endl;
		cout << "1. Display University" << endl << "2. Sort University" << endl << "3. Search University" << endl << "4. Register" << endl << "5. Login" << endl << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			DisplayUniFromFront();
			continue;
		case 2:
			SortUni();
			continue;
		case 3:
			searchinstitution();
			continue;
		case 4:
			Register();
			continue;
		case 5:
			UserLogin();
			continue;
		case 6:
			LoginPage();
			break;
		default:
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Invalid Input!!" << endl;
				system("pause");
			}
			//system("cls");
			GuestPage();
		}
		//system("cls");
		//fflush(stdin);
		//break;
	}
}

void LoginPage() {
	int choice;
	cout << endl << "** Login Page **";
	cout << endl << "1. User" << endl << "2. Admin" << endl << "3. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		GuestPage();
		break;
	case 2:
		AdminLogin();
		break;
	case 3:
		cout << endl << string(50, '=') << endl << "\t\tTHANK YOU!" << endl << "\t\tSee You Again!! " << endl << string(50, '=');
		exit(0);
		break;
	default:
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Invalid Input!!" << endl;
			system("pause");
		}
		system("cls");
		LoginPage();
	}
}

int main() {
	//Menu page
	unihead = NULL;
	userhead = NULL;
	int choice1, password = 0;
	bool status = true;
	string username, email, address, phonenum;
	cout << string(50, '-') << endl;

	ifstream file("Uni2.csv");
	string rank, name, loc, location, ars, arr, ers, err, fsrs, fsrr, cpfs, cpfr, ifrs, ifrr, isrs, isrr, irns, irnr, gers, gerr, score;

	if (file.is_open())
	{
		cout << ":>" << endl;
	}
	else
	{
		cout << ":<" << endl;
	}

	while (file.good()) {
		getline(file, rank, ',');
		getline(file, name, ',');
		getline(file, loc, ',');
		getline(file, location, ',');
		getline(file, ars, ',');
		getline(file, arr, ',');
		getline(file, ers, ',');
		getline(file, err, ',');
		getline(file, fsrs, ',');
		getline(file, fsrr, ',');
		getline(file, cpfs, ',');
		getline(file, cpfr, ',');
		getline(file, ifrs, ',');
		getline(file, ifrr, ',');
		getline(file, isrs, ',');
		getline(file, isrr, ',');
		getline(file, irns, ',');
		getline(file, irnr, ',');
		getline(file, gers, ',');
		getline(file, gerr, ',');
		getline(file, score);
		if (name == "Institution") {
			continue;
		}
		else if (rank == "") {
			break;
		}

		InsertToEndUni(rank, name, loc, location, ars, arr, ers, err, fsrs, fsrr, cpfs, cpfr, ifrs, ifrr, isrs, isrr, irns, irnr, gers,
			gerr, score);
	}
	file.close();
	bool exitProgram = false;
	do {
		LoginPage();
	} while (!exitProgram);
	return 0;
}