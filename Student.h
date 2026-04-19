#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
inline void SetColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
inline void ResetColor() { SetColor(7); }
inline int RandomColor() { return 1 + rand() % 15; }
inline void SetRandomColor() { SetColor(RandomColor()); }
struct Student
{
    char surname[50];
    char group[20];
    //зачёты
    unsigned int test1 : 1;
    unsigned int test2 : 1;
    unsigned int test3 : 1;
    //экзамены 
    unsigned int exam1 : 3;
    unsigned int exam2 : 3;
    unsigned int exam3 : 3;
};
int InputValue(int min, int max, const char* prompt)
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);
    int temp;
    do {
        SetRandomColor();
        cout << prompt;
        ResetColor();
        cin >> temp;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(LLONG_MAX, '\n'); 
            SetColor(12); 
            cout << "Ошибка! Введите число.\n";
            ResetColor();
            if (OCP != 1251) SetConsoleOutputCP(OCP);
            if (CP != 1251) SetConsoleCP(CP);
            temp = min - 1; 
        }
        else if (temp < min || temp > max) { // если число вне диапазона
            cin.ignore(LLONG_MAX, '\n');
            SetColor(12);
            cout << "Ошибка! Введите значение от " << min << " до " << max << ".\n";
            ResetColor();
        }
        else {
            cin.ignore(LLONG_MAX, '\n');
            break;
        }
    } while (temp < min || temp > max);
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);
    return temp;
}
void InputStudent(Student& s)
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);
    SetRandomColor();
    cout << "Фамилия: ";
    ResetColor();
    cin.getline(s.surname, 50);
    SetRandomColor();
    cout << "Группа: ";
    ResetColor();
    cin.getline(s.group, 20);
    SetRandomColor();
    cout << "Зачеты (0 - не сдал, 1 - сдал) \n";
    ResetColor();
    s.test1 = InputValue(0, 1, "Зачет 1: ");
    s.test2 = InputValue(0, 1, "Зачет 2: ");
    s.test3 = InputValue(0, 1, "Зачет 3: ");
    SetRandomColor();
    cout << "Экзамены (оценки 2-5) \n";
    ResetColor();
    s.exam1 = InputValue(2, 5, "Экзамен 1: ");
    s.exam2 = InputValue(2, 5, "Экзамен 2: ");
    s.exam3 = InputValue(2, 5, "Экзамен 3: ");
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);
}
int MaxLengthSurname(const Student students[], int count) {
    int maxLen = strlen("Фамилия"); 
    for (int i = 0; i < count; i++) {
        int len = strlen(students[i].surname);
        if (len > maxLen) maxLen = len;
    }
    return maxLen;
}
int MaxLengthGroup(const Student students[], int count) {
    int maxLen = strlen("Группа");
    for (int i = 0; i < count; i++) {
        int len = strlen(students[i].group);
        if (len > maxLen) maxLen = len;
    }
    return maxLen;
}
void PrintCentered(const char* text, int width) {
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    int len = strlen(text);
    int padding = (width - len) / 2;
    int extra = (width - len) % 2; // если ширина нечетная
    for (int i = 0; i < padding; i++) cout << ' ';
    cout << text;
    for (int i = 0; i < padding + extra; i++) cout << ' ';
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
void PrintLine(int surnameWidth, int groupWidth) {
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    cout << "+" << string(surnameWidth + 2, '-') << "+" << string(groupWidth + 2, '-') << "+----+----+----+----+----+----+\n";
    if (OCP != 1251) SetConsoleOutputCP(OCP);

}
void PrintHeader(const Student students[], int count)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    int surnameWidth = MaxLengthSurname(students, count);
    int groupWidth = MaxLengthGroup(students, count);
    PrintLine(surnameWidth, groupWidth);
    cout << "| ";
    SetRandomColor();
    PrintCentered("Фамилия", surnameWidth);
    ResetColor();
    cout << " | ";
    SetRandomColor();
    PrintCentered("Группа", groupWidth);
    ResetColor();
    SetRandomColor();
    cout << " | З1 | З2 | З3 | Э1 | Э2 | Э3 |\n";
    ResetColor();
    PrintLine(surnameWidth, groupWidth);
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
void PrintRow(const Student& s, int surnameWidth, int groupWidth)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    SetRandomColor();
    cout << "| " << setw(surnameWidth) << left << s.surname << " | " << setw(groupWidth) << left << s.group << " | " << setw(2) << s.test1 << " | " << setw(2) << s.test2 << " | " << setw(2) << s.test3  << " | " << setw(2) << s.exam1 << " | " << setw(2) << s.exam2 << " | " << setw(2) << s.exam3 << " |\n";
    ResetColor();
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}