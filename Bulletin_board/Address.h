#pragma once
#include <string>

class RealEstate;

class Address {
public:
    std::string street;
    std::string city;

    Address() { }
    Address(const std::string& street, const std::string& city) : street(street), city(city) {}
};

