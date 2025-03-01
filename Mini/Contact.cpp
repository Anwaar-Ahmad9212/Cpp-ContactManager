
#include "Contact.h"

Contact::Contact(std::string fname, std::string lname, std::string num, std::string email, Address* address) :
	first_name(fname), last_name(lname), mobile_number(num), email_address(email), address(address) {}

Contact::Contact() {}

Contact::~Contact()
{

	//	delete address;
}



bool Contact::setf_name(const std::string& fname) {
	if (!fname.empty()) 
	{
		bool flag = true;
		for (int i = 0; i < fname.length(); i++) {
			if (!isalpha(fname[i])) // Check if character is not a digit
				flag = false;

		}
		if (flag == true)
		{
			std::cout << "Error! Please enter a Name\n";

			return false;
		}
		else {
			first_name = fname;
			return true;
		}
		//first_name = fname;
	}
}

std::string Contact::getf_name() const {
	return first_name;
}

bool Contact::setl_name(const std::string& lname)
{

	bool flag = true;
	for (int i = 0; i < lname.length(); i++) {
		if (!isalpha(lname[i])) // Check if character is not a letter
			flag = false;
	}
	if (flag == false)
	{
		std::cout << "Error! Please enter a Name\n";
		return false;
	}
	else {
		last_name = lname;
		return true;
	}
}



std::string Contact::getl_name() const {
	return last_name;
}

bool Contact::setm_num(const std::string& mnum) {
	bool flag = true;
	for (int i = 0; i < mnum.length(); i++) {
		if (!isdigit(mnum[i])) // Check if character is not a digit
			flag = false;
		
	}
	
	if (mnum.length() != 11 || flag == false) {
		std::cout << "Error! Please enter a valid phone number\n";
		return false;
	}
	else {
		mobile_number = mnum;
		return true;
	}
}

std::string Contact::getm_num() const {
	return mobile_number;
}

std::string Contact::gete_add() const {
	return email_address;
}

bool Contact::sete_add(const std::string& email)
{
	bool flag = false;
	if (!email.empty())
	{
		for (int i = 0; i < email.length(); i++)
		{
			if (email[i] == '@')
			{
				flag = true;
				email_address = email;
				return true;
			}
		}
		
			
	}
	return flag;
}


void Contact::setaddress(Address* myaddress) {
	address = myaddress;
}

Address* Contact::getaddress() const {
	return address;
}

bool Contact::equals(Contact contact) {
	if (first_name == contact.getf_name() &&
		last_name == contact.getl_name() &&
		mobile_number == contact.getm_num() &&
		email_address == contact.gete_add()) {
		return true;
	}
	else {
		return false;
	}
}

Contact* Contact::copy_contact() {
	Contact* NewContact = new Contact();
	NewContact->first_name = first_name;
	NewContact->last_name = last_name;
	NewContact->mobile_number = mobile_number;
	NewContact->email_address = email_address;
	NewContact->address = address;
	return NewContact;
}

std::istream& operator>>(std::istream& input, Contact& obj)
{
	std::cout << "\n";
	std::cout << "Enter First name of Contact: ";
	std::string fname;
	getline(input, fname);
	while (!obj.setf_name(fname)) {
		std::cout << "Enter Name again: ";
		getline(input, fname);
	}

	std::cout << "Enter Last name of Contact: ";
	std::string lname;
	getline(input, lname);
	while (!obj.setl_name(lname)) {
		std::cout << "Enter Name again: ";
		getline(input, lname);
	}

	std::cout << "Enter Mobile Number of Contact: ";
	std::string mnum;
	getline(input, mnum);
	while (!obj.setm_num(mnum)) {
		std::cout << "Enter Number again: ";
		getline(input, mnum);
	}

	std::cout << "Enter Email Address of Contact: ";
	std::string email_address;
	getline(input, email_address);
	while (!obj.sete_add(email_address)) {
		std::cout << "Enter Email again: ";
		getline(input, email_address);
	}
	//getline(input, obj.email_address);

	std::cout << "\n";
	std::cout << "Enter Address of Contact\n";

	input >> obj.address;  // Assuming Address input operator is defined
	return input;
}
bool Contact::operator==(const Contact& other) const
{
	return (first_name == other.first_name &&
		last_name == other.last_name &&
		mobile_number == other.mobile_number &&
		email_address == other.email_address &&
		*address == *(other.address)); // Comparing contents of Address objects
}




std::ostream& operator<<(std::ostream& output, Contact& obj)
{
	//std::cout << "\n";
	std::cout << "First name of Contact: ";
	output << obj.getf_name() << std::endl;

	std::cout << "Last name of Contact: ";
	output << obj.getl_name() << std::endl;

	std::cout << "Mobile Number of Contact: ";
	output << obj.getm_num() << std::endl;



	std::cout << "Email Address of Contact: ";
	output << obj.gete_add() << std::endl;
	std::cout << "\n";
	std::cout << "Address of Contact\n";
	obj.getaddress()->print_address();
	return output;
}