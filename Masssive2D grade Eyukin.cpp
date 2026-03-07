// Masssive2D grade Eyukin
//Создать двумерный массив оценок студентов:
// 30 студентов(строк) у каждого по 5 оценок(столбцов).
//Заполнить весь массив случайными оценками от 2 до 5 включительно.
//Подсчитать и вывести на экран средний балл каждого студента.
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <iomanip>
using namespace std;
int main()
{
    system("chcp 1251>NUL");
    //аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("---Успеваемость---");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 0x0E);
    cout << "---Программа для подсчёта среднего балла каждого студента!---" << endl;
    SetConsoleTextAttribute(h, 0x07);
    const int Students = 30;
    const int Marks = 5;
    int A[Students][Marks]{};
    double avg = 0;
    for (int i = 0; i < Students;i++)
    {
        int sum = 0;
        for (int j = 0;j < Marks;j++)
        {
            A[i][j] = rand() % 4 + 2; 
            sum += A[i][j];
            SetConsoleTextAttribute(h, 1 + rand() % 15);
            cout << A[i][j] << " ";
        }
        avg = (double)sum / Marks;
        cout << fixed << setprecision(1) << avg << endl;
    }
    cout << "\nДля выхода из программы нажмите любую клавишу..." << endl;
    system("pause>NUL");
}

