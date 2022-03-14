#include <iostream>
#include <string>

using namespace std;

// ������� ������ ������������� ��� ������������.
class A
{
public:
	A()
	{
		cout << "�������� ����������� � " << endl;
	}

	virtual ~A()	// ����������� ����������
	{
		cout << "�������� ���������� � " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "�������� ����������� B " << endl;
	}

	~B() override		// ����������� ����������
	{
		cout << "�������� ���������� � " << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "�������� ����������� C " << endl;
	}

	~C()
	{
		cout << "�������� ���������� � " << endl;
	}
};

// ����� ������������ �������� ������ �� ������������ ������-����������.

class D
{
private:
	string msg;
	
public:
	D() // ����������� �����������
	{
		msg = "�������� ����������� D �����������";
	}
	D(string msg) // ����������� ���������������
	{
		this->msg = msg;
	}
	void PrintMsg()
	{
		cout << msg << endl;
	}
};

class E : public D
{
private:

public:
	E():D("������� ����������� ���������������")
	{
		
	}
};

// ����������� ������ ������ �������� ����� virtual. �������� ����� override. ����������� ���

class Gun
{
public:
	virtual void Shoot()	// Virtual method
	{
		cout << "BANG!" << endl;
	}
};

class SMGun : public Gun
{
public:
	void Shoot() override	// override method
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Rifle : public Gun
{
public:
	void Shoot() override	// override method
	{
		cout << "Head shoot!" << endl;
	}
};

class Player
{
public:
	void Shoot(Gun *gun) 
	{
		gun->Shoot();
	}
};

// ����������� �����. ����� ����������� �������. virtual. override. ����������� ���

class Weapon
{
public:
	virtual void Shoots() = 0; // ����� ����������� ������� / ����� ��� ����������
};


class GunShoot : public Weapon
{
public:
	void Shoots() override	// override method
	{
		cout << "���!" << endl;
	}
};

class AutomaticGun : public GunShoot
{
public:
	void Shoots() override	// override method
	{
		cout << "���! ���! ���!" << endl;
	}
};

class Knife : public Weapon
{
public:
	void Shoots() override	// override method
	{
		cout << "��� � ��!" << endl;
	}
};

class Police
{
public:
	void Shoots(Weapon *gun)
	{
		gun->Shoots();
	}
};

// ����� ����������� ����������

class X
{
public:
	X()
	{

	}
	virtual ~X() = 0;
	

};

X :: ~X() {};

class Y : public X
{
public:
	Y()
	{

	}
	~Y() override
	{

	}
};

// ������������ ������������

class Human
{
public:
	Human(string Name)
	{
		this->Name = Name;
		this->Age = 0;
		this->Weight = 0;
	}
	Human(string Name, int Age):Human(Name)
	{this->Name = Name;
		this->Age = Age;
	}
	Human(string Name, int Age, double Weight):Human(Name, Age)
	{
		this->Weight = Weight;
	}


	string Name;
	int Age;
	double Weight;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");

	// ������� ������ ������������� ��� ������������.
	cout << "������ ����� a " << endl;
	A a;
	cout << "������ ����� b " << endl;
	B b;
	cout << "������ ����� c " << endl;
	C c;

	

	// ����� ������������ �������� ������ �� ������������ ������-����������.
	cout << "����� ������������ �������� ������ �� ������������ ������-����������." << endl;

	D Emsg2("MSG");
	Emsg2.PrintMsg();

	E Emsg3;
	Emsg3.PrintMsg();

	// ����������� ������ ������ �������� ����� virtual. �������� ����� override.
	cout << "����������� ������ ������ �������� ����� virtual. �������� ����� override." << endl;

	Gun TT;
	TT.Shoot();

	SMGun machinegun;
	machinegun.Shoot();

	Gun *weapon_1 = &machinegun;

	weapon_1->Shoot();

	Gun *weapon_2 = &TT;
	weapon_2->Shoot();

	Rifle dragunov;

	Player player_1;
	player_1.Shoot(&TT);
	player_1.Shoot(&dragunov);
	player_1.Shoot(&machinegun);

	// ����������� �����. ����� ����������� �������. virtual. override. ����������� ���
	cout << "����������� �����. ����� ����������� �������. virtual. override. ����������� ���." << endl;
	
	GunShoot pistol;
	Knife knife;
	AutomaticGun ak47;

	Police police_1;
	police_1.Shoots(&pistol);
	police_1.Shoots(&knife);
	police_1.Shoots(&ak47);

	// ����������� ����������
	cout << "����������� ����������. ������ ������� ������ ����� ������" << endl;
	// X x;		// ������ ������� ������ ����� ������"
	X *y_pointer = new Y;

	delete y_pointer;

	// ������������ ������������

	Human man("VDK45");
	Human man_2("GG", 20);
	Human man_3("Put in", 22, 50);

	cout << man.Name << endl;
	cout << man_2.Age << endl;
	cout << man_3.Weight << endl;







	// ������� ������ ����������� ��� ������������.
	cout << endl << "------- ����� ��������� ����� ����������� ---------" << endl;
	return 0;
}