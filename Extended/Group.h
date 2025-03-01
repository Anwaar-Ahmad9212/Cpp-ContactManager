#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"Contact.h"

class Group
{
	int* ContactId = nullptr;
	int count_of_contacts = 0;
	int sizeoflist = 5;

	string group_name;
public:
	Group() { }//list_of_contacts = new Contact[sizeoflist]; }
	Group(string s);

	void addname(string);
	string getname()const;
	int getcountofcontacts();
	//void Addcontactstogroup(const Contact& contact);

	void Addcontactstogroup(const int& Id);

	void resize_list();
	int* getids();
	int getid();

	/*void RemovecontactsFromgroup(const Contact& contact);*/
	void RemovecontactFromgroup(int);
	void RemovecontactsFromgroup(const int& id);
	void ReplaceID(const int& source, const int& desid);

	//string ShowcontactinGroup(Contact& contact);
//void PrintContactsofGroup();
};

