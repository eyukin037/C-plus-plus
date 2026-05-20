#pragma once
#include <iostream>
#include <Windows.h> //в каждом методе, где есть ввод-вывод символов,
//отличающихся от латинского алфавита нужно устанавливать соответсвующую кодировку
#include <stdlib.h>
#include <time.h>
#include <initializer_list> //класс для инициализации путем перечисления значений(унифицированной списочной инициализации)

using namespace std;
void SetColor(int color);
void ResetColor();
void SetRandomColor();
//класс описывающий динамический одномерный массив элементов типа данных int
class DynArray
{
	//private:
		//int size = 0;				//кол-во элементов
		//unsigned int size = 0;	//кол-во элементов
	size_t size = 0;			//кол-во элементов
	int* array = nullptr;		//указатель на элементы типа данных int

public:
	DynArray(char) = delete; //отключаем конструктор с char в качестве аргумента
	//Конструктор по умолчанию
	DynArray() = default; //default - просьба компилятору добавить автоматическую реализацию конструктора
	//Конструктор с параметром
	explicit DynArray(size_t);	//DynArray(unsigned int); 
	//DynArray(); //для теста
	//Конструктор копирования
	DynArray(const DynArray&); //принимает константную lvalue ссылку
	//Конструктор перемещения
	DynArray(DynArray&&)noexcept; //rvalue ссылка в качестве параметра, принимает временный безымянный rvalue объект класса DynArray
	//конструктор перемещения служит для извлечения содержимого из одного объекта(временного безымянного) класса DynArray
	//в другой(новый постоянный именованный) объект класса DynArray при его создании
	//Конструктор списочной инициализации
	DynArray(const initializer_list<int>&); //константная ссылка на объект шаблона класса initializer_list, с типом данных int внутри

	//Деструктор
	~DynArray();

	//Сеттеры:
	//Метод заполнения случайными числами от указанного числа и до указанного(по умолчанию от -99 до 99)
	//Нужно сдвинуть генератор случайных чисел в начале функции main!!!
	void Randomize(int = -99, int = 99);
	//Метод изменения размера массива внутри объекта класса DynArray
	void ReSize(size_t);	//void ReSize(unsigned int);

	//Метод установки сторожа (барьера)
	void setExtreme(bool Type);
	//Метод сортировки вставками со сторожем с указанием направления сортировки 
	void Sort(bool Type = false);

	//Геттеры:

	//Метод получения текущего размера массива(кол-ва элементов)
	size_t Size()const;		//unsigned int Size()const;	

	//Перегрузка операторов как методов класса:
	//Перегрузка оператора индексирования []
	int& operator[](int); //как сеттер и геттер для переменных(обычных) объектов класса DynArray(для массива переменных типа данных int)
	//Константная перегрузка оператора индексирования []
	const int operator[](int)const; //только как геттер для константных объектов класса DynArray(для массива констант типа данных int)
	//Перегрузка оператора копирующего присваивания
	DynArray& operator=(const DynArray&); //принимает константную lvalue ссылку
	//Перегрузка оператора перемещающего присваивания
	DynArray& operator=(DynArray&&)noexcept; //rvalue ссылка в качестве параметра, принимает временный безымянный rvalue объект класса DynArray
	//оператор перемещающего присваивания служит для извлечения содержимого из одного объекта(временного безымянного) класса DynArray
	//в другой(постоянный именованный) объект класса DynArray при присваивании в него

	//Перегрузка оператора проверки на равенство ==
	bool operator==(const DynArray&)const; //при сравнении не может быть изменено содержимое сравниваемых объектов
	//Перегрузка оператора проверки на неравенство !=
	bool operator!=(const DynArray&)const; //при сравнении не может быть изменено содержимое сравниваемых объектов
	// Метод класса
	DynArray operator+(int) const;
	DynArray operator/(int) const;
	DynArray operator-(int) const;
	DynArray operator*(int) const;
	DynArray operator%(int) const;
	// Дружественные
	friend DynArray operator+(int, const DynArray&);
	friend DynArray operator-(int, const DynArray&);
	friend DynArray operator*(int, const DynArray&);


	//Перегрузка операторов в виде дружественных функции
	//Перегрузка оператора вывода
	friend ostream& operator<<(ostream&, const DynArray&);
	//Перегрузка оператора ввода
	friend istream& operator>>(istream&, DynArray&);

};
//Перегрузка оператора в виде глобальной функции
DynArray operator/(int, const DynArray&);
DynArray operator%(int, const DynArray&);
//Прототип перегрузки оператора сложения + в виде глобальной фукцнии (сложение массивов поэлементно)
DynArray operator+(const DynArray&, const DynArray&); //возвращает значение временного безымянного объекта