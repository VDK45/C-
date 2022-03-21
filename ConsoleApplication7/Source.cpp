#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

// ����� ������������ ������ �������� ������

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
		return "[" + :: Msg :: GetMsg() + "]";	// ������� ����� GetMsg() �������� ������
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

// ������������� ������������ - ����������� �� ������ ���������

class Car
{
public:
	Car()
	{
		cout << "�������� ����������� Car" << endl;
	}
	~Car()
	{
		//cout << "�������� ���������� Car" << endl;
	}
	string salon = "BMW";
	void Drive()
	{
		cout << "Driving" << endl;
	}
	void Use()
	{
		cout << "����� Car Use" << endl;
	}
private:

};

class Airplane
{
public:
	Airplane()
	{
		cout << "�������� ����������� AirPlane" << endl;
	}
	~Airplane()
	{
		//cout << "�������� ���������� AirPlane" << endl;
	}
	string engine = "Boeing";
	void Fly()
	{
		cout << "Flying" << endl;
	}
	void Use()
	{
		cout << "����� Airplane Use " << endl;
	}
private:

};
/*
* ������� ������ ������������� ��� ������������� ������������ ������� �� ������� ������������.
* ������� ������ ������������ ��� ������������� ������������ � �������� ������������������ �� ������������.
*/
class FlyingCar : public Car, public Airplane	// ������������� ������������
{
public:
	
private:

};

// ��������� � ��� - ���������� ����� (����� � ������ ����������� ������� )

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
		cout << "������ ����" << endl;
		bycicle.EwistTheWheel();
		cout << "Go go go " << endl;
		bycicle.Ride();

	}
};

// ����������� ������������ - ����������� ������������

class Character
{
public:
	int HP;
	Character()
	{
		cout << "����������� Character" << endl;
	}
};


class Orc : public virtual Character	// ����������� ������������ - ����������� ������������
{
public:
	Orc()
	{
		cout << "����������� Orc" << endl;
	}
};

class Warrior  : public virtual Character	// ����������� ������������ - ����������� ������������
{
public:
	Warrior()
	{
		cout << "����������� Warrior" << endl;
	}
};

class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "����������� OrcWarrior" << endl;
	}
};

// ������ ������� ������ � ����

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
	
private:	// ���������� ���������� ����� � ������ ��� ��������� �������� x,y,z
	int x;
	int y;
	int z;
	friend istream& operator >> (istream& is, Point& point);
	friend ostream& operator << (ostream& os, const Point& point);
};

//  ����� 
ostream& operator << (ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}
// ���������� ��������a  ������
istream& operator >> (istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}

// ��������� ����������. ������. throw
void Foo(int value)
{
	if (value < 0)
	{
		throw exception("����� ������ ����!");
	}
	cout << "���������� = " << value << endl;
}
// ��������� ������ catch.
void Foo2(int value)
{
	if (value < 0)
	{
		//throw exception("����� ������ ����!");
		throw "����� ������ ����!";
	}
	cout << "���������� = " << value << endl;

	if (value == 0)
	{
		throw exception("����� ����� ����!");
	}
	cout << "���������� = " << value << endl;

	if (value == 1)
	{
		throw 1;
	}
	cout << "���������� = " << value << endl;
}

