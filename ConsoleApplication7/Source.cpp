#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

// вызов виртуального метода базового класса

class Msg
{
public:
	Msg(string msg)
	{
		this->msg = msg;
	}
	virtual string GetMsg()
	{
		return msg;
	}

private:
	string msg;
};

class BracketMsg : public Msg
{
public:
	BracketMsg(string msg) :Msg(msg)
	{

	}
	string GetMsg() override
	{
		return "[" + :: Msg :: GetMsg() + "]";	// Вызвать метод GetMsg() базового класса
	}

};

class Printer
{
public:
	void Print(Msg *msg)
	{
		cout << msg->GetMsg() << endl;
	}
private:
};

// Множественное наследование - Наследовать от многих родителей

class Car
{
public:
	Car()
	{
		cout << "Вызвался конструктор Car" << endl;
	}
	~Car()
	{
		//cout << "Вызвался Деструктор Car" << endl;
	}
	string salon = "BMW";
	void Drive()
	{
		cout << "Driving" << endl;
	}
	void Use()
	{
		cout << "Метод Car Use" << endl;
	}
private:

};

class Airplane
{
public:
	Airplane()
	{
		cout << "Вызвался конструктор AirPlane" << endl;
	}
	~Airplane()
	{
		//cout << "Вызвался Деструктор AirPlane" << endl;
	}
	string engine = "Boeing";
	void Fly()
	{
		cout << "Flying" << endl;
	}
	void Use()
	{
		cout << "Метод Airplane Use " << endl;
	}
private:

};
/*
* Порядок вызова конструкторов при множественном наследовании зависит от порядка наследования.
* Порядок вызова Деструкторов при множественном наследовании в обратном последовательности от конструктора.
*/
class FlyingCar : public Car, public Airplane	// Множественное наследование
{
public:
	
private:

};

// Интерфейс в ООП - Абстракный класс (класс с чистой виртуальной функцей )

class IBicycle
{
public:
	void virtual EwistTheWheel() = 0;
	void virtual Ride() = 0;

};

class SimpleBicycle : public IBicycle
{
public:
	void EwistTheWheel() override
	{
		cout << "Method EwistTheWheel class SimpleBicycle" << endl;
	}
	void Ride() override
	{
		cout << "Method Ride class SimpleBicycle" << endl;
	}

};

class SportBicycle : public IBicycle
{
public:
	void EwistTheWheel() override
	{
		cout << "Method EwistTheWheel class SportBicycle" << endl;
	}
	void Ride() override
	{
		cout << "Method Ride class SportBicycle" << endl;
	}

};

class Human
{
public:
	void RideOn(IBicycle & bycicle)
	{
		cout << "Крутим руль" << endl;
		bycicle.EwistTheWheel();
		cout << "Go go go " << endl;
		bycicle.Ride();

	}
};

// Виртуальное наследование - Ромбовидное наследование

class Character
{
public:
	int HP;
	Character()
	{
		cout << "Конструктор Character" << endl;
	}
};


class Orc : public virtual Character	// Виртуальное наследование - Ромбовидное наследование
{
public:
	Orc()
	{
		cout << "Конструктор Orc" << endl;
	}
};

class Warrior  : public virtual Character	// Виртуальное наследование - Ромбовидное наследование
{
public:
	Warrior()
	{
		cout << "Конструктор Warrior" << endl;
	}
};

class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "Конструктор OrcWarrior" << endl;
	}
};

// Запись ОБЪЕКТА КЛАССА в файл

class Point
{
public:
	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void PrintPoints()
	{
		cout << "X: " << x << "\tY: " << y << "\tZ: " << z << endl;
	}
	
private:	// Перегрузка операторов ввода и вывода для приватных объектов x,y,z
	int x;
	int y;
	int z;
	friend istream& operator >> (istream& is, Point& point);
	friend ostream& operator << (ostream& os, const Point& point);
};

//  ввода 
ostream& operator << (ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}
// Перегрузка операторa  вывода
istream& operator >> (istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}

