// PasswordEyukin
//Написать функцию, принимающую строку Buffer (первый пароль, введённый пользователем) и проверяющую её совпадение с «предыдущим» паролем. 
//«Предыдущий пароль» — это строка, созданная внутри функции и хранящая один из «популярных» надёжных паролей (придумать самостоятельно или 
// найти в Интернете). Функция должна возвращать true, когда пароль совпал с «предыдущим», и false, когда отличается от «предыдущего». 
// В основной части программы (в main) при совпадении введённого пароля с «предыдущим» «заставить» пользователя ввести новый пароль. 
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// смена цвета
void SetColor(int color) { SetConsoleTextAttribute(h, color); }
// генератор случайного цвета 
int RandomColor() { return 1 + rand() % 15; }
// установить случайный цвет
void SetRandomColor() { SetConsoleTextAttribute(h, RandomColor()); }
// Сброс цвета
void ResetColor() { SetColor(7); }
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
    ResetColor();
    cout << "\b ";
}
// функция проверки пароля
bool CheckOldPassword(const char* Buffer)
{
    SetRandomColor();
    const char* OldPassword = "Qwerty123!"; // "предыдущий" пароль
    ResetColor();
    // если строки равны → вернуть true
    return strcmp(Buffer, OldPassword) == 0;
}
int main()
{
    system("chcp 1251>NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Пароль пользователя");
    SetRandomColor();
    cout << "---Программа для создания пароля!---" << endl;
    ResetColor();
    char* Buffer = new char[255]{};
    while (true)
    {
        SetRandomColor();
        cout << "Введите пароль: ";
        ResetColor();
        cin.getline(Buffer, 255);
        // Проверка на пустой ввод
        if (strlen(Buffer) == 0)
        {
            SetRandomColor();
            cout << "Пароль не может быть пустым!\n";
            ResetColor();
            continue;
        }
        // Проверка на совпадение со старым паролем
        if (CheckOldPassword(Buffer))
        {
            SetRandomColor();
            cout << "Пароль совпадает с предыдущим! Введите новый пароль.\n";
            ResetColor();
            continue;
        }
      break; // всё ок — выходим
    }
    SetRandomColor();
    cout << "|";
    ResetColor();
    Spinner(30);
    SetRandomColor();
    cout << "Пароль принят!" << endl;
    ResetColor();
    delete[] Buffer;
    Buffer = nullptr;
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}