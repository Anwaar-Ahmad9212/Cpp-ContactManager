

#include "ContactsBook.h"
#include"Contact.h"
//#include"ListGeneric.h"
#include <fstream>
#include <iostream>
using namespace std;

void ContactsBook::add_contact(const Contact& contact)
{
	if (contacts_count < size_of_contacts)
	{
		contacts_list[contacts_count++] = contact;

	}
	else
	{
		resize_list();
		add_contact(contact);
	}


	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
}

int ContactsBook::total_contacts()
{
	return contacts_count;
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
}


//void ContactsBook::DisplayUsingID(int temp)
//{
//cout<<	contacts_list[temp];
//}

bool ContactsBook::full()
{

	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	else
	{
		return false;
	}
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	//return false;
}

void ContactsBook::resize_list()
{
	int size = 2 * contacts_count;
	Contact* NewArray;
	NewArray = new Contact[size];

	for (int i = 0; i < contacts_count; i++)
	{
		*(NewArray + i) = *(contacts_list + i)->copy_contact();
	}

	//delete[]contacts_list;

	contacts_list = NewArray;
	this->size_of_contacts = size;


	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	Contact* NewContact = nullptr; // Initialize to nullptr
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getf_name() == first_name && contacts_list[i].getl_name() == last_name)
		{
			NewContact = contacts_list[i].copy_contact();
			break; // Found the contact, no need to continue searching
		}
		else
		{
			cout << "Contact not found\n";
		}
	}
	// Return the found contact or nullptr if not found
	return NewContact;
}


Contact* ContactsBook::search_contact(std::string phone, SearchObjects& S1)
{
	Contact* NewContact = NULL;
	//SearchObjects S1(size_of_contacts);
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getm_num() == phone)
		{
			NewContact = contacts_list[i].copy_contact();
			count[i]++;
			Count++;
			HistoryObjects H1(phone);

			S1.addhistory(H1);
			break;
		}
		else
		{
			cout << "Contact not found\n";
		}
	}
	/*
	*	Remove this return nullptr; before writing your code
	*/
	return NewContact;
}


Contact* ContactsBook::search_contact(const Address& address)
{
	Contact* NewContact = nullptr;
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getaddress() == &address)
		{
			NewContact = contacts_list[i].copy_contact();
		}
		else
		{
			cout << "Contact not found\n";
		}
	}
	/*
	*	Remove this return nullptr; before writing your code
	*/
	return NewContact;
}

ContactsBook::~ContactsBook()
{
	delete[]contacts_list;
}

ContactsBook::ContactsBook(int size_of_list)
{

	contacts_list = new Contact[size_of_list];
	count = new int[size_of_list];
	contacts_count = 0;
	Count = 0;
	size_of_contacts = size_of_list;
	for (int i = 0; i < size_of_list; i++)
	{
		count[i] = 0;
	}
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
}

void ContactsBook::ViewContact()
{
	print();
	cout << "Enter Contact to View its Details" << endl;
	int choice;
	cin >> choice;

	if (choice >= 1 && choice <= contacts_count)
	{
		cout << contacts_list[choice - 1]<<endl;
	}
	else { cout << "Wrong Choice Contact Does not Exists" << endl; }
}

void ContactsBook::print_contacts_sorted(std::string choice)
{
	Contact* NewContact = new Contact[size_of_contacts]; // Allocate array of Contact objects
	Contact* Unsorted = new Contact[size_of_contacts];
	for (int i = 0; i < size_of_contacts; i++)
	{
		// Copy each contact from contacts_list to NewContact using copy_contact()
		*(NewContact + i) = contacts_list[i];
		*(Unsorted + i) = contacts_list[i];
	}

	// Sort the contacts based on the provided choice
	sort_contacts_list(NewContact, choice);

	// Print the sorted contacts
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (NewContact[i].getf_name() != "" || NewContact[i].getl_name() != "")
		{
			std::cout << "Name: " << NewContact[i].getf_name() << " " << std::endl
				<< "Last Name: " << NewContact[i].getl_name() << std::endl
				<< "Number: " << NewContact[i].getm_num() << std::endl
				<< "Email: " << NewContact[i].gete_add() << std::endl;

			//Address::print_address;
			cout << "Address:" << endl;
			NewContact[i].getaddress()->print_address();
			cout << endl;
		}
	}

	// Restore the original order of contacts in contacts_list
	for (int i = 0; i < size_of_contacts; i++)
	{
		*(contacts_list + i) = *(Unsorted + i);
	}

	// Don't forget to deallocate memory for dynamic arrays
	delete[] NewContact;
	delete[] Unsorted;
}

