// BrickEyukin
//Создать класс Кирпич с полями(длина, высота, ширина) и методами(конструктор по умолчанию, конструктор с параметрами, 
//метод изменения размеров кирпича и метод вывода данных на экран).
//Создать в main несколько объектов и проверь работу всех методов.
//Под* добавить поле Марка кирпича(в виде строки) в класс и все методы для этого поля необходимые
#include <iostream>
#include <Windows.h> 
#include <stdlib.h>
#include <string.h> 
#include <time.h>
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
// Класс, описывающий кирпич
class Brick {
//private: //по умолчанию всё содержимое класса с модификатором(спецификатор) доступа private
//т.е. доступно только внутри самого класса, private можно не указывать
// Поля класса (скрыты от прямого доступа извне)
    int length; // Длина
    int width;  // Ширина
    int height; // Высота
    char brand[50];  // Марка кирпича (задание под *)
public:
    // 1. Конструктор по умолчанию (создает стандартный одинарный кирпич)
    Brick(){
    length = 250;
    width = 120;
    height = 65;
    strcpy_s(brand, "Стандартный рядовой");
    SetRandomColor();
    cout << "Сработал конструктор по умолчанию!" << endl; 
    ResetColor();
}
    // 2. Конструктор с параметрами
    Brick(int l, int w, int h, const char* b)
    {
        length = l;
        width = w;
        height = h;
        strcpy_s(brand, b);
        SetRandomColor();
        cout << "Сработал конструктор с параметрами!" << endl;
        ResetColor();
    }
    // Деструктор для демонстрации жизненного цикла объекта
    ~Brick()
    {
        SetRandomColor();
        cout << "Сработал деструктор для кирпича марки: " << brand << "!" << endl;
        ResetColor();
    }
    // 3. Метод изменения размеров кирпича (Сеттер для размеров)
    void SetDimensions(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
    }
    // Дополнительный метод изменения марки кирпича (Сеттер для марки)
    void SetBrand(const char* b) 
    {
        strcpy_s(brand, b);
    }
    // Метод для вычисления объема
    int GetVolume()
    {
        return length * width * height;
    }

    // Метод для вычисления площади поверхности
    int GetSurfaceArea()
    {
        return 2 * (length * width + length * height + width * height);
    }
    // 4. Метод вывода данных на экран (Геттер/Инспектор)
    void Show()
    {
        SetRandomColor();
        cout << "--- Данные о кирпиче ---" << endl;
        ResetColor();
        SetRandomColor();
        cout << "Марка: " << brand << endl;
        ResetColor();
        SetRandomColor();
        cout << "Размеры (ДхШхВ): " << length << " x " << width << " x " << height << " мм" << endl;
        ResetColor();
        SetRandomColor();
        cout << "Объем: " << GetVolume() << " мм^3" << endl;
        ResetColor();
        SetRandomColor();
        cout << "Площадь поверхности: " << GetSurfaceArea() << " мм^2" << endl;
        ResetColor();
        SetRandomColor();
        cout << "------------------------\n" << endl;
        ResetColor();
    }
};
int main()
{
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("Кирпич");
    SetRandomColor();
    cout << "Кирпич! \n";
    ResetColor();
    // Блок, ограничивающий время жизни объектов brick1, brick2 и ptrBrick
    {
        cout << "Создание объекта Brick1 (по умолчанию):" << endl;
        Brick brick1;                     // конструктор по умолчанию
        brick1.Show();
        SetRandomColor();
        cout << "Создание объекта Brick2 (с параметрами):" << endl;
        ResetColor();
        Brick brick2(250, 120, 88, "Eyukin-Premium");
        brick2.Show();
        SetRandomColor();
        cout << "Изменение размеров и марки объекта Brick1:" << endl;
        ResetColor();
        brick1.SetDimensions(250, 85, 65);
        brick1.SetBrand("Евро-облицовочный");
        brick1.Show();
        SetRandomColor();
        cout << "Динамическое создание объекта Brick3:" << endl;
        ResetColor();
        Brick* ptrBrick = new Brick(288, 138, 65, "Керамический модульный");
        ptrBrick->Show();
        delete ptrBrick;   // деструктор для динамического объекта вызывается здесь
        ptrBrick = nullptr;
    }   // <-- здесь вызываются деструкторы для brick1 и brick2 (в порядке, обратном созданию)
    // После выхода из блока все автоматические объекты уже уничтожены
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}