// DynArraysOperatorsEyukin
//Перегрузить для класса DynArray операторы + - * / % для ситуаций DynArray+int и int+DynArray. Использовать дружественные и глобальные перегрузки и перегрузку как метод класса
//Ситуации для перегрузки :
//DynArray + int
//DynArray - int
//DynArray * int
//DynArray / int
//DynArray % int
//int + DynArray
//int - DynArray
//int* DynArray
//int / DynArray
//int% DynArray

//#include <iostream> //не требуется, так как подключена в "DynArray.h"
#include "DynArray.h"
//using namespace std; //не требуется, так как подключена в "DynArray.h"
//функция создания и заполнения массива случайными числами
DynArray CreateArray(size_t Size)
{
    DynArray TMP(Size); //создает локальный lvalue объект функции, указанного размера
    TMP.Randomize();	//заполняет объект случайными числами от -99 до 99 включительно
    return TMP;
}
//функция красивого вывода массива объектов класса DynArray на экран
void Show(const DynArray* Array, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Array[i].Size(); j++)
        {
            if (Array[i][j] >= 0)cout << " "; //пробел перед положительным числом
            if (Array[i][j] >= -9 && Array[i][j] <= 9)cout << " "; //пробел перед числом из одной цифры
            SetRandomColor();
            cout << Array[i][j] << " ";
            ResetColor();
        }
        cout << endl;
    }
}

