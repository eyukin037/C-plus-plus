// OverLoadFunctions Eyukin
//1. Реализуйте перегруженные функции для Нахождения максимального значения двух целых чисел.
//Нахождения максимального значения трёх целых чисел.Нахождения максимального значения четырех целых чисел.
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// смена цвета
void SetColor(int color)
{
    SetConsoleTextAttribute(h, color);
}
// генератор случайного цвета 
int RandomColor()
{
    return 1 + rand() % 15;
}
// установить случайный цвет
void SetRandomColor()
{
    SetConsoleTextAttribute(h, RandomColor());
}
// Сброс цвета 
void ResetColor()
{
    SetColor(7);
}
// анимация обработки
void Spinner(int cycles)
{
    char spin[] = "|/-\\";
    for (int i = 0; i < cycles; i++)
    {
        cout << "\b" << spin[i % 4];
        Sleep(150);
    }
    cout << "\b ";
}
// Для 2 чисел
int Max(int a, int b)
{
    return (a > b) ? a : b;
}
// Для 3 чисел 
int Max(int a, int b, int c)
{
    return (a > b && a > c) ? a : (b > c ? b : c);
}
// Для 4 чисел 
int Max(int a, int b, int c, int d)
{
    return (a > b && a > c && a > d) ? a : (b > c && b > d) ? b : (c > d) ? c : d;
}
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("---Перегруженные функции Max---");
    int a = rand() % 100 - 100;   // [-100; -1]
    int b = rand() % 100 - 100;   // [-100; -1]
    int c = rand() % 100 + 1;     // [1; 100]
    int d = rand() % 100 + 1;     // [1; 100]
    SetRandomColor(); cout << "a = " << a << endl;
    SetRandomColor(); cout << "b = " << b << endl;
    SetRandomColor(); cout << "c = " << c << endl;
    SetRandomColor(); cout << "d = " << d << endl;
    cout << endl;
    // 2 числа
    SetRandomColor();
    cout << "Поиск максимума из двух целых чисел: a, b ";
    Spinner(25);
    SetRandomColor();
    cout << "\nМаксимум: " << Max(a, b) << "\n\n";
    // 3 числа
    SetRandomColor();
    cout << "Поиск максимума из трёх целых чисел: a, b, c ";
    Spinner(25);
    SetRandomColor();
    cout << "\nМаксимум: " << Max(a, b, c) << "\n\n";
    // 4 числа
    SetRandomColor();
    cout << "Поиск максимума из четырёх целых чисел: a, b, c, d ";
    Spinner(25);
    SetRandomColor();
    cout << "\nМаксимум: " << Max(a, b, c, d) << "\n\n";
    // Выход
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}