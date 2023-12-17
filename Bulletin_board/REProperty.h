#pragma once
#include "Address.h"

class RealEstateProperty {
public:
    int NumberAnnouncement;
    Address address;
    std::string typeApartment;
    int CountRooms;
    int PropertyNumber;
    std::string SellOrBuy;
    int WhatPrice;

    RealEstateProperty(const int Number, const Address& address, const std::string& typeApartment, const int rooms, const int PropertyNumber, const std::string& SellOrBuy, const int WhatPrice)
        : NumberAnnouncement(Number), address(address), typeApartment(typeApartment), CountRooms(rooms), PropertyNumber(PropertyNumber), SellOrBuy(SellOrBuy), WhatPrice(WhatPrice) {}
};