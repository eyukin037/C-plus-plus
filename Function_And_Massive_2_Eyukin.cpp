// Function_And_Massive_2_Eyukin
// 2.Написать функцию получающую двумерный массив размером 10 на 10, заполненный случайными числами от -99 до 99
//и заменяющую в нём максимальный элемент на 777, а минимальный на 555
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int Size = 10;
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
void Randomize(int[][Size]);
void Show(int[][Size]);
void ReplaceMinMax(int[][Size]);
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
    int A[Size][Size]{};
    Randomize(A);
    SetColor(11);
    cout << "Исходный массив:\n";
    Show(A);
    cout << "\nОбработка ";
    Spinner(10);
    cout << endl;
    ReplaceMinMax(A);
    SetColor(11);
    cout << "\nМассив после замены минимума и максимума:\n";
    Show(A);
    SetColor(12);
    cout << "Для выхода из программы нажмите любую клавишу!" << endl;
    SetColor(7);
    system("pause > NUL");
}
// заполнение массива случайными числами
void Randomize(int Array[][Size])
{
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            Array[i][j] = rand() % 199 - 99;
}
// вывод двумерного массива (каждый элемент — случайного цвета)
void Show(int Array[][Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            SetRandomColor();

            if (Array[i][j] >= 0) cout << " ";
            if (Array[i][j] >= -9 && Array[i][j] <= 9) cout << " ";

            cout << Array[i][j] << " ";
        }
        cout << endl;
    }
    SetColor(7);
}
// замена одного максимального и минимального элементов
void ReplaceMinMax(int Array[][Size])
{
    int Min = Array[0][0], Max = Array[0][0];
    int MinI = 0, MinJ = 0, MaxI = 0, MaxJ = 0;
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
        {
            if (Array[i][j] < Min)
            {
                Min = Array[i][j];
                MinI = i;
                MinJ = j;
            }
            if (Array[i][j] > Max)
            {
                Max = Array[i][j];
                MaxI = i;
                MaxJ = j;
            }
        }
    Array[MinI][MinJ] = 555;
    Array[MaxI][MaxJ] = 777;
}