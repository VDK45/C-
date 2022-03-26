#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>
#include <memory>

using namespace std;

// ������������� ��� enum 
class PC
{
public:
	enum PCState  // enum ��������������� � ������ PC
	{
		OFF,
		ON,
		SLEEP
	};

	PCState SetPcState(PCState state)
	{
		this->State = state;
		return State;
	}
	PCState GetPcState()
	{
		return State;
	}
private:
	PCState State;
};

enum Speed	//	constan enum
{
	MIN = 100,
	NORMAL = 300,
	MAX = 600
};

// ������������ ���� name space 
namespace ns_1
{
	void Foo()
	{
		cout << "Foo ns_1" << endl;
	}
	class Point
	{
	public:

		Point()
		{
			cout << "Point ns_1" << endl;
		}
	};
}

namespace ns_2		// ns_2
{
	void Foo()
	{
		cout << "Foo ns_2" << endl;

	}
	class Point
	{
	public:
		Point()
		{
			cout << "Point ns_2" << endl;
		}
	};
}

namespace third_ns
{
	namespace ns_2		// ns_2
	{
		void Foo()
		{
			cout << "third_ns ns_2 Foo" << endl;

		}
	}
}

// ������� �������

//template <typename T1, typename T2>	// ���������� ��� �
template <class T1, class T2>	// ���������� ��� �

class MyClass
{
public:
	MyClass(T1 value, T2 value2)
	{
		this->value = value;
		this->value2 = value2;
	}

	void DataTypeSizeT()
	{
		cout << "\nvalue = " << sizeof(value) << endl;
		cout << "value2 = " << sizeof(value2) << endl;

	}
private:
	T1 value;
	T2 value2;
};

class MyPoint
{
public:
	MyPoint() 
	{
		x = y = z = 0;
	}
	MyPoint(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	int x;
	int y;
	int z;

private:

};

// ������������ ��������� �������

template <class T1>
class TypeSize
{
public:
	TypeSize(T1 value)
	{
		this->value;
	}

	void DataTypeSize()
	{
		cout << "Value = " << sizeof(value) << endl;
	}
protected:
	T1 value;
};

template <typename T1>
class TypeInfo : public TypeSize<T1>
{
public:
	TypeInfo(T1 value):TypeSize(value)  // ???
	{

	}
};

// ������������� ������� ������

template <typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};

template<>
class Printer<string>	// ������������� ������� ������
{
public:
	void Print(string value)
	{
		cout << "----- " << value << " -----" << endl;

	}
};

template<>
class Printer<int>	// ������������� ������� ������
{
public:
	void Print(int value)
	{
		cout << "+++++++ " << value << " +++++++" << endl;

	}
};

// ��������� � C++ | struct ������� ����� ���������� � �������
class ClassA
{
	int a = 110;
	void Print()
	{
		cout << a << endl;

	}
};
class ClassA2 : ClassA	// ������������ private ����������
{

};

struct StructA
{
	int a = 80;
	void Print()
	{
		cout << a << endl;

	}
};
struct StructA2 : StructA	// ������������ public ����������
{

};

// ����� ���������. Smart pointers.

template<typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr)
	{
		this->ptr = ptr;
		cout << "CONSTRUCTOR: " << *ptr << endl;
	}
	~SmartPointer()
	{
		cout << "DESTRUCTOR: " << *ptr << endl;
		delete ptr;
	}
	// ������������ ��������� *
	T& operator*()
	{
		cout << "RETURN: " << *ptr << endl;
		return *ptr;
	}
