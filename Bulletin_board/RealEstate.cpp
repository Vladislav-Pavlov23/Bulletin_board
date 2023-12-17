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
    // Объекты адресов с разными городами
    addresses[0] = Address("Герцль", "Ашкелон");
    addresses[1] = Address("Бен-Гурион", "Тель-Авив");
    addresses[2] = Address("Бен-Гурион", "Тель-Авив");
    addresses[3] = Address("Бен-Гурион", "Иерусалим");
    addresses[4] = Address("Бен-Гурион", "Ашкелон");
    addresses[5] = Address("Герцль", "Иерусалим");
}


void RealEstate::chackBrokerOrUser() {
    cls();

    std::cout << "Кем вы являетесь?\n";
    std::cout << "\n1. Обычный пользователь (лимит 3 обявления)";
    std::cout << "\n2. Брокер (лимит 10 обявлений)\n\n";

    ASD::Input who(1);
    std::cout << "Сделайте выбор -> ";
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

    // Проверка сколько осталось обьявлений
    if (saveAdLimit == 0) {
        SetColor(Red, Black);
        std::cout << "\nОШИБКА - Вы достигли лимита обьявлений!";
        SetColor(White, Black);
    }
    else {
        bool correctlyAdress = false;
        while (!correctlyAdress && saveAdLimit > 0) {
            cls();
            std::cout << "Адреса которые есть в системе:";

            int coordY = 2;
            for (const auto& address : addresses) {
                GotoXY(0, coordY);
                SetColor(5, Black);
                std::cout << "Город\t";
                SetColor(White, Black);
                std::cout << address.city;
                GotoXY(20, coordY);
                SetColor(5, Black);
                std::cout << "Улица\t";
                SetColor(White, Black);
                std::cout << address.street;
                coordY++;
            }


            std::string selectedCity, selectedStreet;
            std::cout << "\n\n\nВведите название города из списка: ";
            std::cin >> selectedCity;

            // Проверяем, есть ли такой город в списке
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

                std::cout << "\nВведите название улицы из списка: ";
                std::cin >> selectedStreet;

                // Проверяем, есть ли такой город в списке
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
                    std::cout << "\nУлица не найдена в списке.";
                    SetColor(White, Black);
                    _getch();
                }
            }
            else {
                SetColor(Red, Black);
                std::cout << "\nГород не найден в списке.";
                SetColor(White, Black);
                _getch();
            }
        }

        std::cout << "\n\n1. Стандартная квартира в многоквартирном доме\n";
        std::cout << "2. Квартира-пентхаус в многоквартирном доме\n";
        std::cout << "3. Частной дом\n";
        std::cout << "Какой тип апаратаментов: ";

        ASD::Input TypeHouse(1);
        TypeHouse.inputOnlyNumbers();

        if (ConverToInt(TypeHouse.get()) == 1) { TypeApartament = "Стандартная квартира в многоквартирном доме"; }
        else if (ConverToInt(TypeHouse.get()) == 2) { TypeApartament = "Квартира-пентхаус в многоквартирном доме"; }
        else if (ConverToInt(TypeHouse.get()) == 3) { TypeApartament = "Частной дом"; }

        std::cout << "\n\nСколько комнат: ";
        ASD::Input countRoom(2);
        countRoom.inputOnlyNumbers();
        CountRooms = ConverToInt(countRoom.get());

        std::cout << "\n\nКаков номер собственности: ";
        ASD::Input NumberProp(10);
        NumberProp.inputOnlyNumbers();
        PropertyNumber = ConverToInt(NumberProp.get());

        std::cout << "\n\n(1 - Сдается)/(2 - Продажа): ";
        ASD::Input buyOrSell(1);
        buyOrSell.inputOnlyNumbers();

        if (ConverToInt(buyOrSell.get()) == 1) { SellOrBuy = "Продажа"; }
        else if (ConverToInt(buyOrSell.get()) == 2) { SellOrBuy = "Сдается"; }

        std::cout << "\n\nОриентировочная цена Продажи/Покупки (в $): ";
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
    // Выводим улицы выбранного города
    std::cout << "\nСписок улиц в городе:" << selectedCity << ":\n";
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
        std::cout << "ОШИБКА - У вас еще нет обьявлений для удаления!";
        SetColor(White, Black);
    }
    else {
        // Вывод всех обьявлений перед удалением
        printEnteredProperties();

        SetColor(Green, Black);
        std::cout << "\n\nВведите номер обьявления, которое вы хотите удалить: ";
        SetColor(White, Black);

        ASD::Input propertyIndex(1);
        propertyIndex.inputOnlyNumbers();
        int index = ConverToInt(propertyIndex.get());

        if (index >= 1 && index <= (int)(enteredProperties.size())) {
            enteredProperties.erase(enteredProperties.begin() + index - 1);

            SetColor(Green, Black);
            std::cout << "\nСвойство успешно удалено.\n";
            SetColor(White, Black);
            saveAdLimit++;
        }
        else {
            SetColor(Red, Black);
            std::cout << "\nНеверный номер свойства.\n";
            SetColor(White, Black);
        }


    }
}


