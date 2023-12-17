#include "RealEstate.h"
#include <iostream>
#include "start_Menu.h"
#include "Address.h"
#include "REProperty.h"
#include "personal_Data.h"
#include "fun_console.h"
#include "ASDInput.h"


RealEstate::RealEstate() {
    adLimit = new int[2];
    saveAdLimit = NumberAdsCreated = PropertyNumber = WhatPrice = tmpLimit = 0;
    Street = City = TypeApartament = SellOrBuy = "";
    // ������� ������� � ������� ��������
    addresses[0] = Address("������", "�������");
    addresses[1] = Address("���-������", "����-����");
    addresses[2] = Address("���-������", "����-����");
    addresses[3] = Address("���-������", "���������");
    addresses[4] = Address("���-������", "�������");
    addresses[5] = Address("������", "���������");
}


void RealEstate::chackBrokerOrUser() {
    cls();

    std::cout << "��� �� ���������?\n";
    std::cout << "\n1. ������� ������������ (����� 3 ���������)";
    std::cout << "\n2. ������ (����� 10 ���������)\n\n";

    ASD::Input who(1);
    std::cout << "�������� ����� -> ";
    who.inputOnlyNumbers();
    int choice = ConverToInt(who.get());

    if (choice == 1) { adLimit[0] = 3; adLimit[1] = 0; }
    if (choice == 2) { adLimit[1] = 10; adLimit[0] = 0; }
}


int RealEstate::ConverToInt(char* inputUser) { 
    return atoi(inputUser); 
}


void RealEstate::BoardMenu() {
    cls();
    Menu menuBoard;
    menuBoard.MenuBoardAtCabinet();
}


void RealEstate::postNewProperty() {
    cls();

    // �������� ������� �������� ����������
    if (saveAdLimit == 0) {
        SetColor(Red, Black);
        std::cout << "\n������ - �� �������� ������ ����������!";
        SetColor(White, Black);
    }
    else {
        bool correctlyAdress = false;
        while (!correctlyAdress && saveAdLimit > 0) {
            cls();
            std::cout << "������ ������� ���� � �������:";

            int coordY = 2;
            for (const auto& address : addresses) {
                GotoXY(0, coordY);
                SetColor(5, Black);
                std::cout << "�����\t";
                SetColor(White, Black);
                std::cout << address.city;
                GotoXY(20, coordY);
                SetColor(5, Black);
                std::cout << "�����\t";
                SetColor(White, Black);
                std::cout << address.street;
                coordY++;
            }


            std::string selectedCity, selectedStreet;
            std::cout << "\n\n\n������� �������� ������ �� ������: ";
            std::cin >> selectedCity;

            // ���������, ���� �� ����� ����� � ������
            bool cityFound = false;
            for (const auto& address : addresses) {
                if (address.city == selectedCity) {
                    cityFound = true;
                    City = selectedCity;
                    break;
                }
            }

            if (cityFound) {
                showStreetsInCity(selectedCity);

                std::cout << "\n������� �������� ����� �� ������: ";
                std::cin >> selectedStreet;

                // ���������, ���� �� ����� ����� � ������
                bool cityFound = false;
                for (const auto& address : addresses) {
                    if (address.street == selectedStreet) {
                        cityFound = true;
                        Street = selectedStreet;
                        break;
                    }
                }

                if (cityFound) {
                    saveAdLimit--;
                    correctlyAdress = true;
                }
                else {
                    SetColor(Red, Black);
                    std::cout << "\n����� �� ������� � ������.";
                    SetColor(White, Black);
                    _getch();
                }
            }
            else {
                SetColor(Red, Black);
                std::cout << "\n����� �� ������ � ������.";
                SetColor(White, Black);
                _getch();
            }
        }

        std::cout << "\n\n1. ����������� �������� � ��������������� ����\n";
        std::cout << "2. ��������-�������� � ��������������� ����\n";
        std::cout << "3. ������� ���\n";
        std::cout << "����� ��� �������������: ";

        ASD::Input TypeHouse(1);
        TypeHouse.inputOnlyNumbers();

        if (ConverToInt(TypeHouse.get()) == 1) { TypeApartament = "����������� �������� � ��������������� ����"; }
        else if (ConverToInt(TypeHouse.get()) == 2) { TypeApartament = "��������-�������� � ��������������� ����"; }
        else if (ConverToInt(TypeHouse.get()) == 3) { TypeApartament = "������� ���"; }

        std::cout << "\n\n������� ������: ";
        ASD::Input countRoom(2);
        countRoom.inputOnlyNumbers();
        CountRooms = ConverToInt(countRoom.get());

        std::cout << "\n\n����� ����� �������������: ";
        ASD::Input NumberProp(10);
        NumberProp.inputOnlyNumbers();
        PropertyNumber = ConverToInt(NumberProp.get());

        std::cout << "\n\n(1 - �������)/(2 - �������): ";
        ASD::Input buyOrSell(1);
        buyOrSell.inputOnlyNumbers();

        if (ConverToInt(buyOrSell.get()) == 1) { SellOrBuy = "�������"; }
        else if (ConverToInt(buyOrSell.get()) == 2) { SellOrBuy = "�������"; }

        std::cout << "\n\n��������������� ���� �������/������� (� $): ";
        ASD::Input price(5);
        price.inputOnlyNumbers();
        WhatPrice = ConverToInt(price.get());

        NumberAdsCreated++;
        enteredProperties.push_back(RealEstateProperty(NumberAdsCreated, Address(Street, City), TypeApartament, CountRooms, PropertyNumber, SellOrBuy, WhatPrice));
    }
}


