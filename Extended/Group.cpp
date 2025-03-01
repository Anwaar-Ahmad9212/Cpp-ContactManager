#include "Group.h"
Group::Group(string s)
{
	this->group_name = s;
	ContactId = new int[sizeoflist];
	for (int i = 0; i < 5; i++)
	{
		ContactId[i] = 0;
	}
}
void Group::addname(string name)
{
	this->group_name = name;

}
string Group::getname() const
{
	return group_name;
}
int Group::getcountofcontacts()
{
	return count_of_contacts;
}
//Group::Group(string s):group_name(s)
//{}
void Group::Addcontactstogroup(const int & Id)
{
	bool samecontacts = false;
	if (count_of_contacts < sizeoflist)
	{
		for (int i = 0; i < count_of_contacts; i++)
		{
			if (ContactId[i] == Id)//a loop for checking if that same unique id already exists in a group
			{
				samecontacts = true;
				break;
			}
		}
		if (!samecontacts)
		{
			ContactId[count_of_contacts++] = Id;
			cout << "Contact Added To Group Successfully" << endl;
		}
		else { cout << "You cant add same contact twice to same Group" << endl; }
	}
	else
	{
		resize_list();
		Addcontactstogroup(Id);
		cout << "Contact Added To Group Successfully" << endl;

	}
}

void Group::resize_list()
{
	int size = 2 * count_of_contacts;
	int *NewCount = nullptr;
	NewCount = new int [size];

	for (int i = 0; i < count_of_contacts; i++)
	{
		*(NewCount + i) = *(ContactId + i);
	}

	delete[]ContactId;

	ContactId = NewCount;
	this->sizeoflist = size;

}

int* Group::getids()
{
	return ContactId;
}

int Group::getid()
{
	return 0;
}

//void Group::RemovecontactsFromgroup(const Contact& contact)
//{
//	//add delete functionality for group same as contact book cpp
//		bool contactFound = false;
//
//			for (int j = choice; j < count_of_contacts - 1; j++)
//			{
//				list_of_contacts[j] = list_of_contacts[j + 1];
//			}
//
//			count_of_contacts--;
//			contactFound = true;
//		
//		if (contactFound)
//		{
//			cout << "Contact deleted successfully\n";
//		}
//		else
//		{
//			cout << "Contact not found\n";
//		}
//	
//	//for (int i = 0; i < count_of_contacts; i++)
//	//{
//	//	list_of_contacts[i] = *(list_of_contacts + i + 1)->copy_contact();// data pushback
//	//}
//
//}

void Group::RemovecontactFromgroup(int choice)
{
	bool contactFound = false;

	if (choice >= 0 && choice < count_of_contacts)
	{
		for (int j = choice; j < count_of_contacts - 1; j++)
		{
			ContactId[j] = ContactId[j + 1];
		}

		count_of_contacts--;
		contactFound = true;
	}

	if (contactFound)
	{
		cout << "Contact deleted from Group successfully\n";
	}
	else
	{
		cout << "Contact not found\n";
	}

}

//void Group::RemovecontactsFromgroup()
//{
//
//}

void Group::RemovecontactsFromgroup(const int& id)
{
	bool contactFound = false;
	
	
	
		for (int j = 0; j < count_of_contacts ; j++)
		{
			if (ContactId[j]= id)
			{
				ContactId[j] = ContactId[j + 1];
	

				count_of_contacts--;
				contactFound = true;
			}
	
	
		}
	
		if (contactFound)
		{
			cout << "Contact deleted from Group successfully\n";
		}
		else
		{
			cout << "Contact not found in Group\n";
		}
}

void Group::ReplaceID(const int& source, const int& desid)
{
	for (int i = 0; i < count_of_contacts; i++)
	{
		if (ContactId[i] == source)
		{
			ContactId[i] = desid; //break;
		}
	}
}

//void Group::ReplaceID(const int& id)
//{
//	for (int i = 0; i < count_of_contacts; i++)
//	{
//		if (ContactId[i] == id)
//		{
//
//		}
//	}
//}

//void Group::RemovecontactsFromgroup(string const number)
//{
//	bool contactFound = false;
//
//
//
//	for (int j = 0; j < count_of_contacts ; j++)
//	{
//		if (list_of_contacts[j].getm_num() == number)
//		{
//			list_of_contacts[j] = list_of_contacts[j + 1];
//			count_of_contacts--;
//			contactFound = true;
//		}
//
//
//
//	}
//
//	if (contactFound)
//	{
//		cout << "Contact deleted from Group successfully\n";
//	}
//	else
//	{
//		cout << "Contact not found in Group\n";
//	}
//}
//string Group::ShowcontactinGroup(Contact& contact)
//{
//	// can be made in
//	for (int i = 0; i < count_of_contacts; i++)
//	{
//		if (list_of_contacts[i] == contact)
//		{
//			return group_name;
//		}
//	}
//
//}

//void Group::PrintContactsofGroup()
//{
//	for (int i = 0; i < count_of_contacts; i++)
//	{
//		if (list_of_contacts[i].getf_name() != "")
//		{
//			cout << i + 1 << " First Name " << list_of_contacts[i].getf_name()
//				<< " Last Name " << list_of_contacts[i].getl_name()
//				<< " Mobile Number " << list_of_contacts[i].getm_num()
//				<< " Email Address " << list_of_contacts[i].gete_add() << endl;
//
//			//Address::print_address;
//			list_of_contacts[i].getaddress()->print_address(); cout << endl;
//
//		}
//
//	}
//}
//
