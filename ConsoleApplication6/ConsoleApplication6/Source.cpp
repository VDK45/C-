#include <iostream>
#include <string>

using namespace std;

// Порядок вызова конструкторов при наследовании.
class A
{
public:
	A()
	{
		cout << "Вызвался конструктор А " << endl;
	}

	virtual ~A()	// виртуальный деструктор
	{
		cout << "Вызвался ДЕСТРУКТОР А " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "Вызвался конструктор B " << endl;
	}

	~B() override		// виртуальный деструктор
	{
		cout << "Вызвался ДЕСТРУКТОР В " << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "Вызвался конструктор C " << endl;
	}

	~C()
	{
		cout << "Вызвался ДЕСТРУКТОР С " << endl;
	}
};

// Вызов конструктора базового класса из конструктора класса-наследника.

class D
{
private:
	string msg;
	
public:
	D() // Конструктор поумолчанию
	{
		msg = "Вызвался конструктор D Поумолчанию";
	}
	D(string msg) // Конструктор допольнительный
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
	E():D("Вызвать конструктор допольнительный")
	{
		
	}
};

// Виртуальные методы класса Ключевое слово virtual. Ключевое слово override. Полиморфизм ООП

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

// Абстрактный класс. Чисто виртуальная функция. virtual. override. Полиморфизм ООП

class Weapon
{
public:
	virtual void Shoots() = 0; // Чисто виртуальная функция / метод нет реализации
};


class GunShoot : public Weapon
{
public:
	void Shoots() override	// override method
	{
		cout << "Бах!" << endl;
	}
};

class AutomaticGun : public GunShoot
{
public:
	void Shoots() override	// override method
	{
		cout << "Бах! Бах! Бах!" << endl;
	}
};

class Knife : public Weapon
{
public:
	void Shoots() override	// override method
	{
		cout << "Хыч и всё!" << endl;
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

// Чисто Виртуальный деструктор

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

// Делегирующие конструкторы

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

	// Порядок вызова конструкторов при наследовании.
	cout << "Создан объек a " << endl;
	A a;
	cout << "Создан объек b " << endl;
	B b;
	cout << "Создан объек c " << endl;
	C c;

	

	// Вызов конструктора базового класса из конструктора класса-наследника.
	cout << "Вызов конструктора базового класса из конструктора класса-наследника." << endl;

	D Emsg2("MSG");
	Emsg2.PrintMsg();

	E Emsg3;
	Emsg3.PrintMsg();

	// Виртуальные методы класса Ключевое слово virtual. Ключевое слово override.
	cout << "Виртуальные методы класса Ключевое слово virtual. Ключевое слово override." << endl;

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

	// Абстрактный класс. Чисто виртуальная функция. virtual. override. Полиморфизм ООП
	cout << "Абстрактный класс. Чисто виртуальная функция. virtual. override. Полиморфизм ООП." << endl;
	
	GunShoot pistol;
	Knife knife;
	AutomaticGun ak47;

	Police police_1;
	police_1.Shoots(&pistol);
	police_1.Shoots(&knife);
	police_1.Shoots(&ak47);

	// Виртуальный деструктор
	cout << "Виртуальный деструктор. Нельзя создать объект этого класса" << endl;
	// X x;		// Нельзя создать объект этого класса"
	X *y_pointer = new Y;

	delete y_pointer;

	// Делегирующие конструкторы

	Human man("VDK45");
	Human man_2("GG", 20);
	Human man_3("Put in", 22, 50);

	cout << man.Name << endl;
	cout << man_2.Age << endl;
	cout << man_3.Weight << endl;







	// Порядок вызова Деструкторы при наследовании.
	cout << endl << "------- Конец программы вызов Деструкторы ---------" << endl;
	return 0;
}