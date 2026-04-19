// FractionEyukin6.0.cpp 
//Создать класс «Дробь» для представления простой(обыкновенной) дроби.
//Поля:
//1. Числитель
//2. Знаменатель
//Методы :
//1. Конструктор принимающий числитель и знаменатель.Предусмотреть сокращение дроби в конструкторе.
//2. Вывод на экран дроби.
//3. Set(Предусмотреть сокращение дроби) и Get методы
//Под * методы : сложение / вычитание / умножение / деление простой дроби с целым числом.
//Под * *методы : сложение / вычитание / умножение / деление простой дроби с простой дробью.
#include <iostream>
#include <Windows.h> 
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color) {
    SetConsoleTextAttribute(h, color);
}
void ResetColor() {
    SetColor(7);
}
void SetRandomColor() {
    SetColor(1 + rand() % 15);
}
int ReadInt(const string& prompt, bool& isNeg) {
    double val;
    while (true) {
        SetRandomColor();
        cout << prompt;
        ResetColor();
        if (!(cin >> val)) {
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
            SetRandomColor();
            cout << "Ошибка: введите число!\n";
            ResetColor();
            continue;
        }
        // signbit вернет true для любого отрицательного числа и для -0.0
        isNeg = signbit(val);
        return (int)val;
    }
}
class Fraction {
    int originalNumerator;
    int originalDenominator;
    int numerator;
    int denominator;
    bool isInfinity = false;
    bool isNaN = false;
    bool sign = false; // false = +, true = -
    //Алгоритм Евклида для нахождения наибольшего общего делителя (НОД)
    int GetGSD(int a, int b)const {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void NormalizeSign() {
        if (isInfinity || isNaN) return;
        // Не меняем знаки, если числитель равен нулю, 
        // чтобы сохранить "отрицательный ноль" в знаменателе
        if (denominator < 0 && numerator != 0 && !isInfinity) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    //Метод сокращения дробей
    void Reduce() {
        if (denominator == 0) return; // Защита на случай некорректного состояния
        if (numerator == 0) {
            // Сохраняем знак знаменателя: 1 или -1
            denominator = (denominator < 0) ? -1 : 1;
            return;
        }
        int gsd = GetGSD(numerator, denominator);
        numerator /= gsd;
        denominator /= gsd;
    }
    // Считаем количество символов в числе 
    int GetDigitsCount(int n) const {
        if (n == 0) return 1;
        int count = 0;
        if (n < 0) count++;
        long long temp = abs((long long)n);
        while (temp > 0) {
            temp /= 10;
            count++;
        }
        return count;
    }
    void PrintSpaces(int n) const {
        for (int i = 0; i < n; i++) cout << " ";
    }
    void PrintLine(int n) const {
        for (int i = 0; i < n; i++) cout << "-";
    }

public:
    Fraction(int num = 0, int den = 1) {
        originalNumerator = num;
        originalDenominator = den;
        numerator = num;
        denominator = den;
        isInfinity = false;
        isNaN = false;
        sign = false;
        // NaN
        if (num == 0 && den == 0) {
            isNaN = true;
            return;
        }
        // infinity
        if (den == 0) {
            isInfinity = true;
            sign = (num < 0) ^ (den < 0);
            return;
        }
        NormalizeSign();
        Reduce(); // Сокращаем дробь при создании
    }
    //Представление дроби как смешанное число
    void ShowMixed(const char* prefix) const;
    //Сеттеры:
    void SetNumerator(int num);
    void SetDenominator(int den);
    void SetFraction(int num, int den);
    //Геттеры:
    int GetNumerator()const;
    int GetDenominator()const;
    //Операции с целым числом (*):
    Fraction Add(int value) const; //+
    Fraction Subtract(int value) const; //-
    Fraction Multiply(int value) const;//*
    Fraction Divide(int value) const;//:
    //Операции с простой дробью (**):
    Fraction Add(const Fraction& other) const;//+
    Fraction Subtract(const Fraction& other) const;//-
    Fraction Multiply(const Fraction& other) const;//*
    Fraction Divide(const Fraction& other) const;//:
   //Проверка пользовательского ввода
    void Input() {
        bool nIsNeg, dIsNeg;
        int num = ReadInt("Введите числитель: ", nIsNeg);
        int den = ReadInt("Введите знаменатель: ", dIsNeg);
        // Сохраняем для истории
        originalNumerator = num;
        originalDenominator = den;
        numerator = num;
        denominator = den;
        isInfinity = false;
        isNaN = false;
        if (num == 0 && den == 0) {
            isNaN = true;
            return;
        }
        // Деление на ноль
        if (den == 0) {
            isInfinity = true;
            sign = nIsNeg ^ dIsNeg;
            return;
        }
        NormalizeSign();
        Reduce();
    }
};
int main() {
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Дробь");
    SetRandomColor();
    cout << "Работа с дробями!\n\n";
    ResetColor();
    SetRandomColor();
    cout << "--- Инициализация и сокращение дроби! ---" << endl;
    ResetColor();
    Fraction A, B;
    int choice;
    SetRandomColor();
    cout << "Введите дробь A!\n";
    ResetColor();
    A.Input();
    SetRandomColor();
    cout << "\nВведите дробь B!\n";
    ResetColor();
    B.Input();
    do {
        SetRandomColor();
        cout << "\n========= Меню =========\n";
        ResetColor();
        SetRandomColor();
        cout << "1. Показать дроби\n";
        ResetColor();
        SetRandomColor();
        cout << "2. A + B\n";
        ResetColor();
        SetRandomColor();
        cout << "3. A - B\n";
        ResetColor();
        SetRandomColor();
        cout << "4. A * B\n";
        ResetColor();
        SetRandomColor();
        cout << "5. A / B\n";
        ResetColor();
        SetRandomColor();
        cout << "6. Операции с числом\n";
        ResetColor();
        SetRandomColor();
        cout << "7. Ввести новые дроби A и B\n"; //возможность повторного ввода дробей в меню
        ResetColor();
        SetRandomColor();
        cout << "0. Выход\n";
        ResetColor();
        SetRandomColor();
        cout << "========================\n";
        ResetColor();
        bool dummy;
        choice = ReadInt("Выберите пункт: ", dummy);
        cin.clear();
        system("cls");
        switch (choice) {
        case 1:
            A.ShowMixed("A = ");
            B.ShowMixed("B = ");
            break;
        case 2:
            A.Add(B).ShowMixed("A + B = ");
            break;
        case 3:
            A.Subtract(B).ShowMixed("A - B = ");
            break;
        case 4:
            A.Multiply(B).ShowMixed("A * B = ");
            break;
        case 5:
            A.Divide(B).ShowMixed("A / B = ");
            break;
        case 6: {
            int subChoice;
            int x = ReadInt("Введите число: ", dummy);
            do {
                system("cls");
                SetRandomColor();
                cout << "=== Операции дроби A с числом " << x << " ===\n";
                ResetColor();
                SetRandomColor();
                cout << "1. A + ";
                ResetColor();
                if (x < 0) cout << "(" << x << ")";
                else cout << x;
                cout << "\n";
                SetRandomColor();
                cout << "2. A - ";
                ResetColor();
                if (x < 0) cout << "(" << x << ")";
                else cout << x;
                cout << "\n";
                SetRandomColor();
                cout << "3. A * ";
                ResetColor();
                if (x < 0) cout << "(" << x << ")";
                else cout << x;
                cout << "\n";
                SetRandomColor();
                cout << "4. A / ";
                ResetColor();
                if (x < 0) cout << "(" << x << ")";
                else cout << x;
                cout << "\n";
                SetRandomColor();
                cout << "5. Изменить число (сейчас: " << x << ")\n";
                ResetColor();
                SetRandomColor();
                cout << "0. Вернуться в главное меню\n";
                ResetColor();
                SetRandomColor();
                subChoice = ReadInt("Выберите действие: ", dummy);
                ResetColor();
                system("cls");
                switch (subChoice) {
                case 1:
                    A.Add(x).ShowMixed("Результат A + x = ");
                    system("pause");
                    break;
                case 2:
                    A.Subtract(x).ShowMixed("Результат A - x = ");
                    system("pause");
                    break;
                case 3:
                    A.Multiply(x).ShowMixed("Результат A * x = ");
                    system("pause");
                    break;
                case 4:
                {
                    A.Divide(x).ShowMixed("Результат A / x = ");
                    system("pause");
                    break;
                }
                case 5:
                    x = ReadInt("Введите новое число: ", dummy);
                    break;
                case 0:
                    break;
                default:
                    SetRandomColor();
                    cout << "Ошибка: неверный пункт!\n";
                    ResetColor();
                    system("pause");
                }
            } while (subChoice != 0);
            system("cls"); // Очистка перед возвратом в основное меню
            break;
        }
        case 7:
            SetRandomColor();
            cout << "Введите новые значения для дроби A!\n";
            ResetColor();
            A.Input();
            SetRandomColor();
            cout << "\nВведите новые значения для дроби B!\n";
            ResetColor();
            B.Input();
            break;
        case 0:
            SetRandomColor();
            cout << "Для выхода из программы нажмите любую клавишу...\n";
            ResetColor();
            system("pause > NUL");
            break;
        default:
            SetRandomColor();
            cout << "Ошибка: такого пункта нет!\n";
            ResetColor();
        }
    } while (choice != 0);
}
//Реализация методов
//1.Вывод целой части дроби
// Реализация вывода псевдографикой с поддержкой смешанных дробей
void Fraction::ShowMixed(const char* prefix) const {
    SetRandomColor();
    if (isNaN) {
        ResetColor();
        cout << prefix << "-nan(ind)\n\n";
        return;
    }
    if (isInfinity) {
        if (sign) cout << prefix << "-inf\n\n";
        else cout << prefix << "inf\n\n";
        return;
    }
    if (numerator == 0) {
        cout << prefix << "0\n\n";
        ResetColor();
        return;
    }
    // Подготовка данных
    long long on = abs((long long)originalNumerator);
    long long od = abs((long long)originalDenominator);
    long long sn = abs((long long)numerator);
    long long sd = abs((long long)denominator);
    bool negLeft = (originalNumerator < 0) ^ (originalDenominator < 0);
    bool negRight = (numerator < 0) ^ (denominator < 0);
    long long wholePart = sn / sd;
    long long remPart = sn % sd;
    // Условия для отображения разных частей
    bool hasReduction = (on != sn || od != sd); // Было ли сокращение?
    bool hasMixed = (wholePart > 0 && remPart > 0); // Нужна ли смешанная дробь (напр. 1 2/3)?
    bool isInteger = (wholePart > 0 && remPart == 0); // Стала ли дробь целым числом (напр. 5/1 = 5)?
    // Ширина блоков
    int wOrig = max(GetDigitsCount((int)on), GetDigitsCount((int)od));
    int wRed = max(GetDigitsCount((int)sn), GetDigitsCount((int)sd));
    int wRem = max(GetDigitsCount((int)remPart), GetDigitsCount((int)sd));
    int wWhole = GetDigitsCount((int)wholePart);
    int prefixLen = 0;
    while (prefix[prefixLen] != '\0') prefixLen++;
    const int gap = 2;
    // --- 1-я строка: Числители ---
    PrintSpaces(prefixLen);
    if (hasReduction) {
        PrintSpaces(negLeft ? 2 : 1);
        PrintSpaces((wOrig - GetDigitsCount((int)on)) / 2);
        cout << on;
        PrintSpaces(wOrig - GetDigitsCount((int)on) - (wOrig - GetDigitsCount((int)on)) / 2);
        PrintSpaces(gap + 1 + gap); // Пропуск под "="
    }
    // Числитель сокращенной дроби
    PrintSpaces(negRight ? 2 : 1);
    PrintSpaces((wRed - GetDigitsCount((int)sn)) / 2);
    cout << sn;
    PrintSpaces(wRed - GetDigitsCount((int)sn) - (wRed - GetDigitsCount((int)sn)) / 2);
    // Числитель остатка (для смешанной дроби)
    if (hasMixed) {
        PrintSpaces(gap + 1 + gap); // Пропуск под "="
        PrintSpaces(negRight ? 2 : 1);
        PrintSpaces(wWhole + 1); // Целая часть + пробел
        PrintSpaces((wRem - GetDigitsCount((int)remPart)) / 2);
        cout << remPart;
    }
    cout << "\n";
    // --- 2-я строка: Линии и целые части ---
    cout << prefix;
    if (hasReduction) {
        if (negLeft) cout << "- "; else cout << " ";
        PrintLine(wOrig);
        PrintSpaces(gap); cout << "="; PrintSpaces(gap);
    }
    // Основная сокращенная дробь
    if (negRight) cout << "- "; else cout << " ";
    PrintLine(wRed);
    // Смешанная дробь или целое число
    if (hasMixed || isInteger) {
        PrintSpaces(gap); cout << "="; PrintSpaces(gap);
        if (negRight) cout << "- "; else cout << " ";
        cout << wholePart;
        if (hasMixed) {
            cout << " ";
            PrintLine(wRem);
        }
    }
    cout << "\n";
    // --- 3-я строка: Знаменатели ---
    PrintSpaces(prefixLen);
    if (hasReduction) {
        PrintSpaces(negLeft ? 2 : 1);
        PrintSpaces((wOrig - GetDigitsCount((int)od)) / 2);
        cout << od;
        PrintSpaces(wOrig - GetDigitsCount((int)od) - (wOrig - GetDigitsCount((int)od)) / 2);
        PrintSpaces(gap + 1 + gap);
    }
    // Знаменатель сокращенной дроби
    PrintSpaces(negRight ? 2 : 1);
    PrintSpaces((wRed - GetDigitsCount((int)sd)) / 2);
    cout << sd;
    PrintSpaces(wRed - GetDigitsCount((int)sd) - (wRed - GetDigitsCount((int)sd)) / 2);
    // Знаменатель остатка
    if (hasMixed) {
        PrintSpaces(gap + 1 + gap);
        PrintSpaces(negRight ? 2 : 1);
        PrintSpaces(wWhole + 1);
        PrintSpaces((wRem - GetDigitsCount((int)sd)) / 2);
        cout << sd;
    }
    cout << "\n\n";
    ResetColor();
}
//2.Сеттеры:
void Fraction::SetNumerator(int num)
{
    numerator = num;
    NormalizeSign();
    Reduce(); // Сокращаем после каждого изменения
}
void Fraction::SetDenominator(int den) {
    denominator = den;
    NormalizeSign();
    Reduce();
}
void Fraction::SetFraction(int num, int den) {
    // сохраняем исходную
    originalNumerator = num;
    originalDenominator = den;
    numerator = num;
    denominator = den;
    NormalizeSign();
    Reduce();
}
//3.Геттеры:
int Fraction::GetNumerator() const
{
    return numerator;
}
int Fraction::GetDenominator() const
{
    return denominator;
}
//4.Операции с целым числом (*):
Fraction Fraction::Add(int value) const {
    // a/b + c = (a + c*b) / b
    return Fraction(numerator + value * denominator, denominator);
}
Fraction Fraction::Subtract(int value) const
{
    return Fraction(numerator - value * denominator, denominator);
}
Fraction Fraction::Multiply(int value) const
{
    return Fraction(numerator * value, denominator);
}
Fraction Fraction::Divide(int value) const
{
    if (value == 0) {
        Fraction f;
        f.isInfinity = true;
        f.sign = (numerator > 0);
        return f;
    }
    return Fraction(numerator, denominator * value);
}
//5.Операции с простой дробью (**):
Fraction Fraction::Add(const Fraction& other) const {

    // a/b + c/d = (a*d + c*b) / (b*d)
    int res_num = (this->numerator * other.denominator) + (other.numerator * this->denominator);
    int res_den = this->denominator * other.denominator;
    return Fraction(res_num, res_den);
    // Возвращаем новый безымянный объект. Конструктор Fraction сам вызовет Reduce()
}
Fraction Fraction::Subtract(const Fraction& other) const {
    int res_num = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int res_den = this->denominator * other.denominator;
    return Fraction(res_num, res_den);
}
Fraction Fraction::Multiply(const Fraction& other) const {
    return Fraction(this->numerator * other.numerator, this->denominator * other.denominator);
}
Fraction Fraction::Divide(const Fraction& other) const {
    // Если делим на дробь вида 0/1 или -0/1
    if (other.numerator == 0) {
        Fraction f;
        f.isInfinity = true;
        // Правило знаков:
        // (+) / (+) = +inf
        // (+) / (-) = -inf
        // (-) / (+) = -inf
        // (-) / (-) = +inf
        // Проверяем знак текущей дроби и знак делителя (числителя дроби)
        bool currentSign = (this->numerator < 0) ^ (this->denominator < 0);
        bool otherSign = (other.originalNumerator < 0) ^ (other.originalDenominator < 0);
        f.sign = currentSign ^ otherSign;
        return f;
    }
    return Fraction(this->numerator * other.denominator,
        this->denominator * other.numerator);
}