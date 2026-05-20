#include "DynArray.h"
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color)
{
    SetConsoleTextAttribute(h, color);
}
void ResetColor()
{
    SetColor(7);
}
void SetRandomColor()
{
    SetColor(1 + rand() % 15);
}
//Конструктор с параметром
DynArray::DynArray(size_t Size) : size{ Size }, array{ new(nothrow)int[size] {} }
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251)  SetConsoleOutputCP(1251);
    if (!array) //проверка выделения памяти
    {
        SetRandomColor();
        cout << "Ошибка выделния памяти! Создан пустой массив!" << endl;
        ResetColor();
        size = 0; //тогда создаем пустой массив
        
    }
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    //else cout << "Память для поля array объекта " << this << " успешно выделена в конструкторе с параметром!" << endl; //для теста!!!
}
//DynArray::DynArray()
//{
    //cout << "Сработал конструктор по умолчанию для объекта " << this << endl;
//}
//Конструктор копирования принимает константную lvalue ссылку на постоянный именованный lvalue объект(Original)
DynArray::DynArray(const DynArray& Original) //: size{Original.size}, array{ new(nothrow)int[size]{} }
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    this->size = Original.size;
    this->array = new(nothrow)int[size] {};
    if (!array) //проверка выделения памяти
    {
        SetRandomColor();
        cout << "Ошибка выделния памяти! Создан пустой массив!" << endl;
        ResetColor();
        size = 0; //тогда создаем пустой массив
    }
    else
    {
        //cout << "Память для поля array объекта " << this << " - копия объекта "<<&Original<<" успешно выделена в конструкторе копирования" << endl; //для теста!!!
        for (size_t i = 0; i < size; i++)
        {
            //копируем значения элементов из поля array объекта Original в новый объект(в копию) this
            this->array[i] = Original.array[i]; //array[i] = Original.array[i];
        }
    }
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
////Eсли в классе перегружен оператор копирующего присваивания, то его можно использовать в конструкторе копирования
//DynArray::DynArray(const DynArray& Original)
//{
//	*this = Original; //использование перегруженного оператора копирующего присваивания
//}

