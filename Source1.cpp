#include<iostream>
#include<vector>
#include<fstream>
#include"UserInfoheader.h"
using namespace std;
class LibraryItem;
User::User(string password) {
		this->password = password;
	}
void Student::IssueBooks(string a) {
		//Search(a)->Borrow();
		cout << "BOOK ISSUED";
	}
void Student::ReturnBooks(string a){
		//Search(a)->Return();
		cout << "BOOK RETURNED";
	}
void Student::displayHistory() {
		system("cls");
		cout << ": : : HISTORY : : :";
	}


class LibraryItem {
	//BarCode a; //object of class barcode;
protected:
	bool IsBorrowed;
	bool IsReturned;
	bool IsRemoved;
public:
	LibraryItem() {
		IsBorrowed = false;
		IsReturned = true;
		IsRemoved = false;
	}
	virtual void remove() = 0;  //this function is linked to class Admin
	virtual void Borrow() = 0;  //Borrow and Return would be linked to User and it's sub-classes;        
	virtual void Return() = 0;

};

class BARcode {
};
class BookItem :public LibraryItem {
	string ISBN;
	vector<string> Authors;
	string title;
	int length;
public:
	BookItem() {
		length = 0;		//insert some default values here
	}
	BookItem(string ISBN, vector<string> Authors, string title, int length) :LibraryItem() {
		this->ISBN = ISBN;
		for (int i = 0; i < title.size(); i++)
		{
			this->Authors[i] = Authors[i];
		}
		this->title = title;
		this->length = length;
	}
	void remove() {/*some code*/ }
	void Borrow() { this->IsBorrowed = true; }
	void Return() {/*some code*/ }
	void setAuthors(vector<string> Authors) {
		for (int i = 0; i < title.size(); i++)
		{
			this->Authors[i] = Authors[i];
		}
	}
	vector<string> getAuthor() {
		return Authors;
	}
	string getISBN() {
		return ISBN;
	}
	string getTitle() {
		return title;
	}
};
int j = 0;
BookItem* Search(string name) {
	ifstream fp;
	BookItem b1;
	fp.open("LibraryItems.txt", ios::in);
	fp.seekg(0);
	while (fp.read((char*)&b1, sizeof(b1))) {
		if (b1.getTitle() == name)
		{
			return &b1;
		}
	}
}
void Register::checkPassword(string a) {
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
	for (int i = 0; i < sizeof(a); i++)
	{
		if (47 < int(a[i]) && int(a[i]) < 58) {
			count1++;
		}
		else if (96 < int(a[i]) && int(a[i]) < 123) {
			count2++;
		}
		else if (66 < int(a[i]) && int(a[i]) < 91)
		{
			count3++;
		}
		else if ((31 < int(a[i])) && (int(a[i]) < 48) || (57 < int(a[i]) && int(a[i]) < 65) || (90 < int(a[i]) && int(a[i]) < 97) || (122 < int(a[i]) && int(a[i]) < 127)) {
			count4++;
		}
	}
	if (count1 && count2 && count3 && count4 > 0 && (count1 + count2 + count3 + count4) >= 8) { cout << "STRONG PASSWORD" << endl; }
	if (count1 == 0) { cout << "MISSING UPPERCASE LETTERS" << endl; }
	if (count2 == 0) { cout << "MISSING LOWERCASE LETTERS" << endl; }
	if (count3 == 0) { cout << "MISSING NUMBERS" << endl; }
	if (count4 == 0) { cout << "MISSING SPECIAL CHARACTERS" << endl; }
}