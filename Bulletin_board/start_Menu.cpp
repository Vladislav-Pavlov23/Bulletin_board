// RealEstate.cpp
#include "start_Menu.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "RealEstate.h"
#include "Address.h"
#include "REProperty.h"
#include "personal_Data.h"
#include "fun_console.h"

Menu::Menu() {
	counter = 2;
	key = '0';
	width_screen = GetCols();
	height_screen = GetRows();
	BgcolorMenu = 0;
	Colors = new int[6];
	for (int i = 0; i < 6; i++) { Colors[i] = 7; }
}


void Menu::mainMenu() {
    bool exitProgram = false;
    PersonalData User;

    while (!exitProgram) {
        cls();

        const int menuSize = 3;
        const char* menuItems[menuSize] = {
            "1. Регистрация         ",
            "2. Авторизация         ",
            "3. Выйти с программы   "
        };

        GotoXY(widthCenter(), heightCenter());
        SetColor(7, BgcolorMenu);
        SetColor(White, BgcolorMenu);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~+";

        for (int i = 0; i < menuSize; ++i) {
            GotoXY(widthCenter(), heightCenter() + (i + 1));
            std::cout << "|   ";
            SetColor(Colors[i], BgcolorMenu);
            std::cout << menuItems[i];
            SetColor(7, BgcolorMenu);
            std::cout << "|" << "\n";
        }

        GotoXY(widthCenter(), heightCenter() + 4);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~+";
        SetColor(White, Black);

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3)) { counter--; }
        else if (key == 80 && (counter >= 1 && counter <= 2)) { counter++; }
        else if (key == '\r') {
            cls();
            if (counter == 1) { User.createUser(); }
            if (counter == 2) { User.loginUser(); }
            if (counter == 3) { std::cout << "Досвидания!\n\n\n\n"; User.logout(); }
            _getch();
        }

        Colors[0] = Colors[1] = Colors[2] = 7;

        if (counter == 1) { Colors[0] = 12; }
        if (counter == 2) { Colors[1] = 12; }
        if (counter == 3) { Colors[2] = 12; }
    }
}


bool Menu::MenuBoardAtCabinet() {
    bool inSubMenu = false;
    RealEstate objectRS;

    objectRS.chackBrokerOrUser();
    // проверка обычный пользователь или брокер
    for (int i = 0; i < 2; i++) {
        if (objectRS.adLimit[i] != 0) { objectRS.saveAdLimit = objectRS.adLimit[i]; objectRS.tmpLimit = objectRS.adLimit[i]; }
    }

    while (!inSubMenu) {
        cls();
        std::cout << "Осталось обьявлений: " << objectRS.saveAdLimit;
        const int menuBoardSize = 6;
        const char* menuItemsBoard[menuBoardSize] = {
            "1. Разместите новую недвижимость                         ",
            "2. Убрать рекламу на объекте                             ",
            "3. Просмотреть все активы в системе                      ",
            "4. Просмотреть все активы, опубликованные пользователем  ",
            "5. Поиск недвижимости по параметрам                      ",
            "6. Отключитесь и вернитесь в главное меню                "
        };

        GotoXY(widthCenter() - 17, heightCenter());
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";

        for (int i = 0; i < menuBoardSize; ++i) {
            GotoXY(widthCenter() - 17, heightCenter() + (i + 1));
            SetColor(7, BgcolorMenu);
            std::cout << "|  ";
            SetColor(Colors[i], BgcolorMenu);
            std::cout << menuItemsBoard[i];
            SetColor(7, BgcolorMenu);
            std::cout << "|" << "\n";
        }

        GotoXY(widthCenter() - 17, heightCenter() + 7);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3)) { counter--; }
        else if (key == 72 && (counter >= 3 && counter <= 4)) { counter--; }
        else if (key == 72 && (counter >= 4 && counter <= 5)) { counter--; }
        else if (key == 72 && (counter >= 5 && counter <= 6)) { counter--; }
        else if (key == 72 && (counter >= 6 && counter <= 7)) { counter--; }
        else if (key == 72 && (counter >= 7 && counter <= 8)) { counter--; }

        else if (key == 80 && (counter >= 1 && counter <= 2)) { counter++; }
        else if (key == 80 && (counter >= 2 && counter <= 3)) { counter++; }
        else if (key == 80 && (counter >= 3 && counter <= 4)) { counter++; }
        else if (key == 80 && (counter >= 4 && counter <= 5)) { counter++; }

        if (key == '\r') {
            cls();
            if (counter == 1) { objectRS.postNewProperty(); }
            if (counter == 2) { objectRS.removeProperty(); }
            if (counter == 3) { objectRS.printAllProperties2(); }
            if (counter == 4) { objectRS.printEnteredProperties(); }
            if (counter == 5) { objectRS.propertySearchParameter(); }
            if (counter == 6) { inSubMenu = true; }
            _getch();
        }

        for (int i = 0; i < menuBoardSize; i++) { Colors[i] = 7; }

        if (counter == 1) { Colors[0] = 12; }
        if (counter == 2) { Colors[1] = 12; }
        if (counter == 3) { Colors[2] = 12; }
        if (counter == 4) { Colors[3] = 12; }
        if (counter == 5) { Colors[4] = 12; }
        if (counter == 6) { Colors[5] = 12; }
    }

    return inSubMenu;
}