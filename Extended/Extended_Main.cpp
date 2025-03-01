#include<iostream>
#include<string>
#include<Windows.h>
#include<thread>
#include<chrono>
#include "Address.h"
#include"Contact.h"
#include"ContactsBook.h"
#include "HistoryObjects.h";
#include"SearchObjects.h";
using namespace std;
int main()
{
	/*Address* addressptr = new Address("12", "54", "FSD", "Pakistan");

	Contact newobj("Anwaar", "Ahmad", "1234567891", "any@email.com", addressptr);


	Address* addressptr2 = new Address("12", "54", "FSD", "Pakistan");

	Contact newobj2("Hamza", "Kamran", "1234567891", "any@email.com", addressptr2);



	Address* addressptr3 = new Address("12", "54", "FSD", "Pakistan");

	Contact newobj3("Muneeb", "Anjum", "1234567891", "any@email.com", addressptr3);



	Address* addressptr4 = new Address("12", "54", "FSD", "Pakistan");

	Contact newobj4("Hashim", "Zia", "1234567891", "any@email.com", addressptr4);*/


	ContactsBook List(2);
	Contact Ctoadd;
	SearchObjects S1(1);
	 string searchthing;
	char endchoice = 'y';
	char choice;

	while (endchoice != 'n' && endchoice != 'N')
	{
		cout << "\n-------------------------";
		cout << "\nContacts Management System";
		cout << "\n-------------------------\n";
		cout << "1. Add New Contact\n";
		cout << "2. Update Contacts\n";
		cout << "3. Delete Contacts \n";
		cout << "4. View Contact Details\n";
		cout << "5. Search Contacts All three Choices\n";
		cout << "6. Advanced Search\n";
		cout << "7. View Frequently Searched Contacts\n";
		cout << "8. View Search History \n";
		cout << "9. Manage Groups\n";
		cout << "10. Exit\n";
		cout << "Enter Your Choice: ";
		cin >> choice;

		switch (choice) {

		case '1':
			cout << "How many New Contacts do you want to add: ";
			int size2;
			cin >> size2;


			for (int i = 0; i < size2; i++)
			{
				// Assuming Ctoadd is a Contact object or a string
				Contact Ctoadd;
				cin >> Ctoadd;
				List.add_contact(Ctoadd);
			}
			

			
			break;

		case '2':
			List.updatecontact();
			break;
		case '3':

			List.print();
			cout << "Enter the index of the contact you want to delete" << endl;
			int choice;
			cin >> choice;
			List.deletecontact(choice - 1);
			break;
		case '4':
			List.ViewContact();
			break;
		case '5':
		{
			bool flag = false;
			int ch;
			cout << "Enter Choice 1 to search by Firstname & Lastname\n 2 to search by phonenumber\n 3 to search by Address\n";

			while (flag != true)
			{
				cout << "Enter 1 to Search By FirstName and LastName\n";
				cout << "Enter 2 to Search By Phone Number\n";
				cout << "Enter 3 to Search by Adress\n";

				cin >> ch;

				if (ch < 1 || ch > 3)
					flag = false;
				else
					flag = true;
			}

			if (flag == true)
			{
				switch (ch)
				{
				case 1:
				{
					string fname, lname;
					cout << "Enter First & Last Name: ";
					cin.ignore();
					getline(cin, fname);
					getline(cin, lname);
					cout << *(List.search_contact(fname, lname)) << endl;
					break;
				}
				case 2:
				{
					string number;
					cout << "Enter Phone Number: ";
					cin.ignore();
					getline(cin, number);
					cout << *(List.search_contact(number,S1)) << endl;
					break;
				}
				case 3:
				{
					string house, street, city, country;
					cout << "Enter house: "; getline(cin, house);
					cout << "Enter street: "; getline(cin, street);
					cout << "Enter city: "; getline(cin, city);
					cout << "Enter country: "; getline(cin, country);
					Address Add(house, street, city, country);
					cout << *(List.search_contact(Add)) << endl;
				}
				default:
					break;
				}
			}
			break;
		}
		case '6':
			cout << "Enter The text do you Want to Search" << endl;
			cin.ignore();
			getline(cin, searchthing);
			List.GenericSearch(searchthing, S1);
			break;
		case '9':
		{

			// Manage Groups
			cout << "\n-------------------------";
			cout << "\nGroup Management";
			cout << "\n-------------------------\n";
			cout << "1. Make New Group\n";
			cout << "2. Add more Groups\n";
			cout << "3. Add Contacts To Group\n";
			cout << "4. Delete Contact From Group\n";
			cout << "5. Delete Group\n";
			cout << "6. Print Group Names\n";


			cout << "Enter Your Choice: ";
			int choice2;
			cin >> choice2;

			switch (choice2) {
			case 1:
				List.Groupmaker();
				break;
			case 2:
				List.GroupAdder();
				break;
			case 3:
				List.AddContactstoGroupuser();
				break;
			case 4:
				List.deletecontactsfromgroup();
				break;
			case 5:
				List.GroupDelete();
				break;
			case 6:
				List.PrintGroupNames();
				break;
			default:
				cout << "Invalid choice. Please enter again.\n";
				break;
			}
			break;
		}
		case '7':
		{	List.Frequently();
		break;
		}
		case'8':
		{
			S1.sorttime();
			S1.print();
			break;
		}

		case '10':
		{	cout << "Exiting program.\n";
		exit(0);
		break;
		}
		default:
		{	cout << "Invalid choice. Please enter again.\n";
		break;

		}
		}
		cout << "Do you want to continue (Y/N)? ";
		cin >> endchoice;

		if (endchoice == 'N' || endchoice == 'n')
		{
			cout << "\n-------------------------";
			cout << "\nThank You";
			cout << "\n-------------------------\n";
			
		}


	}
	return 0;
}
