#pragma once
#include <string>
#include <vector>
#include "Address.h"
#include "REProperty.h"

class RealEstate {
private:
    std::string City, Street;                           // Город и улица для обьявления
    std::string TypeApartament;                         // Тип квартиры
    int NumberAdsCreated;                               // Количество созданных обьявлений для их удаления
    int CountRooms;                                     // Количество комнат
    int PropertyNumber;                                 // Номер собственности
    std::string SellOrBuy;                              // Сдаеться или продажа
    int WhatPrice;                                      // Цена для обьявления
public:
    int* adLimit, tmpLimit;
    int saveAdLimit;                                    // Кем являеться пользователь

    Address addresses[6];                               // Массив обьектов
    std::vector<RealEstateProperty> enteredProperties;

    RealEstate();

    void chackBrokerOrUser();                                               // Кем являеться пользователь Брокер/Об. Пользователь

    void BoardMenu();                                                       // Меню после авторизации

    void postNewProperty();                                                 // (размещение нового свойства):

    void showStreetsInCity(const std::string& selectedCity);                // Для выбота в масива олиц которые пренадлежат к городу

    void removeProperty();                                                  // (удалить публикацию)

    void printEnteredProperties();                                          // (просмотреть все активы)

    void printAllProperties2();                                             // (отображать все активы, опубликованные пользователем)

    void propertySearchParameter();                                         // (поиск свойства по параметрам)

    void StartProgram();                                                    // запуск программы

    int ConverToInt(char* inputUser);
};
