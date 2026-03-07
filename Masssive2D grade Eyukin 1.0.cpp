// Masssive2D grade Eyukin 1.0
//Создать двумерный массив оценок студентов:
// 30 студентов(строк) [1,2,3,...,30] у каждого по 5 оценок(столбцов).
//Заполнить весь массив случайными оценками от 2 до 5 включительно[2,3,4,5]. 
//Подсчитать и вывести на экран средний балл каждого студента.
//Подсчитать и вывести на экран кол - во студентов "отличников"(все оценки 5),
//"хорошистов"(оценки только 4 и 5) и "двоечников"(есть хотя бы одна оценка 2)
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
    int excellent = 0, good = 0, bad = 0;
    // Верхняя граница таблицы
    cout << "+----+";
    for (int k = 0; k < Marks; k++) cout << "----+";
    cout << "------+\n";
    // Заголовки столбцов
    cout << "| #  |";
    for (int k = 0; k < Marks; k++) cout << " 0" << k + 1 << " |";
    cout << " Балл |\n";
    // Разделитель под заголовком
    cout << "+----+";
    for (int k = 0; k < Marks; k++) cout << "----+";
    cout << "------+\n";
    // Основной вывод оценок
    for (int i = 0; i < Students; i++)
    {
        int sum = 0;
        bool has2 = false, all5 = true, only45 = true;
        cout << "| " << setw(2) << i + 1 << " | ";
        for (int j = 0; j < Marks; j++)
        {
            //A[i][j] = rand() % 4 + 2;
            //A[i][j] = rand() % 2 + 4;
            //int r = rand() % 4; // 0..3
           // if (r == 0)       A[i][j] = 2;
            //else if (r == 1)  A[i][j] = 3;
            //else if (r == 2)  A[i][j] = 4;
            //else              A[i][j] = 5;

            //int r = rand() % 100; // 0..99
           // if (r < 25)        A[i][j] = 2;  // 0..24 → 25%
           // else if (r < 35)   A[i][j] = 3;  // 25..34 → 10%
          //  else if (r < 65)   A[i][j] = 4;  // 35..64 → 30%
           // else               A[i][j] = 5;  // 65..99 → 35%

            int r = rand() % 100; 
            if (r < 10)        A[i][j] = 2; 
            else if (r < 15)   A[i][j] = 3; 
            else if (r < 30)   A[i][j] = 4; 
            else               A[i][j] = 5;
            sum += A[i][j];
            if (A[i][j] == 2) has2 = true;
            if (A[i][j] != 5) all5 = false;
            if (A[i][j] < 4) only45 = false;
            // Цвет по оценке
            switch (A[i][j])
            {
            case 5: SetConsoleTextAttribute(h, 0x0A); break; // зеленый
            case 4: SetConsoleTextAttribute(h, 0x0B); break; // голубой
            case 3: SetConsoleTextAttribute(h, 0x06); break; // желтый
            case 2: SetConsoleTextAttribute(h, 0x0C); break; // красный
            }
            cout << setw(2) << A[i][j];
            SetConsoleTextAttribute(h, 0x07);
            if (j != Marks - 1) cout << " | ";
        }
        double avg = (double)sum / Marks;
        // Цвет по среднему баллу
        if (avg < 3.0) SetConsoleTextAttribute(h, 0x0C);
        else if (avg < 4.0) SetConsoleTextAttribute(h, 0x06);
        else if (avg < 5.0) SetConsoleTextAttribute(h, 0x0B);
        else SetConsoleTextAttribute(h, 0x0A);
        cout << " | " << fixed << setprecision(1) << setw(4) << avg << " |\n";
        SetConsoleTextAttribute(h, 0x07);
        // Разделительная граница
        cout << "+----+";
        for (int k = 0; k < Marks; k++) cout << "----+";
        cout << "------+\n";
        // Классификация
        bad += has2 ? 1 : 0;
        excellent += (!has2 && all5) ? 1 : 0;
        good += (!has2 && !all5 && only45) ? 1 : 0;
    }
    SetConsoleTextAttribute(h, 0x0A); // зелёный
    cout << "\nОтличников: " << excellent << endl;
    SetConsoleTextAttribute(h, 0x0B); // голубой
    cout << "Хорошистов: " << good << endl;
    SetConsoleTextAttribute(h, 0x0C); // красный
    cout << "Двоечников: " << bad << endl;
    SetConsoleTextAttribute(h, 0x07);
    SetConsoleTextAttribute(h, 0x0A);
    cout << "\nДля выхода из программы нажмите любую клавишу..." << endl;
    SetConsoleTextAttribute(h, 0x07);
    system("pause>NUL");
}

