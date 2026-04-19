#pragma once
#include "Date.h"
#include <string.h>
//#include <iostream>
using namespace std;
// определение структуры Film
struct Film // Film - новый тип данных
{
    // поля структуры
    char Name[50];     // Название фильма
    char Genre[30];    // Жанр
    Date Release;      // Дата выхода
    double Price;      // Цена
};
// функция вывода объекта структуры Film
void Show(Film F)
{
    // проверка кодировки
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    SetRandomColor();
    cout << "Название: " << F.Name << endl;
    ResetColor();
    SetRandomColor();
    cout << "Жанр: " << F.Genre << endl;
    ResetColor();
    SetRandomColor();
    cout << "Дата выхода: ";
    ResetColor();
    Show(F.Release);
    cout << endl;
    SetRandomColor();
    cout << "Цена: " << F.Price << " руб." << endl;
    ResetColor();
    SetRandomColor();
    cout << "------------------------" << endl;
    ResetColor();
    // возврат кодировки
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
// функция ввода (по ссылке)
void Input(Film& REF)
{
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (CP != 1251) SetConsoleCP(1251);
    cin.ignore();
    SetRandomColor();
    cout << "Введите название: ";
    ResetColor();
    cin.getline(REF.Name, 50);
    SetRandomColor();
    cout << "Введите жанр: ";
    ResetColor();
    cin.getline(REF.Genre, 30);
    Input(REF.Release);
    SetRandomColor();
    cout << "Введите цену: ";
    ResetColor();
    cin >> REF.Price;
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    if (CP != 1251) SetConsoleCP(CP);
}
// поиск фильмов по году
void FindByYear(Film* arr, int size, int year)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    bool found = false;
    SetRandomColor();
    cout << "\nФильмы за " << year << " год:\n";
    ResetColor();
    for (int i = 0; i < size; i++)
    {
        if (arr[i].Release.Year == year)
        {
            Show(arr[i]);
            found = true;
        }
    }
    if (!found)
    {
        SetRandomColor();
        cout << "Ничего не найдено.\n";
        ResetColor();
    }
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
// поиск фильмов по жанру
void FindByGenre(Film* arr, int size, const char* genre)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);

    bool found = false;

    SetRandomColor();
    cout << "\nФильмы жанра: " << genre << endl;
    ResetColor();
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].Genre, genre) == 0)
        {
            Show(arr[i]);
            found = true;
        }
    }
    if (!found)
    {
        SetRandomColor();
        cout << "Ничего не найдено.\n";
        ResetColor();
    }
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}