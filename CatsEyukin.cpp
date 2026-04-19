// CatsEyukin
//Создать структуру Кошка с полями (кличка, порода, возраст и т. д.) и функции (заполнения полей и функцию вывода данных на экран). 
//Создать несколько объектов и проверить работу функций.
#include "Cat.h"
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
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Кошки");
    SetRandomColor();
    cout << "Кошки! \n";
    ResetColor();
    Cat c1, c2, c3;
    system("cls");
    SetRandomColor();
    cout << "Введите данные кошки 1\n";
    ResetColor();
    InputCat(c1);
    system("cls");
    SetRandomColor();
    cout << "Введите данные кошки 2\n";
    ResetColor();
    InputCat(c2);
    system("cls");
    SetRandomColor();
    cout << "Введите данные кошки 3\n";
    ResetColor();
    InputCat(c3);
    system("cls");
    SetRandomColor();
    cout << "Список кошек:\n";
    ResetColor();
    Spinner(10);
    SetRandomColor();
    cout << "----------------------\n";
    ResetColor();
    PrintCat(c1);
    PrintCat(c2);
    PrintCat(c3);
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}