// RectangleEyukin
//Создать класс прямоугольник(Rectangle) с полями "длина" (length) и "ширина" (width) и перегрузить для него 
// все операторы сравнения, сравнение производить по площади(2 перегрузки как методы класса, 
// 2 перегрузки дружественные перегрузки, 2 глобальные перегрузки)
//как метод
//bool operator==(const Rectangle& B)const;
//дружественная перегрузка
//friend bool operator!=(const Rectangle& A, const Rectangle& B);
//глобальная перегрузка
//bool operator<=(const Rectangle& A, const Rectangle& B);
//operator==
//operator!=
//operator<=
//operator>=
//operator<
//operator>
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

// Класс прямоугольник
class Rectangle {
    int length;
    int width;

public:
    Rectangle(int l = 0, int w = 0) : length(l), width(w) {}

    int area() const {
        return length * width;
    }

    // методы класса
    bool operator==(const Rectangle& other) const {
        return area() == other.area();
    }

    bool operator<(const Rectangle& other) const {
        return area() < other.area();
    }
    void draw() const {
        int l = length;
        int w = width;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < l; j++) {
                if (i == 0 || i == w - 1 || j == 0 || j == l - 1)
                {
                    SetRandomColor();
                    cout << "* ";//рамка
                    ResetColor();
                }
                else
                    cout << "  ";//пространство внутри прямоугольника
            }
            cout << endl;
        }
        cout << endl;
    }

    // дружественные
    friend bool operator!=(const Rectangle& A, const Rectangle& B);
    friend bool operator>(const Rectangle& A, const Rectangle& B);


};

// ===== Реализация дружественных =====
bool operator!=(const Rectangle& A, const Rectangle& B) {
    return A.area() != B.area();
}

bool operator>(const Rectangle& A, const Rectangle& B) {
    return A.area() > B.area();
}
// ===== Реализация глобальных =====
bool operator<=(const Rectangle& A, const Rectangle& B) {
    return A.area() <= B.area();
}

bool operator>=(const Rectangle& A, const Rectangle& B) {
    return A.area() >= B.area();
}
int safeInput(const char* text)
{
    int value;
    char extra;

    while (true)
    {
        SetRandomColor();
        cout << text;
        ResetColor();

        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            while (cin.get() != '\n');

            SetRandomColor();
            cout << "Ошибка: введите число!\n";
            ResetColor();
            continue;
        }

        if (cin.get(extra) && extra != '\n')
        {
            while (cin.get() != '\n');

            SetRandomColor();
            cout << "Ошибка: введите число!\n";
            ResetColor();
            continue;
        }

        if (value <= 0)
        {
            SetRandomColor();
            cout << "Ошибка: значение должно быть > 0!\n";
            ResetColor();
            continue;
        }

        return value;
    }
}

// ===== ввод прямоугольника =====
Rectangle inputRectangle(int n) {
    int l, w;

    SetRandomColor();
    cout << "Прямоугольник " << n << endl;
    ResetColor();

    l = safeInput("Введите длину прямоугольника: ");
    w = safeInput("Введите ширину прямоугольника: ");

   return Rectangle(l, w);
}

// ===== меню =====
void menu() {
    SetRandomColor();
    cout << "\n===== Меню =====\n";
    ResetColor();
    SetRandomColor();
    cout << "1. r1 == r2\n";
    ResetColor();
    SetRandomColor();
    cout << "2. r1 != r2\n";
    ResetColor();
    SetRandomColor();
    cout << "3. r1 < r2\n";
    ResetColor();
    SetRandomColor();
    cout << "4. r1 > r2\n";
    ResetColor();
    SetRandomColor();
    cout << "5. r1 <= r2\n";
    ResetColor();
    SetRandomColor();
    cout << "6. r1 >= r2\n";
    ResetColor();
    SetRandomColor();
    cout << "7. Ввести новые прямугольники\n";
    ResetColor();
    SetRandomColor();
    cout << "8. Показать текущие площади\n";
    ResetColor();
    SetRandomColor();
    cout << "0. Выйти\n";
    ResetColor();
    SetRandomColor();
    cout << "Выбор: ";
    ResetColor();
}

int main() {
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    system("title Прямоугольник - сравнение по площади!");
    cout << boolalpha;
    Rectangle r1, r2;
    int choice;

    // первый ввод
    r1 = inputRectangle(1);
    r2 = inputRectangle(2);

    do {
        menu();
        cin >> choice;
        system("cls");
        SetRandomColor();
        switch (choice) {

        case 1:
            cout << (r1 == r2) << endl;
            break;

        case 2:
            cout << (r1 != r2) << endl;
            break;

        case 3:
            cout << (r1 < r2) << endl;
            break;

        case 4:
            cout << (r1 > r2) << endl;
            break;

        case 5:
            cout << (r1 <= r2) << endl;
            break;

        case 6:
            cout << (r1 >= r2) << endl;
            break;

        case 7:
            SetRandomColor();
            cout << "\n=== Новые прямоугольники ===\n"; //возможность повторного ввода параметров прямоугольников
            ResetColor();
            r1 = inputRectangle(1);
            r2 = inputRectangle(2);
            break;

        case 8:
            SetRandomColor();
            cout << "\nТекущие площади:\n";
            ResetColor();
            SetRandomColor();
            cout << "r1 = " << r1.area() << endl;
            ResetColor();
            SetRandomColor();
            cout << "r2 = " << r2.area() << endl;
            ResetColor();
            r1.draw();
            r2.draw();
            break;

        case 0:
            SetRandomColor();
            cout << "Для выхода из программы нажмите любую клавишу...";
            ResetColor();
            system("pause > NUL");
            break;

        default:
            SetRandomColor();
            cout << "Неверный выбор!\n";
            ResetColor();
        }

        ResetColor();

    } while (choice != 0);
}