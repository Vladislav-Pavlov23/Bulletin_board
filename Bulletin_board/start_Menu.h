#pragma once

class Menu {
private:
    int* Colors;                                        // Масив цветов полей меню по умолчанию
    char counter;                                       // Для итерации и поиска индекса строки
    char key;                                           // Ввод пользователя
    int width_screen, height_screen;                    // Получение координат центра по высоте/ширине
    int BgcolorMenu;                                    // Заливка фона
public:
    Menu();
    ~Menu() { delete[]Colors; }

    void mainMenu();                                    // Главное меню

    bool MenuBoardAtCabinet();                          // Меню при входе в кабинет

    int widthCenter() { return width_screen / 2 - 14; }                 // Центр по ширине экран
    int heightCenter() { return height_screen / 2 - 3; }                // Центр по высоте экрана
};