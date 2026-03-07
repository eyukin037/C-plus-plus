// TemplateSelectSortFunctionsEyukin
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
// Анимация обработки
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
// Прототип шаблона
template <typename T, typename L> void SelectSort(T Array[], L Size, bool Type = false);
int main()
{
    system("chcp 1251 > NUL");
    srand(time(NULL));
    SetConsoleTitleA("Сортировка выбором");
    SetRandomColor();
    cout << "---Программа сортировки массива!---\n";
    ResetColor(); 
    const int Size = 14;
    int    ArrayInt[Size]{};
    double ArrayDouble[Size]{};
    char   ArrayChar[Size]{};
    bool Type = false;
    // Заполнение и вывод Int
    for (int i = 0; i < Size; i++)
    {
        ArrayInt[i] = rand() % (100 - (-99)) - 99;
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    // Заполнение и вывод Double
    for (int i = 0; i < Size; i++)
    {
        ArrayDouble[i] = (rand() % 1000) / 10.0 - 50;
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    // Заполнение и вывод Char
    for (int i = 0; i < Size; i++)
    {
        ArrayChar[i] = 'A' + rand() % 26;
        SetRandomColor();
        cout << "C[" << i << "]=" << ArrayChar[i] << "; ";
        ResetColor();
    }
    cout << endl;
    SetRandomColor();
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
    // Вызовы сортировки
    SelectSort(ArrayInt, Size, Type);
    SelectSort(ArrayDouble, Size, Type);
    SelectSort(ArrayChar, Size, Type);
    // Вывод отсортированных массивов
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    for (int i = 0; i < Size; i++)
    {
        SetRandomColor();
        cout << "C[" << i << "]=" << ArrayChar[i] << "; ";
        ResetColor();
    }
    cout << endl;
    SetRandomColor();
    cout << "\nДля выхода нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}
//Реализация шаблона функции Сортировка выбором
template<typename T, typename L> void SelectSort(T Array[], L Size, bool Type)
{
    L i = 0, j = 0, k = 0; //индексы элементов массива
    T tmp{}; //вспомогательный буфер для перестановки элементов
    for (i = 0; i < Size - 1; i++) //цикл проходов по массиву для поиска мин.(макс.) элемент
    //и установки его в начало неотсортированной последовательности 
    {
        k = i; //запоминаем индекс первого элемента неотсортированной последовательности, предполагая, что
                //он и есть тот, который нужно выбрать(мин. или макс. в зависимости от направления сортировки) 
        tmp = Array[i]; //tmp = Array[k]; //откладываем(копируем) в буфер значение элемента, предполагая, что
                //он и есть тот, который нужно выбрать(мин. или макс. в зависимости от направления сортировки) 
        for (j = i + 1; j < Size; j++)//цикл выбора(поиска) мин.(макс.) элемента
        {
            ////I Вариант
            //if (Type) //if(Type==true)
            //{
            //    //от Макс. к Мин. (по убыванию значений)
            //    if (Array[j] > tmp)
            //    {
            //        k = j;          //запоминаем индекс и значение выбранного элемента
            //        tmp = Array[j]; //того, которого считаем максимальным
            //    }
            //}
            //else
            //{
            //    //от Мин. к Макс. (по возрастанию значений)
            //    if (Array[j] < tmp)
            //    {
            //        k = j;          //запоминаем индекс и значение выбранного элемента
            //        tmp = Array[j]; //того, которого считаем минимальным
            //    }
            //}
            //II Вариант
            if (Type ? Array[j] > tmp : Array[j] < tmp)
            {
                k = j;          //запоминаем индекс и значение выбранного элемента
                tmp = Array[j]; //того, которого считаем мин. или макс.
            }
        }
        Array[k] = Array[i]; //помещаем на место выбранного элемента(мин. или макс.) первый элемент неотсортированной последовательности
        Array[i] = tmp; //помещаем на первое место неотсортированной последовательности значение выбранного элемента(мин. или макс.)
                // --- Визуализация ---
        SetRandomColor();
        cout << "Шаг " << i + 1 << ": ";
        ResetColor();
        for (L m = 0; m < Size; m++)
        {
            if (m == i) SetColor(10); // зелёный — зафиксированный элемент
            else if (m == k) SetColor(12); // красный — найденный min/max
            else SetRandomColor();
            if (m == i) cout << "| "; //граница отсортированной части
            cout << Array[m] << " ";
            ResetColor();
        }
        SetRandomColor();
        cout << " <- выбран элемент " << tmp;
        ResetColor();
        cout << endl;
        Sleep(600);
    }
}