void RealEstate::printEnteredProperties() {
    std::cout << "Мои обьявления:";
    for (const auto& property : enteredProperties) {
        std::cout << "\n\nНомер:                      " << property.NumberAnnouncement
            << "\nГород:                      " << property.address.city
            << "\nУлица:                      " << property.address.street
            << "\nТип апартаментов:           " << property.typeApartment
            << "\nКоличество комнат:          " << property.CountRooms
            << "\nНомер собственности:        " << property.PropertyNumber
            << "\nПродажа/Сдается:            " << property.SellOrBuy
            << "\nЦена Продажи/Покупки (в $): " << property.WhatPrice;
    }
}


void RealEstate::printAllProperties2() {
    printEnteredProperties();
}


void RealEstate::propertySearchParameter() {
    cls();

    std::string inputRentOrSale, inputType;
    int countRooms = 0, minMaxPrice = 0;
    std::cout << "Поиск обьявления по критериям:\n";

    ASD::Input InputRentOrSale(1);
    std::cout << "\n(1 - Сдается)/(2. Продается) -> ";
    InputRentOrSale.inputOnlyNumbers();

    if (ConverToInt(InputRentOrSale.get()) == 1) { inputRentOrSale = "Сдается"; }
    else if (ConverToInt(InputRentOrSale.get()) == 2) { inputRentOrSale = "Продажа"; }

    ASD::Input InputType(1);
    std::cout << "\n\n1. Стандартная квартира в многоквартирном доме";
    std::cout << "\n2. Квартира-пентхаус в многоквартирном доме";
    std::cout << "\n3. Частной дом";
    std::cout << "\n\nКакой тип недвижимости вы хотите -> ";
    InputType.inputOnlyNumbers();

    if (ConverToInt(InputType.get()) == 1) { inputType = "Стандартная квартира в многоквартирном доме"; }
    else if (ConverToInt(InputType.get()) == 2) { inputType = "Квартира-пентхаус в многоквартирном доме"; }
    else if (ConverToInt(InputType.get()) == 3) { inputType = "Частной дом"; }

    ASD::Input CountRooms(2);
    std::cout << "\n\nКакое желаемое количество комнат -> ";
    CountRooms.inputOnlyNumbers();
    countRooms = ConverToInt(CountRooms.get());

    ASD::Input MinMaxPrice(10);
    std::cout << "\n\nКакой желаемый ценовой диапазон(минимальный и максимальный) -> ";
    MinMaxPrice.inputOnlyNumbers();
    minMaxPrice = ConverToInt(MinMaxPrice.get());


    std::cout << "\n\nВаши критерии:";
    std::cout << "\nСдается или продается: " << inputRentOrSale;
    std::cout << "\nТип недвижимости:      " << inputType;
    std::cout << "\nКол-во комнат          " << countRooms;
    std::cout << "\nЦеновой диапазон:      " << minMaxPrice;


    int index = 0;
    bool isAdFound = false;

    for (const auto& property : enteredProperties) {
        if ((property.SellOrBuy == inputRentOrSale) && property.typeApartment == inputType &&
            (property.WhatPrice == minMaxPrice) && (property.CountRooms == countRooms)) {
            SetColor(Green, Black);
            std::cout << "\n\nУСПЕХ - ";
            SetColor(7, Black);
            std::cout << "По критериям найдено:";

            std::cout << "\n\nНомер:                      " << property.NumberAnnouncement
                << "\nГород:                      " << property.address.city
                << "\nУлица:                      " << property.address.street
                << "\nТип апартаментов:           " << property.typeApartment
                << "\nКоличество комнат:          " << property.CountRooms
                << "\nНомер собственности:        " << property.PropertyNumber
                << "\nПродажа/Сдается:            " << property.SellOrBuy
                << "\nЦена Продажи/Покупки (в $): " << property.WhatPrice;
        }
    }
}


void RealEstate::StartProgram() {
    Menu start;
    start.mainMenu();
}

