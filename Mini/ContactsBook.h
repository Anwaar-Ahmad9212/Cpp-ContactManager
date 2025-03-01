

#pragma once
#include "Address.h"
#include "Contact.h"
//#ifndef BASIC_LIB
//#define BASIC_LIB
#include <iostream>
#include <string>
//#endif !BASIC_LIB


class ContactsBook
{
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index

public:
	int Count;
	int *count;
	void add_contact(const Contact& contact);
	int total_contacts();
	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address& address);
	~ContactsBook();
	//void Frequently();
	ContactsBook(int size_of_list);

	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if

/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

	void PrintContacts();
	void print();
	void updatecontact();
	void deletecontact(int choice);


	//void PrintContacts(Contact* contacts_list);

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
};


/*  MANAGING CONTACTS

for (int i = 0 ; i < contacts_counts;i++)
{
	 cout << contactlist[i].getf_name() << " "<< contactlist[i].getl_name() << endl;

}

  cout << "Enter Contact Number for details\n";

  cout <<*(List.searchcontact(Number));

  cin >> obj;

  List.addcontact
*/

// print contact

//update contact

// delete
