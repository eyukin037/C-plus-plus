#pragma once  //директива препроцессора исключает множественное подключение файла
#include <iostream>
#include <string>		//содержит класс string
#include <Windows.h>	//для изменения кодировок
using namespace std;
void SetColor(int color);
void ResetColor();
void SetRandomColor();

//класс описывающий студента
class Student
{
	//Поля:
	string Last_Name;								//Фамилия
	string Name;									//Имя
	string Middle_Name;								//Отчество
	string Group;									//Группа
	int Age;										//Возраст
	string Gender;									//Пол
	string Phone;									//Телефон
	int Count_Grades;								//Кол-во оценок
	int* Grades;									//Динамический массив оценок(указатель на динамически выделенную память)
	float GPA;										//Средний балл оценок
	static int Count;								//Счетчик текущего кол-ва студентов(объектов класса Student)
	static int Count_ID;							//Счетчик для создания уникальных идентификаторов
	const int ID;									//Идентификатор студента

public:
	//Прототипы методов:
	//Student(string, string, string, string, int=0);		//Конструктор с параметрами(Ф,И,О,Г,К_О)
	//Если может не быть отчества, тогда будет пустая строка вместо отчество
	Student(
		string,     // Фамилия (обязательно)
		string,       // Имя (обязательно)
		string,       // Группа (обязательно)
		int = 0,          // Возраст (обязательно)
		string = "",    // Отчество (необязательно)
		string = "",     // Пол (необязательно, по умолчанию "М" или "Ж")
		string = "",      // Телефон (необязательно)
		int = 0        // Количество оценок (необязательно)
	);	//Конструктор с параметрами
	Student();										//Коснтруктор по умолчанию(без параметров)
	Student(const Student&) = delete;				//Исключаем конструктор копирования
	~Student();										//Деструктор
	//Задающие методы(сеттеры):
	inline void Set_Last_Name(string);				//Метод изменения значения поля Фамилия
	inline void Set_Name(string);					//Метод изменения значения поля Имя
	inline void Set_Middle_Name(string);			//Метод изменения значения поля Отчество
	inline void Set_Group(string);					//Метод изменения значения поля Группа
	inline void Set_Age(int);					    //Метод изменения значения поля Возраст
	inline void Set_Gender(string);					//Метод изменения значения поля Пол
	inline void Set_Phone(string);					//Метод изменения значения поля Телефон
	void Set_Grades();								//Метод задания оценок
	void Set_Console_Input();						//Метод заполнение всего студента с клавиатуры
	//Получающие методы(геттеры):
	string Get_Last_Name()const;					//Метод получения значения поля Фамилия
	string Get_Name()const;							//Метод получения значения поля Имя
	string Get_Middle_Name()const;					//Метод получения значения поля Отчество
	string Get_Group() const;						//Метод получения значения поля Группа
	int Get_Age() const;							//Метод получения значения поля Возраст
	string Get_Gender() const;						//Метод получения значения поля Пол
	string Get_Phone() const;						//Метод получения значения поля Телефон
	inline int Get_ID()const;						//Метод получения значения поля ID
	static int Get_Count();							//Статический метод получения текущего кол-ва студентов(объектов класса Student)
	const int* Get_Grades()const;					//Метод получения адреса массива оценок, без возможности их изменения
	inline float Get_GPA()const;					//Метод получения знчения среднегого балла студента
	void Show()const;								//Метод вывода данных о студенте на экран
};