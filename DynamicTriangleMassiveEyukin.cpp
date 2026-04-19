// DynamicTriangleMassiveEyukin.cpp 
//Реализовать работу с "треугольным" динамическим массивом(Урок 15, стр. 10) Вывести массив на экран и найти в нем элемент с 
//максимальным значением. Пользователь задает размер максимальной строки, способ создания(в 0-й строке заданное кол-во элементов, 
//в последней 1 элемент или наоборот) Под* добавить выбор способа вывода на экран (прямоугольный треугольник или равносторонний (равнобедренный)).
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
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
// Функция для вывода двумерного массива в виде равнобедренного (равностороннего) треугольника (более профессиональный) (I способ согласно текущему занятию)
//void printisoscelestriangle(int** arr, int rows, int* rowlengths, const string& name) {
 //   const int width = 5; // ширина одного элемента
 //   int maxcols = 0;
// найдём максимальную длину строки
 //   for (int i = 0; i < rows; i++)
 //       if (rowlengths[i] > maxcols) maxcols = rowlengths[i];
 //  SetRandomColor();
 //  cout << "массив " << name << " (равнобедренный треугольник):" << endl;
 // ResetColor();
 //   for (int i = 0; i < rows; i++) {
 //      int currentlen = rowlengths[i];
 //      int totalwidth = maxcols * width;    // ширина самой длинной строки
 //      int rowwidth = currentlen * width;   // ширина текущей строки
 //      int leftpad = (totalwidth - rowwidth) / 2;
 // выводим нужное количество пробелов перед всей строкой
 //      cout << setw(leftpad) << "";
 // выводим все элементы текущей строки
 //      for (int j = 0; j < currentlen; j++) {
 //          SetRandomColor();
 //          cout << setw(width - 1) << arr[i][j] << " ";
 //          ResetColor();
 //      }
 //      cout << endl;
 //  }
 //  cout << endl;
