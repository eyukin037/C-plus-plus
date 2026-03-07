// chemodan  Eyukin.cpp
//На чемодане стоит трехзначный код(от 000 до 999).Он состоит из трёх разных цифр, которые не повторяются.
//Напишите программу, которая выведет все возможные такие комбинации цифр.
//А также определите сколько таких комбинаций
#include <iostream>
#include <Windows.h>  
#include <stdlib.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    SetConsoleTitleA("Чемодан");
	//system("chcp 1251>NUL"); //аналогично
   	 int count = 0;
    cout << "Программа подсчёта списка всех комбинаций с уникальными цифрами:" << endl;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                // Проверка на отсутствие повторений
                if (i != j && i != k && j != k) {
                    cout << i << j << k << " ";
                    count++;
                    if (count % 10 == 0) {
                        cout << endl;
                    }
                }
            }
        }
    }
    cout << "\n\nОбщее количество уникальных комбинаций: " << count << endl;
	cout << "Для завершения программы нажмите любую клавишу!" << endl;
	system("pause > NUL");
}