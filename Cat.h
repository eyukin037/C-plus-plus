#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
inline void SetColor(int color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
inline void ResetColor() { SetColor(7); }
inline int RandomColor() { return 1 + rand() % 15; }
inline void SetRandomColor() { SetColor(RandomColor()); }
struct Cat
{
	char name[50];
	char breed[50];
	int age;
	int height;
	float weight;
	char gender[10];
	char color[30];
	char eyeColor[20];
	char woolType[20];
	char character[50];
};
// Удаление пробелов
void Trim(char* str)
{
    int start = 0;
    while (isspace((unsigned char)str[start])) start++;

    int end = strlen(str) - 1;
    while (end >= start && isspace((unsigned char)str[end])) end--;

    int i = 0;
    for (int j = start; j <= end; j++)
        str[i++] = str[j];

    str[i] = '\0';
}

//  Проверка русских букв (CP1251)
bool IsRussianLetter(unsigned char c)
{
    return (c >= 192 && c <= 255) || c == 168 || c == 184;
}

// Проверка строки (только русские буквы и пробелы)
bool IsValidString(const char* str, int minLen = 1)
{
    if (!str) return false;
    int len = strlen(str);
    if (len < minLen) return false;
    bool hasLetter = false;
    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];
        if (IsRussianLetter(c) || c == ' ')
        {
            if (!isspace(c))
                hasLetter = true;
        }
        else
        {
            return false; //  всё кроме русских букв запрещено
        }
    }
    return hasLetter;
}

//  Ввод строки
void InputString(char* buffer, int size, const char* prompt)
{
    while (true)
    {
        SetRandomColor();
        cout << prompt;
        ResetColor();

        cin.getline(buffer, size);
        Trim(buffer);

        if (!IsValidString(buffer))
        {
            SetColor(12);
            cout << "Ошибка! Только русские буквы без цифр и символов.\n";
            ResetColor();
        }
        else
        {
            break;
        }
    }
}

//  Проверка пола
bool IsValidGender(const char* str)
{
    return strcmp(str, "кот") == 0 || strcmp(str, "кошка") == 0;
}

//  Ввод пола
void InputGender(char* buffer, int size)
{
    while (true)
    {
        SetRandomColor();
        cout << "Пол (кот/кошка): ";
        ResetColor();

        cin.getline(buffer, size);
        Trim(buffer);

        if (!IsValidGender(buffer))
        {
            SetColor(12);
            cout << "Ошибка! Введите только 'кот' или 'кошка'.\n";
            ResetColor();
        }
        else
        {
            break;
        }
    }
}

// Ввод чисел
template<typename T>
T InputValue(T min, T max, const char* prompt)
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);

    T value;
    do {
        SetRandomColor();
        cout << prompt;
        ResetColor();

        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');

            SetColor(12);
            cout << "Ошибка! Введите число.\n";
            ResetColor();

            value = min - 1;
        }
        else if (value < min || value > max) {
            SetColor(12);
            cout << "Введите число от " << min << " до " << max << endl;
            ResetColor();
        }
        else {
            cin.ignore(LLONG_MAX, '\n');
            break;
        }

    } while (value < min || value > max);

    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);

    return value;
}
// Ввод кота
void InputCat(Cat& c)
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);
    InputString(c.name, 50, "Кличка: ");
    InputString(c.breed, 50, "Порода: ");
    c.age = InputValue<int>(0, 30, "Возраст: ");
    c.height = InputValue<int>(0, 100, "Рост: ");
    c.weight = InputValue<float>(0.1f, 30.0f, "Вес (кг): ");
    InputGender(c.gender, 10);
    InputString(c.color, 30, "Окрас: ");
    InputString(c.eyeColor, 20, "Цвет глаз: ");
    InputString(c.woolType, 20, "Тип шерсти: ");
    InputString(c.character, 50, "Характер: ");
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);
}

void PrintCat(const Cat& c)
{
	int OCP = GetConsoleOutputCP();
	if (OCP != 1251) SetConsoleOutputCP(1251);
	SetRandomColor();
	cout << "Кличка: " << c.name << endl;
	ResetColor();
	SetRandomColor();
	cout << "Порода: " << c.breed << endl;
	ResetColor();
	if (c.age % 100 >= 11 && c.age % 100 <= 14) {
		SetRandomColor();
		cout << "Возраст: " << c.age << " лет" << endl;
		ResetColor();
	}
	else if (c.age % 10 == 1) {
		SetRandomColor();
		cout << "Возраст: " << c.age << " год" << endl;
		ResetColor();
	}
	else if (c.age % 10 >= 2 && c.age % 10 <= 4) {
		SetRandomColor();
		cout << "Возраст: " << c.age << " года" << endl;
		ResetColor();
	}
	else {
		SetRandomColor();
		cout << "Возраст: " << c.age << " лет" << endl;
		ResetColor();
	}
	SetRandomColor();
	cout << "Рост: " << c.height << " см" << endl;
	ResetColor();
	SetRandomColor();
	cout << "Вес: " << c.weight << " кг" << endl;
	ResetColor();
	SetRandomColor();
	cout << "Пол: " << c.gender << endl;
	ResetColor();
	SetRandomColor();
	cout << "Окрас: " << c.color << endl;
	ResetColor();
	SetRandomColor();
	cout << "Цвет глаз: " << c.eyeColor << endl;
	ResetColor();
	SetRandomColor();
	cout << "Тип шерсти: " << c.woolType << endl;
	ResetColor();
	SetRandomColor();
	cout << "Характер: " << c.character << endl;
	ResetColor();
	SetRandomColor();
	cout << "----------------------\n";
	ResetColor();
	if (OCP != 1251) SetConsoleOutputCP(OCP);
}