#include "Student.h"
//глобальная инициализация статических полей
int Student::Count = 0;
int Student::Count_ID = 0;
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
//Конструктор с параметрами
Student::Student(
	string L_N,     // Фамилия
	string N,       // Имя
	string G,       // Группа
	int A,          // Возраст
	string M_N,     // Отчество
	string g,       // Пол
	string p,       // Телефон
	int C_G         // Количество оценок
)
	: Last_Name{ L_N }, Name{ N }, Middle_Name{ M_N }, Group{ G }, Age{ A }, Gender{ g }, Phone{ p }, Count_Grades{ C_G }, GPA{ 0.0F }, ID{ ++Count_ID }

{
	Count++; //Увеличиваем текущее кол-во студентов
	if (Count_Grades) //если было указано кол-во оценок при вызове конструктора
	{
		//чтобы можно было при создании студента задать кол-во его оценок 
		Grades = new(nothrow)int[Count_Grades] {};  //и это кол-во нельзя будет изменить потом
		//Проверка выделения памяти!
		if (!Grades)
		{
			SetRandomColor();
			cout << "Error! Try again later!" << endl;
			ResetColor();
			Count_Grades = 0;	 //обнуляем кол-во оценок, чтобы потом выделенить память заново в методе Set_Grades
		}
	}
	else Grades = nullptr; //иначе, кол-во оценок не задано при создании студента, оно будет задаваться позднее
	SetRandomColor();
	cout << "Constructor for ID: " << ID << endl; //для теста
	ResetColor();
}
//Коснтруктор по умолчанию(без параметров) с делигированием
Student::Student() : Student("", "", "", 1)
{
	SetRandomColor();
	cout << "Default constructor for ID: " << ID << endl; //для теста
	ResetColor();
}
//Деструктор
Student::~Student()
{
	SetRandomColor();
	cout << "Destructor for ID: " << ID << endl;
	ResetColor();
	Count--;	//уменьшаем текущее кол-во студентов
	if (Grades)	//если были оценки,
	{
		delete[] Grades;	//то освобождаем память
		Grades = nullptr;	//если деструктор был вызван явно(вручную)обнуляем указатель
	}
	Count_Grades = 0;		//если деструктор был вызван явно(вручную) обнуляем кол-во оценок
}
//Задающие методы(сеттеры):
//Метод изменения значения поля Фамилия
inline void Student::Set_Last_Name(string L_N)
{
	//char* Last_Name;
	//delete[] Last_Name;
	//Last_Name = new char[strlen(L_N)+1]{};
	//strcpy_s(Last_Name,strlen(L_N)+1,L_N);
	Last_Name = L_N;
}
//Метод изменения значения поля Имя
inline void Student::Set_Name(string N)
{
	Name = N;
}
//Метод изменения значения поля Отчество
inline void Student::Set_Middle_Name(string M_N)
{
	Middle_Name = M_N;
}
//Метод изменения значения поля Группа
inline void Student::Set_Group(string s) { Group = s; }
//Метод изменения значения поля Возраст
inline void Student::Set_Age(int a) { Age = a; }
//Метод изменения значения поля Пол
inline void Student::Set_Gender(string s) { Gender = s; }
//Метод изменения значения поля Телефон
inline void Student::Set_Phone(string s) { Phone = s; }