private :
	T* ptr;
};



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
	setlocale(LC_ALL, "ru");

	// ������������� ��� enum 
	cout << "----------- ������������� ��� enum -----------" << endl;

	PC pc1;
	PC::PCState pcs;
	pc1.SetPcState(PC::PCState::SLEEP);

	if (pc1.GetPcState() == PC::PCState :: ON)
	{
		cout << "PC ON" << endl;
	}
	if (pc1.GetPcState() == PC::PCState::OFF)
	{
		cout << "PC OFF" << endl;
	}
	if (pc1.GetPcState() == PC::PCState::SLEEP)
	{
		cout << "PC Sleep" << endl;
	}

	switch (pc1.GetPcState())
	{
	case PC::PCState :: OFF:
		cout << "PC OFF" << endl;
		break;
	case PC::PCState::ON:
		cout << "PC ON" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "PC Stanby" << endl;
		break;
	}

	// ������������ ���� name space 
	cout << "\n-------- ������������ ���� name space  ---------" << endl;

	ns_1::Foo();
	ns_2::Foo();
	third_ns::ns_2::Foo();
	using namespace ns_1;		// ������������ � ns_1 ��� ��������� ns_1::
	Foo();
	Point p1;	// using namespace ns_1;	
	ns_2::Point p2;		// using namespace ns_2;

	// ������� �������
	cout << "\n-------- ������� �������  ---------" << endl;

	int a = 5;
	string b = "Hello world";
	MyPoint mypoint;

	MyClass<int, MyPoint> myclass_1(a, mypoint);
	myclass_1.DataTypeSizeT();
	
	MyClass<string, MyPoint> myclass_2(b, mypoint);
	myclass_2.DataTypeSizeT();

	MyClass<MyPoint, MyPoint> myclass_3(mypoint, mypoint);
	myclass_3.DataTypeSizeT();

	// ������������ ��������� �������
	cout << "\n-------- ������������ ������� �������  ---------" << endl;

	int c = 6;
	TypeSize<int> tpsize(c);
	tpsize.DataTypeSize();

	//TypeInfo<int> tpinfo(c);
	//tpinfo.DataTypeSize();

	// ������������� ������� ������
	cout << "\n-------- ������������� ������� ������  ---------" << endl;

	Printer<string> P;
	P.Print("Helllo world!!!");

	Printer<int> P2;
	P2.Print(4444);

	// ��������� � C++ | struct ������� ����� ���������� � �������
	cout << "\n-------- ��������� � C++ | struct ������� ����� ���������� � �������  ---------" << endl;

	ClassA ca;
	StructA sa;
	
	// ca2.Print()); error
	sa.Print();

	ClassA2 ca2;
	StructA2 sa2;

	// ca2.Print()); error
	sa2.Print();

	// ����� ���������. Smart pointers.
	cout << "\n--------  ����� ���������.| Smart pointers.  ---------" << endl;

	SmartPointer<int> sptr = new int(45);
	cout << *sptr << endl;
	*sptr = 99;
	cout << *sptr << endl;

	// ����� ���������.| auto_ptr | unique_ptr | shared_ptr | 
	cout << "\n--------  ����� ���������.| auto_ptr | unique_ptr | shared_ptr |  ---------" << endl;

	// SmartPointer<int> sptr1 = new int(999);
	// SmartPointer<int> sptr2 = sptr1; // Error - 2 ��������� �� 1 ������ � Destructor ������ �������

	auto_ptr<int> ap1(new int (5));
	auto_ptr<int> ap2(ap1);	// ��������� ap1 ���������

	unique_ptr<int> up1(new int(5));
	unique_ptr<int> up2;
	//up2 = move(up1);	// ok
	//up2.swap(up1);	// ok
	//int *p = up1.get(); //ok

	//int* p = new int(5);
	//unique_ptr<int> p1(p);

	shared_ptr<int> sp1(new int(50));	// ����� ������� 
	shared_ptr<int> sp2(sp1);
	
	// ������������ ������ � ����� ���������. | Smart pointers
	cout << "\n-------- ������������ ������ � ����� ���������. | Smart pointers ---------" << endl;

	int SIZE;
	cout << "Enter number: " << endl;
	cin >> SIZE;
	int* arr = new int[SIZE] {};

	shared_ptr<int[]> spa1(arr);	// ������

	for (int i = 0; i < SIZE; i++)
	{
		spa1[i] = rand() % 100;
		cout << spa1[i] << endl;
	}

	// ������������ ������ | ������������ ��������� ������ #1
	cout << "\n-------- ������������ ������ | ������������ ��������� ������ #1 ---------" << endl;

	

	// ����� ���������. END
	cout << "\n--------  ����� ���������.| END  ---------" << endl;
}