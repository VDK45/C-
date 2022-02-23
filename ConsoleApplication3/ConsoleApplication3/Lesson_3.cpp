#include <iostream>
#include <string>
#define PI 3.14
#define print cout <<
#define tab << "\t" <<
#define ok << endl
#define FUNC(x,y) ((x)*(y))
#define DEBUG			// #define DEBUG	


using namespace std;

// Указатель на функцию в качестве параметра
string GetDataFromBD()
{
	return "Data from BD";
}

string GetDataFromServer()
{
	return "Data from Web Server";
}

void ShowInfo(string (*foo)())		// Указатель на функцию в качестве параметра
{
	cout << foo() << endl;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	/* Строки
	Строковый массив */
	char hi[] = {'H', 'i', '!', '\0'};
	char hello[] = "Hello world!";
	cout << hello << " = " << strlen(hello) << endl;
	cout << hi << " = " << strlen(hi) << endl;

	// Преобразование типов
	cout << "____________ Преобразование типов _____________" << endl;
	double a = 4.9;
	cout << "4.5 => " << (char)a << endl;	// Явное преобразование
	int b = 5.045;
	cout << b << endl;						// Неявное преобразование

	// Таблица ascii
	cout << "____________ Таблица ascii _____________" << endl;
	cout << "Размер (char) = " << sizeof(char) << " bit" << endl;
	//for (int i = 0; i <= 255; i++)
	//{
	//	cout << "ASCII code = " << i << "\t" << (char)i << endl;
	//}
	// До 127 = англиские символы после // setlocale(LC_ALL, "Rus");

	// Указатели символьные строки и функции.
	cout << "____________ Указатели символьные строки и функции _____________" << endl;

	char string_1[] = "Hello";	// array char

	char *str = "Hello";		// pointer char

	cout << str << endl;		// 

	cout << "-------------------" << endl;
	char *str_arr[] = {"Hello", "world", "Test"};

	for (int i = 0; i < 3; i++)
	{
		cout << str_arr[i] << endl;
	}

	cout << "--------- len(str) ---------- \n---- while ----" << endl;

	char *str_1 = "Hello world";

	int counter = 0;
	while (str_1[counter] != '\0')
	{
		counter++;
	}
	cout << "Len (str_1) = " << counter << endl << "--- for --- \n";

	int i = 0;
	for ( i = 0; str_1[i] != '\0';)
	{
		i++;
	}
	cout << "Len (str_1) = " << i << endl;

	// Конкатенация строк
	cout << "--------- Конкатенация строк ---------" << endl;
	cout << "----- str_a + str_b -----" << endl;

	char str_a[255] = "Hello";		// 255 - Требуется  место
	char str_b[255] = "_world";

	cout << str_a << endl;

	strcat(str_a, str_b);

	cout << str_a << endl;

	cout << "----- concat -----" << endl;

	char concat[255]{};
	char str_c[255] = "Hello";		
	char str_d[255] = "_world";

	strcat(concat, str_c);
	strcat(concat, str_d);

	cout << concat << endl;

	cout << "----- string -----" << endl;

	string str_e = "Hello";
	string str_f = "world";
	string str_j = "!!!";
	string result;

	result = str_e + " " + str_f + str_j + " CONCAT";

	cout << result << endl;

	// Указатель на функцию в качестве параметра
	cout << "--------- Указатель на функцию в качестве параметра ---------" << endl;
	
	ShowInfo(GetDataFromBD);
	ShowInfo(GetDataFromServer);

	// Препроцессор - Директива #define (import module)
	cout << "--------- Препроцессор - Директива #define ---------" << endl;

	print "Hello"  tab "world" ok;

	// Mакрос функция #define FUNC(x,y) ((x)*(y))
	cout << "--------- макрос функция ---------" << endl;

	print FUNC(5, 6) ok;

	// Условная компиляция. #ifdef #else #endif #if #elif #endif #ifndef 
	cout << "--------- Условная компиляция.  ---------" << endl;

#ifdef DEBUG
	print "Begin for" ok;
#endif	

		for (int i = 0; i < 5; i++)
		{
			print "i = " << i ok;
		}

#ifdef DEBUG
		print "End for" ok;
#else 
		print "// DEBUG = 0" ok;
#endif	

	// Условный тернарный оператор
	cout << "--------- Условный тернарный оператор  ---------" << endl;

		
		for (size_t i = 0; i < 4; i++)
		{
			int num;
			print "Enter number: " ok;
				cin >> num;
				(num < 0) ? print "Number < zero" ok : (num > 0) ? print "Number > zero" ok : print "Number = 0" ok; // Тернарная операция
		}
		
		












}