#include<iostream>
#include<string>
#include "Address.h"
#include"Contact.h"
#include"ContactsBook.h"
using namespace std;
int main()
{
//	//Scenario 1
	ContactsBook List(2);
	Contact Contacttoadd{};


//	for (int i = 0; i < 2; i++)
//	{
//		cout << "Add details of Contact" << i + 1 << " ";
//		cin >> Contacttoadd;
//		List.add_contact(Contacttoadd);
//	}
//
//	cout << "Enter how do you want your Contacts to be Sorted " << endl << "1. For sorting by First Name "
//		<< "2. For sorting by Last Name" << endl;
//	string choice;
//	cin >> choice;
//
//
//	List.print_contacts_sorted(choice);
//	List.PrintContacts();
//
//
////	Scenario 2
//
//	cout << "Total No of Contacts is " << List.total_contacts();
//
	for (int i = 0; i < 2; i++)
	{
		cin >> Contacttoadd;
		List.add_contact(Contacttoadd);
	}
	cout << "Total No of Contacts is " << List.total_contacts();
//
//
//	//Scenario 3
	Address *addressptr = new Address("house", "Fsd", "Jinnah", "Pk");

	Contact newobj("Anwaar", "Ahmad", "1234442", "any@email.com", addressptr);

	List.add_contact(newobj);//1st copy
	List.add_contact(newobj);//1st copy
//
//
//	cin >> Contacttoadd;
//
//	List.add_contact(Contacttoadd);
//
//	List.add_contact(newobj); //made a 2nd copy of same contact
//
//	cout << "Total No of Contacts is " << List.total_contacts();
//
//	List.merge_duplicates();

	//cout << "Total No of Contacts is " << List.total_contacts();


	//Scenario 4

	List.save_to_file("outfile.txt");
	//List.load_from_file("outfile.txt");

	//List.PrintContacts();

	//List.Groupmaker();
 //   List.AdContactstoGroupuser();
 //   List.deletecontactsfromgroup();


    List.PrintContacts();
    cout << "Enter Choice " << endl;
    int delch; cin >> delch;
    List.deletecontact(delch-1);

	//List.save_to_file("outfile.txt");
	//
	//


        //int choice;
        //string file_name;
        //string first_name, last_name, phone;
        //ContactsBook List; // You can adjust the size accordingly

        //do {
        //    cout << "\n==== Contacts Book Menu ====\n";
        //    cout << "1. Create contacts list with given size\n";
        //    cout << "2. Add New Contact\n";
        //    cout << "3. Merge Duplicates\n";
        //    cout << "4. Store To File\n";
        //    cout << "5. Load From File\n";
        //    cout << "6. Print Contacts Sorted\n";
        //    cout << "7. Print Contacts\n";
        //    cout << "8. Search contacts\n";
        //    cout << "9. Display Count of Contacts\n";
        //    cout << "0. Exit\n";
        //    cout << "Enter your choice: ";
        //    cin >> choice;

        //    switch (choice) {
        //    case 1:
        //        // Create contacts list with given size
        //        int size_of_list;
        //        cout << "Enter the size of the contacts list: ";
        //        cin >> size_of_list;
        //        ContactsBook List(size_of_list);
        //        break;


	return 0;
}

//
//
//#include <iostream>
//#include <ctime>
//#include <string>
//
//int main() {
//    std::time_t currentTime;
//    std::time(&currentTime); // Get the current time
//
//    // Convert the current time to a string
//    char buffer[26];
//    ctime_s(buffer, sizeof(buffer), &currentTime);
//    std::string currentTimeString(buffer);
//
//    // Print the current time
//    std::cout << "Current time: " << currentTimeString;
//
//    return 0;
//}
//
//template <class T1, class T2>
//class GenericeArray
//{
//	void Additem(T1* a, T2 size)
//	{
//
//	}
//};