void RealEstate::showStreetsInCity(const std::string& selectedCity) {
    std::string tmp = "";
    int index = 1;
    // ������� ����� ���������� ������
    std::cout << "\n������ ���� � ������:" << selectedCity << ":\n";
    for (const auto& address : addresses) {
        if (address.city == selectedCity) {
            if (tmp != address.street) {
                tmp = address.street;
                std::cout << index << ". " << address.street << "\n";
                index++;
            }
            else {
                break;
            }
        }
    }
}


void RealEstate::removeProperty() {
    cls();

    if (enteredProperties.empty()) {
        SetColor(Red, Black);
        std::cout << "������ - � ��� ��� ��� ���������� ��� ��������!";
        SetColor(White, Black);
    }
    else {
        // ����� ���� ���������� ����� ���������
        printEnteredProperties();

        SetColor(Green, Black);
        std::cout << "\n\n������� ����� ����������, ������� �� ������ �������: ";
        SetColor(White, Black);

        ASD::Input propertyIndex(1);
        propertyIndex.inputOnlyNumbers();
        int index = ConverToInt(propertyIndex.get());

        if (index >= 1 && index <= (int)(enteredProperties.size())) {
            enteredProperties.erase(enteredProperties.begin() + index - 1);

            SetColor(Green, Black);
            std::cout << "\n�������� ������� �������.\n";
            SetColor(White, Black);
            saveAdLimit++;
        }
        else {
            SetColor(Red, Black);
            std::cout << "\n�������� ����� ��������.\n";
            SetColor(White, Black);
        }


    }
}


void RealEstate::printEnteredProperties() {
    std::cout << "��� ����������:";
    for (const auto& property : enteredProperties) {
        std::cout << "\n\n�����:                      " << property.NumberAnnouncement
            << "\n�����:                      " << property.address.city
            << "\n�����:                      " << property.address.street
            << "\n��� ������������:           " << property.typeApartment
            << "\n���������� ������:          " << property.CountRooms
            << "\n����� �������������:        " << property.PropertyNumber
            << "\n�������/�������:            " << property.SellOrBuy
            << "\n���� �������/������� (� $): " << property.WhatPrice;
    }
}


void RealEstate::printAllProperties2() {
    printEnteredProperties();
}


void RealEstate::propertySearchParameter() {
    cls();

    std::string inputRentOrSale, inputType;
    int countRooms = 0, minMaxPrice = 0;
    std::cout << "����� ���������� �� ���������:\n";

    ASD::Input InputRentOrSale(1);
    std::cout << "\n(1 - �������)/(2. ���������) -> ";
    InputRentOrSale.inputOnlyNumbers();

    if (ConverToInt(InputRentOrSale.get()) == 1) { inputRentOrSale = "�������"; }
    else if (ConverToInt(InputRentOrSale.get()) == 2) { inputRentOrSale = "�������"; }

    ASD::Input InputType(1);
    std::cout << "\n\n1. ����������� �������� � ��������������� ����";
    std::cout << "\n2. ��������-�������� � ��������������� ����";
    std::cout << "\n3. ������� ���";
    std::cout << "\n\n����� ��� ������������ �� ������ -> ";
    InputType.inputOnlyNumbers();

    if (ConverToInt(InputType.get()) == 1) { inputType = "����������� �������� � ��������������� ����"; }
    else if (ConverToInt(InputType.get()) == 2) { inputType = "��������-�������� � ��������������� ����"; }
    else if (ConverToInt(InputType.get()) == 3) { inputType = "������� ���"; }

    ASD::Input CountRooms(2);
    std::cout << "\n\n����� �������� ���������� ������ -> ";
    CountRooms.inputOnlyNumbers();
    countRooms = ConverToInt(CountRooms.get());

    ASD::Input MinMaxPrice(10);
    std::cout << "\n\n����� �������� ������� ��������(����������� � ������������) -> ";
    MinMaxPrice.inputOnlyNumbers();
    minMaxPrice = ConverToInt(MinMaxPrice.get());


    std::cout << "\n\n���� ��������:";
    std::cout << "\n������� ��� ���������: " << inputRentOrSale;
    std::cout << "\n��� ������������:      " << inputType;
    std::cout << "\n���-�� ������          " << countRooms;
    std::cout << "\n������� ��������:      " << minMaxPrice;


    int index = 0;
    bool isAdFound = false;

    for (const auto& property : enteredProperties) {
        if ((property.SellOrBuy == inputRentOrSale) && property.typeApartment == inputType &&
            (property.WhatPrice == minMaxPrice) && (property.CountRooms == countRooms)) {
            SetColor(Green, Black);
            std::cout << "\n\n����� - ";
            SetColor(7, Black);
            std::cout << "�� ��������� �������:";

            std::cout << "\n\n�����:                      " << property.NumberAnnouncement
                << "\n�����:                      " << property.address.city
                << "\n�����:                      " << property.address.street
                << "\n��� ������������:           " << property.typeApartment
                << "\n���������� ������:          " << property.CountRooms
                << "\n����� �������������:        " << property.PropertyNumber
                << "\n�������/�������:            " << property.SellOrBuy
                << "\n���� �������/������� (� $): " << property.WhatPrice;
        }
    }
}


void RealEstate::StartProgram() {
    Menu start;
    start.mainMenu();
}