//Конструктор перемещения, принимает временный безымянный rvalue объект класса DynArray
DynArray::DynArray(DynArray&& rVal)	noexcept //: size{rVal.size}, array{rVal.array}
//копириуем адрес памяти, выделенной в исходном(временном безымянном объекте)
//по ссылке rVal в новый постоянный именованный объект
{
    this->size = rVal.size;
    this->array = rVal.array;
    //отбираем право владения памятью у исходного(временного безымянного) объекта и "обнуляем" его
    rVal.array = nullptr;
    rVal.size = 0;
    //cout << "Сработал конструктор перемещения для объекта " << this << ". Объект " << &rVal << " был опустошен!" << endl; //для теста!!!
}
//Конструктор списочной инциализации
//Делегирование - явный вызов конструктора с параметром
DynArray::DynArray(const initializer_list<int>& list) : DynArray(list.size())
{
    size_t i = 0;

    //range-base цикл
    for (int element : list) //for (auto element : list)
    {
        this->array[i] = element; //element - буфер в который на каждом шаге цикла копируются значения
        //из объекта list класса initializer_list<int> с первого до последнего включительно
        i++;
    }
    //cout << "Сработал конструктор списочной инициализации для объекта " << this << endl; //для теста!!!
}
//Деструктор
DynArray::~DynArray()
{
    if (array) //если объект не "пустой"
    {
        //освобождение памяти, выделенной под поле array
        delete[] array;
        array = nullptr;
        size = 0;
        //cout << "Память для поля array объекта " << this << " успешно освобождена!" << endl; //для теста!!!
    }
    //иначе если явно вызывался деструктор или объект пустым изначально или был "опустошен"
    //else cout << "Память для поля array объекта " << this << " уже была освобождена или была пустой!" << endl; //для теста!!!
}
//Сеттеры:
//Метод заполнения случайными числами от укзанного числа и до указанного(по умолчанию от -99 до 99)	
void DynArray::Randomize(int Begin, int End)
{
    //сдвиг генератора случайных чисел в main
    //если массив пустой, то можно запросить размер, выделить память и заполнить
    //проверка если Begin>End
    if (Begin > End)
    {
        int Buffer = Begin;
        Begin = End;
        End = Buffer;
    }
    for (size_t i = 0; i < size; i++)
    {
        //rand()%(A-B)+B от В до А-1 включительно
        array[i] = rand() % (End + 1 - Begin) + Begin;
    }
}
//Метод изменения размера массива внутри объекта класса DynArray
void DynArray::ReSize(size_t NewSize)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    //если текущий размер и новый размер совпадают
    if (this->size == NewSize)return;
    //если новый размер указан ноль
    if (NewSize == 0)
    {
        delete[] array;
        array = nullptr;
        size = 0;
        return;
    }
    //выделяем память под элементы типа данных int новым кол-вом
    int* temp = new(nothrow) int[NewSize] {};
    if (!temp)
    {
        SetRandomColor();
        cout << "Ошибка выделения памяти! Размер массива не будет изменен!" << endl;
        ResetColor();
        return; //тогда не изменяем массив
    }
    if (this->size != 0) //	if(this->size) //if(size)
    {
        //копируем элементы из поля array текущего объекта в новую память
        for (size_t i = 0; i < NewSize; i++)
        {
            if (i < size)temp[i] = array[i]; //если ещё есть элементы в текущем объекте
            else break;	//иначе выход из цикла копирования элементов из поля array текущего объекта в новую память
        }
        delete[] array; //освобождаем старую память поля array
    }
    //изменяем размер текущего объекта
    this->size = NewSize; //size = NewSize;
    //помещаем в поле array текущего объекта адрес новой памяти нужного размера
    this->array = temp; //array = temp;
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}
//Метод установки сторожа (барьера)
void DynArray::setExtreme(bool Type)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    // Type:
    // true  -> максимальный элемент (для сортировки по убыванию)
    // false -> минимальный элемент (для сортировки по возрастанию)
    if (size <= 1) return;
    size_t ExtremeIndex = 0;
    // Поиск экстремального элемента
    for (size_t i = 1; i < size; i++)
    {
        if ((Type && array[i] > array[ExtremeIndex]) || (!Type && array[i] < array[ExtremeIndex]))
        {
            ExtremeIndex = i;
        }
    }
    // Сохраняем найденный элемент
    int temp = array[ExtremeIndex];
    // Сдвиг элементов вправо
    for (size_t j = ExtremeIndex; j > 0; j--)
    {
        array[j] = array[j - 1];
    }
    // Установка сторожа в начало массива
    array[0] = temp;
    SetRandomColor();
    cout << "После перемещения " << (Type ? "максимального" : "минимального") << " элемента: ";
    ResetColor();
    for (size_t k = 0; k < size; k++)
    {
        if (k == 0) SetColor(12);
        else SetRandomColor();
        cout << array[k] << " ";
        ResetColor();
    }
    cout << endl;
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    Sleep(600);
}
//Метод сортировки вставками со сторожем с указанием направления сортировки 
void DynArray::Sort(bool Type)
{
    if (size <= 1) return;
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    setExtreme(!Type);
    size_t i, j;
    int x;
    for (i = 1; i < size; i++)
    {
        x = array[i];
        for (j = i; (Type ? array[j - 1] > x :
        array[j - 1] < x); j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = x;
        SetRandomColor();
        cout << "Шаг " << i << ": ";
        ResetColor();
        for (size_t k = 0; k < size; k++)
        {
            (k == j) ? SetColor(12) : SetRandomColor();

            cout << (k == i ? "| " : "") << array[k] << " ";

            ResetColor();
        }
        SetRandomColor();
        cout << " <- вставляем " << x << endl;
        ResetColor();

        Sleep(600);
    }
    if (OCP != 1251) SetConsoleOutputCP(OCP);
}

//Геттеры:
//Метод получения текущего размера массива(кол-ва элементов)
size_t DynArray::Size() const
{
    return size;
}
//Перегрузка операторов как методов класса:
//Перегрузка оператора индексирования []
int& DynArray::operator[](int index)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    //проверка выхода за границы массива
    //I Вариант - цикл повторного ввода индекса
    while (index < 0 || (size_t)index >= size)
    {
        SetRandomColor();
        cout << "Выход за границы массива! Введите индекс: " << endl;
        ResetColor();
        cin >> index;
    }
    ////II Вариант - закрыть всю программу
    //if (index < 0 || (size_t)index >= size)
    //{
    //	cout << "Выход за границы массива!" << endl;
    //	delete[] array;
    //	exit(3);
    //}
    ////III Вариант - вернуть элемент из начала массива
    //if (index < 0 || (size_t)index >= size)
    //{
    //	cout << "Выход за границы массива! Будет возвращаент элемент с индексом 0!" << endl;
    //	return array[0];
    //}
    //IV Вариант - использовать исключения
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    return array[index]; //возвращаем ссылку на элемент с указанным индексом
}
//Константная перегрузка оператора индексирования []
const int DynArray::operator[](int index) const
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (index < 0 || (size_t)index >= size)
    {
        SetRandomColor();
        cout << "Выход за границы массива!" << endl;
        ResetColor();
        delete[] array;
        exit(3);
    }
    //Но лучше использовать исключения
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    return array[index]; //возвращаем константу - копию значения элемента массива
}
//Перегрузка оператора копирующего присваивания	
DynArray& DynArray::operator=(const DynArray& Original)
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    if (this != &Original) //если не один и тот же объект
    {
        if (this->size != Original.size) //если размеры не совпадают 
        {
            delete[] this->array; //освобождаем старую память поля array текущего объекта this
            this->array = nullptr; //обнуляем указатель
            this->size = Original.size; //получаем новый размер из копируемого объекта Original
            if (this->size)
            {
                this->array = new(nothrow)int[this->size]{}; //array = new(nothrow)int[size]{};
                if (!array)
                {
                    SetRandomColor();
                    cout << "Ошибка выделения памяти!" << endl;
                    ResetColor();
                    size = 0; //тогда оставляем текущий массив пустым
                }
            }
        }
        for (size_t i = 0; i < this->size; i++)
        {
            //копируем элементы из копируемого объекта Original в текущий объект this
            this->array[i] = Original.array[i];
        }
    }
    //cout << "Оператор копирующего присваивания из объекта " << &Original << " в объект " << this << endl; //для теста!!!
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    return *this; //возвращаем ссылку на объект для которого вызывался оператор

}
//Перегрузка оператора перемещающего присваивания
DynArray& DynArray::operator=(DynArray&& rVal) noexcept
{
    //A = move(A);
    if (this != &rVal) //если не один и тот же объект
    {
        //освобождаем старую память поля array текущего объекта
        delete[] this->array; //delete[] array;
        //копируем адрес памяти из присваиваемого объекта, полученнного по rvalue ссылке rVal в текущий this 
        this->array = rVal.array; //array = rVal.array; 
        //получаем новый размер из присваиваемого объекта, полученнного по rvalue ссылке rVal в текущий this 
        this->size = rVal.size;
        //"обнуляем" присваиваемый объект, полученнный по rvalue ссылке rVal
        rVal.array = nullptr;
        rVal.size = 0;
    }
    //cout << "Оператор перемещающего присваивания из объекта " << &rVal << " в объект " << this << endl; //для теста!!!
    return *this; //возвращаем ссылку на объект для которого вызывался оператор
}
//Перегрузка оператора проверки на равенство ==
bool DynArray::operator==(const DynArray& REF) const //*this == REF;
{
    if (this == &REF)return true;	//если сравнивают объект сам с собой
    if (this->size != REF.size)return false;

    //I Вариант
    for (size_t i = 0; i < size; i++)
    {
        //как только найдены неравные элементы
        if (this->array[i] != REF.array[i]) //if(array[i] != REF.array[i])
            return false;
    }
    return true;	//массивы равны

    ////II Вариант
    ////при необходимости сортировка копий обоих объектов *this и REF
    //DynArray Copy_this = *this;
    //DynArray Copy_REF = REF;
    //Copy_this.Sort();
    //Copy_REF.Sort();
    //
    //for (size_t i = 0; i < size; i++)
    //{		
    //	//сравнение отсортированных копий
    //	//как только найдены неравные элементы
    //	if (Copy_this.array[i] != Copy_REF.array[i]) 
    //		return false;
    //}
    //return true;	//массивы равны
}
//Перегрузка оператора проверки на неравенство !=
bool DynArray::operator!=(const DynArray& REF) const //*this != REF;
{
    return !(*this == REF); //обратный результат перегруженного оператора проверки на равенство ==
    //текущего объекта - разыменованный указатель *this и сравниваемого с ним объекта REF
}
//Перегрузка операторов как методы класса 
DynArray DynArray::operator+(int value) const
{
    DynArray result(size);

    for (size_t i = 0; i < size; i++)
    {
        result.array[i] = array[i] + value;
    }

    return result;
}
DynArray DynArray::operator-(int value) const
{
    DynArray result(size);

    for (size_t i = 0; i < size; i++)
    {
        result.array[i] = array[i] - value;
    }

    return result;
}
DynArray DynArray::operator*(int value) const
{
    DynArray result(size);

    for (size_t i = 0; i < size; i++)
    {
        result.array[i] = array[i] * value;
    }

    return result;
}
DynArray DynArray::operator/(int value) const
{
    DynArray result(size);

    for (size_t i = 0; i < size; i++)
    {
        result.array[i] = array[i] / value;
    }

    return result;
}
DynArray DynArray::operator%(int value) const
{
    DynArray result(size);

    for (size_t i = 0; i < size; i++)
    {
        result.array[i] = array[i] % value;
    }

    return result;
}

