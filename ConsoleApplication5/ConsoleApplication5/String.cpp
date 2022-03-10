#include <iostream>
#include <string>

using namespace std;

class MyClassSTR
{
public: 
	// ����������� �����������
	MyClassSTR()
	{
		str = nullptr;
	}
	// ����������� �������� �����
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
	// �������� ������������
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
	// ����������� �����������  
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
	// Concatenation string +  ������������
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

class Test; // ������������� ������� � ������ 

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
	// ���������� ��������� + 
	Point operator +(const Point & other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	// ���������� ��������� -
	Point operator -(const Point & other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}
	// ���������� ��������� *
	Point operator *(const Point & other)
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;
		return temp;
	}
	// ���������� ��������� /
	Point operator /(const Point & other)
	{
		Point temp;
		temp.x = this->x / other.x;
		temp.y = this->y / other.y;
		return temp;
	}

	// ���������� ���������� � ����������
	Point & operator ++() // ����������
	{
		this->x += 1;
		this->y++;
		return *this;
	}
	Point & operator ++(int value) // �����������
	{
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}
	Point & operator --() // ����������
	{
		this->x -= 1;
		this->y--;
		return *this;
	}
	Point & operator --(int value) // �����������
	{
		Point temp(*this);
		this->x--;
		this->y--;
		return temp;
	}
	// ������������� ������� � ������ 
	friend void ChangeX(Point &value, Test &test_value);
};

// ���������� ��������� ��������������

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

// ������������� ������� � ������ 
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

// ������������� ����� ������. 

class Apple;


class Human
{
public:
	void TakeApple(Apple &apple);  // ��������� ��������������� ������ ������. 
	
	void EatApple(Apple &apple) // (��)������������� ����� ������. 
	{
		// ������ ���������� � apple.wheit
		// ������ ���������� � apple.color
	}
};



class Apple
{
public:
	

	Apple(int wheit, string color)  // ����������� �������� ������
	{
		this->color = color;
		this->wheit = wheit;
		Count++;
		id = Count;
	}
	friend void Human::TakeApple(Apple &apple); // ������������� ����� ������. 

	void GetId()
	{
		cout << id << endl;
	}

	void GetWheit()
	{
		cout << this->wheit << endl;
	}

	static int GetCount() // ����������� ����� ������
	{
		return Count;
		//this->wheit = 0; // ERROR ��������� ������ (����������) 
	}

	static void CutWheit(Apple & apple, int procent)
	{
		apple.wheit = apple.wheit/procent;
	}

private:
	static int Count; // ��������� ������ ������
	int wheit;		  // ��������� ������ (����������) Dinamic
	string color;
	int id;
};

// ������������� ������������ ���� ������
int Apple::Count = 0;

// ��������� ������ in class
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

// ��������� � ����������-���������

class Cap
{
public:
	string Get_color()
	{
		return color;
	}
private:
	string color = "�������";
};

class Dog
{
public:
	void CheckCap()
	{
		cout << "����� �� ������ " << cap.Get_color() << endl;
	}
private:
	Cap cap; // ���������
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
		cout << "���� ����� " <<  cap_1.Get_color() << endl;
	}
private:
	class Brain
	{
	public:
		void Think()
		{
			cout << "� �����..." << endl;
		}
	};
	Cap cap_1;	 // ���������
	Brain brain; // ����������
};

// ������������

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
	void learn()	// ���������� ������� 
	{
		cout << "� �������� " << endl;
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
	void learn()	// ���������� ������� 
	{
		cout << "� �������� ������������ " << endl;
	}
};

class Professor : public People
{
public:
	string subject;
};

// ������������ ������� ��� ������������. private public protected

class Message
{
public:
	string msg_public = "��������� public 1";

protected:
	string msg_protected = "��������� protected 3";

private:
	string msg_private = "��������� private 2";

};

class Message_Public : public Message
{
public:
	void PrintMsg_Public()
	{
		cout << msg_public << endl;
	}
	void PrintMsg_Protected()		// Protected ����� ����������� �� ������ ���������� �� �������
	{
		cout << msg_protected << endl;
	}
};

class Message_Protected : protected Message		// Publiv , Protected ����� 
{
public:
	void PrintMsg_Public()
	{
		cout << msg_public << endl;
	}
	void PrintMsg_Protected()		// Protected ����� ����������� �� ������ ���������� �� �������
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
	cout << endl << "--- �������� ������������ = ---" << endl;

	str1 = str2;

	str1.Print();
	str2.Print();
	cout << endl << "---- ������������ ����� + ----" << endl;

	MyClassSTR str3("Hello +");
	MyClassSTR str4(" World");

