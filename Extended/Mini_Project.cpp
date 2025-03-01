//////#include<iostream>
//////#include<string>
//////#include<Windows.h>
//////#include<thread>
//////#include<chrono>
//////#include "Address.h"
//////#include"Contact.h"
//////#include"ContactsBook.h"
//////#include "HistoryObjects.h";
//////#include"SearchObjects.h";
//////using namespace std;
//////int main()
//////{
//////	//Scenario 1
//////	//ContactsBook List(2);
//////
//////	//Contact Contacttoadd{};
//////
//////	//Contact co;
//////	//
//////	//	for (int i = 0; i < 2; i++)
//////	//	{
//////	//		cout << "Add details of Contact" << i + 1 << " ";
//////	//		cin >> Contacttoadd;
//////	//		List.add_contact(Contacttoadd);
//////	//	}
//////	//
//////	//	cout << "Enter how do you want your Contacts to be Sorted " << endl << "1. For sorting by First Name "
//////	//		<< "2. For sorting by Last Name" << endl;
//////	//	string choice;
//////	//	cin >> choice;
//////	//
//////	//
//////	//	List.print_contacts_sorted(choice);
//////	//	List.PrintContacts();
//////	//
//////	//
//////	////	Scenario 2
//////	//
//////	//	cout << "Total No of Contacts is " << List.total_contacts();
//////	//
//////	//	for (int i = 0; i < 3; i++)
//////	//	{
//////	//		cin >> Contacttoadd;
//////	//		List.add_contact(Contacttoadd);
//////	//	}
//////	//	cout << "Total No of Contacts is " << List.total_contacts();
//////	//
//////	//
//////	//	//Scenario 3
//////	//Address*addressptr = new Address("house", "Fsd", "Jinnah", "Pk");
//////
//////	//Contact newobj("Anwaar", "Ahmad", "1234442", "any@email.com", addressptr);
//////
//////	//List.add_contact(newobj);//1st copy
//////	//List.add_contact(newobj);//1st copy
//////	//
//////	//
//////	//	cin >> Contacttoadd;
//////	//
//////	//	List.add_contact(Contacttoadd);
//////	//
//////	//	List.add_contact(newobj); //made a 2nd copy of same contact
//////	//
//////	//	cout << "Total No of Contacts is " << List.total_contacts();
//////	//
//////	//	List.merge_duplicates();
//////
//////	//	cout << "Total No of Contacts is " << List.total_contacts();
//////
//////	//List.save_to_file("outfile.txt");
//////	//List.load_from_file("outfile.txt");
//////
//////	//List.PrintContacts();
//////
//////	//List.save_to_file("outfile.txt");
//////	//
//////	//
//////
//////	//cout << *(List.search_contact("1234442"));
//////	//cout << *Newcontact;
//////
//////	//Address* addressptr = new Address("house", "Fsd", "Jinnah", "Pk");
//////
//////	//Contact newobj("Anwaar", "Ahmad", "1234442", "any@email.com", addressptr);
//////	//Contact newobj1("Anwaar", "Ahmad", "123442", "any@email.com", addressptr);
//////
//////	//List.add_contact(newobj);//1st copy
//////	//List.add_contact(newobj1);//1st copy
//////	//List.PrintContacts();
//////
//////	//
////
////
//////hhhhhhhhhhhhhhhhhhhhh
//////#include<iostream>
//////#include<string>
//////#include "Address.h"
//////#include"Contact.h"
//////#include"ContactsBook.h"
//////using namespace std;
//////
//////int main()
//////{
//////    int Size;
//////    cout << "Enter the Size of the ContactList: ";
//////    cin >> Size;
//////    cin.ignore(); // Ignore the newline character in the input buffer
//////
//////    ContactsBook List(Size);
//////    char choice = 'Y';
//////    int option;
//////
//////    while (choice != 'N' && choice != 'n') // Use && instead of || for correct logic
//////    {
//////        cout << "\n-------------------------";
//////        cout << "\nContacts Book Management";
//////        cout << "\n-------------------------\n";
//////
//////       
//////        cout << "1. Add New Contact\n";
//////        cout << "2. Merge Duplicates\n";
//////        cout << "3. Store To File (input file name)\n";
//////        cout << "4. Load From File (input file name)\n";
//////        cout << "5. Print Contacts Sorted (input choice, first_name or last_name)\n";
//////        cout << "6. Print Contacts\n";
//////        cout << "7. Search contacts (all three choices)\n";
//////        cout << "8. Display Count of Contacts\n";
//////
//////        cout << "Enter Your Choice: ";
//////        cin >> option;
//////        cin.ignore(); // Ignore the newline character in the input buffer
//////
//////        switch (option)
//////        {
//////        case 1:
//////        {
//////            int size = 0;
//////            cout << "Enter How Many Objects You Want to Create: ";
//////            cin >> size;
//////            cin.ignore(); // Ignore the newline character in the input buffer
//////
//////            for (int i = 0; i < size; i++)
//////            {
//////                Contact Contacttoadd;
//////                cin >> Contacttoadd;
//////                List.add_contact(Contacttoadd);
//////            }
//////            break;
//////        }
//////        case 2:
//////        {
//////            List.merge_duplicates();
//////            break;
//////        }
//////        case 3:
//////        {
//////            string FileName;
//////            cout << "Enter File Name to Store Contacts: ";
//////            getline(cin, FileName);
//////
//////            List.save_to_file(FileName);
//////            break;
//////        }
//////        case 4:
//////        {
//////            string FileName;
//////            cout << "Enter File Name to Load Contacts From: ";
//////            getline(cin, FileName);
//////
//////            List.load_from_file(FileName);
//////            break;
//////        }
//////        case 5:
//////        {
//////            string choice;
//////            cout << "Enter 1 to Sort By FirstName OR 2 to Sort by LastName: ";
//////            getline(cin, choice);
//////
//////            bool flag = false;
//////            while (flag != true)
//////            {
//////                if (choice == "1" || choice == "2")
//////                    flag = true;
//////                else
//////                {
//////                    cout << "Invalid choice. Please enter 1 or 2: ";
//////                    getline(cin, choice);
//////                }
//////            }
//////            List.print_contacts_sorted(choice);
//////            break;
//////        }
//////        case 6:
//////        {
//////            List.PrintContacts();
//////            break;
//////        }
//////        case 7:
//////        {
//////            bool flag = false;
//////            int ch;
//////            cout << "Enter Choice 1 to search by Firstname & Lastname\n 2 to search by phonenumber\n 3 to search by Address\n";
//////
//////            while (flag != true)
//////            {
//////                cout << "Enter 1 to Sort By FirstName OR 2 to Sort by LastName\n";
//////                cin >> ch;
//////
//////                if (ch < 1 || ch > 3)
//////                    flag = false;
//////                else
//////                    flag = true;
//////            }
//////
//////            if (flag == true)
//////            {
//////                switch (ch)
//////                {
//////                case 1:
//////                {
//////                    string fname, lname;
//////                    cout << "Enter First & Last Name: ";
//////                    cin.ignore();
//////                    getline(cin, fname);
//////                    getline(cin, lname);
//////                    List.search_contact(fname, lname);
//////                    break;
//////                }
//////                case 2:
//////                {
//////                    string number;
//////                    cout << "Enter Phone Number: ";
//////                    cin.ignore();
//////                    getline(cin, number);
//////                    List.search_contact(number);
//////                    break;
//////                }
//////                default:
//////                    break;
//////                }
//////            }
//////            break;
//////        }
//////        case 8:
//////        {
//////            List.total_contacts();
//////            break;
//////        }
//////        default:
//////            break;
//////        }
//////
//////        cout << "Do you want to continue (Y/N)? ";
//////        cin >> choice;
//////        cin.ignore(); // Ignore the newline character in the input buffer
//////    }
//////
//////    return 0;
//////}
////
////
//#include<iostream>
//#include<string>
//#include<Windows.h>
//#include<thread>
//#include<chrono>
//#include "Address.h"
//#include"Contact.h"
//#include"ContactsBook.h"
//#include "HistoryObjects.h";
//#include"SearchObjects.h";
//using namespace std;
//int main()
//{
//	//Scenario 1
//	ContactsBook List(3);
//
//	Contact Contacttoadd{};
//
//	//	//Contact co;
//	//	//
//	//	//	for (int i = 0; i < 2; i++)
//	//	//	{
//	//	//		cout << "Add details of Contact" << i + 1 << " ";
//	//	//		cin >> Contacttoadd;
//	//	//		List.add_contact(Contacttoadd);
//	//	//	}
//	//	//
//	//	//	cout << "Enter how do you want your Contacts to be Sorted " << endl << "1. For sorting by First Name "
//	//	//		<< "2. For sorting by Last Name" << endl;
//	//	//	string choice;
//	//	//	cin >> choice;
//	//	//
//	//	//
//	//	//	List.print_contacts_sorted(choice);
//	//	//	List.PrintContacts();
//	//	//
//	//	//
//	//	////	Scenario 2
//	//	//
//	//	//	cout << "Total No of Contacts is " << List.total_contacts();
//	//	//
//	//	//	for (int i = 0; i < 3; i++)
//	//	//	{
//	//	//		cin >> Contacttoadd;
//	//	//		List.add_contact(Contacttoadd);
//	//	//	}
//	//	//	cout << "Total No of Contacts is " << List.total_contacts();
//	//	//
//	//	//
//	//	//	//Scenario 3
//		Address*addressptr = new Address("house", "Fsd", "Jinnah", "Pk");
//	
//		Contact newobj("Anwaar", "Ahmad", "1234442", "any@email.com", addressptr);
//	
//
//		Address* addressptr2 = new Address("house", "Fsd", "Jinnah", "Pk");
//
//		Contact newobj2("Hamza", "Kamran", "1234442", "any@email.com", addressptr);
//
//
//
//		Address* addressptr3 = new Address("house", "Fsd", "Jinnah", "Pk");
//
//		Contact newobj3("Muneeb", "Anjum", "1234442", "any@email.com", addressptr);
//
//
//
//		Address* addressptr4 = new Address("house", "Fsd", "Jinnah", "Pk");
//
//		Contact newobj4("Muneeb", "Anjum", "1234442", "any@email.com", addressptr);
//
//
//		List.add_contact(newobj);//1st copy
//		List.add_contact(newobj3);//1st copy
//		List.add_contact(newobj2);//2nd copy
//		List.add_contact(newobj4);//1st copy
//		List.add_contact(newobj2);//2nd copy
//
//	//	//
//	//	//	cin >> Contacttoadd;
//	//	//
//	//	//	List.add_contact(Contacttoadd);
//	//	//
//	//	//	List.add_contact(newobj); //made a 2nd copy of same contact
//	//	//
//	//	//	cout << "Total No of Contacts is " << List.total_contacts();
//	//	//
//	//	//	List.merge_duplicates();
//	//
//	//	//	cout << "Total No of Contacts is " << List.total_contacts();
//	//
//	//	//List.save_to_file("outfile.txt");
//	//	//List.load_from_file("outfile.txt");
//	//
//	//	//List.PrintContacts();
//	//
//	//	//List.save_to_file("outfile.txt");
//	//	//
//	//	//
//	//
//	//	//cout << *(List.search_contact("1234442"));
//	//	//cout << *Newcontact;
//	//
//	//	Address* addressptr = new Address("house", "Fsd", "Jinnah", "Pk");
//	//
//	//	Contact newobj("Anwaar", "Ahmad", "1234442", "any@email.com", addressptr);
//	//	Contact newobj1("Anwaar", "Ahmad", "123442", "any@email.com", addressptr);
//	//
//	//	List.add_contact(newobj);//1st copy
//	//	List.add_contact(newobj1);//1st copy
//	//
//	//
//	//	//List.print();
//	//	/*cout << "Do you want to update the details of any of the contact??\ Yes or No \n";
//	//	char choice = 'N';
//	//	cin >> choice;
//	//	if (choice == 'Y' || choice == 'y')
//	//	{
//	//		List.updatecontact();
//	//	}*/
//	//	/*cout << "Enter the Contact Id to Delete\n";
//	//	int id;
//	//	cin >> id;
//	//	bool flag = false;
//	//	while (flag != true)
//	//	{
//	//		if (id <= 0 || id >= 9)
//	//		{
//	//			cout << "Enter Valid Id\n";
//	//			cin >> id;
//	//			flag = false;
//	//		}
//	//		else
//	//			flag = true;
//	//	}
//	//	List.deletecontact(id - 1);
//	//	List.PrintContacts();*/
//	//
//	
//
//	HistoryObjects H1("Ayaan");
//	cout << H1.getStr() << H1.getCurrentTime() << endl;
//
//	SearchObjects S1(3);
//	/*for (int i = 0; i < 3; i++)
//	{
//		List.search_contact("1442", S1);
//	}*/
//
//
//	/*for (int i = 0; i < 3; i++)
//	{
//		List.save_to_file("outfile.txt");
//
//		List.load_from_file("outfile.txt");
//	
//	}
//	List.PrintContacts();
//	*/
//
//	//List.Groupmaker();
//		//List.GenericSearch("Dil Dar");
//		/*List.AddContactstoGroupuser();
//		List.AddContactstoGroupuser();
//
//
//	List.merge_duplicates();
//	List.PrintContacts();*/
//
//	
//	//List.deletecontactsfromgroup();
//	//List.PrintcontactsofGroup(0);*/
//
//	//List.GroupDelete();
//	//List.GroupAdder();
//
////	List.PrintGroupNames();
//	
//	/*S1.sorttime();
//	S1.print();
//	*///HistoryObjects H2("Hadee", buffer);
//	//cout << H2.getStr() << H2.getCurrentTime() << endl;
//
//	List.GenericSearch("anr", S1);
//	Sleep(2000);
//	List.GenericSearch(" anwar", S1);
//	S1.sorttime();
//	S1.print();
//
//}
//
//
//
////	List.Frequently();
////
////	List.PrintContacts();
////	/*List.Groupmaker();
////	List.AdContactstoGroupuser();
////	List.deletecontact(1);
////	List.deletecontactsfromgroup();*/
////
////	return 0;
////}
////
////
////