//Перегрузка операторов в виде дружественных функции
//Перегрузка оператора вывода
ostream& operator<<(ostream& Out, const DynArray& REF) //Out это ссылка на объект cout класса ostream
{
    int OCP = GetConsoleOutputCP();
    if (OCP != 1251) SetConsoleOutputCP(1251);
    //для дружественной перегрузки									//для глобальной перегрузки
    //прямое обращение к полю size объекта REF						//вызов метод Size()	
    for (size_t i = 0; i < REF.size; i++)							//for (size_t i = 0; i < REF.Size(); i++)
    {																//{
        //прямое обращение к полю array объекта REF					//		//вызов перегруженного оператор индексирования для объекта REF
        Out << REF.array[i] << " ";									//		Out << REF[i] <<" ";
    }																//}
    //Out << endl;													//Out << endl;
    if (OCP != 1251) SetConsoleOutputCP(OCP);
    return Out;														//return Out;	

}
//Перегрузка оператора ввода
istream& operator>>(istream& In, DynArray& REF) //In это ссылка на объект cin класса istream
{

    //узнать текущие кодировки на вывод и ввод текста
    int OCP = GetConsoleOutputCP();
    int CP = GetConsoleCP();
    //если текущие кодировки нам не подходят, меняем на нужные
    if (OCP != 1251)SetConsoleOutputCP(1251);  //установка кодировки на вывод текста
    if (CP != 1251)SetConsoleCP(1251); //установка общей кодировки(на ввод теста)
    //cout << "Введите элементы массива через Enter: ";
    //для дружественной перегрузки									//для глобальной перегрузки
    //прямое обращение к полю size объекта REF						//вызов метод Size()	
    for (size_t i = 0; i < REF.size; i++)							//for (size_t i = 0; i < REF.Size(); i++)
    {																//{
        SetRandomColor();
        cout << "Введите " << i << "-й элемент массива: ";			//		cout << "Введите " << i << "-й элемент массива: ";	
        ResetColor();
        //прямое обращение к полю array объекта REF					//		//вызов перегруженного оператор индексирования для объекта REF
        In >> REF.array[i];											//		In>>REF[i];
    }																//}
    //если кодировки менялись нужно вернуть прежние
    if (OCP != 1251)SetConsoleOutputCP(OCP);
    if (CP != 1251)SetConsoleCP(CP);

    return In;														//return In;
}
DynArray operator+(int value, const DynArray& obj)
{
    DynArray result(obj.size);

    for (size_t i = 0; i < obj.size; i++)
    {
        result.array[i] = value + obj.array[i];
    }

    return result;
}
DynArray operator-(int value, const DynArray& obj)
{
    DynArray result(obj.size);

    for (size_t i = 0; i < obj.size; i++)
    {
        result.array[i] = value - obj.array[i];
    }

    return result;
}
DynArray operator*(int value, const DynArray& obj)
{
    DynArray result(obj.size);

    for (size_t i = 0; i < obj.size; i++)
    {
        result.array[i] = value * obj.array[i];
    }

    return result;
}
//Перегрузка оператора в виде глобальной функции
DynArray operator/(int value, const DynArray& obj)
{
    DynArray result(obj.Size());

    for (size_t i = 0; i < obj.Size(); i++)
    {
        result[i] = value / obj[i];
    }

    return result;
}
DynArray operator%(int value, const DynArray& obj)
{
    DynArray result(obj.Size());

    for (size_t i = 0; i < obj.Size(); i++)
    {
        result[i] = value % obj[i];
    }

    return result;
}
//Прототип глобальной перегрузки оператора сложения + (сложение массивов поэлементно)
//Прототип перегрузки оператора сложения + в виде глобальной фукцнии (сложение массивов поэлементно)
DynArray operator+(const DynArray& A, const DynArray& B) //A+B
{
    DynArray Result; //Буфферный пустой объект для хранения результата

    //Сравниваем размеры складываемых объектов
    if (A.Size() > B.Size())
    {
        //копируем в Result объект А бОльшего размера
        Result = A; //перегруженный оператор копирующего присваивания
        size_t Small_Size = B.Size();
        for (size_t i = 0; i < Small_Size; i++)
        {
            Result[i] += B[i]; //прибавляем значения из меньшего массива B,
            //используя перегруженные операторы индексирования []
        }
    }
    else
    {
        //копируем в Result объект B бОльшего размера
        Result = B; //перегруженный оператор копирующего присваивания
        size_t Small_Size = A.Size();
        for (size_t i = 0; i < Small_Size; i++)
        {
            Result[i] += A[i]; //прибавляем значения из меньшего массива A,
            //используя перегруженные операторы индексирования []
        }
    }
    return Result; //Возвращаем значение итогового буферного объекта
}