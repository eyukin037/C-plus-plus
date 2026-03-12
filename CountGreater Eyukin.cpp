// CountGreater Eyukin
//1.Написать рекурсивную функцию (без шаблона) подсчёта количества чисел в массиве из 20 случайных чисел, которые больше заданного (введённого с клавиатуры).
//Без циклов
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Смена цвета
void SetColor(int color) { SetConsoleTextAttribute(h, color); }
// Генератор случайного цвета
int RandomColor() { return 1 + rand() % 15; }
// Установить случайный цвет
void SetRandomColor() { SetConsoleTextAttribute(h, RandomColor()); }
// Сброс цвета
void ResetColor() { SetColor(7); }
// Анимация обработки
void Spinner(int cycles) {
    char spin[] = "|/-\\";
    for (int i = 0; i < cycles; i++) {
        SetRandomColor();
        cout << "\b" << spin[i % 4];
        Sleep(150);
    }
    ResetColor();
    cout << "\b ";
}
// прототип рекурсивной функции
int CountGreater(int Array[], int Size, int Key);
int main() {
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("Подсчёт элементов больше заданного");
    SetRandomColor();
    cout << "---Программа подсчёта элементов массива---\n\n";
    ResetColor();
    const short Size = 20;
    int ArrayInt[Size];
    for (short i = 0; i < Size; i++)
    {
        ArrayInt[i] = rand() % 100 - 50;
        SetRandomColor();
        cout << "I[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    int keyInt;
    SetRandomColor();
    cout << "\nВведите int: ";
    ResetColor();
    cin >> keyInt;
    SetRandomColor();
    cout << "\nВыполняется подсчёт ";
    ResetColor();
    cout << "|";
    Spinner(20);
    cout << endl;
    int resInt = CountGreater(ArrayInt, Size, keyInt);
    SetRandomColor();
    cout << "\nБольше " << keyInt << " (int): " << resInt << endl;
    ResetColor();
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}
int CountGreater(int Array[], int Size, int Key)
{
    if (Size == 0) return 0;
    if (Array[Size - 1] > Key) return 1 + CountGreater(Array, Size - 1, Key);
    else return CountGreater(Array, Size - 1, Key);
}