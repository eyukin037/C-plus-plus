#pragma once
#include <iostream>
#include <Windows.h>
//#include <stdlib.h>
using namespace std;
struct Date
{
    unsigned short Day;
    char Month[15];
    short Year;
};
inline void SetColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
inline void ResetColor() { SetColor(7); } 
inline int RandomColor() { return 1 + rand() % 15; }
inline void SetRandomColor() { SetColor(RandomColor()); }
// вывод даты
void Show(Date D)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    SetRandomColor();
    cout << D.Day << " " << D.Month << " " << D.Year;
    ResetColor();
    if (OCP != 1251) SetConsoleOutputCP(OCP);

}
// ввод (возврат объекта)
Date Input()
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);
    Date temp{};
    cin >> temp.Day >> temp.Month >> temp.Year;
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);
    return temp;
}
/* ввод по указателю
void Input(Date* ptr)
{
    cout << "¬ведите день: "; cin >> ptr->Day;
    cout << "¬ведите мес€ц: "; cin >> ptr->Month;
    cout << "¬ведите год: "; cin >> ptr->Year;
}
*/
// ввод по ссылке
void Input(Date& ref)
{
    //узнать текущие кодировки на вывод и ввод текста
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    //если текущие кодировки нам не подход€т, мен€ем на нужные
    if (OCP != 1251)SetConsoleOutputCP(1251);  //установка кодировки на вывод текста
    if (CP != 1251)SetConsoleCP(1251); //установка общей кодировки(на ввод теста)
    SetRandomColor();
    cout << "¬ведите день: ";
    ResetColor();
    cin >> ref.Day; 
    SetRandomColor();
    cout << "¬ведите мес€ц: ";
    ResetColor();
    cin >> ref.Month;
    SetRandomColor();
    cout << "¬ведите год: "; 
    ResetColor();
    cin >> ref.Year; 
    //если кодировки мен€лись нужно вернуть прежние
    if (OCP != 1251)SetConsoleOutputCP(OCP);
    if (CP != 1251)SetConsoleCP(CP);
}