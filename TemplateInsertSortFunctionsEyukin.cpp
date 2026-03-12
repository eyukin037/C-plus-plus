// TemplateInsertSortFunctionsEyukin
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
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
// Прототипы
template <typename T, typename L> void setExtreme(T Array[], L Size, bool Type = false);
template <typename T, typename L> void InsertSort(T Array[], L Size, bool Type = false);
int main()
{
    system("chcp 1251>NUL");
    //Аналогично
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("Сортировка вставками");
    SetRandomColor();
    cout << "---Программа сортировки массива!---" << endl;
    ResetColor();
    const short Size = 5;
    int    ArrayInt[Size]{};
    double ArrayDouble[Size]{};
    char   ArrayChar[Size]{};
    bool Type = false;
    for (short i = 0; i < Size; i++)
    {
        ArrayInt[i] = rand() % (100 - (-99)) - 99;
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (short i = 0; i < Size; i++)
    {
        ArrayDouble[i] = (rand() % 1000) / 10.0 - 50;
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (short i = 0; i < Size; i++)
    {
        ArrayChar[i] = 'A' + rand() % 26;
        SetRandomColor();
        cout << "C[" << i << "]=" << ArrayChar[i] << "; ";
        ResetColor();
    }
    cout << endl;
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
    SetRandomColor();
    cout << "\nСортировка выполняется ";
    ResetColor();
    cout << "|";
    Spinner(20);
    cout << endl;
    //Вызов функций сортировки для Int, Double, Char
    InsertSort(ArrayInt, Size, Type);
    InsertSort(ArrayDouble, Size, Type);
    InsertSort(ArrayChar, Size, Type);
    // Вывод отсортированных массивов
    for (short i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (short i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (short i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "C[" << i << "]=" << ArrayChar[i] << "; ";
        ResetColor();
    }
    cout << endl;
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}
template<typename T, typename L> void setExtreme(T Array[], L Size, bool Type)
{
    // ищем минимальный/максимальный элемент для вставки в начало
    L ExtremeIndex = 0;
    if (Size <= 1) return;
    for (L i = 1; i < Size; i++) {
        if ((Type && Array[i] > Array[ExtremeIndex]) || (!Type && Array[i] < Array[ExtremeIndex])) {
            ExtremeIndex = i;
        }
    }
    T tmp = Array[ExtremeIndex]; // сохраняем значение перемещаемого элемента
    for (L j = ExtremeIndex; j > 0; j--) {
        Array[j] = Array[j - 1];
    }
    // вставка элемента в начало
    Array[0] = tmp;
    // визуализация итогового состояния
    SetRandomColor();
    cout << "После перемещения " << (Type ? "максимального" : "минимального") << " элемента: ";
    for (L k = 0; k < Size; k++)
    {
        k == 0 ? SetColor(12) : SetRandomColor();
        cout << Array[k] << " ";
    }
    cout << endl;
    Sleep(600);
}
template<typename T, typename L> void InsertSort(T Array[], L Size, bool Type)
{
    if (Size <= 1) return;
    L i = 0, j = 0;
    T x;
    setExtreme(Array, Size, Type); // Устанавливаем барьер
    for (i = 1; i < Size; i++)
    {
        x = Array[i];
        for (j = i; (Type ? Array[j - 1] < x : Array[j - 1] > x); j--)
        {
            Array[j] = Array[j - 1];
        }
        Array[j] = x;
        SetRandomColor();
        cout << "Шаг " << i << ": ";
        ResetColor();
        for (L k = 0; k < Size; k++)
        {
            (k == j) ? SetColor(12) : SetRandomColor();
            cout << (k == i ? "| " : "") << Array[k] << " ";//граница отсортированной части
            //cout << (k == j ? "* " : "") << Array[k] << " "; //место вставки элемента
            ResetColor();
        }
        SetRandomColor();
        cout << " <- вставляем " << x << endl;
        ResetColor();
        Sleep(600);
    }
}