#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


class LibraryItem;
class User {
protected:
	string password;
public:
	virtual void IssueBooks() = 0;
	virtual void ReturnBooks() = 0;
	virtual void displayHistory() = 0;
};
class Student :public User {
	string f_name;
	string l_name;
	string roll_no;
public:
void IssueBooks(string a) {
	Search(a)->Borrow();
	}

};

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
	BARcode barcode;
	string ISBN;
	vector<string> Authors;
	string title;
	int length;
public:
	BookItem() {
		//insert some default values here
	}
	BookItem(string ISBN, vector<string> Authors, string title, int length):LibraryItem() {
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
	while (fp.read((char*)&b1,sizeof(b1))) {
		if (b1.getTitle() == name)
		{
			return &b1;
		}
	}
}