//} 
// Функция для вывода двумерного массива в виде равнобедренного (равностороннего) треугольника (более предпочтительный через string (строку)) (II способ согласно следующему занятию)
void printIsoscelesTriangle(int** arr, int rows, int* rowLengths, const string& name) {
    const int width = 5; // ширина одного элемента (включая пробел)
    int maxCols = 0;
    for (int i = 0; i < rows; i++)
        if (rowLengths[i] > maxCols) maxCols = rowLengths[i];
    SetRandomColor();
    cout << "Массив " << name << " (равнобедренный треугольник):" << endl;
    ResetColor();
    for (int i = 0; i < rows; i++) {
        int currentLen = rowLengths[i];
        int spaces = (maxCols - currentLen) * width / 2;
        cout << string(spaces, ' ');
        for (int j = 0; j < currentLen; j++) {
            SetRandomColor();
            cout << setw(width - 1) << arr[i][j] << " ";
            ResetColor();
        }
        cout << endl;
    }
    cout << endl;
}
// Функция для вывода двумерного массива в виде прямоугольного треугольника
void printRightTriangle(int** arr, int rows, int* rowLengths, const string& name) {
    SetRandomColor();
    cout << "Массив " << name << " (прямоугольный треугольник):" << endl;
    ResetColor();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowLengths[i]; j++) {
            SetRandomColor();
            cout << setw(4) << arr[i][j] << " ";
            ResetColor();
        }
        cout << endl;
    }
    cout << endl;
}
// Функция поиска максимального элемента
int findMaxElement(int** arr, int rows, int* rowLengths) {
    int maxElement = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rowLengths[i]; j++) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }
    }
    return maxElement;
}
// Очистка памяти
void freeMemory(int** arr, int* rowLengths, int rows) {
    if (arr != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    delete[] rowLengths;
}
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251); 
    //srand(time(NULL));
    //time(NULL); //для языка C
    //time(nullptr); //так корректнее для C++
    //srand((unsigned int)time(NULL)); //для языка C
    srand((unsigned int)time(nullptr)); //так корректнее для C++
    //srand(static_cast<unsigned int>(time(nullptr))); //так ещё корректнее для C++
    SetConsoleTitleA("Треугольный динамический массив");
    SetRandomColor();
    cout << "---Программа для создания треугольного динамического массива!---" << endl;
    ResetColor();
    int rows;
    SetRandomColor();
    cout << "Введите количество строк (N) от двух и более: ";
    ResetColor();
    cin >> rows;
    if (rows <= 1) {
        SetRandomColor();
        cout << "Ошибка: количество строк должно быть больше 1." << endl;
        ResetColor();
        return 1;
    }
    SetRandomColor();
    cout << "|";
    ResetColor();
    Spinner(30);
    int creationChoice;
    SetRandomColor();
    cout << "Выберите способ создания массива:\n";
    ResetColor();
    SetRandomColor();
    cout << "1 — 0-я строка: максимальное количество элементов, последняя строка: 1 элемент\n";
    ResetColor();
    SetRandomColor();
    cout << "2 — 0-я строка: 1 элемент, последняя строка: максимальное количество элементов\n";
    ResetColor();
    SetRandomColor();
    cout << "Ваш выбор: ";
    ResetColor();
    cin >> creationChoice;
    if (creationChoice != 1 && creationChoice != 2) {
        SetRandomColor();
        cout << "Ошибка: неверный выбор способа создания массива." << endl;
        ResetColor();
        return 1;
    }
    SetRandomColor();
    cout << "|";
    ResetColor();
    Spinner(10);
    int triangleChoice;
    SetRandomColor();
    cout << "Выберите форму треугольника:\n";
    ResetColor();
    SetRandomColor();
    cout << "1 — равнобедренный\n";
    ResetColor();
    SetRandomColor();
    cout << "2 — прямоугольный\n";
    ResetColor();
    SetRandomColor();
    cout << "Ваш выбор: ";
    ResetColor();
    cin >> triangleChoice;
    if (triangleChoice != 1 && triangleChoice != 2) {
        SetRandomColor();
        cout << "Ошибка: неверный выбор формы треугольника." << endl;
        ResetColor();
        return 1;
    }
    SetRandomColor();
    cout << "|";
    ResetColor();
    Spinner(10);
    // Выделение памяти
// Выделение памяти для массива указателей
    int** arr = new (nothrow) int* [rows];
    if (!arr) {
        SetRandomColor();
        cout << "Ошибка выделения памяти для массива указателей!" << endl;
        ResetColor();
        return 1;
    }
    // Выделение памяти для массива длин строк
    int* rowLengths = new (nothrow) int[rows];
    if (!rowLengths) {
        SetRandomColor();
        cout << "Ошибка выделения памяти для массива длин строк!" << endl;
        ResetColor();
        delete[] arr;
        return 1;
    }
    // Выделение памяти для каждой строки
    for (int i = 0; i < rows; i++) {
        int len = (creationChoice == 1) ? (rows - i) : (i + 1);
        rowLengths[i] = len;
        arr[i] = new (nothrow) int[len];
        if (!arr[i]) {
            SetRandomColor();
            cout << "Ошибка выделения памяти для строки " << i << "!" << endl;
            ResetColor();
            // Освобождаем уже выделенную память
            for (int j = 0; j < i; j++) {
                delete[] arr[j];
            }
            delete[] arr;
            delete[] rowLengths;
            return 1;
        }
        for (int j = 0; j < len; j++) {
            arr[i][j] = rand() % 199 - 99;
        }
    }
    // Вывод массива
    if (triangleChoice == 1) printIsoscelesTriangle(arr, rows, rowLengths, "треугольный");
    else printRightTriangle(arr, rows, rowLengths, "прямоугольный");
    // Максимальный элемент
    int maxElement = findMaxElement(arr, rows, rowLengths);
    SetRandomColor();
    cout << "Максимальный элемент в массиве: " << maxElement << endl;
    ResetColor();
    // Очистка памяти
    freeMemory(arr, rowLengths, rows);
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}