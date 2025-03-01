#pragma once
#include "Address.h"
#include <iostream>
#include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string mobile_number;
    std::string email_address;
    Address* address;

public:
    Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
    Contact();
    ~Contact();
    // Getters and setters
    bool setf_name(const std::string& fname);
    std::string getf_name() const;
    bool setl_name(const std::string& lname);
    std::string getl_name() const;
    bool setm_num(const std::string& mnum);
    std::string getm_num() const;
    std::string gete_add() const;
    bool sete_add(const std::string& email);
    void setaddress(Address* myaddress);
    Address* getaddress() const;

    // Other member functions
    bool equals(Contact contact);
    Contact* copy_contact();

    // Overloaded input operator
    friend std::istream& operator>>(std::istream& input, Contact& obj);
    friend std::ostream& operator<<(std::ostream& output, Contact& obj);
    bool operator== (const Contact& other) const;

};