void ContactsBook::sort_contacts_list(Contact* contacts_list, std::string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	int i, j, min_idx;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < size_of_contacts - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < size_of_contacts; j++)
		{
			if ((choice == "1") && (contacts_list[j].getf_name() < contacts_list[min_idx].getf_name()) ||
				(choice == "2") && (contacts_list[j].getl_name() < contacts_list[min_idx].getl_name()))
			{
				min_idx = j;
			}


		}

		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
		{
			Contact temp_data = contacts_list[min_idx];
			contacts_list[min_idx] = contacts_list[i];
			contacts_list[i] = temp_data;
		}

	}





}

void ContactsBook::merge_duplicates()
{
	int new_contacts_count = contacts_count;
	int count = 0;
	for (int i = 0; i < new_contacts_count; ++i)
	{
		for (int j = i + 1; j < new_contacts_count;)
		{
			if (contacts_list[i] == contacts_list[j])
			{

				for (int k = j; k < new_contacts_count - 1; ++k)
				{
					contacts_list[k] = contacts_list[k + 1];
				}

				--new_contacts_count;
				++count;

				
				for (int NCount = 0; NCount < countofgroups; NCount++)
				{
					if (Grouplist != nullptr) 
					{
						Grouplist[NCount].RemovecontactsFromgroup(i);
					}
				}
			}
			else
			{
				++j;
			}
		}
		cout << endl;
		if (count > 0)
		{
			std::cout << "Contacts Merged with Same Data are: " << std::endl << "Name " << contacts_list[i].getf_name()
				<< std::endl << "Number " << contacts_list[i].getm_num() << endl;
		}
	}

	std::cout << "Total numbers of contacts merged: " << count << std::endl;
	contacts_count = new_contacts_count;
}


// Implement this function that finds and merges all the duplicates
// Duplicate means exact equal
// If there are three copies of a Contact, then only one should remain
// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
// 9 contacts will be left; and the this->contacts_count of list will 9
// At the end display contacts merged, and count of merged contacts



void ContactsBook::load_from_file(std::string file_name)
{


	ifstream infile(file_name);
	if (!infile.is_open())
	{
		cout << "File not found or cannot be opened." << endl;
		return;
	}

	//infile >> contacts_count;
	//delete[] contacts_list;
//infile >> size_of_contacts;
	int newcountfromfile;
	infile >> newcountfromfile;
	//contacts_count += newcountfromfile;
	//	infile >> contacts_count;

	int oldcount = contacts_count;
	contacts_count = 0;

	if (contacts_list != NULL)
		delete[] contacts_list;

	//	contacts_list = new Contact[contacts_count];
	//contacts_list = new Contact[contacts_count];
	//contacts_list = new Contact[oldcount + newcountfromfile];//Array initialized to some extra to not go to resize list;
	 //or
	  contacts_list = new Contact[newcountfromfile];//Array initialized to full extent as it got from file;


	for (int i = 0; i < newcountfromfile; i++)
	{
		std::string first_name, last_name, mobile_number, email_address;
		std::string house, street, city, country;


		//infile >> first_name >> last_name >> mobile_number >> email_address;


		//infile >> house >> street >> city >> country;
		
		getline(infile, first_name, ',');
		first_name.erase(0, 1);
		getline(infile, last_name, ',');
		getline(infile, mobile_number, ',');
		infile >> email_address;
		
		getline(infile, house, ',');
		house.erase(0, 1);

		getline(infile, street, ',');
		getline(infile, city, ',');
		infile >> country;

		Contact contact;
		contact.setf_name(first_name);
		contact.setl_name(last_name);
		contact.setm_num(mobile_number);
		contact.sete_add(email_address);

		// Create a new Address object and set it in the Contact object
		Address* new_address = new Address(house, street, city, country);
		contact.setaddress(new_address);

		// Add the Contact object to the list using add_contact function
		this->add_contact(contact);
	}

	infile.close();


}