// Обработка исключений. Пример. throw
void Foo(int value)
{
	if (value < 0)
	{
		throw exception("Число меньше ноля!");
	}
	cout << "Переменная = " << value << endl;
}
// Несколько блоков catch.
void Foo2(int value)
{
	if (value < 0)
	{
		//throw exception("Число меньше ноля!");
		throw "Число меньше ноля!";
	}
	cout << "Переменная = " << value << endl;

	if (value == 0)
	{
		throw exception("Число равна нолю!");
	}
	cout << "Переменная = " << value << endl;

	if (value == 1)
	{
		throw 1;
	}
	cout << "Переменная = " << value << endl;
}

//  Создание собственного класса исключений
class MyException : public exception
{
public:
	MyException(int dataState) //: exception(msg)
	{
		this->dataState = dataState;
	}
	int GetdataState()
	{
		return dataState;
	}
private:
	int dataState;

};

void Foo3(int value)
{
	if (value < 0)
	{
		throw exception("Число меньше ноля!");
	}
	
	if (value == 1)
	{
		throw MyException(value);	
	}
	cout << "Переменная = " << value << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "ru");

	// вызов виртуального метода базового класса
	cout << "Вызов виртуального метода базового класса" << endl;

	Msg message_1("Hello");
	Printer p_1;
	p_1.Print(&message_1);
	BracketMsg msg_breaket("Вызов виртуального метода базового класса!");
	msg_breaket.GetMsg();
	p_1.Print(&msg_breaket);

	// Множественное наследование  - Наследовать от многих родителей
	cout << "Множественное наследование  - Наследовать от многих родителей" << endl;

	FlyingCar fc;
	fc.Drive();
	fc.Fly();
	cout << "Engin " << fc.engine << endl;
	cout << "Salon " << fc.salon << endl;

	Car* pointerCar = &fc;
	Airplane* pointerPlaner = &fc;

	// Порядок вызова конструкторов при множественном наследовании.
	cout << "Порядок вызова конструкторов при множественном наследовании." << endl;

	FlyingCar my_flyingcar;

	// Множественное наследование одинаковые методы
	cout << "множественное наследование одинаковые методы." << endl;

	((Car)my_flyingcar).Use();
	((Airplane)my_flyingcar).Use();

	// Интерфейс в ООП - Абстракный класс (класс с чистой виртуальной функцей )
	cout << "-------------------- Интерфейс в ООП - Абстракный класс (класс с чистой виртуальной функцей ) ----------------------" << endl;

	SportBicycle sport_bike;
	SimpleBicycle bicycle_1;
	Human man_1;

	man_1.RideOn(bicycle_1);
	man_1.RideOn(sport_bike);

	// Виртуальное наследование - Ромбовидное наследование
	cout << "Виртуальное наследование - Ромбовидное наследование." << endl;

	OrcWarrior Orc_man;		// Вызывает Character только 1 раз

	// Работа с файлами  
	cout << "Работа с файлами. ofstream Запись " << endl;
	// fstream
	// ifstream
	// ofstream

	string path = "MyFile.txt";
	ofstream fout;
	fout.open(path, ofstream::app); // ofstream::app Дозапись
	

	if (!fout.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "Введите число: " << endl;
		int number;
		cin >> number;
		fout << "\n";
		fout << number;
	}

	fout.close();

	// Чтение из файла 
	cout << "Работа с файлами. ofstream Чтение " << endl;
	ifstream fin;

	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "File opened: \n" << endl;
		char ch;
		string str;
		/* 
		while (fin.get(ch))
		{
			cout << ch;
		}
		*/
		/*
		while (!fin.eof())
		{
			str = "";		// Чтобы последняя не повторялась 
			fin >> str;		// Считывает до пробела 
			cout << str << endl;
		}
		*/
		while (!fin.eof())
		{
			str = "";		// Чтобы последняя не повторялась 
			getline(fin, str);	// По строчно
			cout << str << endl;
		}
	}
	fin.close();

	// Запись ОБЪЕКТА КЛАССА в бинарный файл

	cout << "Запись ОБЪЕКТА КЛАССА в файл " << endl;
	string path_point = "File_point.txt";

	Point point1(450, 657, 98);

	point1.PrintPoints();

	ofstream file_save;
	file_save.open(path_point, ofstream::app); // ofstream::app Дозапись


	if (!file_save.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "File opened for write" << endl;
		file_save.write((char*)&point1,sizeof(Point));
	}

	file_save.close();

	// Считать с бинарного файла 
	ifstream get_file_point;

	get_file_point.open(path_point);

	if (!get_file_point.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "\nFile opened for read:" << endl;
		Point pnt;
		while (get_file_point.read((char*)&pnt, sizeof(Point)))
		{
			pnt.PrintPoints();
		}
		
	}
	get_file_point.close();

	// Чтение и запись в файл используя класс fstream
	cout << "\nЧтение и запись в файл используя класс fstream:" << endl;

	string path_2 = "in_out_fstream.txt";
	fstream fs;
	fs.open(path_2, fstream::in | fstream::out | fstream::app);	// 

	if (!fs.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		string msg;
		int value;
		cout << "\nФайл открыт!" << endl;
		cout << "Введите 1 для записи сообщения в файл:" << endl;
		cout << "Введите 2 для считывания всех сообщения из файла:" << endl;
		cin >> value;
		if (value == 1)
		{
			cout << "Введите ваше сообщение:" << endl;
			SetConsoleCP(1251);	// Русская кодировка консоли
			cin >> msg;
			fs << msg << "\n";
			SetConsoleCP(866);	// Вернуть стандартную кодировку консоли
		}
		if (value == 2)
		{
			
			string str2;
			while (!fs.eof())
			{
				str2 = "";		// Чтобы последняя не повторялась 
				getline(fs, str2);	// По строчно
				cout << str2 << endl;
			}
			
		}
	}
	fs.close();

	// Перегрузка операторов потокового ввода вывода
	cout << "\nПерегрузка операторов потокового ввода вывода" << endl;

	string path_ptn = "point.txt";
	Point point(400, 500, 600);
	//cout << point;		// Перегрузка операторa вывода
	fstream fs_ptn;	
	fs_ptn.open(path_ptn, fstream::in | fstream::out | fstream::app);

	if (!fs_ptn.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "\nФайл открыт!" << endl;
		//fs_ptn << point << "\n";  // Перегрузка операторa вввода
		while (true)
		{
			Point p_temp;
			fs_ptn >> p_temp;
			if (fs_ptn.eof())	
			{
				break;
			}
			cout << p_temp << endl;
		}

		
	}
	fs_ptn.close();

	// Обработка исключений  try catch 
	cout << "\nОбработка исключений  try catch " << endl;

	string path_tc = "try_catch.txt";

	ifstream fin_tc;

	fin_tc.exceptions(ifstream::badbit | ifstream::failbit);	// 

	try
	{
		cout << "Попытка открыть файл!" << endl;
		fin_tc.open(path_tc);
		cout << "Файл успешно открыт!" << endl;

	}
	//catch (const std::exception& ex)		//Стандартный метод 
	catch (const ifstream::failure & ex)	// Перезагрузка ifstream
	{
		cout << "Error!" << endl;
		cout << "Code error: " << ex.code() << endl;	// код ошибки ifstream
		cout << ex.what() << endl;
		
	}

	// Обработка исключений. Пример. throw
	cout << "\nОбработка исключений. Пример. throw " << endl;
	try
	{
		Foo(-55);
	}
	catch (const exception &ex)
	{
		cout << "Поймали исключений " << ex.what() << endl;
	}

	// Несколько блоков catch.
	cout << "\nНесколько блоков catch." << endl;
	try
	{
		//Foo2(-55);
		//Foo2(0);
		Foo2(1);
	}
	catch (exception &ex2)
	{
		cout << "Блок 1 Поймали исключений " << ex2.what() << endl;
	}
	catch (const char *ex2)
	{
		cout << "Блок 2 Поймали исключений " << ex2 << endl;
	}
	catch (...)		// Ловим все виды исключения - Блок в конце должен быть 
	{
		cout << "Блок 3 Что то пошло не так. " << endl;
	}

	//  Создание собственного класса исключений
	cout << "\nСоздание собственного класса исключений." << endl;

	try
	{
		Foo3(1);
	}
	catch (exception& ex4)
	{
		cout << "Блок 2 Поймали исключений " << ex4.what() << endl;
	}
	catch (MyException &ex3)
	{
		cout << "Блок 1 Поймали исключений " << ex3.what() << endl;
		cout << "Состояние  dataState = " << ex3.GetdataState()  << endl;
	}
	
	
	


















	return 0;
}
