#pragma once
// клас для вводу строки с консолі без додаткових функцій
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
                        std::cout << "\b \b";  // Перемещение курсора назад, печать пробела, перемещение курсора назад снова.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // Продолжаем цикл без увеличения k, чтобы не записывать Backspace в строку.
                }

                if (key == 13) { break; }     // Если нажата клавиша Enter, завершаем ввод.
                if (key == 9) { continue; }   // Если нажата Tab пропускаем и вводим дальше
                if (key == 27) { std::cout << "\n\nВы завершили работу! До свидания!)\n\n"; exit(0); }     // Если нажата Esc завершаем ввод

                str[k] = key;
                std::cout << str[k];
                k++;
                str[k] = '\0';
            }
            return true;
        }

        bool inputOnlyNumbers() {
            str[0] = '\0';    // Обнуление если нажали Enter без ввода
            size_t k = 0;  // Переменная k используется для отслеживания текущей позиции в строке.

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";  // Перемещение курсора назад, печать пробела, перемещение курсора назад снова.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // Продолжаем цикл без увеличения k, чтобы не записывать Backspace в строку.
                }
                
                if (key == 13 && k != 0) { break; }     // Если нажата клавиша Enter, завершаем ввод.
                if (key == 9) { continue; }   // Если нажата Tab пропускаем и вводим дальше
                if (!(key >= '0' && key <= '9')) { continue; }
                if (key == 27) { std::cout << "\n\nВы завершили работу! До свидания!)\n\n"; exit(0); }     // Если нажата Esc завершаем ввод

                str[k] = key;  // Записываем введенную цифру в текущую позицию строки.
                std::cout << str[k];
                k++;
                str[k] = '\0';  // Устанавливаем конец строки после новой цифры.
            }
            return true;
        }

        bool inputOnlyText() {
            str[0] = '\0';    // Обнуление если нажали Enter без ввода
            size_t k = 0;  // Переменная k используется для отслеживания текущей позиции в строке.

            while (k < length) {
                int key = _getch();

                if (key == 8) {
                    if (k > 0) {
                        std::cout << "\b \b";  // Перемещение курсора назад, печать пробела, перемещение курсора назад снова.
                        k--;
                        str[k] = '\0';
                    }
                    continue;  // Продолжаем цикл без увеличения k, чтобы не записывать Backspace в строку.
                }

                if (key == 13) { break; }     // Если нажата клавиша Enter, завершаем ввод.
                if (key == 9) { continue; }   // Если нажата Tab пропускаем и вводим дальше
                if (key == 27) { std::cout << "\n\nВы завершили работу! До свидания!)\n\n"; exit(0); }     // Если нажата Esc завершаем ввод
                
                if (!((key >= 97 && key <= 122) || (key >= 65 && key <= 90) || (key >= 192 && key <= 255) || (key == 165) || (key == 180) ||
                   (key == 184) || (key == 186) || (key == 170) || (key == 191) || (key == 175) || (key == 178) || (key == 179))) {
                    continue;
                }

                str[k] = key;  // Записываем введенную цифру в текущую позицию строки.
                std::cout << str[k];
                k++;
                str[k] = '\0';  // Устанавливаем конец строки после новой цифры.
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