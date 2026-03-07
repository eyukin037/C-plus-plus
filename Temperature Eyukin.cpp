// Temperature Eyukin
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
using namespace std;
int main()
{
    system("chcp 1251 > NUL");
    //аналогично 
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    // заголовок программы
    SetConsoleTitleA("---Температура воздуха за январь!---");
    const int DAYS = 31;
    int temp[DAYS]; 
    int mark = 0;
    int countBelowMark = 0;
    HANDLE h{}; //"переменная" для хранения дескриптора окна консоли нашей программы
    h = GetStdHandle(STD_OUTPUT_HANDLE);  //получаем информацию об окне консоли про отображаемые в ней данные
    //Цвета по умолчанию, Фон - 0 Черный, Текст 7 - Светло-Серый 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // зелёный
    cout << "Температура воздуха за январь: \n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  // стандартный
    // I. Заполнение массива случайными температурами от -27 до -12
    for (int i = 0; i < DAYS; i++)
    {
        int color = rand() % 15 + 1; // случайный цвет 1..15
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
        //rand() % (A - B) + B - формула генератора случайных чисел с B до A(B...A - 1)	
     	//Включая В, но не включая A
		//от В до А-1 включительно
        //Подставляем числовые значения в выражение temp[i] = rand() % (-12 - (-27) + 1) + (-27); 
        // В результате упрощения выражение temp[i] примет вид:
        temp[i] = rand() % 16 - 27; 
        cout << "День " << i + 1 << ": " << temp[i] << " °C\n";
    }
    // вернуть стандартный цвет
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << endl;
    // а) Средняя температура за месяц
    double sum = 0;
    for (int i = 0; i < DAYS; i++)
        sum += temp[i];
    double avg = sum / DAYS;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // зелёный
    cout << "Средняя температура за месяц: " << avg << " °C\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    // б) Температура ниже средней
    int countBelowAvg = 0;
    cout << "Температура ниже средней была в дни:\n";
    for (int i = 0; i < DAYS; i++)
    {
        if (temp[i] < avg)
        {
            int color = rand() % 15 + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            cout << i + 1 << " ";
            countBelowAvg++;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "\nКоличество раз: " << countBelowAvg << "\n\n";
    // в) Ниже заданной пользователем отметки
    do
    {
        cout << "Введите температурную отметку: ";
        cin >> mark;

        if (cin.fail()) // поток сломался
        {
            cout << "Ошибка! Введите число!\n";
            cin.clear();                 // сброс флага ошибки
            cin.ignore(LLONG_MAX, '\n'); // очистка буфера
        }
        else
        {
            cin.ignore(LLONG_MAX, '\n'); // очистка буфера
            break; // корректный ввод — выходим из цикла
        }

    } while (true);  
    cout << "Температура ниже " << mark << " °C была в дни:\n";
    for (int i = 0; i < DAYS; i++)
    {
        if (temp[i] < mark)
        {
            int color = rand() % 15 + 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
            cout << i + 1 << " ";
            countBelowMark++;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "\nКоличество раз: " << countBelowMark << endl;
    cout << "\nДля выхода из программы нажмите любую клавишу!" << endl;
    system("pause > NUL");
}