// LibManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<fstream>
#include<string>
#include <iostream>
#include"UserInfoheader.h"
using namespace std;

/*class Book {
    string bname;
    string ISBN;
    string aname[4];
    string genre;
    int number_of_copies;
    int length;
public:
    void issueBooks()
    {

    }

};*/
void Register :: prompt()
	{
		system("cls");
		cout << "ARE YOU A:\n1.STUDENT\n2.TEACHER\n" << endl;
		int a;
		cin >> a;
		fstream fout;
		fout.open("sample.txt", ios::out | ios::app);
		switch (a)
		{
		case 1:
		{  
			cout << "ENTER YOUR FIRST NAME : : ";
		    cin >> f_name;
		    cout << "ENTER YOUR LAST NAME : : ";
		    cin >> l_name;
		    cout << "ENTER YOUR ROLL NO. : : ";
		    cin >> id;
			cout << "ENTER YOUR PASSWORD : : ";
			cin >> password;
			//checkPassword(password);
		/*	while (checkPassword(password) == 0) {
				cout << "ENTER YOUR PASSWORD : : ";
				cin >> password;
		   }*/
			Student s2(f_name, l_name, id, password);
		break; }
		case 2:
		{
			cout << "ENTER YOUR FIRST NAME : : ";
			cin >> f_name;
			fout << f_name;
			cout << "ENTER YOUR LAST NAME : : ";
			cin >> l_name;
			cout << "ENTER YOUR EMPLOYEE ID. : : ";
			cin >> id;
			cout << "ENTER YOUR PASSWORD : : ";
			cin >> password;
			break;
		}
		default:
		{
			cout << "INVALID INPUT" << endl << "TRY AGAIN";
			prompt();
			break;
		}
		
		}
		this->checkPassword(password);
	}

void display() {
	cout << "\n\t*****************************************************************************************************\n\n";
	cout << "\t\t\t\t\t\t\tTHE BOOK NOOK\n";
	cout << "\n\t*****************************************************************************************************\n\n";
};

int main()
{
    Register r1;
    int n,n1;
    while (true)

    {
        system("cls");
		display();
		cout << "\t\t\t\t\tWELCOME TO THE LIBRARY MANAGEMENT SYSTEM\t\t\n";
		cout << "\n\t\t\t\t\t\t\t  MAIN MENU\n";
		cout << "\n\t*****************************************************************************************************\n";
		system("cls");
		display();
        cout << "\nARE YOU A:  1.USER \t2.ADMINISTRATOR\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {

			system("cls");
			display();
			
            cout << "1.USER LOGIN\n2.USER REGISTER\n";
            cin >> n1;
            switch (n1)
            {
            case 1:
            {
                
            }
            case 2:
            {
               
                r1.prompt();

            }
            }
        }
        }
        
    
       
    }
    
    

  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
