// perevod cm to inch and back Eyukin.cpp  
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "---Программа перевода сантиметров в дюймы и дюймов в сантиметры!---" << endl;
    const double INCH_TO_CM = 2.54;
    double inch = 0.0, cm = 0.0L;
    // Перевод сантиметров в дюймы
    cout << "Введите количество сантиметров: ";
    cin >> cm;
    inch = cm / INCH_TO_CM;
    cout << cm << " сантиметров = " << inch << " дюймов" << endl;
    // Перевод дюймов в сантиметры
    cout << "Введите количество дюймов: ";
    cin >> inch;
    cm = inch * INCH_TO_CM;
    cout << inch << " дюймов = " << cm << " сантиметров" << endl;
    cout << "Для выхода из программы нажмите любую клавишу...";
    system("pause > NUL");
}
