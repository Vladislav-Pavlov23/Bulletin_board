#include <Windows.h>
#include "RealEstate.h"
#include "Address.h"
#include "start_Menu.h"
#include <iostream>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    RealEstate start;
    start.StartProgram();


    std::cout << "\n\n";
    return 0;
}