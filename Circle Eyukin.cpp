// Circle Eyukin
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    // Заголовок программы
    cout << "---Программа для вычисления площади круга и длины окружности!---" << endl;
    // Объявляем константу Пи
    const float PI = 3.14;
    // Объявляем переменные
    float Radius = 0, Area = 0, Circumference = 0;
    // Ввод радиуса круга
    cout << "Введите радиус круга: "; cin >> Radius;
    // Вычисления площади круга Area и длины окружности Circumference
    Area = PI * Radius * Radius;
    Circumference = 2 * PI * Radius;
    // Вывод результатов 
    cout << "Площадь круга с заданным радиусом равна: " << Area << endl;
    cout << "Длина окружности с заданным радиусом равна: " << Circumference << endl;
    cout << "Для выхода из программы нажмите любую клавишу...";
    system("pause > NUL");
}