// Calculator 3.0 Eyukin
//Добавить в программу калькулятора с помощью массива указателей на функции.Две функции : возведения числа А в степень B и вычисление корня A-ой степени из числа B.
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
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
float Summa(float A, float B)
{
	return A + B;
}
float Raznost(float A, float B)
{
	return A - B;
}
float Proizvedenie(float A, float B)
{
	return A * B;
}
float Chastnoe(float A, float B)
{
	return A / B;
}
float Stepen(float A, float B)//Число A в степени B
{
	return pow(A, B); // A^B
}
float Koren(float A, float B) // корень A-ой степени из числа B
{
	return pow(B, 1 / A);
}
float Vyhod(float, float)
{
	SetRandomColor();
	cout << "Для подверждения выхода нажмите любую клавишу..." << endl;
	ResetColor();
	system("pause > NUL");
	return 0.0F;
}
int main()
{
	system("chcp 1251 > NUL");
	SetConsoleTitleA("Калькулятор"); //заголовок окна консоли
	float A = 0.0, B = 0.0, Result = 0.0;
	int Select = 0; //индекс элемента массива(номер пункта меню)
	//статический массив указателей на функции
	const int CountFunctions = 7;
	//объявляем массив указателей на функции и инициализаируем его адресами функций
	float (*Calculator[CountFunctions])(float, float) = {Vyhod,Summa,Raznost, Proizvedenie, Chastnoe, Stepen, Koren};
	//float (*Calculator[])(float, float) = { Vyhod,Summa,Raznost,Proizvedenie,Chastnoe, Stepen, Koren};
	do
	{
		system("cls");
		SetRandomColor();
		cout << "---Величайший в мире калькулятор!---" << endl;
		ResetColor();
		do
		{
			const char* menu[] =
			{
				"Выберите действие:",
				"1. Сложение",
				"2. Вычитание",
				"3. Умножение",
				"4. Деление",
				"5. Возведение числа А в степень B",
				"6. Корень A-ой степени из числа B",
				"0. Выход"
			};
			int colors[8] = { 9, 10, 11, 12, 13, 14, 15, 8 }; 
			for (int i = 0; i < 8; i++)
			{
				SetColor(colors[i]);
				cout << menu[i] << endl;
			}
			ResetColor();
			cin >> Select;
			if (Select < 0 || Select >= CountFunctions)
			{
				SetRandomColor();
				cout << "Некорректный выбор действия! Попробуйте ещё раз!" << endl;
				ResetColor();
			}
			else break; //выход из бесконечного цикла
		} while (true); //while (Select<0||Select>=CountFunctions); //цикл проверки пользовательского ввода
		SetRandomColor();
		cout << "|";
		ResetColor();
		Spinner(30);
		if (Select != 0)
		{
			system("cls");
			if (Select == 5) // Возведение в степень
			{
				SetRandomColor();
				cout << "Введите число A (основание): "; cin >> A;
				ResetColor();
				SetRandomColor();
				cout << "Введите число B (степень): "; cin >> B;
				ResetColor();
			}
			else if (Select == 6) // Корень A-ой степени
			{
				SetRandomColor();
				cout << "Введите число A (степень корня): "; cin >> A;
				ResetColor();
				SetRandomColor();
				cout << "Введите число B (число, из которого извлекаем корень): "; cin >> B;
				ResetColor();
			}
			else // Остальные операции
			{
				SetRandomColor();
				cout << "Введите число A: "; cin >> A;
				ResetColor();
				SetRandomColor();
				cout << "Введите число B: "; cin >> B;
				ResetColor();
			}
			SetRandomColor();
			cout << "Результат равен: " << Calculator[Select](A, B) << endl;
			ResetColor();
			//cout << "Результат равен: " << (*(Calculator+Select))(A, B) << endl; //так тоже можно
		}
		else
		{
			//вызов функции выход
			//Calculator[0](A, B);  //Calculator[Select](A, B); 
			(*Calculator)(A, B);	//так тоже сработает
			break; //выход из всей программы

		}
		SetRandomColor();
		cout << "Для продолжения вычислений нажмите любую клавишу...";
		ResetColor();
		system("pause > NUL");
	} while (true); //while (Select!=0);
}