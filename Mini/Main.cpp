#include<iostream>
#include<string>
#include "Address.h"
#include"Contact.h"
using namespace std;
#include"ContactsBook.h"


int main()
{

	int Size{};
	

	cout << "Enter the Size of the ContactList: ";
	cin >> Size;

	if (cin.fail())
	{
		cout << "Dummy Size " << endl;
		cin.clear();
		cin.ignore();
		cin >> Size;
	}

	
	ContactsBook List(Size);
	char choice = 'Y';
	int option;

	while (choice != 'N' && choice != 'n') 
	{
		cout << "\n-------------------------";
		cout << "\nContacts Book Management";
		cout << "\n-------------------------\n";


		cout << "1. Add New Contact\n";
		cout << "2. Merge Duplicates\n";
		cout << "3. Store To File (input file name)\n";
		cout << "4. Load From File (input file name)\n";
		cout << "5. Print Contacts Sorted (input choice, first_name or last_name)\n";
		cout << "6. Print Contacts\n";
		cout << "7. Search contacts (all three choices)\n";
		cout << "8. Display Count of Contacts\n";
		cout << "9. Exit\n";


		cout << "Enter Your Choice: ";
		cin >> option;
		cout << endl;
		if (cin.fail())
		{
			cout << "Dummy Option " << endl;
			cin.clear();
			cin.ignore();
			cin >> option;
		}


		cin.ignore(); 

		switch (option)
		{
		case 1:
		{
			Address* addressptr = new Address("1", "12", "Jinnah", "Pk");

			Contact newobj("Anwaar", "Ahmad", "12334567890", "any@email.com", addressptr);


			Address* addressptr2 = new Address("1", "12", "Jinnah", "Pk");

			Contact newobj2("Hamza", "Kamran", "12334567890", "any@email.com", addressptr);



			Address* addressptr3 = new Address("1", "12", "Jinnah", "Pk");

			Contact newobj3("Muneeb", "Anjum", "12345678900", "any@email.com", addressptr);



			Address* addressptr4 = new Address("1", "12", "Jinnah", "Pk");

			Contact newobj4("Muneeb", "Anjum", "12345678900", "any@email.com", addressptr);


			List.add_contact(newobj);//1st copy
			List.add_contact(newobj3);//1st copy
			List.add_contact(newobj2);//2nd copy
			
			/*int size = 0;
			cout << "Enter How Many Contacts You Want to Create: ";
			cin >> size;
			cin.ignore(); 
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "Enter the Following Details of Contact: " << i + 1 << endl;
				Contact Contacttoadd;
				cin >> Contacttoadd;
				List.add_contact(Contacttoadd);
			}*/
			break;
		}
		case 2:
		{
			List.merge_duplicates();
			break;
		}
		case 3:
		{
			string FileName;
			cout << "Enter File Name to Store Contacts: ";
			getline(cin, FileName);

			List.save_to_file(FileName);
			break;
		}
		case 4:
		{
			string FileName;
			cout << "Enter File Name to Load Contacts From: ";
			getline(cin, FileName);

			List.load_from_file(FileName);
			break;
		}
		case 5:
		{
			string choice;
			cout << "Enter 1 to Sort By FirstName OR 2 to Sort by LastName: ";
			getline(cin, choice);

			bool flag = false;
			while (flag != true)
			{
				if (choice == "1" || choice == "2")
					flag = true;
				else
				{
					cout << "Invalid choice. Please enter 1 or 2: ";
					getline(cin, choice);
				}
			}
			List.print_contacts_sorted(choice);
			break;
		}
		case 6:
		{
			List.PrintContacts();
			break;
		}
		case 7:
		{
			bool flag = false;
			int ch;
			cout << "Enter Choice 1 to search by Firstname & Lastname\n 2 to search by phonenumber\n 3 to search by Address\n";

			while (flag != true)
			{
				cout << "Enter 1 to Sort By FirstName OR 2 to Sort by LastName\n";
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
					cout << *(List.search_contact(number)) << endl;
					break;
				}
				case 3:
				{
					cin.ignore();
					string house, street, city, country;
					cout << "Enter house: "; getline(cin, house);
					cout << "Enter street: "; getline(cin, street);
					cout << "Enter city: "; getline(cin, city);
					cout << "Enter country: "; getline(cin, country);
					Address  Add(house, street, city, country);
					cout << *(List.search_contact(Add)) << endl;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case 8:
		{
			cout << "Current Contacts Count is " << List.total_contacts() << endl;
			break;
		}
		case 9:
		{
			cout << "\n-------------------------";
			cout << "\nThank You";
			cout << "\n-------------------------\n";
			exit(0);
			break;
		}
		default:
			cout << "Wrong Choice " << endl;
			break;
		}


		cout << "Do you want to continue (Y/N)? ";
		cin >> choice;
		if (choice != 'y' && choice != 'Y')
		{
			cout << "\n-------------------------";
			cout << "\nThank You";
			cout << "\n-------------------------\n";

		}
		cin.ignore();
	}

	return 0;


}