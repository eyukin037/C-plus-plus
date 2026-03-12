// SwapEyukin
//Написать функцию, принимающую адреса трех переменных типа float (значения вводятся с клавиатуры) 
//и меняющую значения этих переменных (используя указатели) так, чтобы переменная, чей адрес был передан первым, 
//получила минимальное значение, а переменная, чей адрес был передан последним, получила максимальное значение, 
//а вторая переменная получила среднее по величине значение из трёх (оставшееся не использованным значение).
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
void Swap(float* pA, float* pB, float* pC)
{
    float temp;
    // если первое больше второго — меняем
    if (*pA > *pB)
    {
        temp = *pA;
        *pA = *pB;
        *pB = temp;
    }
    // если первое больше третьего — меняем
    if (*pA > *pC)
    {
        temp = *pA;
        *pA = *pC;
        *pC = temp;
    }
    // если второе больше третьего — меняем
    if (*pB > *pC)
    {
        temp = *pB;
        *pB = *pC;
        *pC = temp;
    }
    //или через тернарники
    //(*pA > *pB) ? (temp = *pA, *pA = *pB, *pB = temp) : 0;
    //(*pA > *pC) ? (temp = *pA, *pA = *pC, *pC = temp) : 0;
    //(*pB > *pC) ? (temp = *pB, *pB = *pC, *pC = temp) : 0;
}
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    SetConsoleTitleA("Функция, принимающая и меняющая адреса переменных типа float");
    SetRandomColor();
    cout << "---Программа, принимающая адреса трех переменных типа float и меняющая значения этих переменных!---" << endl;
    ResetColor();
    float A, B, C;
    SetRandomColor();
    cout << "Введите число A: ";
    ResetColor();
    cin >> A;
    SetRandomColor();
    cout << "Введите число B: ";
    ResetColor();
    cin >> B;
    SetRandomColor();
    cout << "Введите число C: ";
    ResetColor();
    cin >> C;
    SetRandomColor();
    cout << "\nДо функции Swap:\n";
    ResetColor();
    SetRandomColor();
    cout << "A = " << A << endl;
    ResetColor();
    SetRandomColor();
    cout << "B = " << B << endl;
    ResetColor();
    SetRandomColor();
    cout << "C = " << C << endl;
    ResetColor();
    // передаем адреса переменных
    Swap(&A, &B, &C);
    SetRandomColor();
    cout << "\nПосле функции Swap:\n";
    ResetColor();
    cout << "|";
    Spinner(20);
    cout << endl;
    SetRandomColor();
    cout << "A  = " << A << endl;
    ResetColor();
    SetRandomColor();
    cout << "B  = " << B << endl;
    ResetColor();
    SetRandomColor();
    cout << "C  = " << C << endl;
    ResetColor();
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}