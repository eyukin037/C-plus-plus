// Password+Eyukin
//Написать функцию, принимающую строку Buffer(первый пароль, введенный пользователем) и проверяющую её совпадение с "предыдущим" паролем. 
//"Предыдущий пароль" - это строка созданная внутри функции и хранящая один из "Популярных" надежных паролей(придумать самостоятельно или найти в
//Интернете). Функция должна возвращать true когда пароль совпал с "предыдущим" и false когда отличается от "предыдущего". В основной части 
//программы (в main) при совпадении введенного пароля с "предыдущим" "заставить" пользователя ввести новый пароль. Если новый пароль отличается 
//от предыдущего, заменить предыдущий в функции на новый
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color) { SetConsoleTextAttribute(h, color); }
int RandomColor() { return 1 + rand() % 15; }
void SetRandomColor() { SetConsoleTextAttribute(h, RandomColor()); }
void ResetColor() { SetColor(7); }
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
// Функция проверки и обновления пароля
bool CheckAndUpdatePassword(const char* inputBuffer)
{
    // "Предыдущий пароль" внутри функции
    static char* oldPassword = []() {
        const char* init = "admin123!";
        char* buf = new char[strlen(init) + 1];
        strcpy_s(buf, strlen(init) + 1, init);
        return buf;
    }();
    if (strcmp(inputBuffer, oldPassword) == 0)
    {
        return true; // совпал
    }
    else
    {
        // обновляем пароль (динамическая память)
        delete[] oldPassword;
        int len = strlen(inputBuffer) + 1;
        oldPassword = new char[len];
        strcpy_s(oldPassword, len, inputBuffer);
        SetRandomColor();
        cout << "Предыдущий пароль обновлён.\n";
        ResetColor();
        return false;
    }
}

int main()
{
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Пароль пользователя");
    SetRandomColor();
    cout << "--- Программа для создания пароля ---" << endl;
    ResetColor();
    char inputBuffer[255];
    while (true)
    {
        SetRandomColor();
        cout << "Введите пароль: ";
        ResetColor();
        cin.getline(inputBuffer, 255);
        Spinner(10);
        if (strlen(inputBuffer) == 0)
        {
            SetRandomColor();
            cout << "Пароль не может быть пустым!\n";
            ResetColor();
            continue;
        }
        Spinner(10);
        if (CheckAndUpdatePassword(inputBuffer))
        {
            SetRandomColor();
            cout << "Пароль совпадает с предыдущим! Введите новый.\n";
            ResetColor();
            continue;
        }
        break;
    }
    SetRandomColor();
    cout << "Для выхода нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}