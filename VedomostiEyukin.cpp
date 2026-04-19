// VedomostiEyukin
//Написать программу учета сдачи зачетов и экзаменов при помощи структуры с битовыми полями. Структура "Студент" содержит поля: фамилия, группа, зачеты(несколько битовых полей) и экзамены (несколько битовых полей).
//Экзамены - каждое поле 3 бита (значение от 2 до 5) зачеты - каждое поле 1 бит(1 сдал, 0 не сдал).  Написать функции заполнения структуры с клавиатуры и вывода данных на экран. Структуру и функции реализовать в отдельном 
//заголовочном файле Student.h. Создать трех студентов разной успеваемости и вывести данные о них на экран
#include "Student.h"
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
    srand((unsigned int)time(nullptr)); 
    SetConsoleTitleA("Ведомость");
    SetRandomColor();
    cout << "Ведомость! \n";
    ResetColor();
    Student s1, s2, s3;
    // Ввод первого студента
    system("cls");
    SetRandomColor();
    cout << "Введите данные студента 1\n";
    ResetColor();
    InputStudent(s1);
    // Ввод второго студента
    system("cls");
    SetRandomColor();
    cout << "Введите данные студента 2\n";
    ResetColor();
    InputStudent(s2);
    // Ввод третьего студента
    system("cls");
    SetRandomColor();
    cout << "Введите данные студента 3\n";
    ResetColor();
    InputStudent(s3);
    // Финальная анимация и вывод
    system("cls");
    SetRandomColor();
    cout << "Обработка данных... ";
    ResetColor();
    Spinner(10);
    system("cls"); // Очищаем перед финальным списком
    SetRandomColor();
    cout << "Данные всех студентов: \n";
    ResetColor();
    Student students[3] = { s1, s2, s3 };
    int surnameWidth = MaxLengthSurname(students, 3);
    int groupWidth = MaxLengthGroup(students, 3);
    PrintHeader(students, 3);
    for (int i = 0; i < 3; i++) {
        PrintRow(students[i], surnameWidth, groupWidth);
        PrintLine(surnameWidth, groupWidth);
    }
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}