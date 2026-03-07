//Home Eyukin
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitleA("Домик");
    cout << "--- Программа для изображения домика! ---\n";
    int N=0;
    cout << "Введите размер домика (высота стен): ";
    cin >> N;

    // Гарантируем минимальный размер для корректного отображения деталей
    // if (N < 5) {
     //    N = 5;
     //    cout << "Размер увеличен до 5 для размещения всех деталей!" << endl;
    // }

    // Для симметрии крыши делаем N нечетным
    if (N % 2 == 0) N++;

    int width = N * 4;
    int center = width / 2;

    // ==========================================
    // ЭТАП 1: НЕБО
    // ==========================================
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 2) cout << "0";           // Солнце
            else if (i == 1 && j == center + 6) cout << "~"; // Дым 1
            else if (i == 0 && j == center + 7) cout << "~"; // Дым 2
            else if ((i == 1 && j == 8) || (i == 2 && j == 12)) cout << "v"; // Птицы
            else cout << " ";
        }
        cout << endl;
    }

    // ==========================================
    // ЭТАП 2: КРЫША С ТРУБОЙ
    // ==========================================
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Условие для ТРУБЫ. Труба из кирпича, сверху оголовок.
            // Рисуем трубу в верхней части крыши (i < N/2)
            if (i < N / 2 && j >= center + 5 && j <= center + 7)
            {
                if (i == 0) cout << "="; // Оголовок трубы
                else cout << "*";        // Кирпичи трубы
            }
            // Условие для отрисовки КРЫШИ
            else if (j >= center - i * 2 && j <= center + i * 2)
            {
                if (i == 0 && j == center)
                    cout << "^";
                else if (i == N / 2 && j == center - 4)
                    cout << "C"; // Кошка
                else if (i == N / 2 && j == center + 4)
                    cout << "R"; // Крыса
                else if ((j - (center - i * 2)) % 4 == 0)
                    cout << "|"; // Балки
                else
                    cout << "="; // Черепица
            }
            else cout << " ";
        }
        cout << endl;
    }

    // ==========================================
    // ЭТАП 3: СТЕНЫ, ОКНА И ДВЕРЬ
    // ==========================================
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int left = center - (N * 2 - 2);
            int right = center + (N * 2 - 2);

            if (j >= left && j <= right)
            {
                // Вертикальные границы блоков стены
                if ((j - left) % 4 == 0)
                    cout << "|";
                else
                {
                    // РИСУЕМ ДВЕРЬ (в центре снизу)
                    if (i >= N / 2 && j >= center - 1 && j <= center + 1)
                    {
                        if (i == N / 2 + 1 && j == center + 1)
                            cout << "."; // Ручка
                        else
                            cout << "|"; // Текстура двери
                    }
                    // РИСУЕМ ОКНА
                    else if (
                        (i == N / 4 || i == N / 4 + 1) &&
                        (j - left) % 8 == 2
                        )
                    {
                        if (i == N / 4 + 1) cout << "+"; // Рама
                        else cout << "O";               // Стекло
                    }
                    else
                        cout << "#"; // Кирпичная стена
                }
            }
            else cout << " ";
        }
        cout << endl;
    }
    cout << "\nДом построен!" << endl;
    cout << "Для завершения программы нажмите любую клавишу!" << endl;
    system("pause > NUL");
}