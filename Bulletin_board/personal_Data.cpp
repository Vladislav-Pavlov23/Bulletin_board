#include "personal_Data.h"
#include <iostream>
#include "RealEstate.h"
#include "Address.h"
#include "REProperty.h"
#include "fun_console.h"
#include "start_Menu.h"
#include <string>
#include "ASDInput.h"

void PersonalData::createUser() {
    cls();

    ASD::Input input(20);
    Menu menu;
    Successful_Registr = true;

    GotoXY(menu.widthCenter(), 1);
    SetColor(Green, Black);
    std::cout << "Регистрация кабинета";
    SetColor(White, Black);

    GotoXY(0, 3);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(0, 4);
    std::cout << "| Введите ммя ->  ";
    GotoXY(45, 4);
    std::cout << "|";
    GotoXY(0, 5);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(18, 4);

    input.inputOnlyText();
    NameUser = input.get();

    GotoXY(47, 4);
    if (!NameUser.empty() && NameUser.length() > 2) {
        SetColor(Green, Black);
        std::cout << "+";
        SetColor(7, Black);
    }
    else {
        SetColor(Red, Black);
        std::cout << "-";
        SetColor(7, Black);
        Successful_Registr = false;
    }

    GotoXY(0, 7);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(0, 8);
    std::cout << "| Придумайте пароль ->  ";
    GotoXY(45, 8);
    std::cout << "|";
    GotoXY(0, 9);
    std::cout << "| (должен включать 1 симв. из - $,%_)        |";
    GotoXY(0, 10);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(23, 8);

    const char* SearchSymb = "$&*@/";

    input.input();
    PasswordUser = input.get();

    GotoXY(47, 8);
    if (strpbrk(PasswordUser.c_str(), SearchSymb) != NULL) {
        SetColor(Green, Black);
        std::cout << "+";
        SetColor(7, Black);
    }
    else {
        SetColor(Red, Black);
        std::cout << "-";
        SetColor(7, Black);
        Successful_Registr = false;
    }

    GotoXY(0, 12);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(0, 13);
    std::cout << "| Номер телефона ->  ";
    GotoXY(45, 13);
    std::cout << "|";
    GotoXY(0, 14);
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
    GotoXY(21, 13);
    input.inputOnlyNumbers();
    PhoneUser = input.get();

    GotoXY(47, 13);
    if (checkForNumber(PhoneUser) && PhoneUser.length() == 12) {
        SetColor(Green, Black);
        std::cout << "+";
        SetColor(7, Black);
    }
    else {
        SetColor(Red, Black);
        std::cout << "-";
        SetColor(7, Black);
        Successful_Registr = false;
    }

    if (!Successful_Registr) {
        SetColor(Red, Black);
        std::cout << "\n\nВы неверно указали данные! Попробуйте снова)";
        SetColor(7, Black);
        _getch();
    }
    else {
        SetColor(Green, Black);
        std::cout << "\n\nВы успешно зарегистрировались!";
        SetColor(7, Black);
        _getch();
    }
}

bool PersonalData::checkForNumber(const std::string& phone) {
    for (char c : phone) {
        if (!isdigit(c)) { return false; }
    }
    return true;
}

void PersonalData::loginUser() {
    cls();

    if (!Successful_Registr) {
        SetColor(Red, Black);
        std::cout << "ОШИБКА - Для начала нужно зарегистрироваться!!!";
        SetColor(7, Black);
    }
    else {
        std::string NameLogin, PasswordLogin;
        ASD::Input input(20);
        Menu menu;

        GotoXY(menu.widthCenter(), 1);
        SetColor(Green, Black);
        std::cout << "Авторизация";
        SetColor(7, Black);

        GotoXY(0, 3);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
        GotoXY(0, 4);
        std::cout << "| Введите ммя ->  ";
        GotoXY(45, 4);
        std::cout << "|";
        GotoXY(0, 5);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
        GotoXY(18, 4);
        input.inputOnlyText();
        NameLogin = input.get();

        GotoXY(47, 4);
        if (!NameLogin.empty() && NameLogin.length() > 2 && NameLogin == NameUser) {
            SetColor(Green, Black);
            std::cout << "+";
            SetColor(7, Black);
        }
        else {
            SetColor(Red, Black);
            std::cout << "-";
            SetColor(7, Black);
            _getch();
            return;
        }

        GotoXY(0, 7);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
        GotoXY(0, 8);
        std::cout << "| Введите пароль ->  ";
        GotoXY(45, 8);
        std::cout << "|";
        GotoXY(0, 9);
        std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
        GotoXY(19, 8);
        input.input();
        PasswordLogin = input.get();

        GotoXY(47, 8);
        if (!PasswordLogin.empty() && PasswordLogin == PasswordUser) {
            SetColor(Green, Black);
            std::cout << "+";
            SetColor(7, Black);
        }
        else {
            SetColor(Red, Black);
            std::cout << "-";
            SetColor(7, Black);
            _getch();
            return;
        }

        GotoXY(0, 12);
        SetColor(Green, Black);
        std::cout << "УСПЕШНО - Вы успешно авторизировались!";
        SetColor(7, Black);
        _getch();

        RealEstate GoToMenu;
        GoToMenu.BoardMenu();
    }
}

void PersonalData::logout() {
    exit(0);
}
