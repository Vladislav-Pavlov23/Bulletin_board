#pragma once
// ���� ��� ����� ������ � ������ ��� ���������� �������
#include <iostream>
#include <conio.h>
#include <Windows.h>

namespace ASD {
    class Input {
        size_t length;
        char* str;
        char ch;
    public:
        Input(size_t len) {
            length = len;
            str = new char[length + 1];
            ch = ' ';
        }
        ~Input() { delete str; }

        bool input() {
            str[0] = '\0';
            size_t k = 0;

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";  // ����������� ������� �����, ������ �������, ����������� ������� ����� �����.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // ���������� ���� ��� ���������� k, ����� �� ���������� Backspace � ������.
                }

                if (key == 13) { break; }     // ���� ������ ������� Enter, ��������� ����.
                if (key == 9) { continue; }   // ���� ������ Tab ���������� � ������ ������
                if (key == 27) { std::cout << "\n\n�� ��������� ������! �� ��������!)\n\n"; exit(0); }     // ���� ������ Esc ��������� ����

                str[k] = key;
                std::cout << str[k];
                k++;
                str[k] = '\0';
            }
            return true;
        }

        bool inputOnlyNumbers() {
            str[0] = '\0';    // ��������� ���� ������ Enter ��� �����
            size_t k = 0;  // ���������� k ������������ ��� ������������ ������� ������� � ������.

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";  // ����������� ������� �����, ������ �������, ����������� ������� ����� �����.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // ���������� ���� ��� ���������� k, ����� �� ���������� Backspace � ������.
                }
                
                if (key == 13 && k != 0) { break; }     // ���� ������ ������� Enter, ��������� ����.
                if (key == 9) { continue; }   // ���� ������ Tab ���������� � ������ ������
                if (!(key >= '0' && key <= '9')) { continue; }
                if (key == 27) { std::cout << "\n\n�� ��������� ������! �� ��������!)\n\n"; exit(0); }     // ���� ������ Esc ��������� ����

                str[k] = key;  // ���������� ��������� ����� � ������� ������� ������.
                std::cout << str[k];
                k++;
                str[k] = '\0';  // ������������� ����� ������ ����� ����� �����.
            }
            return true;
        }

        bool inputOnlyText() {
            str[0] = '\0';    // ��������� ���� ������ Enter ��� �����
            size_t k = 0;  // ���������� k ������������ ��� ������������ ������� ������� � ������.

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";  // ����������� ������� �����, ������ �������, ����������� ������� ����� �����.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // ���������� ���� ��� ���������� k, ����� �� ���������� Backspace � ������.
                }

                if (key == 13) { break; }     // ���� ������ ������� Enter, ��������� ����.
                if (key == 9) { continue; }   // ���� ������ Tab ���������� � ������ ������
                if (key == 27) { std::cout << "\n\n�� ��������� ������! �� ��������!)\n\n"; exit(0); }     // ���� ������ Esc ��������� ����
                
                if (!((key >= 97 && key <= 122) || (key >= 65 && key <= 90) || (key >= 192 && key <= 255) || (key == 165) || (key == 180) ||
                   (key == 184) || (key == 186) || (key == 170) || (key == 191) || (key == 175) || (key == 178) || (key == 179))) {
                    continue;
                }

                str[k] = key;  // ���������� ��������� ����� � ������� ������� ������.
                std::cout << str[k];
                k++;
                str[k] = '\0';  // ������������� ����� ������ ����� ����� �����.
            }
            return true;
        }

        char inputOnlyChar() {
            size_t k = 0;

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";
                        k--;
                    }
                    continue;
                }

                if (key == 13) { break; }
                if (key == 9) { continue; }
                if (key == 27) { std::cout << "\n\nYou have terminated the program. Goodbye!)\n\n"; exit(0); }

                if (!((key >= 97 && key <= 122) || (key >= 65 && key <= 90) || (key >= 192 && key <= 255) || (key == 165) || (key == 180) ||
                    (key == 184) || (key == 186) || (key == 170) || (key == 191) || (key == 175) || (key == 178) || (key == 179))) {
                    continue;
                }

                ch = static_cast<char>(key);
                std::cout << ch;
                break;
            }

            return ch;
        }


        char* get() { return str; }
    };
}