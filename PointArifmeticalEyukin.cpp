// PointArifmeticalEyukin
//Написать класс Point и перегрузить для него все математические операторы(+-*/ %) для ситуации Point + Point, 
// для ситуации Point + int и для ситуации int + Point.
// Использовать дружественные и глобальные перегрузки и перегрузку как метод класса
//Список ситуаций для перегрузки :
//Point + Point
//Point - Point
//Point * Point
//Point / Point
//Под * Point % Point
//Point + int
//Point * int
//Point - int
//Point / int
//Под * Point % int

//int + Point
//int* Point
//int - Point
//int / Point
//Под * int% Point
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const string reset = "\033[0m";

void SetRandomColor()
{
    int color = 31 + rand() % 7; // 31–37

    cout << "\033[" << color << "m";
}

void ResetColor()
{
    cout << reset;
}
//класс Точка
class Point 
{
    //координаты точки
    int X, Y;
public:
    //Конструктор с двумя параметрами и унифицированной инциализацией полей
    Point(int x, int y) : X{ x }, Y{ y } {}
    //Метод вывода экран
    void Show(const string& name = "") const
    {
        SetRandomColor();
        cout << name << "(" << X << ";" << Y << ")" << endl;
        ResetColor();
    }
    //перегрузка операторов в качестве метода класса
    Point operator+(const Point&REF) const 
    {  
        return Point(X + REF.X, Y + REF.Y);
    }
    Point operator-(const Point& REF) const 
    {
        return Point(X - REF.X, Y - REF.Y);
    }
    Point operator*(const Point& REF) const
    {
        return Point(X * REF.X, Y * REF.Y);
    }
    Point operator/(const Point& REF) const
    {
         return Point(X / REF.X, Y / REF.Y);
    }
    Point operator%(const Point& REF) const
    {
        return Point(X % REF.X, Y % REF.Y); 
    }
    //перегрузка операторов в виде дружественных функций
    friend Point operator+(const Point& p, int d);
    friend Point operator-(const Point& p, int d);
    friend Point operator*(const Point& p, int d);
    friend Point operator/(const Point& p, int d);
    friend Point operator%(const Point& p, int d);
    
    //методы для доступа к private полям для глобальной перегрузки операторов
    int GetX()const { return X; }
    int GetY()const { return Y; }
    void SetX(int x) { X = x; }
    void SetY(int y) { Y = y; }
};
//дружественные
Point operator+(const Point& p, int d) 
{
 return Point(p.X + d, p.Y + d);
}
Point operator-(const Point& p, int d)
{
    return Point(p.X - d, p.Y - d);
}
Point operator*(const Point& p, int d)
{
    return Point(p.X * d, p.Y * d);
}
Point operator/(const Point& p, int d)
{
    return Point(p.X / d, p.Y / d);
}
Point operator%(const Point& p, int d)
{
    return Point(p.X % d, p.Y % d);  
}
//глобальные
Point operator+(int d, const Point& p)
{
    return Point(d + p.GetX(), d + p.GetY());
}

Point operator-(int d, const Point& p)
{
    return Point(d - p.GetX(), d - p.GetY());
}

Point operator*(int d, const Point& p)
{
    return Point(d * p.GetX(), d * p.GetY());
}

Point operator/(int d, const Point& p)
{

    return Point(d / p.GetX(), d / p.GetY());
}

Point operator%(int d, const Point& p)
{
    return Point(d % p.GetX(), d % p.GetY()); 
}


int main()
{
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    system("title Перегрузка операторов в классе Point!");

    Point A(6, 31);
    Point B(9, 17);
    Point C(-9, -17);

    A.Show("Точка A: ");
    B.Show("Точка B: ");
    C.Show("Точка C: ");

    SetRandomColor();
    cout << "Перегрузка операторов в качестве метода класса:" << endl;
    ResetColor();

    (A + B).Show("A + B = ");
    (A - B).Show("A - B = ");
    (A * B).Show("A * B = ");
    (A / B).Show("A / B = ");
    (A % B).Show("A % B = ");


    (A + C).Show("A + C = ");
    (A - C).Show("A - C = ");
    (A * C).Show("A * C = ");
    (A / C).Show("A / C = ");
    (A % C).Show("A % C = ");

    (B + C).Show("B + C = ");
    (C - B).Show("C - B = ");
    (B * C).Show("B * C = ");
    (C / B).Show("C / B = ");
    (C % A).Show("C % A = ");



    SetRandomColor();
    cout << "Дружественная перегрузка операторов:" << endl;
    ResetColor();
    (A + 3).Show("A + 3 = ");
    (A - 2).Show("A - 2 = ");
    (A * 4).Show("A * 4 = ");
    (A / 5).Show("A / 5 = ");
    (A % 7).Show("A % 7 = ");

    (C + 3).Show("C + 3 = ");
    (C - 2).Show("C - 2 = ");
    (C * 4).Show("C * 4 = ");
    (C / 5).Show("C / 5 = ");
    (C % 7).Show("C % 7 = ");


    (B + (-3)).Show("B + (-3) = ");
    (B - (-2)).Show("B - (-2) = ");
    (B * (-4)).Show("B * (-4) = ");
    (B / (-5)).Show("B / (-5) = ");
    (B % (-7)).Show("B % (-7) = ");


    SetRandomColor();
    cout << "Глобальная перегрузка операторов:" << endl;
    ResetColor();

    (3 + A).Show("3 + A = ");
    (2 - A).Show("2 - A = ");
    (7 * A).Show("7 * A = ");
    (8 / A).Show("8 / A = ");
    (9 % A).Show("9 % A = ");


    (3 + C).Show("3 + C = ");
    (2 - C).Show("2 - C = ");
    (7 * C).Show("7 * C = ");
    (8 / C).Show("8 / C = ");
    (9 % C).Show("9 % C = ");


    (-3 + B).Show("-3 + B = ");
    (-2 - B).Show("-2 - B = ");
    (-7 * B).Show("-7 * B = ");
    (-8 / B).Show("-8 / B = ");
    (-9 % B).Show("-9 % B = ");


    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}