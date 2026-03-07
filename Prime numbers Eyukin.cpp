// Prime numbers Eyukin.cpp 
//Простые числа
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
    SetConsoleTitleA("---Простые числа!---");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    cout << "Программа для вывода простых чисел от 2 до 100:\n\n";
    for (int num = 2; num <= 100; num++)
    {
        bool isPrime = true;

        for (int div = 2; div * div <= num; div++)
        {
            if (num % div == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            int color;

            // генерация читаемого цвета
            do
            {
                color = rand() % 15 + 1; // 1..15
            } while (color == 1 || color == 8); // исключаем тёмные

            SetConsoleTextAttribute(h, color);
            cout << num << " ";
        }
    }
    // возврат стандартного цвета
    SetConsoleTextAttribute(h, 0x07);
    cout << "\n\nДля выхода из программы нажмите любую клавишу...";
    system("pause > NUL");

}