// Function_And_Massive_1_Eyukin
//1. Написать функцию, меняющую порядок следования элементов передаваемого ей одномерного массива(10 элементов от - 99 до 99) на противоположный.
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
// прототипы функций
void Randomize(int[], int);
void Show(int[], int);
void ReverseArray(int[], int);
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
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("---Функции и массивы!---");
    const int Size = 10;
    int A[Size]{};
    Randomize(A, Size);
    SetRandomColor();
    cout << "Исходный массив:" << endl;
    Show(A, Size);
    ReverseArray(A, Size);
    SetRandomColor();
    cout << "Обработка ";
    Spinner(10);
    cout << endl;
    SetRandomColor();
    cout << "\nМассив после изменения порядка элементов:" << endl;
    Show(A, Size);
    SetColor(12);
    cout << "Для выхода из программы нажмите любую клавишу!" << endl;
    SetColor(7); // стандартный цвет
    system("pause > NUL");
}
// заполнение массива случайными числами от -99 до 99
void Randomize(int Array[], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        Array[i] = rand() % 199 - 99;
    }
}
// вывод массива (каждое число — случайного цвета)
void Show(int Array[], int Size)
{
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor();
        if (Array[i] >= 0) cout << " ";
        if (Array[i] >= -9 && Array[i] <= 9) cout << " ";
        cout << Array[i] << " ";
    }
    SetColor(7);
    cout << endl;
}
// функция изменения порядка элементов
void ReverseArray(int Array[], int Size)
{
    for (int i = 0; i < Size / 2; i++)
    {
        int Temp = Array[i];
        Array[i] = Array[Size - 1 - i];
        Array[Size - 1 - i] = Temp;
    }
}