	MyClassSTR concatenation; 
	concatenation = str3 + str4;
	concatenation.Print();
	cout << endl << "--------" << endl;

	// ���������� ��������� + - / * 
	
	Point a(1, 3);
	Point b(2, 6);

	cout << endl << "---- ���������� ��������� +  ----" << endl;
	Point c = a + b;
	c.Print();

	cout << endl << "---- ���������� ��������� -  ----" << endl;
	Point d = b - a;
	d.Print();

	cout << endl << "---- ���������� ��������� *  ----" << endl;
	Point e = b * a;
	e.Print();

	cout << endl << "---- ���������� ��������� /  ----" << endl;
	Point f = b / a;
	d.Print();

	// ���������� ���������� � ����������
	cout << endl << "---- ���������� ���������� � ����������  ----" << endl;
	Point i(1, 1);
	++i;
	i.Print();

	cout << endl << "---- ���������� ���������� ����������� ----" << endl;
	Point j = i++;
	Point i2(2, 2);
	cout << "j " << endl ;
	j.Print();
	cout << "i " << endl;
	i.Print();
	cout << endl << "---- ���������� ���������� ���������� ----" << endl;
	j = ++i2;
	cout << "i2 " << endl;
	i2.Print();
	cout << "j " << endl;
	j.Print();

	// ���������� ��������� ��������������
	cout << endl << "---- ���������� ��������� �������������� ----" << endl;

	Testcls cls;
	cout << cls[0] << endl;
	cls[0] = 999;
	cout << cls[0] << endl;

	// ������������� ������� � ������ 
	cout << endl << "---- ������������� ������� � ������ ----" << endl;
	Point z(0, 0);
	Test t;
	z.Print();
	ChangeX(z, t);
	z.Print();

	// ������������� ����� ������. 
	cout << endl << "---- ������������� ����� ������. ----" << endl;
	Apple apple_1(150, "Red");
	Human man;
	man.TakeApple(apple_1);
	
	// ����������� ������ ������
	cout << endl << "---- ����������� ���� ������. ----" << endl;
	Apple apple_2(160, "Green");

	cout << "Apples = " << Apple::GetCount() << endl;

	cout << "Apple 1 = " << apple_1.GetCount() << endl;
	cout << "Apple 2 = " << apple_2.GetCount() << endl;

	apple_1.GetId();
	apple_2.GetId();
	// ����������� ����� ������
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

	// ��������� ������ in class
	cout << endl << "---- ��������� ������ in class. ----" << endl;

	Image img;
	img.GetImageInfo();

	cout << endl << "---- ������� ������ ��������. ----" << endl;
	Image::Pixel pixel(255, 255, 255);
	cout << pixel.GetInfo() << endl;

	// // ��������� � ����������
	cout << endl << "---- // ��������� � ����������. ----" << endl;

	Man the_man;
	the_man.Think();
	the_man.CheckCap();

	Dog dog;
	dog.CheckCap();

	// ������������
	Studen studen_1;
	studen_1.name = "VDK";	// ��������� � People
	studen_1.learn();		// ���������� ����� 
	studen_1.Set_rating(10);// ���������� ����� 
	cout << "Rating = " << studen_1.Get_rating() << endl;
	
	Studen_distance student_2;
	student_2.name = "Valera";		// ��������� � People
	student_2.learn();				//  ��������� � Studen � �������������
	student_2.Set_rating(8);		//  ��������� � Studen
	cout << "Rating = " <<student_2.Get_rating() << endl;

	Professor proffesor_1;		
	proffesor_1.name = "45";	// ��������� � People
	proffesor_1.Set_age(50);	// ��������� � People
	cout << "Proffesor age " <<proffesor_1.Get_age() << endl;

	// ������������ ������� ��� ������������. private public protected
	cout << endl << "---- // ������������ ������� ��� ������������: public ----" << endl;

	Message_Public Msg_P;	// ������������ �����
	Msg_P.PrintMsg_Public();
	cout << Msg_P.msg_public << endl;
	//cout << Msg_P.msg_2 << endl;	// No private 
	//cout << Msg_P.msg_3 << endl;	// No Protected
	//Msg_P.PrintMsg_Private();		// ����������� ������
	Msg_P.PrintMsg_Protected(); // Protected ����� ����������� �� ������ ���������� �� �������
	cout << endl << "---- // ������������ ������� ��� ������������: protected ----" << endl;

	Message_Protected m_protected;
	m_protected.PrintMsg_Protected();
	m_protected.PrintMsg_Public();

	return 0;
}

// ��������������� ������
void Human::TakeApple(Apple & apple)
{
	cout << "Take apple (color = " << apple.color << ", wheit = " << apple.wheit << " gram)" << endl;
}
