#pragma once
#include <string>
#include <vector>
#include "Address.h"
#include "REProperty.h"

class RealEstate {
private:
    std::string City, Street;                           // ����� � ����� ��� ����������
    std::string TypeApartament;                         // ��� ��������
    int NumberAdsCreated;                               // ���������� ��������� ���������� ��� �� ��������
    int CountRooms;                                     // ���������� ������
    int PropertyNumber;                                 // ����� �������������
    std::string SellOrBuy;                              // �������� ��� �������
    int WhatPrice;                                      // ���� ��� ����������
public:
    int* adLimit, tmpLimit;
    int saveAdLimit;                                    // ��� ��������� ������������

    Address addresses[6];                               // ������ ��������
    std::vector<RealEstateProperty> enteredProperties;

    RealEstate();

    void chackBrokerOrUser();                                               // ��� ��������� ������������ ������/��. ������������

    void BoardMenu();                                                       // ���� ����� �����������

    void postNewProperty();                                                 // (���������� ������ ��������):

    void showStreetsInCity(const std::string& selectedCity);                // ��� ������ � ������ ���� ������� ����������� � ������

    void removeProperty();                                                  // (������� ����������)

    void printEnteredProperties();                                          // (����������� ��� ������)

    void printAllProperties2();                                             // (���������� ��� ������, �������������� �������������)

    void propertySearchParameter();                                         // (����� �������� �� ����������)

    void StartProgram();                                                    // ������ ���������

    int ConverToInt(char* inputUser);
};
