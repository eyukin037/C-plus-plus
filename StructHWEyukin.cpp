// StructHWEyukin
//Написать программу «ОнлайнКинотеатр», содержащую:
//Структуру «Film» с полями : Название фильма, жанр, дата выхода(тип данных Date) и цена.
//Функции для работы с объектами структуры : вывода на экран, заполнения и поиска.
//Создать динамический массив объектов структуры, заполнить его с клавиатуры, организовать в нём поиск по году или жанру с помощью функций, работающих с объектами структуры.Вывести результаты поиска на экран.
//Структуры Date и «Film» разместить в отдельных заголовочных файлах с расширением.h и прикрепить все три файла одним архивом.
#include "Film.h"
//#include <Windows.h>
//#include <time.h>
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
int main()
{
    // установка кодировки консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitleA("Онлайн Кинотеатр");
    SetRandomColor();
    cout << "Посещение онлайн-кинотеатра! \n";
    ResetColor();
    // количество фильмов
    int Size = 0;
    SetRandomColor();
    cout << "Введите количество фильмов: ";
    ResetColor();
    cin >> Size; 
    // динамический массив объектов структуры Film
    Film* Cinema = new Film[Size]{};
    // заполнение массива
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor(); 
        cout << "\nВведите данные для фильма #" << i + 1 << endl;
        ResetColor();

        // ввод через ссылку
        Input(Cinema[i]);
    }
    // очистка экрана
    system("cls");
    // вывод всех фильмов
    SetRandomColor();
    cout << "Список всех фильмов \n";
    ResetColor();
    for (int i = 0; i < Size; i++)
    {
        Show(Cinema[i]);
    }
    // поиск по году
    int year = 0;
    SetRandomColor(); 
    cout << "\nВведите год для поиска: "; 
    ResetColor();
    cin >> year;
    cout << " "; 
    Spinner(10);
    FindByYear(Cinema, Size, year);    
    // поиск по жанру
    char genre[30]{};
    cin.ignore();
    SetRandomColor(); 
    cout << "\nВведите жанр для поиска: ";
    ResetColor();
    cin.getline(genre, 30);
    cout << " ";
    Spinner(10);
    FindByGenre(Cinema, Size, genre);
    // освобождение памяти
    delete[] Cinema;
    Cinema = nullptr;
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}