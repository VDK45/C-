#include <iostream>
#include <string>

using namespace std;

class MyClassSTR
{
public: 
	// Стандартный конструктор
	MyClassSTR()
	{
		str = nullptr;
	}
	// Конструктор создания строк
	MyClassSTR(char *str) 
	{
		int length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0';
	// Destruction
	}
	~MyClassSTR()
	{
		delete[] this->str;
	}
	// Оператор присваивания
	MyClassSTR & operator =(const MyClassSTR & other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}
	// Конструктор копирования  
	MyClassSTR(const MyClassSTR & other)
	{
		int leng = strlen(other.str);
		this->str = new char[leng + 1];

		for (int i = 0; i < leng; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[leng] = '\0';
		
	}
	// Concatenation string +  Конкатенация
	MyClassSTR  operator +(const MyClassSTR & other)
	{
		int length1 = strlen(this->str);
		int length2 = strlen(other.str);
		MyClassSTR newstr;
		newstr.str = new char[length1 + length2 + 1];
		int i = 0;
		for (; i < length1; i++)
		{
			newstr.str[i] = this->str[i];
		}
		for (int j = 0; j < length2; j++, i++)
		{
			newstr.str[i] = other.str[j];
		}
		newstr.str[length1 + length2] = '\0';
		return newstr;

	} 
	// Print
	void Print()
	{
		cout << str;
	}
private:
	char *str;
};

class Test; // Дружественные функции и классы 

class Point
{
private:
	int x;
	int y;
	

public:
	Point()
	{
		int x = 0;
		int y = 0;
	}
	Point(int value_x, int value_y)
	{
		x = value_x;
		y = value_y;
	}

	void Print()
	{
		cout << "X = " << this->x << endl;
		cout << "Y = " << this->y << endl;
	}
	// Перегрузка оператора + 
	Point operator +(const Point & other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	// Перегрузка оператора -
	Point operator -(const Point & other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}
	// Перегрузка оператора *
	Point operator *(const Point & other)
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;
		return temp;
	}
	// Перегрузка оператора /
	Point operator /(const Point & other)
	{
		Point temp;
		temp.x = this->x / other.x;
		temp.y = this->y / other.y;
		return temp;
	}

	// Перегрузка инкремента и декремента
	Point & operator ++() // Префиксная
	{
		this->x += 1;
		this->y++;
		return *this;
	}
	Point & operator ++(int value) // Постфиксная
	{
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}
	Point & operator --() // Префиксная
	{
		this->x -= 1;
		this->y--;
		return *this;
	}
	Point & operator --(int value) // Постфиксная
	{
		Point temp(*this);
		this->x--;
		this->y--;
		return temp;
	}
	// Дружественные функции и классы 
	friend void ChangeX(Point &value, Test &test_value);
};

// Перегрузка оператора индексирования

class Testcls
{
public:
	Testcls()
	{

	}
	int & operator[](int index)
	{
		return arr[index];
	}
private:
	int arr[4]{ 5, 44, 77, 20};
};

// Дружественные функции и классы 
void ChangeX(Point &value, Test &test_value)
{
	value.x = 99999;
	//test_value.Data = 99;
}
class Test
{
	int Data = 0;

	friend void ChangeX(Point &value, Test &test_value);
};

// Дружественный метод класса. 

class Apple;


class Human
{
public:
	void TakeApple(Apple &apple);  // Сигнатура Переопределения метода класса. 
	
	void EatApple(Apple &apple) // (Не)дружественный метод класса. 
	{
		// Нельзя обратиться к apple.wheit
		// Нельзя обратиться к apple.color
	}
};



class Apple
{
public:
	

	Apple(int wheit, string color)  // Конструктор создания класса
	{
		this->color = color;
		this->wheit = wheit;
		Count++;
		id = Count;
	}
	friend void Human::TakeApple(Apple &apple); // Дружественный метод класса. 

	void GetId()
	{
		cout << id << endl;
	}

	void GetWheit()
	{
		cout << this->wheit << endl;
	}

	static int GetCount() // Статический метод класса
	{
		return Count;
		//this->wheit = 0; // ERROR Экземпляр класса (Конкретный) 
	}

