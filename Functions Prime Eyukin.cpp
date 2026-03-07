// Functions Prime Eyukin
//Написать функцию, получающую целое число в качестве параметра и определяющую, 
//простое (делится без остатка только на 1 и на само себя) оно или составное; 
//для составного числа вывести на экран все числа, на которые без остатка делится это число. 
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
// проверка числа
void CheckNumber(int number)
{
    bool isPrime = true;

    SetRandomColor();
    if (number <= 1)
    {
        cout << "Число не является ни простым, ни составным" << endl;
        return;
    }
    SetRandomColor();
    cout << "Число " << number << " ";
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        SetRandomColor();
        cout << "простое." << endl;
    }
    else
    {
        SetRandomColor();
        cout << "составное." << endl;

        SetRandomColor();
        cout << "Делители: ";

        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                SetRandomColor();
                cout << i << " ";
            }
        }
        cout << endl;
    }
}
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
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    //заголовок программы на рамке окна консоли
    SetConsoleTitleA("---Простые и составные числа!---");
    int n; 
    SetRandomColor();
    cout << "Введите число: ";
    SetRandomColor();
    cin >> n;
    cout << "Обработка ";
    Spinner(10);
    cout << endl;
    CheckNumber(n);
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу!" << endl;
    SetColor(7); // вернуть стандартный цвет
    system("pause > NUL");
}
