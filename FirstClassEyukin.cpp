// FirstClassEyukin
//Добавить в класс Student поле «Группа». Добавить метод Set и Get для него и включить это поле во все существующие методы, где
//это необходимо. В main создать массив студентов и организовать поиск по группе и вывод найденных студентов на экран в глобальной 
//функции, написанной в файле, где расположена функция main.
//#include <iostream>    //уже не требуется, так как она подключена в Student.h
#include <stdlib.h>
//если класс находится в том же каталоге, что и основной проект
#include "Student.h" //подключаем заголовочный файл, содержащий описание класса Student
//#include "D:\TOP Шамбала\БД511\FirstClass\Student.h"  //подключение по полному пути
//если класс находится в другом каталоге 
//#include "D:\Библиотеки\Student\Student.h"  //подключение по полному пути

//using namespace std; //уже не требуется, так как она подключена в Student.h
void FindByGroup(Student* arr, int size, string group)
{
    bool Find = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].Get_Group() == group)
        {
            arr[i].Show();
            cout << endl;
            Find = true;
        }
    }
    if (!Find){
        SetRandomColor();
        cout << "Студенты из группы не найдены!" << endl;
        ResetColor();
    }
}
void FindByLastName(Student* arr, int size, string lastName)
{
    bool find = false;

    for (int i = 0; i < size; i++)
    {
        if (arr[i].Get_Last_Name() == lastName)
        {
            arr[i].Show();
            cout << endl;
            find = true;
        }
    }

    if (!find)
    {
        SetRandomColor();
        cout << "Студент с такой фамилией не найден!" << endl;
        ResetColor();
    }
}
int main()
{
    system("chcp 1251 > NUL");
    srand(time(nullptr));
    SetConsoleTitleA("Студенты");
    SetRandomColor();
    cout << "Текущее кол-во студентов: " << Student::Get_Count() << endl;
    ResetColor();
    // ввод размера массива
    int Size = 0;
    SetRandomColor();
    cout << "Введите кол-во студентов: ";
    ResetColor();
    cin >> Size;

    //выделение памяти
    Student* PD511 = new (nothrow) Student[Size]{};

    if (!PD511)
    {
        SetRandomColor();
        cout << "Ошибка выделения памяти!" << endl;
        ResetColor();
        return 0;
    }

    // ввод студентов
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "\nВведите данные " << i + 1 << "-го студента:\n";
        ResetColor();
        PD511[i].Set_Console_Input();
        system("cls");
    }

    // вывод всех студентов
    SetRandomColor();
    cout << "\nСписок всех студентов:\n";
    ResetColor();
    for (int i = 0; i < Size; i++)
    {
        PD511[i].Show();
        cout << endl;
    }
    SetRandomColor();
    cout << "Текущее кол-во студентов: " << Student::Get_Count() << endl;
    ResetColor();
    system("pause");
    system("cls");
    // Поиск по группе
    string group;
    SetRandomColor();
    cout << "Введите группу для поиска: ";
    ResetColor();
    cin >> group;
    SetRandomColor();
    cout << "\nСтуденты из группы:\n";
    ResetColor();
    FindByGroup(PD511, Size, group);
    system("pause");
    system("cls");
    // Поиск по фамилии
    string lastName;
    SetRandomColor();
    cout << "Введите фамилию студента для поиска: ";
    ResetColor();
    cin >> lastName;
    SetRandomColor();
    cout << "\nРезультат поиска по фамилии:\n";
    ResetColor();
    FindByLastName(PD511, Size, lastName);
    // Освобождение памяти
    delete[] PD511;
    PD511 = nullptr;
    /*
    SetRandomColor();
    cout << "\nПосле удаления массива:\n";
    ResetColor();
    */
    SetRandomColor();
    cout << "Текущее кол-во студентов: " << Student::Get_Count() << endl;
    ResetColor();

/*
    //тестовый объект
    Student Pushkin{"Пушкин", "Александр", "A1", 19, "Сергеевич", "М", "+71234567890", 3};
    Pushkin.Set_Grades();
    cout << endl;
    Pushkin.Show();
    SetRandomColor();
    cout << "Текущее кол-во студентов: " << Student::Get_Count() << endl;
    ResetColor();
*/
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}