/*
*	Read contacts back from file in the same format
*	Read the contacts_count, and run a loop for this contacts_count and read the
*	contacts in the same format as you stored
*	Add them to contact book (this.add_contact function can be used)
*	Finally, close the file
*/




void ContactsBook::save_to_file(std::string file_name)
{

	ofstream outfile;

	outfile.open(file_name);
	if (!outfile.is_open())
	{
		cout << "File not exists\n";
	}
	else
	{
		outfile << contacts_count << endl;

		for (int i = 0; i < contacts_count; i++)
		{
			outfile << contacts_list[i].getf_name() << ",";
			outfile << contacts_list[i].getl_name() << ",";
			outfile << contacts_list[i].getm_num() << ",";
			outfile << contacts_list[i].gete_add() << endl;
			outfile << contacts_list[i].getaddress()->gethouse() << ",";
			outfile << contacts_list[i].getaddress()->getstreet() << ",";
			outfile << contacts_list[i].getaddress()->getcity() << ",";
			outfile << contacts_list[i].getaddress()->getcountry() << endl;

		}

	}

	/*



	*/




	outfile.close();
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}


void ContactsBook::PrintContacts()
{
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getf_name() != "")
		{
			cout << "First Name: " << contacts_list[i].getf_name() << '|' << "Last Name: " << contacts_list[i].getl_name() << '|'
				<< "Mobile Number: " << contacts_list[i].getm_num() << '|'
				<< "Email Address: " << contacts_list[i].gete_add() << '|' << endl;

			//Address::print_address;
			contacts_list[i].getaddress()->print_address(); cout << endl;
		}
	}
}

//void ContactsBook::PrintBasicContacts()
//{
//	for (int i = 0; i < contacts_count; i++)
//	{
//		if (contacts_list[i].getf_name() != "")
//		{
//			cout << "First Name: " << contacts_list[i].getf_name() << '|' << "Last Name: " << contacts_list[i].getl_name() << '|'
//				<< "Mobile Number: " << contacts_list[i].getm_num() << '|' << endl;
//		}
//	}
//}

void ContactsBook::print()
{
	for (int i = 0; i < contacts_count; i++)
	{
		cout << i + 1 << ": ";
		cout << contacts_list[i].getf_name() << " " << contacts_list[i].getl_name() << endl << contacts_list[i].getm_num() << endl;

	}


}
void ContactsBook::updatecontact()
{
	print();
	cout << "Enter the Contact number to update\n";
	string num;
	cin >> num;

	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].getm_num() == num)
		{
			int count = contacts_count;
			contacts_count = i;

			Contact newobj;
			cin >> newobj;

			add_contact(newobj);
			contacts_count = count;
			break;
		}
		else
		{
			cout << "Contact not found\n";
		}
	}
}



void ContactsBook::deletecontact(int choice)
{
	bool contactFound = false;

	if (choice >= 0 && choice < contacts_count)
	{
		for (int j = choice; j < contacts_count - 1; j++)
		{
			contacts_list[j] = contacts_list[j + 1];
		}

		contacts_count--;
		contactFound = true;
	}

	if (contactFound)
	{
		cout << "Contact deleted successfully\n";
	}
	else
	{
		cout << "Contact not found\n";
	}
	
	for (int j = 0; j < contacts_count ; j++)
	{
		if (Grouplist != nullptr)

		{
			Grouplist[j].RemovecontactsFromgroup(choice);
		}
	}
}
//void ContactsBook::Groupmaker()
//{
//	string temp;
//	cout << "How many groups do you want to create" << endl;
//	int n; cin >> n;
//	Grouplist = new Group[n];
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << "Enter name of Group " << i + 1 << '\n';
//		getline(cin, temp);
//		Grouplist[i] = Group(temp);
//		countofgroups++;
//	}
//
//}