	static void CutWheit(Apple & apple, int procent)
	{
		apple.wheit = apple.wheit/procent;
	}

private:
	static int Count; // Статическ объект класса
	int wheit;		  // Экземпляр класса (Конкретный) Dinamic
	string color;
	int id;
};

// Инициализация Статического поля класса
int Apple::Count = 0;

// Вложенные классы in class
class Image
{
public:
	void GetImageInfo()
	{
		for (int i = 0; i < LENGHT; i++)
		{
			cout << "#" << i << " " << pixels[i].GetInfo() << endl;
		}
	}

//private:
	static const int LENGHT = 5;
	class Pixel
	{
	public:
		Pixel(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}

		string GetInfo()
		{
			return "Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
		}
	private:
		int r;
		int g;
		int b;
	};

	Pixel pixels[5]
	{
		Pixel(0, 4, 64),
		Pixel(4, 14, 10),
		Pixel(111, 76, 87),
		Pixel(255, 65, 9),
		Pixel(54, 45, 7)
	};
private:

};

// агрегация и композиция-встроеная

class Cap
{
public:
	string Get_color()
	{
		return color;
	}
private:
	string color = "красный";
};

class Dog
{
public:
	void CheckCap()
	{
		cout << "Кепка на собаке " << cap.Get_color() << endl;
	}
private:
	Cap cap; // агрегация
};

class Man
{
public:
	void Think()
	{
		brain.Think();
	}

	void CheckCap()
	{
		cout << "Цвет кепки " <<  cap_1.Get_color() << endl;
	}
private:
	class Brain
	{
	public:
		void Think()
		{
			cout << "Я думаю..." << endl;
		}
	};
	Cap cap_1;	 // агрегация
	Brain brain; // композиция
};

// Наследование

class People
{
public:
	string name;
	void Set_age(int age)
	{
		this->age = age;
	}
	int Get_age()
	{
		return this->age;
	}
private:
	int age;
};

class Studen : public People
{
public:
	string group;
	void learn()	// Расширеная функция 
	{
		cout << "Я обучаюсь " << endl;
	}
	void Set_rating(int rating)
	{
		this->rating = rating;
	}
	int Get_rating()
	{
		return rating;
	}
private:
	int rating = 0;
};

class Studen_distance : public Studen
{
public:
	void learn()	// Расширеная функция 
	{
		cout << "Я обучаюсь дистанционно " << endl;
	}
};

class Professor : public People
{
public:
	string subject;
};

// Модификаторы доступа при наследовании. private public protected

class Message
{
public:
	string msg_public = "Сообщение public 1";

protected:
	string msg_protected = "Сообщение protected 3";

private:
	string msg_private = "Сообщение private 2";

};

class Message_Public : public Message
{
public:
	void PrintMsg_Public()
	{
		cout << msg_public << endl;
	}
	void PrintMsg_Protected()		// Protected можно наследовать но нельзя обратиться из объекта
	{
		cout << msg_protected << endl;
	}
};

class Message_Protected : protected Message		// Publiv , Protected можно 
{
public:
	void PrintMsg_Public()
	{
		cout << msg_public << endl;
	}
	void PrintMsg_Protected()		// Protected можно наследовать но нельзя обратиться из объекта
	{
		cout << msg_protected << endl;
	}
};

/////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");

	MyClassSTR str1("Hello ");
	MyClassSTR str2(" World ");
	str1.Print();
	str2.Print();
	cout << endl << "--- Оператор присваивания = ---" << endl;

	str1 = str2;

	str1.Print();
	str2.Print();
	cout << endl << "---- Конкатенация строк + ----" << endl;

	MyClassSTR str3("Hello +");
	MyClassSTR str4(" World");

	MyClassSTR concatenation; 
	concatenation = str3 + str4;
	concatenation.Print();
	cout << endl << "--------" << endl;

	// Перегрузка оператора + - / * 
	
	Point a(1, 3);
	Point b(2, 6);

	cout << endl << "---- Перегрузка оператора +  ----" << endl;
	Point c = a + b;
	c.Print();

	cout << endl << "---- Перегрузка оператора -  ----" << endl;
	Point d = b - a;
	d.Print();

	cout << endl << "---- Перегрузка оператора *  ----" << endl;
	Point e = b * a;
	e.Print();

	cout << endl << "---- Перегрузка оператора /  ----" << endl;
	Point f = b / a;
	d.Print();

	// Перегрузка инкремента и декремента
	cout << endl << "---- Перегрузка инкремента и декремента  ----" << endl;
	Point i(1, 1);
	++i;
	i.Print();

