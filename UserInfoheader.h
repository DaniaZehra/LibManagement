#pragma once
using namespace std;
class User {
	string password;
public:
	User(string password);
	virtual void IssueBooks(string a) = 0;
	virtual void ReturnBooks(string a) = 0;
	virtual void displayHistory() = 0;
};
class Student :public User {
	string f_name;
	string l_name;
	string roll_no;
public:
	Student(string f_name, string l_name, string roll_no, string password) :User(password) {};
	void IssueBooks(string a);
	void ReturnBooks(string a);
	void displayHistory();
};
class Register {
	string id;
	string f_name;
	string l_name;
	string password;
public:
	void prompt();
	void checkPassword(string a);
};
