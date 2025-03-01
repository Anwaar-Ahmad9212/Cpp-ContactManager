
#include "Address.h"
#include <iostream>

Address::Address(std::string house, std::string street, std::string city, std::string country) :
    house(house), street(street), city(city), country(country) {}

Address::Address() {}

Address::~Address()
{
    
}

void Address::sethouse(const std::string& h) {
    house = h;
}

bool Address::setstreet(const std::string& s) {
    //street = s;
    if (!s.empty()) {
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) // Check if character is not a letter
                flag = false;
        }
        if (flag == false)
        {
            std::cout << "Error! Please enter a Street\n";
            return false;
        }
        else {
            street = s;
            return true;
        }
    }
}

bool Address::setcity(const std::string& c) {
    //city = c;
    if (!c.empty()) {
        bool flag = true;
        for (int i = 0; i < c.length(); i++) {
            if (!isalpha(c[i])) // Check if character is not a letter
                flag = false;
        }
        if (flag == false)
        {
            std::cout << "Error! Please enter a City\n";
            return false;
        }
        else {
            city = c;
            return true;
        }
    }
}

bool Address::setcountry(const std::string& co) {
   // country = co;
    if (!co.empty()) {
        bool flag = true;
        for (int i = 0; i <co.length(); i++) {
            if (!isalpha(co[i])) // Check if character is not a letter
                flag = false;
        }
        if (flag == false)
        {
            std::cout << "Error! Please enter a Name\n";
            return false;
        }
        else {
            country =co;
            return true;
        }
    }
}

std::string Address::gethouse() const {
    return house;
}

std::string Address::getstreet() const {
    return street;
}

std::string Address::getcity() const {
    return city;
}

std::string Address::getcountry() const {
    return country;
}

void Address::print_address() {
    std::cout << house << ", " << street << ", " << city << ", " << country << std::endl;
}

Address Address::copy_address() {
    return Address(house, street, city, country);
}


bool Address::operator==(const Address& address)
{
    return (house == address.house &&
        street == address.street &&
        city == address.city &&
        country == address.country);
   
}

bool Address::equals(const Address& address)
{
    if ((this->copy_address()) == (address))
    {
        return true;
    }
}



std::istream& operator>>(std::istream& input, Address*& objadd) {
    objadd = new Address;
    std::cout << "Enter House Number: ";
    getline(input, objadd->house);

    std::cout << "Enter Street Number: ";
    std::string street;
    getline(input, street);
    while (!objadd->setstreet(street)) {
        std::cout << "Enter street again: ";
        getline(input, street);
    }

    std::cout << "Enter City: ";
    std::string city;
    getline(input, city);
    while (!objadd->setcity(city)) {
        std::cout << "Enter city again: ";
        getline(input, city);
    }

    std::cout << "Enter Country: ";
    std::string country;
    getline(input, country);
    while (!objadd->setcountry(country)) {
        std::cout << "Enter country again: ";
        getline(input, country);
    }
    std::cout << "\n";
    return input;
}
