#pragma once
#include <iostream>
#include <string>
//#include "Contact.h"

class Address  {
private:
    std::string house;
    std::string street;
    std::string city;
    std::string country;

public:
    Address(std::string house, std::string street, std::string city, std::string country);
    Address();
    ~Address();
    // Getters and setters
    void sethouse(const std::string& h);
    bool setstreet(const std::string& s);
    bool setcity(const std::string& c);
    bool setcountry(const std::string& co);
    std::string gethouse() const;
    std::string getstreet() const;
    std::string getcity() const;
    std::string getcountry() const;

    // Other member functions
    void print_address();
    Address copy_address();

    // Overloaded input operator
    friend std::istream& operator>>(std::istream&, Address*&);

    // Comparison function
    bool operator ==(const Address& address);
    bool equals(const Address& address);
};
