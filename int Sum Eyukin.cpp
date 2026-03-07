// int Sum Eyukin
#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "---Программа для вычисления суммы всех целых чисел в диапазоне от A до B!---" << endl;
    int A = 0; // левая граница диапазона
    int B = 0; // правая граница диапазона
    long long sum = 0LL; // переменная для хранения суммы (может быть большой)
    cout << "Введите число A: ";    cin >> A;
    cout << "Введите число B: ";    cin >> B;
   if (A > B)
    {
        cout << "Введены некорректные данные!" << endl;
    }
    else
    {
        int i = A; // инициализируем счетчик после ввода A
        while (i <= B)
        {
            sum += i;  // суммируем числа
            i++;       // переход к следующему числу
        }
        cout << "Сумма всех целых чисел от " << A << " до " << B << " включительно = " << sum << endl;
    }
    cout << "Для выхода из программы нажмите любую клавишу...";
    system("pause > NUL");
}