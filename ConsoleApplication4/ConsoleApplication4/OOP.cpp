#include <iostream>
#include <string>
using namespace std;

class Human
{
public:				// Модификатор доступа классов
	string name;
	int age;
	double height;
	char sex;
	void print_all()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Height: " << height << endl;
		cout << "Sex: " << sex << endl;
		// private 
		cout << "Telephone: " << telephone << endl;
		// protected
		cout << "Password: " << password << endl;
		// --- Call protected ----
		cout << "//----- Call protected -----//" << endl;
		print_private_protected();
	}

	void print_get()
	{
		cout << "Tel = " << telephone << endl;
		cout << "Pass = " << password << endl;
	}

	// Set 

	void Set_telephone(int number)
	{
		telephone = number;
	}

	void Set_password(string pass)
	{
		password = pass;
	}

	// Get

	int Get_telephone()
	{
		return telephone;
	}

	string Get_password()
	{
		return password;
	}

private:			// Модификатор доступа классов
	int telephone;
protected:			// Модификатор доступа классов
	string password;

	void print_private_protected()
	{
		// private 
		cout << "Telephone: " << telephone << endl;
		// protected
		cout << "Password: " << password << endl;
	}
};

// Конструктор класса
class Point
{
private:
	int x;
	int y;

public:
	Point(int value_x, int value_y)
	{
		x = value_x;
		y = value_y;
	}

	void print()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	int get_x()
	{
		return x;
	}

	int get_y()
	{
		return y;
	}
	// Перегрузка оператора равенства == 
	bool operator ==(const Point & other)
	{
		return this->x == other.x && this->y == other.y;
	}
	// Перегрузка оператора не равно != 
	bool operator !=(const Point & other)
	{
		return !(this->x == other.x && this->y == other.y);
	}
};

// Деструктор класса
class My_class
{
private:
	int* data;	// Выделить память для динамического массива
public:
	My_class(int size)
	{
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Объект " << data << " Вызвался Конструктор" << endl;
	}
	~My_class()			// Деструктор
	{
		delete[] data;	// Удалить память динамического массива
		cout << "Объект " << data << " Вызвался Деструктор" << endl;
	}
};

// Construction copy

class Copy
{
public:
	int *data;

	Copy(int size)
	{
		this->data = new int[size];
		this->Size = size;
		cout << "Constructer called " << this << endl;
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
	}

	Copy(const Copy &other)
	{
		//this->data = other.data; // standart
		this->Size = other.Size;
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Constructor copy called " << this << endl;
	}

	// Перегрузка оператора (=) присваивания 

	Copy & operator = (const Copy &other)
	{
		cout << "Operator = called " << this << endl;
		this->Size = other.Size;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}
		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		return *this;
	}

	~Copy()
	{
		cout << "Destructer called  " << this << endl;
		delete[] data;
	}
private:
	int Size;
};






//////////////////////////////////////////////////
void main()
{
	setlocale(LC_ALL, "Rus");

	cout << "//----------- Первый объект (Экземпляр) -------------//" << endl;

	Human first_man;
	first_man.name = "Adam";
	first_man.age = 37;
	first_man.height = 185.45;
	first_man.sex = 'M';

	cout << "first_man name: " << first_man.name << endl;
	cout << "first_man year birth day: " << 2022 - first_man.age << endl;
	cout << "first_man height: " << first_man.height << " cm" << endl;
	cout << "first_man sex: " << first_man.sex << endl;

	cout << "//----------- Второй объект  (Экземпляр) -------------//"  << endl;

	Human first_woman;
	first_woman.name = "Eva";
	first_woman.age = 27;
	first_woman.height = 170.77;
	first_woman.sex = 'W';

	cout << "first_woman name: " << first_woman.name << endl;
	cout << "first_woman year birth day: " << 2022 - first_woman.age << endl;
	cout << "first_woman height: " << first_woman.height << " cm" << endl;
	cout << "first_woman sex: " << first_woman.sex << endl;

	// Метод (функции) класса
	cout << "//----------- Метод (функции) класса -------------//" << endl;

	cout << "//----- Man -----//" << endl;
	first_man.print_all();

	cout << "//----- Woman -----//" << endl;
	first_woman.print_all();

	// Модификаторы доступа классов
	cout << "//----------- Модификаторы доступа классов -------------//" << endl;

	// Get & Set private & protected
	cout << "//----------- Get & Set  -------------//" << endl;
	// Set  private & protected
	first_man.Set_telephone(558066);
	first_man.Set_password("CfyN5#54");

	first_woman.Set_telephone(123456);
	first_woman.Set_password("ArhN58Jik");

	// Get  private & protected
	cout << "Get telephone man: " << first_man.Get_telephone() << endl;
	cout << "Get password man: " << first_man.Get_password() << endl;
	
	cout << "Get telephone woman: " << first_woman.Get_telephone() << endl;
	cout << "Get password woman: " << first_woman.Get_password() << endl;

	cout << "//----- Call print_get() -----//" << endl;
	first_man.print_get();
	first_woman.print_get();

	// Конструктор класса
	cout << "//----- Конструктор класса -----//" << endl;

	Point p1(5, 5);
	Point p2(22, 45);

	p1.print();
	p2.print();

	cout << "p2 - p1 = (" << p2.get_x() - p1.get_x() << ", " << p2.get_y() - p1.get_y() << ")" << endl;

	// Деструктор класса - Удалить память динамического массива
	cout << "//----- Деструктор класса -----//" << endl;
	My_class cl(2);

	// Конструктор копирования
	cout << "//----- Конструктор копирования -----//" << endl;
	Copy a(10);
	Copy b(a);

	//  Перегрузка оператора (=) присваивания 
	cout << "//-----Перегрузка оператора присваивания-----//" << endl;
	Copy x(5);
	Copy y(2);
	Copy z(8);
	x.operator=(y); // a = b;
	x = y = z;
	
	// Перегрузка оператора равенства == и не равно !=
	cout << "//----- Перегрузка оператора равенства == и не равно != -----//" << endl;
	Point p3(5, 1);
	Point p4(9, 4);
	bool result = p3 == p4;
	cout << "P3 == P4: " << result << endl;
	Point p5(5, 1);
	Point p6(9, 4);
	bool result2 = p5 != p6;
	cout << "P3 != P4: " << result2 << endl;
	
	// Перегрузка оператора равенства == и не равно !=
	cout << "//----- Перегрузка оператора равенства == и не равно != -----//" << endl;

}

