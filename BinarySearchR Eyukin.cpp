// BinarySearchR Eyukin
//2.* Написать шаблон рекурсивной функции, реализующей бинарный поиск с возможностью выбора направления сортировки массива, в котором происходит поиск.
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
// Смена цвета
void SetColor(int color) { SetConsoleTextAttribute(h, color); }
// Генератор случайного цвета
int RandomColor() { return 1 + rand() % 15; }
// Установить случайный цвет
void SetRandomColor() { SetConsoleTextAttribute(h, RandomColor()); }
// Сброс цвета
void ResetColor() { SetColor(7); }
// Анимация обработки
void Spinner(int cycles) {
    char spin[] = "|/-\\";
    for (int i = 0; i < cycles; i++) {
        SetRandomColor();
        cout << "\b" << spin[i % 4];
        Sleep(150);
    }
    ResetColor();
    cout << "\b ";
}
//Прототипы шаблонов функций сортировок, по умолчанию сортировка по возрастанию
template <typename T, typename L> void QuickSort_R(T Array[], L Size, bool Type = false);
// прототип шаблона функции Бинарный(Двоичный)поиск
template <typename T, typename L> L BinarySearch_R(T Array[], L Begin, L End, T Key, bool Type = false);
int main(){
system("chcp 1251>NUL");
//Аналогично
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("Рекурсивный бинарный поиск");
    SetRandomColor();
    cout << "---Программа сортировки массива!---" << endl;
    ResetColor();
    const short Size = 5;
    int    ArrayInt[Size]{};
    double ArrayDouble[Size]{};
    char   ArrayChar[Size]{};
    bool Type = false;
    // Заполнение и вывод массива int
    for (short i = 0; i < Size; i++) {
        ArrayInt[i] = rand() % (100 - (-99)) - 99;
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    // Заполнение и вывод массива double
    for (short i = 0; i < Size; i++) {
        ArrayDouble[i] = (rand() % 1000) / 10.0 - 50;
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    // Заполнение и вывод массива char
    for (short i = 0; i < Size; i++) {
        ArrayChar[i] = 'A' + rand() % 26;
        SetRandomColor();
        cout << "C[" << i << "]=" << ArrayChar[i] << "; ";
        ResetColor();
    }
    cout << endl;
    // Выбор направления сортировки
    SetRandomColor();
    cout << "\nВыберите как отсортировать массив:\n";
    ResetColor();
    SetRandomColor();
    cout << "0 - от меньшего к большему (по возрастанию значений)\n";
    ResetColor();
    SetRandomColor();
    cout << "1 - от большего к меньшему (по убыванию значений)\n";
    ResetColor();
    cin >> Type;
    // Анимация выполнения сортировки
    SetRandomColor();
    cout << "\nСортировка выполняется ";
    ResetColor();
    cout << "|";
    Spinner(20);
    cout << endl;
    //Вызов рекурсии
    QuickSort_R(ArrayInt, Size, Type);
    QuickSort_R(ArrayDouble, Size, Type);
    QuickSort_R(ArrayChar, Size, Type);
    // Вывод отсортированных массивов
    SetRandomColor();
    cout << "Отсортированный массив int:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) cout << ArrayInt[i] << " ";
    cout << endl;
    SetRandomColor();
    cout << "Отсортированный массив double:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) cout << ArrayDouble[i] << " ";
    cout << endl;
    SetRandomColor();
    cout << "Отсортированный массив char:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) cout << ArrayChar[i] << " ";
    cout << endl;
    // Ввод и поиск int
    int keyInt;
    SetRandomColor();
    cout << "\nВведите int для поиска: ";
    ResetColor();
    cin >> keyInt;
    short resInt = BinarySearch_R(ArrayInt, 0, Size - 1, keyInt, Type);
    SetRandomColor();
    if (resInt == -1)
    {
     SetRandomColor();
    cout << "Не найден!\n";
    ResetColor();
    }
    else 
    {
        SetRandomColor();
        cout << "Индекс int: " << resInt << endl;
        ResetColor();
    }
    // Ввод и поиск double
    double keyDouble;
    SetRandomColor();
    cout << "\nВведите double для поиска: ";
    ResetColor();
    cin >> keyDouble;
    short resDouble = BinarySearch_R(ArrayDouble, 0, Size - 1, keyDouble, Type);
    if (resDouble == -1) {
        SetRandomColor();
        cout << "Не найден!\n";
        ResetColor();
    }
    else 
    {
        SetRandomColor();
        cout << "Индекс double: " << resDouble << endl;
        ResetColor();
    }
    // Ввод и поиск char
    char keyChar;
    SetRandomColor();
    cout << "\nВведите char для поиска: ";
    ResetColor();
    cin >> keyChar;
    short resChar = BinarySearch_R(ArrayChar, 0, Size - 1, keyChar, Type);
    if (resChar == -1) {
        SetRandomColor();
        cout << "Не найден!\n";
        ResetColor();
    }
    else
    {
        SetRandomColor();
        cout << "Индекс char: " << resChar << endl;
    ResetColor();
    }
    cout << endl;
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}
//реализация шаблона функции Быстрая сортировка
template<typename T, typename L> void QuickSort_R(T Array[], L Size, bool Type)
{
    L i = 0, j = Size - 1; //счетчик i движется от начала, j движется от конца последовательности элементов
    T tmp = 0, cnt = Array[Size / 2]; //Вспомогательный буффер для перестановки, cnt - опорное значение
    do
    {
        if (Type)
        {
            //от Макс. к Мин.(по убыванию значений)
            while (Array[i] > cnt)i++; //пропуск элементов, больше опорного значения и находящихся в левой части последовательности
            while (Array[j] < cnt)j--; //пропуск элементов, меньше опорного значения и находящихся в правой части последовательности
        }
        else
        {
            //от Мин. к Макс.(по возрастанию значений)
            while (Array[i] < cnt)i++; //пропуск элементов, меньше опорного значения и находящихся в левой части последовательности
            while (Array[j] > cnt)j--; //пропуск элементов, больше опорного значения и находящихся в правой части последовательности
        }
        if (i <= j) //если счетчики не пересеклись, меняем элементы местами
        {
            tmp = Array[i];
            Array[i] = Array[j];
            Array[j] = tmp;
            i++; //исключаем элементы, которые были перемещены в нужные части массива
            j--; //относительно опорного значения, сдвигая счетчики
        }
    } while (i <= j); //до тех пор, пока счетчики не пересеклись
    //Если остались не отсортированные элементы в левой части последовательности, вызываем функцию для левой части последовательности
    if (j > 0)QuickSort_R(Array, j + 1, Type); //j+1 кол-во элементов от начала последовательности, Array - адрес начала последовательности
    //Если остались не отсортированные элементы в правой части последовательности, вызываем функцию для правой части последовательности
    if (i < Size)QuickSort_R(Array + i, Size - i, Type); //Size-i кол-во элементов до конца последовательности
    //Array+i смещение от адреса начала последовательности на i элементов
}
template <typename T, typename L> L BinarySearch_R(T Array[], L Begin, L End, T Key, bool Type)
{
    if (Begin > End) return -1;
    L mid = Begin + (End - Begin) / 2;
    if (fabs(Array[mid] - Key) < 1e-9) return mid;
   // if (Array[mid] == Key) return mid;
    if (Type) { // убывание
        if (Key < Array[mid])
            return BinarySearch_R(Array, mid + 1, End, Key, Type);
        else
            return BinarySearch_R(Array, Begin, mid - 1, Key, Type);
    }
    else { // возрастание
        if (Key < Array[mid])
            return BinarySearch_R(Array, Begin, mid - 1, Key, Type);
        else
            return BinarySearch_R(Array, mid + 1, End, Key, Type);
    }
}