void ContactsBook::Groupmaker()
{
	if (contacts_list == nullptr) { cout << "Add some Contacts in Order to Proceed" << endl; return; }
			string temp;
			cout << "How many groups do you want to create" << endl;
			cin >> sizeofgroups;
			cin.ignore();
			Grouplist = new Group[sizeofgroups];

			for (int i = 0; i < sizeofgroups; i++)
			{
				cout << "Enter name of Group " << i + 1 << '\n';
				getline(cin, temp);
				Grouplist[countofgroups++] = Group(temp);

			}
		
	
}

void ContactsBook::GroupAdder()
{
	if (Grouplist != nullptr) { cout << "No Group was Already Made" << endl; return; }
	cout << "How many more Groups do you want to Add ?" << endl;
	int choice; 
	cin >> choice;
	if (countofgroups > sizeofgroups)
	{
		Groupresize();
	}

	cin.ignore();
	string temp;
	for (int i = 0; i < choice; i++)
	{
		cout << i + 1 << " Enter Name of Group ";
		getline(cin, temp);
		if (countofgroups >= sizeofgroups)
		{ Groupresize(); }
		Grouplist[countofgroups++] = Group(temp);

		
		
	}



}

void ContactsBook::Groupresize()
{
	int size = 2 * countofgroups;
Group *NewGroup = nullptr;
	NewGroup = new Group[size];

	for (int i = 0; i < countofgroups; i++)
	{
		*(NewGroup + i) = *(Grouplist + i);
	}

	delete[]Grouplist;
	 
	Grouplist = new Group[size];

	for (int i = 0; i < size; i++)
	{
		*(Grouplist + i)= *(NewGroup+i);

	}
	
	delete []NewGroup;
	//Grouplist = NewGroup;
this->sizeofgroups = size;
}

void ContactsBook::PrintGroupNames()
{
	for (int i = 0; i < countofgroups; i++)
	{
		if (Grouplist != nullptr) 
		{

			cout << i + 1 << " Group " << Grouplist[i].getname() << endl;
		}
	}
}

void ContactsBook::AddContactstoGroupuser()
{
	PrintGroupNames();
	int choice=0;
	cout << "Enter the Group index you want to add contact" << endl;
	cin >> choice;
	while (choice < 1 && choice > countofgroups)
	{
		cout << "Enter the Correct Group index you want to add contact" << endl;
		cin >> choice;
	}
	
	print();
	cout << "Enter the Contacts index you want to add in Group" << endl;
	int choiceofcontact; cin >> choiceofcontact;
	if (choiceofcontact >= 1 && choiceofcontact <= contacts_count )
	{
		Grouplist[choice - 1].Addcontactstogroup(choiceofcontact - 1);

	}
	else
	{
		cout << "Wrong Index of Contact Entered\n";
	}
}

void ContactsBook::deletecontactsfromgroup()
{
	PrintGroupNames();
	cout << "Enter the Group you want to remove contact from" << endl;
	int choice; cin >> choice;
	if (choice >= 1 && choice <= countofgroups)
	{
		PrintcontactsofGroup(choice - 1);
		cout << "Enter Contact do you want to delete " << endl;
		int choice2; cin >> choice2;
		Grouplist[choice - 1].RemovecontactFromgroup(choice2 - 1);

	}
}


	void ContactsBook::GroupDelete()
	{
		if (countofgroups == 0) {
			cout << "No groups exist to delete." << endl;
			return;
		}

		cout << "Available Groups:" << endl;
		PrintGroupNames();

		int choice;
		cout << "Enter the number of the group you want to delete: ";
		cin >> choice;

		if (choice < 1 || choice > countofgroups) {
			cout << "Invalid choice. No such group exists." << endl;
			return;
		}

		for (int i = choice - 1; i < countofgroups - 1; ++i) 
		{
			Grouplist[i] = Grouplist[i + 1];
		}

		--countofgroups;
		cout << "Group deleted successfully." << endl;
	}

	void ContactsBook::PrintcontactsofGroup(int choice)
	{
		if (choice >= 0 && choice < countofgroups) {
			int* temp = Grouplist[choice].getids();
			int CountofContacts = Grouplist[choice].getcountofcontacts();
			if (temp != nullptr)
			{

				for (int i = 0; i < CountofContacts; i++)
				{
					if (temp != nullptr)
					{
						cout << contacts_list[temp[i]] << endl;
					}
				}
			}
			else { cout << "Group Does not consists any contacts" << endl; }
		}
		else { cout << "Group not found" << endl; }
	}

	string ContactsBook::to_upper(const string& source)
	{
		
			string result = source;
			for (int i = 0; i < source.length(); i++)
			{
				result[i] = std::toupper(source[i]);
			}
			return result;
		
	}

	string ContactsBook::to_lower(const string& source)
	{
		
			string result = source;
			for (int i = 0; i < source.length(); i++)
			{
				result[i] = std::tolower(source[i]);
			}
			return result;
		
	}





