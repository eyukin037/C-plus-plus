// Chemodan Eyukin 1.0.cpp 
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main()
{
    system("chcp 1251 > NUL");
    //аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    SetConsoleTitleA("---Подсчёт количества целых чисел!---");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    int count = 0;
    //cin.exceptions(std::istream::badbit | std::istream::failbit); // включение обработки исключений
    // Заголовок
    SetConsoleTextAttribute(h, 0x0E); // желтый
    cout << "Программа для подсчёта количества целых чисел\n";
    cout << "в диапазоне от 100 до 999, у которых есть\n";
    cout << "две одинаковые цифры (не учитывать числа,\n";
    cout << "состоящие из трёх одинаковых цифр).\n";
    SetConsoleTextAttribute(h, 0x07);
    // Вложенные циклы по цифрам
    for (int a = 1; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                int number = a * 100 + b * 10 + c;
                // цепочка тернарных операторов: проверка "две одинаковые, но не три"
                bool ok =
                    (a == b && a != c) ? true :
                    (a == c && a != b) ? true :
                    (b == c && b != a) ? true :
                    false;
                count += ok ? 1 : 0;
                ok && (
                    SetConsoleTextAttribute(h, 1 + rand() % 15),
                    cout << number << "  ",
                    cout << ((count % 10 == 0) ? "\n" : "")
                    );
            }
        }
    }
    // Результат
    cout << "\n\n"; 
    SetConsoleTextAttribute(h, 0x0B); // голубой
    cout << "Количество таких чисел: ";
    SetConsoleTextAttribute(h, 0x0C); // светло-красный
    cout << count << endl;
    SetConsoleTextAttribute(h, 0x07);
    cout << "Для выхода из программы нажмите любую клавишу!" << endl;
    system("pause > NUL");
}