int main()
{
    system("chcp 1251 > NUL");
    srand((unsigned int)time(nullptr));
    SetConsoleTitleA("DynArray");

 // Конструктор с параметром

    DynArray arr1(size_t(10));

    arr1.Randomize(-50, 50);

    SetRandomColor();
    cout << "Массив arr1: "<< arr1 << endl;
    ResetColor();

    // Сортировка по возрастанию

    SetRandomColor();
    cout << "Сортировка arr1 по возрастанию:\n";
    ResetColor();

    arr1.Sort(true);

    SetRandomColor();
    cout << "Результат: "<< arr1 << endl;;
    ResetColor();

    // Сортировка по убыванию

    DynArray arr2(size_t(10));

    arr2.Randomize(-99, 99);

    SetRandomColor();
    cout << "Массив arr2: "<< arr2 << endl;
    ResetColor();

    SetRandomColor();
    cout << "Сортировка arr2 по убыванию:\n";
    ResetColor();

    arr2.Sort(false); // arr2.Sort(); 

    SetRandomColor();
    cout << "Результат: "<< arr2 << endl;
    ResetColor();

    // Конструктор копирования
    DynArray copyArr(arr2);
    SetRandomColor();
    cout << "Создание копии arr2: "<< copyArr << endl;
    ResetColor();

    SetRandomColor();
    cout << "arr1 + 5: "<< arr1 + 5 << endl;;
    ResetColor();

    SetRandomColor();
    cout << "arr1 - 5: "<< arr1 - 5 << endl;
    ResetColor();

    SetRandomColor();
    cout << "arr1 * 2: "<< arr1 * 2 << endl;
    ResetColor();

    SetRandomColor();
    cout << "arr1 / 2: "<< arr1 / 2 << endl;;
    ResetColor();


    SetRandomColor();
    cout << "arr1 % 7: "<< arr1 % 7 << endl;;
    ResetColor();

    SetRandomColor();
    cout << "100 + arr2: "<< 100 + arr2 << endl;;
    ResetColor();

    SetRandomColor();
    cout << "100 - arr2: "<< 100 - arr2 << endl;
    ResetColor();

    SetRandomColor();
    cout << "3 * arr2: "<< 3 * arr2 << endl;
    ResetColor();

    SetRandomColor();
    cout << "100 / arr2: "<< 100 / arr2 << endl;
    ResetColor();

    SetRandomColor();
    cout << "100 % arr2: "<< 100 % arr2 << endl;;
    ResetColor();

    // Конструктор списочной инициализации

    DynArray listArr{ 5, 1, 9, -3, 7, 0, 12 };

    SetRandomColor();
    cout << "Массив listArr: "<< listArr << endl;
    ResetColor();

    listArr.Sort();
    SetRandomColor();
    cout << "listArr после сортировки: "<< listArr << endl;
    ResetColor();

    // Оператор +
    DynArray sum = arr1 + arr2;
    SetRandomColor();
    cout << "Сумма arr1 + arr2: "<< sum << endl;;
    ResetColor();
    
    // Операторы == и !=

    SetRandomColor();
    cout << "Проверка операторов сравнения:\n";
    ResetColor();

    if (arr1 == arr2) {
        SetRandomColor();
        cout << "arr1 == arr2\n";
        ResetColor();
    }
    else {
        SetRandomColor();
        cout << "arr1 != arr2\n";
        ResetColor();
    }

    if (copyArr == arr2)
    {
        SetRandomColor();
        cout << "copyArr == arr2\n";
        ResetColor();
    }

    DynArray A; //Конструктор по умолчанию
    SetRandomColor();
    cout << "Объект А: " << A << endl;
    ResetColor();

    ////I Вариант переменная типа данных size_t
    //size_t Size = (size_t)10;
    //DynArray B(Size); //конструктор с параметром
    //cout << "Объект B: " << B << endl;

    ////II Вариант приведение типа данных к size_t
    //DynArray B((size_t)10); //конструктор с параметром
    //cout << "Объект B: " << B << endl;

    ////III Вариант литерал типа данных unsigned int для x86
    DynArray B(10U); //конструктор с параметром
    SetRandomColor();
    cout << "Объект B: " << B << endl;
    ResetColor();

    ////III Вариант литерал типа данных unsigned long long для x64
    //DynArray B(10ULL); //конструктор с параметром
    //cout << "Объект B: " << B << endl;
    //	//III Вариант выбор типа данных исходя из платформы x64 или x86	
    //#ifdef _WIN64
    //	DynArray B(10ULL); //конструктор с параметром
    //#else
    //	DynArray B(10U); //конструктор с параметром
    //#endif
    //	cout << "Объект B: " << B << endl;

    DynArray C{ 1,2,3,4,5 }; //конструктор списочной инициализации
    SetRandomColor();
    cout << "Объект C: " << C << endl;
    ResetColor();
    ////DynArray D(5U); //конструктор с параметром, получим объект из 5 элементов заполненных 0
    DynArray D{ 5U }; //конструктор списочной инициализации
    //получим объект из одного элемента со значением 5
    SetRandomColor();
    cout << "Объект D: " << D << endl;
    ResetColor();
    SetRandomColor();
    cout << "Размер массива внутри объекта: " << D.Size() << endl;
    ResetColor();
    DynArray E = C; //конструктор копирования

    SetRandomColor();
    cout << "Объект E: " << E << endl;
    ResetColor();
    SetRandomColor();
    cout << "Результат работы функции: " << CreateArray(5) << endl;
    ResetColor();


    DynArray F = CreateArray(5); //конструктор перемещения
    SetRandomColor();
    cout << &F << endl;
    ResetColor();

    SetRandomColor();
    cout << "Объект F: " << F << endl;
    ResetColor();
    DynArray T;
    T = CreateArray(5); //оператор  присваивания
    SetRandomColor();
    cout << &T << endl;
    ResetColor();
    SetRandomColor();
    cout << "Объект T: " << T << endl;
    ResetColor();


    DynArray Z(8U);
    SetRandomColor();
    cout << Z << endl;
    ResetColor();
    for (int i = 0; i < Z.Size(); i++)
    {
        Z[i] = i + 1;
        SetRandomColor();
        cout << Z[i] << " ";
        ResetColor();

    }
    cout << endl;

    //cout << Z[13] << endl;

    const DynArray W{ 10,20,30,40,50 }; //массив содержащий 5 констант
    SetRandomColor();
    cout << W << endl;
    ResetColor();
    SetRandomColor();
    cout << W[3] << endl;
    ResetColor();
    //W[3] = 15;
    //cout << W[13] << endl;

    DynArray Q;
    cout << endl;
    Q = Z + W; //оператор перемещающего присваивания переместит результат сложения в объект Q
    SetRandomColor();
    cout << "Объект W: " << W << endl;
    ResetColor();
    SetRandomColor();
    cout << "Объект Z: " << Z << endl;
    ResetColor();
    SetRandomColor();
    cout << "Объект Q: " << Q << endl;
    ResetColor();

    if (Q == Z + W)//if(Q==Z)
    {
        SetRandomColor();
        cout << "Объекты равны!" << endl;
        ResetColor();
    }
    else {
        SetRandomColor();
        cout << "Объекты не равны!" << endl;
        ResetColor();
    }

    // Resize
    arr1.ReSize(15);
    arr1.Randomize(0, 9);
    SetRandomColor();
    cout << "Resize arr1: "<< arr1 << endl;
    ResetColor();

    // Пользовательский массив

    char repeat;

    do
    {
        size_t userSize;

        SetRandomColor();
        cout << "Введите количество элементов массива: ";
        ResetColor();

        cin >> userSize;

        DynArray userArr(userSize);

        SetRandomColor();
        cout << "Введите элементы массива:\n";
        ResetColor();

        cin >> userArr;

        SetRandomColor();
        cout << "Ваш массив: "<< userArr << endl;;
        ResetColor();

        // Выбор сортировки

        int choice;

        SetRandomColor();
        cout << "1 - По возрастанию\n";
        ResetColor();
        SetRandomColor();
        cout << "2 - По убыванию\n";
        ResetColor();
        SetRandomColor();
        cout << "Ваш выбор: ";
        ResetColor();

        cin >> choice;

        if (choice == 1)
        {
            userArr.Sort(true);
            SetRandomColor();
            cout << "Результат: "<< userArr << endl;
            ResetColor();
        }
        else if (choice == 2)
        {
            userArr.Sort(false);
            SetRandomColor();
            cout << "Результат: "<< userArr << endl;
            ResetColor();
        }
        else
        {
            SetRandomColor();
            cout << "Неверный выбор! Сортировка не выполнена.\n";
            ResetColor();
        }

        SetRandomColor();
        cout << "userArr + 5:" << userArr + 5 << endl;
        ResetColor();

        SetRandomColor();
        cout << "userArr - 5: "<< userArr - 5 << endl;
        ResetColor();

        SetRandomColor();
        cout << "userArr * 2: "<< userArr * 2 << endl;
        ResetColor();

        SetRandomColor();
        cout << "userArr / 2: "<< userArr / 2 << endl;
        ResetColor();

        SetRandomColor();
        cout << "userArr % 7: "<< userArr % 7 << endl;
        ResetColor();

        SetRandomColor();
        cout << "100 + userArr: "<< 100 + userArr << endl;
        ResetColor();

        SetRandomColor();
        cout << "100 - userArr: "<< 100 - userArr << endl;
        ResetColor();

        SetRandomColor();
        cout << "3 * userArr: "<< 3 * userArr << endl;
        ResetColor();

        SetRandomColor();
        cout << "100 / userArr: "<< 100 / userArr << endl;
        ResetColor();

        SetRandomColor();
        cout << "100 % userArr: "<< 100 % userArr << endl;
        ResetColor();

        // Повтор

        SetRandomColor();
        cout << "Повторить? (y/n): ";
        ResetColor();

        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    // Динамический массив объектов DynArray

    int Size = 0;

    SetRandomColor();
    cout << "Введите количество объектов таблицы: ";
    ResetColor();

    cin >> Size;

    DynArray* Array = new(nothrow) DynArray[Size]; //массив из Size объектов класса DynArray с конструктором по умолчанию

    if (Array)
    {
        int count = 0; //кол-во элементов используемое при заполениен объекта класса

        //цикл заполнения массива объектов
        for (int i = 0; i < Size; i++)
        {
            //cin >> count;

            ////I Вариант
            //Array[i] = CreateArray(10);
            ////Array[i] = CreateArray(count);
            //cout << Array[i] << endl;

            ////II Вариант
            //Array[i].ReSize(10);
            ////Array[i].ReSize(count);
            //Array[i].Randomize(10,99); //от 10 до 99 включительно
            ////cout << Array[i] << endl; 

            ////III Вариант
            //Array[i].ReSize(5);
            ////Array[i].ReSize(count);
            //cout << "Введите элементы " << i << "-ой строки массива: " << endl;
            //cin >> Array[i]; //Array[i] - объект нашего класса DynArray

            //IV Вариант
            Array[i].ReSize(10);
            //Array[i].ReSize(count);
            for (int j = 0; j < Array[i].Size(); j++)
            {
                Array[i][j] = rand() % (100 - (-99)) - 99; //каждый j-й элемент типа данных int 
                //для каждого i-го объекта класса DynArray заполняем вручную
                //if (Array[i][j] >= 0)cout << " "; //пробел перед положительным числом
                //if (Array[i][j] >= -9 && Array[i][j] <= 9)cout << " "; //пробел перед числом из одной цифры
                //cout << Array[i][j] << " ";
            }
            //cout << endl;
        }
        cout << endl;

        /*for (int i = 0; i < Size; i++)
        {
            cout << Array[i] << endl;
        }*/

        Show(Array, Size);

        int Max = Array[0][0];

        for (int i = 0; i < Size; i++)
        {
            for (int j = 0; j < Array[i].Size(); j++)
            {
                if (Array[i][j] > Max)Max = Array[i][j];
            }
        }
        SetRandomColor();
        cout << "Максимальный элемент всей таблицы равен: " << Max << endl;
        ResetColor();
        cout << endl;

        if (Size >= 2)Array[0] = Array[1]; //оператор копирующего присваивания
        Show(Array, Size);

        if (Size >= 2 && Array[0] == Array[1])
        {
            SetRandomColor();
            cout << "Первая и вторая строка таблицы совпадают!" << endl;
            ResetColor();
        }
        //Array[0].ReSize(15);
        //Array[0].Randomize();
        Show(Array, Size);
        delete[] Array;
        Array = nullptr;
    }
    SetRandomColor();
    cout << "Для выхода из программы нажмите любую клавишу...";
    ResetColor();
    system("pause > NUL");
}

