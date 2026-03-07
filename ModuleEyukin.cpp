// ModuleEyukin
//Написать макрос взятия модуля числа |A| используя директиву #define и проверить его работу в функции main.
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// смена цвета
#define SetColor(color) SetConsoleTextAttribute(h, (color))
// генератор случайного цвета
#define RandomColor() (1 + rand() % 15)
// установить случайный цвет
#define SetRandomColor() SetConsoleTextAttribute(h, RandomColor())
// анимация обработки
void Spinner(int cycles)
{
    char spin[] = "|/-\\";
    for (int i = 0; i < cycles; i++)
    {
        SetRandomColor();
        cout << "\b" << spin[i % 4];
        Sleep(150);
    }
    cout << "\b ";
}
// Функция подробного вывода
double ShowABS(double value)
{
    SetRandomColor();
    if (value < 0)
    {
        cout << "|" << value << "| = " << -value << endl;
        return -value;
    }
    else
    {
        cout << "|" << value << "| = " << value << endl;
        return value;
    }
}
//макрос - #define ИМЯ(Параметры) (выражение, в которое будут подставлены Параметры и которое будет подставлено в текст программы вместо ИМЕНИ)
// Макрос взятия модуля
#define ABS(A) ((A) < 0 ? -(A) : (A))
//Аналогично #define ABS(A) ((A) > 0 ? (A) : -(A))
#define SQR(X) ((X) * (X))
#define CUBE(y) (SQR(y)*(y))
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("---Макрос взятия модуля числа |A|!---");
    // [1.00 ; 100.00]
    double a = static_cast<double>(rand() % 9901 + 100.0) / 100.0;
    double c = static_cast<double>(rand() % 9901 + 100.0) / 100.0;
    // [-100.00 ; -1.00]
    double b = -static_cast<double>(rand() % 9901 + 100.0) / 100.0;
    double d = -static_cast<double>(rand() % 9901 + 100.0) / 100.0;
    SetRandomColor();
    cout << "a = " << a << ", |a| = " << ABS(a) << endl;
    SetRandomColor();
    cout << "b = " << b << ", |b| = " << ABS(b) << endl;
    SetRandomColor();
    cout << "c = " << c << ", |c| = " << ABS(c) << endl;
    SetRandomColor();
    cout << "d = " << d << ", |d| = " << ABS(d) << endl;
    SetRandomColor();
    cout << "\nОбработка ";
    Spinner(10);
    cout << endl;
    SetRandomColor();
    cout << "Вычисляем |a + c|" << endl;
    double temp1 = a + c;
    SetRandomColor();
    cout << "a + c = (" << a << ") + (" << c << ") = " << temp1 << endl;
    SetRandomColor();
    cout << "|a + c| = " << ShowABS(temp1) << endl << endl;
    SetRandomColor();
    cout << "Вычисляем |b - d|" << endl;
    double temp2 = b - d;
    SetRandomColor();
    cout << "b - d = " << b << " - (" << d << ") = " << temp2 << endl;
    SetRandomColor();
    cout << "|b - d| = " << ShowABS(temp2) << endl << endl;
    SetRandomColor();
    cout << "Вычисляем |b * d|" << endl;
    double temp3 = b * d;
    SetRandomColor();
    cout << "b * d = " << b << " * (" << d << ") = " << temp3 << endl;
    SetRandomColor();
    cout << "|b * d| = " << ShowABS(temp3) << endl << endl;
    SetRandomColor();
    cout << "Вычисляем |b / a|" << endl;
    double temp5;
    if (ABS(a) < 1e-10) // почти ноль
    {
        SetRandomColor();
        cout << "Деление на ноль невозможно!" << endl;
        temp5 = 0; // или любое безопасное значение
    }
    else
    {
        temp5 = b / a;
        SetRandomColor();
        cout << "b / a = " << b << " / (" << a << ") = " << temp5 << endl;
        SetRandomColor();
        cout << "|b / a| = " << ShowABS(temp5) << endl << endl;
    }
    SetRandomColor();
    cout << "e = ABS(SQR(a - b) - CUBE(-d + b - c))" << endl;
    SetRandomColor();
    double step1 = a - b;
    SetRandomColor();
    cout << "1) a - b = " << a << " - " << b << " = " << step1 << endl;
    double step2 = SQR(step1);
    SetRandomColor();
    cout << "2) SQR(" << step1 << ") = " << step1 << "^2 = " << step2 << endl;
    double step3 = -d + b - c;
    SetRandomColor();
    cout << "3) -d + b - c = " << -d << " + " << b << " - (" << c << ") = " << step3 << endl;
    double step4 = CUBE(step3);
    SetRandomColor();
    cout << "4) CUBE(" << step3 << ") = " << step3 << "^3 = " << step4 << endl;
    double step5 = step2 - step4;
    SetRandomColor();
    cout << "5) " << step2 << " - " << step4 << " = " << step5 << endl;
    SetRandomColor();
    cout << "6) Берем модуль:" << endl;
    double e = ShowABS(step5);
    SetRandomColor();
    cout << "\nИТОГ: e = " << e << endl;
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу!" << endl;
    SetColor(7); // вернуть стандартный цвет
    system("pause > NUL");
}

