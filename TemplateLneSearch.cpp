// TemplateLineSearch
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//прототип шаблона функции Линенйный поиск
template <typename T, typename L> L LineSearch(T Array[], L Size, T Key);

int main()
{
    system("chcp 1251 > NUL");
    srand(time(NULL));

    const unsigned short Size = 100;
    unsigned short Element_Index = 0;

    int ArrayInt[Size]{}, IntKey = 0; //IntKey переменная для поиска значения в массиве
    float ArrayFloat[Size]{}, FloatKey = 0;
    char ArrayChar[Size]{}, CharKey = 0;

    for (unsigned short i = 0; i < Size; i++)    //for (int i = 0; i < Size; i++)
    {
        ArrayInt[i] = rand() % (100 - (-99)) - 99;
        ArrayFloat[i] = (rand() % (100 - (-99)) - 99) * 1.1F;
        ArrayChar[i] = rand() % (256 - 33) + 33; //коды символов от 33 до 255 включительно
        cout << "[" << i << "]\t" << ArrayInt[i] << "\t" << ArrayFloat[i] << "\t" << ArrayChar[i] << endl;
    }
    //Ввод данных для поиска
    cout << "\nВведите значение искомого элемента типа данных int: "; cin >> IntKey;
    cout << "Введите значение искомого элемента типа данных float: "; cin >> FloatKey;
    cout << "Введите значение искомого элемента типа данных char: "; cin >> CharKey;

    /*if (3.9 == 2.6 + 1.3) cout << "Ура!" << endl;
    else cout << "Ошибка!" << endl;
    double C = 3.9;
    double D = 0.0;
    cin >> D;
    if(2.6 + 1.3 ==D)cout << "Ура!" << endl;
    else cout << "Ошибка!" << endl;*/

    //поиск целого числа
    Element_Index = LineSearch(ArrayInt, Size, IntKey);
    //if(Element_Index==-1)cout << "Искомый элемент не найден!" << endl;
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    else cout << "Индекс искомого элемента типа данных int равен: " << Element_Index << endl;

    //поиск вещественного числа
    Element_Index = LineSearch(ArrayFloat, Size, FloatKey);
    //if(Element_Index==-1)cout << "Искомый элемент не найден!" << endl;
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    else cout << "Индекс искомого элемента типа данных float равен: " << Element_Index << endl;

    //поиск символа
    Element_Index = LineSearch(ArrayChar, Size, CharKey);
    //if(Element_Index==-1)cout << "Искомый элемент не найден!" << endl;
    if (Element_Index == Size)cout << "Искомый элемент не найден!" << endl;
    else cout << "Индекс искомого элемента типа данных char равен: " << Element_Index << endl;

}
//реализация шаблона функции Линейный поиск
template<typename T, typename L> L LineSearch(T Array[], L Size, T Key)
{
    //тип данных счетчика должен совпадал с типом данных размера массива
    for (L i = 0; i < Size; i++)
    {
        if (Array[i] == Key)return i;//возвращаем индекс найденного элемента массива
    }
    //если элемент не найден
    //return -1; //возврат в функциях, с размером Size знакового типа данных(int, short, long, long long)
    return Size; //возврат в функциях, с размером Size беззнакового типа данных(unsigned int, unsigned short, unsigned long, unsigned long long)
}