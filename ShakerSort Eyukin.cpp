//ShakerSort Eyukin
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
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
template<typename T, typename L> void PrintStep(T Array[], L Size, L j, int step, L lb, L ub) {
    SetRandomColor();
    cout << "\nШаг " << step << " [Границы: " << lb << " - " << ub << "]: ";
    ResetColor();
    for (L i = 0; i < Size; i++) {
        if (i == j || i == j - 1) {
            SetColor(12);
            cout << Array[i] << " ";
            ResetColor();
        }
        else if (i >= lb - 1 && i <= ub) {
            SetColor(15); 
            cout << Array[i] << " ";
            ResetColor();
        }
        else {
            SetColor(8);  
            cout << Array[i] << " ";
            ResetColor();
        }
    }
    cout << " (обмен: " << Array[j] << " <-> " << Array[j - 1] << ")";
    Sleep(400); 
}
// Прототип шаблона функции Шейкер
template <typename T, typename L> void ShakerSort(T Array[], L Size, bool Type = false);
int main() {
    system("chcp 1251>NUL");
//Аналогично
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
    srand(time(NULL));
    SetConsoleTitleA("Сортировка Шейкер");
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
    // Вызов функции ShakerSort для каждого массива
    ShakerSort(ArrayInt, Size, Type);  
    ShakerSort(ArrayDouble, Size, Type);
    ShakerSort(ArrayChar, Size, Type);
    // Вывод отсортированных массивов
    SetRandomColor();
    cout << "\nОтсортированный массив int:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) {
        SetRandomColor();
        cout << "A[" << i << "]=" << ArrayInt[i] << "; ";
        ResetColor();
    }
    cout << endl;
    SetRandomColor();
    cout << "Отсортированный массив double:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) {
        SetRandomColor();
        cout << "D[" << i << "]=" << ArrayDouble[i] << "; ";
        ResetColor();
    }
    cout << endl;
    SetRandomColor();
    cout << "Отсортированный массив char:\n";
    ResetColor();
    for (short i = 0; i < Size; i++) {
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
// Реализация шаблона функции Шейкер с выводом шагов
template<typename T, typename L> void ShakerSort(T Array[], L Size, bool Type) {
    L j;
    L lb = 1, ub = Size - 1;
    L k = Size - 1;
    T x;
    int step = 1;
    do {
        // Проход снизу вверх
        for (j = ub; j > 0; j--) {
            if (Type ? (Array[j - 1] < Array[j]) : (Array[j - 1] > Array[j])) {
                x = Array[j - 1];
                Array[j - 1] = Array[j];
                Array[j] = x;
                k = j;
                PrintStep(Array, Size, j, step++, lb, ub);
            }
        }
        lb = k + 1;
        // Проход сверху вниз
        for (j = 1; j <= ub; j++) {
            if (Type ? (Array[j - 1] < Array[j]) : (Array[j - 1] > Array[j])) {
                x = Array[j - 1];
                Array[j - 1] = Array[j];
                Array[j] = x;
                k = j;
                PrintStep(Array, Size, j, step++, lb, ub);
            }
        }
        ub = k - 1;
    } while (lb < ub);   
}