//Метод задания оценок
void Student::Set_Grades()
{
	//узнать текущую кодировку на вывод текста
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка нам не подходит, меняем её на нужную
	if (OCP != 1251)SetConsoleOutputCP(1251);

	//работа с текстом в нужной кодировке
	SetRandomColor();
	cout << "У студента " << Last_Name << " " << Name << " " << Middle_Name << " " << Count_Grades << " оценок." << endl;
	ResetColor();
	if (!Count_Grades || !Grades)	//если оценок не было
	{
		//освобождение память на случай если кол-во оценок ноль, а память выделена
		if (Grades != nullptr)delete[] Grades;
		SetRandomColor();
		cout << "Ведите кол-во оценок студента " << Last_Name << " " << Name << " " << Middle_Name << ": ";
		ResetColor();
		cin >> Count_Grades; //добавить проверку ввода, значение должно быть больше 0
		Grades = new int[Count_Grades] {}; //выделяем память под массив оценок
		//Обязательно проверка выделения памяти!
	}
	GPA = 0.0F; //обнуляем средний балл
	for (int i = 0; i < Count_Grades; i++)
	{
		SetRandomColor();
		cout << "Введите " << i + 1 << "-ю оценку: ";
		ResetColor();
		cin >> Grades[i];  //добавить проверку ввода, что оценки от 2 до 5
		GPA += Grades[i];	//Суммируем оценки
	}
	GPA /= Count_Grades; //вычисляем средний балл

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//Метод заполнение всего студента с клавиатуры
void Student::Set_Console_Input()
{
	//узнаем текущие кодировки на вывод и ввод текста
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущие кодировки нам не подходят, меняем их на нужные
	if (OCP != 1251)SetConsoleOutputCP(1251); //установка кодировки на вывод текста
	if (CP != 1251)SetConsoleCP(1251); //установка общая кодировки(на ввод текста)

	//работа с текстом в нужных кодировках
	//cout << "Введите ФИО через пробелы: ";
	//cin >> Last_Name >> Name >> Middle_Name;
	SetRandomColor();
	cout << "Введите ФИО через пробелы, если отчетво отсутствует нажмите Enter 2 раза после имени:" << endl;
	ResetColor();
	cin >> Last_Name >> Name; cin.ignore(); getline(cin, Middle_Name); //Если отчество может быть пустым
	SetRandomColor();
	cout << "Введите группу: ";
	ResetColor();
	cin >> Group;
	SetRandomColor();
	cout << "Введите возраст: ";
	ResetColor();
	cin >> Age;
	SetRandomColor();
	cout << "Введите пол: ";
	ResetColor();
	cin >> Gender;
	SetRandomColor();
	cout << "Введите телефон: ";
	ResetColor();
	cin >> Phone;
	Set_Grades(); //this->Set_Grades(); //ввод оценок и расчет среднего балла
	//если меняли кодировки, возвращаем их обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP); //возвращаем кодировку на вывод текста
	if (CP != 1251)SetConsoleCP(CP); //возвращаем кодировку на ввод текста
}

//Получающие методы(геттеры):
//Метод получения значения поля Фамилия
string Student::Get_Last_Name() const
{
	return Last_Name;
}
//Метод получения значения поля Имя
string Student::Get_Name() const
{
	return Name;
}
//Метод получения значения поля Отчество
string Student::Get_Middle_Name() const
{
	return Middle_Name;
}
// Метод получения значения поля Группа
string Student::Get_Group() const
{
	return Group;
}
// Метод получения значения поля Возраст
int Student::Get_Age() const
{
	return Age;
}
// Метод получения значения поля Пол
string Student::Get_Gender() const
{
	return Gender;
}
// Метод получения значения поля Телефон
string Student::Get_Phone() const
{
	return Phone;
}
//Метод получения значения поля ID
inline int Student::Get_ID() const
{
	return ID;
}
//Статический метод получения текущего кол-ва студентов(объектов класса Student)
int Student::Get_Count()
{
	return Count;
}
//Метод получения адреса массива оценок, без возможности их изменения
const int* Student::Get_Grades() const
{
	return Grades;
}
//Метод получения знчения среднегого балла студента
inline float Student::Get_GPA() const
{
	return GPA;
}
//Метод вывода данных о студенте на экран
void Student::Show() const
{
	//узнать текущую кодировку на вывод текста
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка нам не подходит, меняем её на нужную
	if (OCP != 1251)SetConsoleOutputCP(1251);

	SetRandomColor();
	cout << "ID: " << ID << endl;
	ResetColor();

	SetRandomColor();
	cout << "ФИО: " << Last_Name << " " << Name << " " << Middle_Name << endl;
	ResetColor();

	SetRandomColor();
	cout << "Группа: " << Group << endl;
	ResetColor();

	SetRandomColor();
	cout << "Возраст: " << Age << " ";
	ResetColor();

	int lastDigit = Age % 10;
	int lastTwoDigits = Age % 100;

	if (lastTwoDigits >= 11 && lastTwoDigits <= 14)
	{
		SetRandomColor();
		cout << "лет";
		ResetColor();
	}
	else if (lastDigit == 1)
	{
		SetRandomColor();
		cout << "год";
		ResetColor();
	}
	else if (lastDigit >= 2 && lastDigit <= 4)
	{
		SetRandomColor();
		cout << "года";
		ResetColor();
	}
	else
	{
		SetRandomColor();
		cout << "лет";
		ResetColor();
	}
	cout << endl;

	SetRandomColor();
	cout << "Пол: " << Gender << endl;
	ResetColor();

	SetRandomColor();
	cout << "Телефон: " << Phone << endl;
	ResetColor();

	SetRandomColor();
	cout << "Оценки: ";
	for (int i = 0; i < Count_Grades; i++)
	{
		cout << Grades[i] << " ";
	}
	cout << endl;
	ResetColor();

	SetRandomColor();
	cout << "Средний балл: " << GPA << endl;
	ResetColor();

	SetRandomColor();
	cout << "------------------------\n";
	ResetColor();

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}