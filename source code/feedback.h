#include<iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct FeedbackNode {
	string PublishDT;
	string username;
	string FeedbackContent;
	string FeedbackReply;
	FeedbackNode* NextAdd;
	FeedbackNode* PrevAdd;
}*feedbackhead, * feedbacktail;

int feedbackSize = 0;

FeedbackNode* createNewFeedbackNode(string username, string FeedbackContent) {
	time_t currentTime = time(nullptr);
	tm localTime{};
	localtime_s(&localTime, &currentTime);
	char timeString[100];
	strftime(timeString, sizeof(timeString), "%d/%m/%Y %H:%M", &localTime);

	FeedbackNode* newnode = new FeedbackNode;
	newnode->PublishDT = timeString;
	newnode->username = username;
	newnode->FeedbackContent = FeedbackContent;
	newnode->FeedbackReply = "";
	newnode->NextAdd = NULL;
	newnode->PrevAdd = NULL;
	return newnode;
}

void InsertToTheFrontOfList(string username, string FeedbackContent) {
	FeedbackNode* newnode = createNewFeedbackNode(username, FeedbackContent);
	if (feedbackhead == NULL)
	{
		feedbackhead = feedbacktail = newnode;
	}
	else {
		newnode->NextAdd = feedbackhead;
		feedbackhead->PrevAdd = newnode;
		feedbackhead = newnode;
	}

	feedbackSize++;
}

void DisplayFromFrontList(int i) {
	int x = 1;
	FeedbackNode* current = feedbackhead;
	while (current != NULL) {
		if (x == i) {
			cout << current->PublishDT << endl;
			cout << current->FeedbackContent << endl;
			cout << current->FeedbackReply << endl;
			break;
		}
		current = current->NextAdd;
		x++;
	}
}

void replyFeedback(string reply, int i) {
	int x = 1;
	FeedbackNode* current = feedbackhead;
	while (current != NULL) {
		if (x == i) {
			current->FeedbackReply = reply;
			break;
		}
		current = current->NextAdd;
		x++;
	}
}

void userMakeFeedback(string username) {
	string feedback;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Feedback Content:" << endl;
	getline(cin, feedback);
	InsertToTheFrontOfList(username, feedback);
}

void userViewFeedback(string username) {
	FeedbackNode* current = feedbackhead;
	while (current != NULL) {
		if (current->username == username) {
			cout << current->PublishDT << endl;
			cout << current->username << endl;
			cout << current->FeedbackContent << endl;
			cout << current->FeedbackReply << endl;
		}
		current = current->NextAdd;
	}
	string choice;
	cout << endl << "Press any key to continue. ";
	cin >> choice;
}



