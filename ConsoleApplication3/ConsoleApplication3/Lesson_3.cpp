#include <iostream>
#include <string>
#define PI 3.14
#define print cout <<
#define tab << "\t" <<
#define ok << endl
#define FUNC(x,y) ((x)*(y))
#define DEBUG			// #define DEBUG	


using namespace std;

// ��������� �� ������� � �������� ���������
string GetDataFromBD()
{
	return "Data from BD";
}

string GetDataFromServer()
{
	return "Data from Web Server";
}

void ShowInfo(string (*foo)())		// ��������� �� ������� � �������� ���������
{
	cout << foo() << endl;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	/* ������
	��������� ������ */
	char hi[] = {'H', 'i', '!', '\0'};
	char hello[] = "Hello world!";
	cout << hello << " = " << strlen(hello) << endl;
	cout << hi << " = " << strlen(hi) << endl;

	// �������������� �����
	cout << "____________ �������������� ����� _____________" << endl;
	double a = 4.9;
	cout << "4.5 => " << (char)a << endl;	// ����� ��������������
	int b = 5.045;
	cout << b << endl;						// ������� ��������������

	// ������� ascii
	cout << "____________ ������� ascii _____________" << endl;
	cout << "������ (char) = " << sizeof(char) << " bit" << endl;
	//for (int i = 0; i <= 255; i++)
	//{
	//	cout << "ASCII code = " << i << "\t" << (char)i << endl;
	//}
	// �� 127 = ��������� ������� ����� // setlocale(LC_ALL, "Rus");

	// ��������� ���������� ������ � �������.
	cout << "____________ ��������� ���������� ������ � ������� _____________" << endl;

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

	// ������������ �����
	cout << "--------- ������������ ����� ---------" << endl;
	cout << "----- str_a + str_b -----" << endl;

	char str_a[255] = "Hello";		// 255 - ���������  �����
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

	// ��������� �� ������� � �������� ���������
	cout << "--------- ��������� �� ������� � �������� ��������� ---------" << endl;
	
	ShowInfo(GetDataFromBD);
	ShowInfo(GetDataFromServer);

	// ������������ - ��������� #define (import module)
	cout << "--------- ������������ - ��������� #define ---------" << endl;

	print "Hello"  tab "world" ok;

	// M����� ������� #define FUNC(x,y) ((x)*(y))
	cout << "--------- ������ ������� ---------" << endl;

	print FUNC(5, 6) ok;

	// �������� ����������. #ifdef #else #endif #if #elif #endif #ifndef 
	cout << "--------- �������� ����������.  ---------" << endl;

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

	// �������� ��������� ��������
	cout << "--------- �������� ��������� ��������  ---------" << endl;

		
		for (size_t i = 0; i < 4; i++)
		{
			int num;
			print "Enter number: " ok;
				cin >> num;
				(num < 0) ? print "Number < zero" ok : (num > 0) ? print "Number > zero" ok : print "Number = 0" ok; // ��������� ��������
		}
		
		












}