	cout << endl << "---- Перегрузка инкремента постфиксная ----" << endl;
	Point j = i++;
	Point i2(2, 2);
	cout << "j " << endl ;
	j.Print();
	cout << "i " << endl;
	i.Print();
	cout << endl << "---- Перегрузка инкремента префиксная ----" << endl;
	j = ++i2;
	cout << "i2 " << endl;
	i2.Print();
	cout << "j " << endl;
	j.Print();

	// Перегрузка оператора индексирования
	cout << endl << "---- Перегрузка оператора индексирования ----" << endl;

	Testcls cls;
	cout << cls[0] << endl;
	cls[0] = 999;
	cout << cls[0] << endl;

	// Дружественные функции и классы 
	cout << endl << "---- Дружественные функции и классы ----" << endl;
	Point z(0, 0);
	Test t;
	z.Print();
	ChangeX(z, t);
	z.Print();

	// Дружественный метод класса. 
	cout << endl << "---- Дружественный метод класса. ----" << endl;
	Apple apple_1(150, "Red");
	Human man;
	man.TakeApple(apple_1);
	
	// Статический объект класса
	cout << endl << "---- Статические поля класса. ----" << endl;
	Apple apple_2(160, "Green");

	cout << "Apples = " << Apple::GetCount() << endl;

	cout << "Apple 1 = " << apple_1.GetCount() << endl;
	cout << "Apple 2 = " << apple_2.GetCount() << endl;

	apple_1.GetId();
	apple_2.GetId();
	// Статический метод класса
	cout << "apple_1 wheit " << endl;
	apple_1.GetWheit();
	apple_1.CutWheit(apple_1, 2);
	cout << "apple_1 cut wheit " << endl;
	apple_1.GetWheit();

	cout << "apple_2 wheit " << endl;
	apple_2.GetWheit();
	Apple::CutWheit(apple_2, 3);
	cout << "apple_2 cut wheit " << endl;
	apple_2.GetWheit();

	// Вложенные классы in class
	cout << endl << "---- Вложенные классы in class. ----" << endl;

	Image img;
	img.GetImageInfo();

	cout << endl << "---- Создать пиксел напрямую. ----" << endl;
	Image::Pixel pixel(255, 255, 255);
	cout << pixel.GetInfo() << endl;

	// // агрегация и композиция
	cout << endl << "---- // агрегация и композиция. ----" << endl;

	Man the_man;
	the_man.Think();
	the_man.CheckCap();

	Dog dog;
	dog.CheckCap();

	// Наследование
	Studen studen_1;
	studen_1.name = "VDK";	// Наследует у People
	studen_1.learn();		// Расширеный метод 
	studen_1.Set_rating(10);// Расширеный метод 
	cout << "Rating = " << studen_1.Get_rating() << endl;
	
	Studen_distance student_2;
	student_2.name = "Valera";		// Наследует у People
	student_2.learn();				//  Наследует у Studen и переопределен
	student_2.Set_rating(8);		//  Наследует у Studen
	cout << "Rating = " <<student_2.Get_rating() << endl;

	Professor proffesor_1;		
	proffesor_1.name = "45";	// Наследует у People
	proffesor_1.Set_age(50);	// Наследует у People
	cout << "Proffesor age " <<proffesor_1.Get_age() << endl;

	// Модификаторы доступа при наследовании. private public protected
	cout << endl << "---- // Модификаторы доступа при наследовании: public ----" << endl;

	Message_Public Msg_P;	// Наследованый класс
	Msg_P.PrintMsg_Public();
	cout << Msg_P.msg_public << endl;
	//cout << Msg_P.msg_2 << endl;	// No private 
	//cout << Msg_P.msg_3 << endl;	// No Protected
	//Msg_P.PrintMsg_Private();		// Наследовать нельзя
	Msg_P.PrintMsg_Protected(); // Protected можно наследовать но нельзя обратиться из объекта
	cout << endl << "---- // Модификаторы доступа при наследовании: protected ----" << endl;

	Message_Protected m_protected;
	m_protected.PrintMsg_Protected();
	m_protected.PrintMsg_Public();

	return 0;
}

// Переопределение метода
void Human::TakeApple(Apple & apple)
{
	cout << "Take apple (color = " << apple.color << ", wheit = " << apple.wheit << " gram)" << endl;
}
