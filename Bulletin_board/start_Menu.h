#pragma once

class Menu {
private:
    int* Colors;                                        // ����� ������ ����� ���� �� ���������
    char counter;                                       // ��� �������� � ������ ������� ������
    char key;                                           // ���� ������������
    int width_screen, height_screen;                    // ��������� ��������� ������ �� ������/������
    int BgcolorMenu;                                    // ������� ����
public:
    Menu();
    ~Menu() { delete[]Colors; }

    void mainMenu();                                    // ������� ����

    bool MenuBoardAtCabinet();                          // ���� ��� ����� � �������

    int widthCenter() { return width_screen / 2 - 14; }                 // ����� �� ������ �����
    int heightCenter() { return height_screen / 2 - 3; }                // ����� �� ������ ������
};