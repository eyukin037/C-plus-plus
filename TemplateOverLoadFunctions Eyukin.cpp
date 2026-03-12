//TemplateOverLoadFunctions Eyukin
//2.Сделать перегруженные функции шаблонными.Проверить работу всех трех шаблонов на различных типах данных
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
// Для 2 значений
template <typename T> T Max(T a, T b)
{
    return (a > b) ? a : b;
}
// Для 3 значений
template <typename T> T Max(T a, T b, T c)
{
    return (a > b && a > c) ? a : (b > c ? b : c);
}
// Для 4 значений
template <typename T> T Max(T a, T b, T c, T d)
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
    SetConsoleTitleA("---Перегруженные шаблонные функции---");
    int A1 = rand() % 100 - 100;   // [-100; -1]
    int B1 = rand() % 100 - 100;   // [-100; -1]
    int C1 = rand() % 100 + 1;     // [1; 100]
    int D1 = rand() % 100 + 1;     // [1; 100]
    double A2 = (rand() % 1000) / 10.0 - 100;  // [-100; -0.1]
    double B2 = (rand() % 1000) / 10.0 - 100;  // [-100; -0.1]
    double C2 = (rand() % 1000) / 10.0 + 0.1;    // [0.1; 100]
    double D2 = (rand() % 1000) / 10.0 + 0.1;    // [0.1; 100]
    char A3 = 'A' + rand() % 6;   // A–F
    char B3 = 'G' + rand() % 6;   // G–L
    char C3 = 'M' + rand() % 6;   // M–R
    char D3 = 'S' + rand() % 6;   // S–X
    SetRandomColor();
    cout << "INT: " << A1 << " " << B1 << " " << C1 << " " << D1 << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из двух целых чисел: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A1, B1) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из трёх целых чисел: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A1, B1, C1) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из четырёх целых чисел: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A1, B1, C1, D1) << "\n\n";
    SetRandomColor();
    cout << "DOUBLE: " << A2 << " " << B2 << " " << C2 << " " << D2 << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из двух чисел типа double: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A2, B2) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из трёх чисел типа double: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A2, B2, C2) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из четырёх чисел типа double: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A2, B2, C2, D2) << "\n\n";
    SetRandomColor();
    cout << "CHAR: " << A3 << " " << B3 << " " << C3 << " " << D3 << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из двух символов: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A3, B3) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из трёх символов: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A3, B3, C3) << "\n\n";
    SetRandomColor(); cout << "Поиск максимума из четырёх символов: ";
    Spinner(15);
    SetRandomColor(); cout << "\nМаксимум: " << Max(A3, B3, C3, D3) << "\n\n";
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}

