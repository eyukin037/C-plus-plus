// PointEyukinOverload
//Реализовать класс Point с полями X и Y и перегрузить для этого класса :
//1. оператор копирующего присваивания =
//2. математические операторы (поэлементные) + -*/
//для ситуаций :
//Point + Point
//Point - Point
//Point * Point
//Point / Point
#include <iostream>
#include <Windows.h> 
#include <stdlib.h>
#include <time.h>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color) { SetConsoleTextAttribute(h, color); }
void ResetColor() { SetColor(7); }
void SetRandomColor() {  SetColor(1 + rand() % 15); }
class Point {
    double X;
    double Y;
public:
    // Конструкторы:
    //1. По умолчанию
    Point();
    //2. С параметрами
    Point(double x, double y);
    //3. Копирования
    Point(const Point& other);
    //Деструктор
    ~Point();
    //Геттеры
    double GetX() const;
    double GetY() const;
    //Сеттеры
    void SetX(double);
    void SetY(double);
    //Перегрузка:
    //1. Оператор копирующего присваивания =
    Point& operator=(const Point&);
    //2. Оператор +
    Point operator+(const Point&) const;
    //3. Оператор -
    Point operator-(const Point&) const;
    //4. Оператор *
    Point operator*(const Point&) const;
    //5. Оператор /
    Point operator/(const Point&) const;
    // Вывод
    void Show() const;
};
int main()
{
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Перегрузка бинарных операторов!");
    Point A(10, 12);
    Point B(12, 8);
    Point C,F, K, L, M, N;

    SetRandomColor();
    cout << "Точка A: ";
    ResetColor();
    A.Show();

    SetRandomColor();
    cout << "Точка B: ";
    ResetColor();
    B.Show();

    SetRandomColor();
    cout << "Точка C (по умолчанию): ";
    ResetColor();
    C.Show();

    // Проверка математических операторов +,-,*,/
    SetRandomColor();
    cout << "\nПроверка математических операторов:\n";
    ResetColor();

    K = A + B;
    SetRandomColor();
    cout << "K = A + B = ";
    ResetColor();
    K.Show();

    L = A - B;
    SetRandomColor();
    cout << "L = A - B = "; 
    ResetColor();
    L.Show();

    M = A * B;
    SetRandomColor();
    cout << "M = A * B = ";
    ResetColor();
    M.Show();

    N = A / B;
    SetRandomColor();
    cout << "N = A / B = "; 
    ResetColor();
    N.Show();

    F = A + B * A - B / A;
    SetRandomColor();
    cout << "F = A+B*A-B/A = ";
    ResetColor();
    F.Show();


    // Проверка оператора =
    SetRandomColor();
    cout << "\nПроверка оператора копирующего присваивания:\n";
    ResetColor();
    Point D;
    D = A;   //проверка operator=
    SetRandomColor();
    cout << "D = A -> ";
    ResetColor();
    D.Show();

     // Проверка конструктора копирования
    SetRandomColor();
    cout << "\nПроверка конструктора копирования:\n";
    ResetColor();

    Point E = B;  // вызов конструктора копирования
    SetRandomColor();
    cout << "E (копия B) -> ";
    ResetColor();
    E.Show();

    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
    }
// Конструктор по умолчанию
Point::Point() : X(0), Y(0) {}
// Конструктор с параметрами
Point::Point(double x, double y) : X(x), Y(y) {}
// Конструктор копирования
Point::Point(const Point& other)
{
    X = other.X;
    Y = other.Y;
}
// Деструктор
Point::~Point() {}

// Геттеры
double Point::GetX() const { return X; }
double Point::GetY() const { return Y; }

// Сеттеры
void Point::SetX(double x) { X = x; }
void Point::SetY(double y) { Y = y; }
// Оператор копирующего присваивания =
Point& Point::operator=(const Point& other)
{
    if (this == &other) return *this;

    X = other.X;
    Y = other.Y;

    return *this;
}
// Арифметические операторы (+,-,*,/)
Point Point::operator+(const Point& other) const
{
    return Point(X + other.X, Y + other.Y);
}

Point Point::operator-(const Point& other) const
{
    return Point(X - other.X, Y - other.Y);
}

Point Point::operator*(const Point& other) const
{
    return Point(X * other.X, Y * other.Y);
}

Point Point::operator/(const Point& other) const
{
    return Point(X / other.X, Y / other.Y);
}
// Вывод
void Point::Show() const
{
    SetRandomColor();
    cout << "(" << X << ", " << Y << ")" << endl;
    ResetColor();
}