//  �������� ������������ ������ ����������
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
		throw exception("����� ������ ����!");
	}
	
	if (value == 1)
	{
		throw MyException(value);	
	}
	cout << "���������� = " << value << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "ru");

	// ����� ������������ ������ �������� ������
	cout << "����� ������������ ������ �������� ������" << endl;

	Msg message_1("Hello");
	Printer p_1;
	p_1.Print(&message_1);
	BracketMsg msg_breaket("����� ������������ ������ �������� ������!");
	msg_breaket.GetMsg();
	p_1.Print(&msg_breaket);

	// ������������� ������������  - ����������� �� ������ ���������
	cout << "������������� ������������  - ����������� �� ������ ���������" << endl;

	FlyingCar fc;
	fc.Drive();
	fc.Fly();
	cout << "Engin " << fc.engine << endl;
	cout << "Salon " << fc.salon << endl;

	Car* pointerCar = &fc;
	Airplane* pointerPlaner = &fc;

	// ������� ������ ������������� ��� ������������� ������������.
	cout << "������� ������ ������������� ��� ������������� ������������." << endl;

	FlyingCar my_flyingcar;

	// ������������� ������������ ���������� ������
	cout << "������������� ������������ ���������� ������." << endl;

	((Car)my_flyingcar).Use();
	((Airplane)my_flyingcar).Use();

	// ��������� � ��� - ���������� ����� (����� � ������ ����������� ������� )
	cout << "-------------------- ��������� � ��� - ���������� ����� (����� � ������ ����������� ������� ) ----------------------" << endl;

	SportBicycle sport_bike;
	SimpleBicycle bicycle_1;
	Human man_1;

	man_1.RideOn(bicycle_1);
	man_1.RideOn(sport_bike);

	// ����������� ������������ - ����������� ������������
	cout << "����������� ������������ - ����������� ������������." << endl;

	OrcWarrior Orc_man;		// �������� Character ������ 1 ���

	// ������ � �������  
	cout << "������ � �������. ofstream ������ " << endl;
	// fstream
	// ifstream
	// ofstream

	string path = "MyFile.txt";
	ofstream fout;
	fout.open(path, ofstream::app); // ofstream::app ��������
	

	if (!fout.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "������� �����: " << endl;
		int number;
		cin >> number;
		fout << "\n";
		fout << number;
	}

	fout.close();

	// ������ �� ����� 
	cout << "������ � �������. ofstream ������ " << endl;
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
			str = "";		// ����� ��������� �� ����������� 
			fin >> str;		// ��������� �� ������� 
			cout << str << endl;
		}
		*/
		while (!fin.eof())
		{
			str = "";		// ����� ��������� �� ����������� 
			getline(fin, str);	// �� �������
			cout << str << endl;
		}
	}
	fin.close();

	// ������ ������� ������ � �������� ����

	cout << "������ ������� ������ � ���� " << endl;
	string path_point = "File_point.txt";

	Point point1(450, 657, 98);

	point1.PrintPoints();

	ofstream file_save;
	file_save.open(path_point, ofstream::app); // ofstream::app ��������


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

	// ������� � ��������� ����� 
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

	// ������ � ������ � ���� ��������� ����� fstream
	cout << "\n������ � ������ � ���� ��������� ����� fstream:" << endl;

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
		cout << "\n���� ������!" << endl;
		cout << "������� 1 ��� ������ ��������� � ����:" << endl;
		cout << "������� 2 ��� ���������� ���� ��������� �� �����:" << endl;
		cin >> value;
		if (value == 1)
		{
			cout << "������� ���� ���������:" << endl;
			SetConsoleCP(1251);	// ������� ��������� �������
			cin >> msg;
			fs << msg << "\n";
			SetConsoleCP(866);	// ������� ����������� ��������� �������
		}
		if (value == 2)
		{
			
			string str2;
			while (!fs.eof())
			{
				str2 = "";		// ����� ��������� �� ����������� 
				getline(fs, str2);	// �� �������
				cout << str2 << endl;
			}
			
		}
	}
	fs.close();

	// ���������� ���������� ���������� ����� ������
	cout << "\n���������� ���������� ���������� ����� ������" << endl;

	string path_ptn = "point.txt";
	Point point(400, 500, 600);
	//cout << point;		// ���������� ��������a ������
	fstream fs_ptn;	
	fs_ptn.open(path_ptn, fstream::in | fstream::out | fstream::app);

	if (!fs_ptn.is_open())
	{
		cout << "Error open file" << endl;
	}
	else
	{
		cout << "\n���� ������!" << endl;
		//fs_ptn << point << "\n";  // ���������� ��������a ������
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

	// ��������� ����������  try catch 
	cout << "\n��������� ����������  try catch " << endl;

	string path_tc = "try_catch.txt";

	ifstream fin_tc;

	fin_tc.exceptions(ifstream::badbit | ifstream::failbit);	// 

	try
	{
		cout << "������� ������� ����!" << endl;
		fin_tc.open(path_tc);
		cout << "���� ������� ������!" << endl;

	}
	//catch (const std::exception& ex)		//����������� ����� 
	catch (const ifstream::failure & ex)	// ������������ ifstream
	{
		cout << "Error!" << endl;
		cout << "Code error: " << ex.code() << endl;	// ��� ������ ifstream
		cout << ex.what() << endl;
		
	}

	// ��������� ����������. ������. throw
	cout << "\n��������� ����������. ������. throw " << endl;
	try
	{
		Foo(-55);
	}
	catch (const exception &ex)
	{
		cout << "������� ���������� " << ex.what() << endl;
	}

	// ��������� ������ catch.
	cout << "\n��������� ������ catch." << endl;
	try
	{
		//Foo2(-55);
		//Foo2(0);
		Foo2(1);
	}
	catch (exception &ex2)
	{
		cout << "���� 1 ������� ���������� " << ex2.what() << endl;
	}
	catch (const char *ex2)
	{
		cout << "���� 2 ������� ���������� " << ex2 << endl;
	}
	catch (...)		// ����� ��� ���� ���������� - ���� � ����� ������ ���� 
	{
		cout << "���� 3 ��� �� ����� �� ���. " << endl;
	}

	//  �������� ������������ ������ ����������
	cout << "\n�������� ������������ ������ ����������." << endl;

	try
	{
		Foo3(1);
	}
	catch (exception& ex4)
	{
		cout << "���� 2 ������� ���������� " << ex4.what() << endl;
	}
	catch (MyException &ex3)
	{
		cout << "���� 1 ������� ���������� " << ex3.what() << endl;
		cout << "���������  dataState = " << ex3.GetdataState()  << endl;
	}
	
	
	


















	return 0;
}