void ContactsBook::Frequently()
{
	if (Count > 0)
	{
		// Initialize an array to store indexes corresponding to counts
		int maxIndex1 = 0, maxIndex2 = 0, maxIndex3 = 0, maxIndex4 = 0, maxIndex5 = 0;

		// Iterate through the count array to find the top five indexes
		for (int i = 1; i < Count; ++i) {
			if (count[i] > count[maxIndex1]) {
				maxIndex5 = maxIndex4;
				maxIndex4 = maxIndex3;
				maxIndex3 = maxIndex2;
				maxIndex2 = maxIndex1;
				maxIndex1 = i;
			}
			else if (count[i] > count[maxIndex2]) {
				maxIndex5 = maxIndex4;
				maxIndex4 = maxIndex3;
				maxIndex3 = maxIndex2;
				maxIndex2 = i;
			}
			else if (count[i] > count[maxIndex3]) {
				maxIndex5 = maxIndex4;
				maxIndex4 = maxIndex3;
				maxIndex3 = i;
			}
			else if (count[i] > count[maxIndex4]) {
				maxIndex5 = maxIndex4;
				maxIndex4 = i;
			}
			else if (count[i] > count[maxIndex5]) {
				maxIndex5 = i;
			}
		}

		// Now, maxIndex1 to maxIndex5 hold the indexes of the top five counts in the count array


		cout << contacts_list[maxIndex1] << endl;
		cout << contacts_list[maxIndex2] << endl;
		cout << contacts_list[maxIndex3] << endl;
		cout << contacts_list[maxIndex4] << endl;
		cout << contacts_list[maxIndex5] << endl;
	}
}
void ContactsBook::GenericSearch(string text , SearchObjects &S1)
{

	Contact* NewContact;
	NewContact = new Contact[size_of_contacts];
	int length = text.length();
	int found = 0;
	int countoffound = 0;
	int newindex = 0;
	int space = 0;

	
	string Uptext = to_upper(text);

	string Lowtext = to_lower(text);

	for (int i = 0; i < contacts_count; i++)
	{
		found = 0;
		newindex = 0;
		string all{};
		space = 0;

		all =
			contacts_list[i].getf_name() +
			contacts_list[i].getl_name() +
			contacts_list[i].getm_num() +
			contacts_list[i].gete_add()
			+ (contacts_list[i].getaddress()->gethouse())
			+ (contacts_list[i].getaddress()->getstreet())
			+ (contacts_list[i].getaddress()->getcity())
			+ (contacts_list[i].getaddress()->getcountry());

		for (int j = 0; j < all.length(); j++)
		{
			if (Uptext[newindex] == ' ' || Lowtext[newindex] == ' ') // Skip spaces
			{
				++newindex;		
				space++;
			}

				if (all[j] == Uptext[newindex] || all[j] == Lowtext[newindex])
				{
					found++;
					newindex++;

					count[i]++;
					Count++;
				}
			
			
		}
		if (found == (length-space) )
		{
			*(NewContact + countoffound++) = *(contacts_list + i)->copy_contact();
			// You can perform any further actions related to the found contact here
						
		}
		


	}


	for (int Lp = 0; Lp < countoffound; Lp++)
	{
		if (NewContact != nullptr)
		{
			cout << NewContact[Lp] << endl;
		}
	}
	
	HistoryObjects H1(text);
	S1.addhistory(H1);
	if (countoffound == 0) { cout << "Nothing found according to your search" << endl; }
}
