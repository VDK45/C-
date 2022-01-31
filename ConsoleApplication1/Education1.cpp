#include <iostream>
#include <ctime>
using namespace std;

/*
многострочный комментар
\b - delete last symbole
\n - new line
\t - Tab

\\ - show \
\" - show "
\' - show '
*/



void main()
{
	setlocale(LC_ALL, "Rus");	/// Для русских букв /// 
	cout << "Hello world!!" << endl;	/// endl = \n = newline  
	cout << "Привет Мир!! \n";
	cout << "\tПривет\b Мир!! \n";
	// 
	int in_from = -2147483647;	// 4 bit
	int in_to = 2147483647;		// 4 bit
	short sh_from = -32767;		// 2 bit
	short sh_to = 32767;		// 2 bit
	long l_from = -2147483647;	// 4 bit
	long l_to = 2147483647;		// 4 bit
								// 
	float fl = 4.5;				// 4 bit
	double fl_double = 4.5;		// 8 bit
								// 
	char symboles = 'f';		// 1 bit
								//
	bool bool_t = true;			// 1 bit
	bool bool_f = false;		// 1 bit
								// 
	int Age;
	char Name, From;
	const char NEW_LINE = '\n';					// const нельзя менять
	Name = 'VDK';								// K
	Age = 45;									// 45
	From = 'VN';								// N
	cout << Age << endl;
	Age = 50;
	cout << "Вас зовут " << Name << NEW_LINE;
	cout << "Вам " << Age << " лет" << NEW_LINE;
	cout << "Вы из " << From << endl;
	// Ввод данных
	int Var, Var_2;
	cout << "Enter number 1: ";
	cin >> Var;
	cout << "Enter number 2: ";
	cin >> Var_2;
	cout << "You sum = " << Var + Var_2 << NEW_LINE;
	cout << "Enter 2 numbers:";
	cin >> Var >> Var_2;
	cout << "Mul numbers = " << Var * Var_2 << NEW_LINE;
	// Унарные Operations
	cout << "--------------- C++ ---------------" << NEW_LINE;
	int c = 0;
	c = c + 1;
	cout << c << NEW_LINE;
	c += c;
	cout << c << NEW_LINE;
	c++;							// Префиксная
	cout << c << NEW_LINE;
	++c;							// Посфиксная
	cout << c << NEW_LINE;

	/*
	a += x
	a -= x
	a *= x
	a /= x
	*/

	// Бинарные операции
	int a = 5, b = 2, sum;
	sum = a + b;
	cout << "Sum(a + b) = " << sum << NEW_LINE;
	int d = (2 + 2) * 2;
	cout << "(2 + 2) * 2 = " << d << NEW_LINE;
	cout << "------- Math -------" << NEW_LINE;
	int x, y, z;
	cout << "Enter 3 numbers" << NEW_LINE;
	cin >> x >> y >> z;
	cout << "Средниее значение 3х чисел = " << (x + y + z) / 3 << NEW_LINE;
	// 
	cout << "------- Префиксная и Посфиксная -------" << NEW_LINE;

	// Префиксная
	int aa = 1, bb;
	bb = ++aa*aa++;						// 2 * 2 before aa++ = 3
	cout << "aa = " << aa << NEW_LINE;	// 3
	cout << "bb = " << bb << NEW_LINE;	// 4

										/* Посфиксная
										int aa = 1, bb;
										bb = ++aa*++aa;						// 2 * 3
										cout << "aa = " << aa << NEW_LINE;	// 3
										cout << "bb = " << bb << NEW_LINE;	// 6
										*/

	cout << "------- Логические операции -------" << NEW_LINE;
	// <	Меньше
	// >	Больше
	// <=	Меньше или равно
	// >=	Больше или равно

	// ==	Равно
	// !=	Не равно

	// &&	И
	// ||	Или
	// !=	Не

	// 1 - True // 0 - False
	cout << "4 Большее 6: " << (4 > 6) << NEW_LINE;
	cout << "4 меньше или равно 6: " << (4 <= 6) << NEW_LINE;
	cout << "6 равно 6: " << (6 == 6) << NEW_LINE;
	cout << "!(6 == 6): " << !(6 == 6) << NEW_LINE;
	// && - И
	cout << "((6 == 6) И (5 > 4) ) " << ((6 == 6) && (5 > 4)) << NEW_LINE; //	True && True == True
	cout << "((5 == 6) И (5 > 4) ) " << ((5 == 6) && (5 > 4)) << NEW_LINE; //	False && True == False
	cout << "((6 == 6) И (5 > 4) и (4 > 6) ) " << ((6 == 6) && (5 > 4) && (4 > 6)) << NEW_LINE; //	True && True && False == False
																								// || - Или 
	cout << "((6 == 6) Или (5 > 4) или (4 > 6) ) " << ((6 == 6) || (5 > 4) || (4 > 6)) << NEW_LINE; //	True && True && False == True

																									// IF / ELSE
	cout << "--------- IF / ELSE ---------" << NEW_LINE;

	bool is_true = false;

	if (is_true)
	{
		cout << "Это True" << NEW_LINE;
	}
	else
	{
		cout << "Это False" << NEW_LINE;
	}
	//
	int number;
	cout << "Введите число: " << NEW_LINE;
	cin >> number;

	if (number > 5)
	{
		cout << "Вы ввели число больше 5" << NEW_LINE;
	}
	else if (number < 5)
	{
		cout << "Вы ввели число меньше 5" << NEW_LINE;
	}
	else
	{
		cout << "Вы ввели число  5" << NEW_LINE;
	}

	// SWITCH
	cout << "--------- SWITCH ---------" << NEW_LINE;

	int num;
	cout << "////// Enter number: " << NEW_LINE;
	cin >> num;

	switch (num)
	{
	case 1:
		cout << "Вы ввели число 1" << NEW_LINE;
		break;				// Выход из switch

	case 2:
		cout << "Вы ввели 2" << NEW_LINE;
		break;				// Выход из switch

	default:				// Не обязательно
		cout << "Вы ввели число: " << num << NEW_LINE;
		break;				// Выход из switch
	}


	// WHILE
	cout << "--------- WHILE ---------" << NEW_LINE;

	int ok = 0;
	while (ok < 5)
	{
		cout << "OK = " << ok << NEW_LINE;
		ok++;
	}

	// DO WHILE
	cout << "--------- DO WHILE ---------" << NEW_LINE;

	int do_while = 10;

	do                       //  1 раз всегда будет работать
	{
		cout << "Do while = " << do_while << NEW_LINE;
		do_while++;
	} while (do_while < 10);

	// FOR
	cout << "--------- FOR ---------" << NEW_LINE;

	int i = 0;					// i global
	for ( ; i < 5; i++)			// for (int i = 0 ; i < 5; i++) // i local
	{
		cout << "For i = " << i << NEW_LINE;
	}

	// FOR 2
	cout << "-- FOR 2 --" << NEW_LINE;

	for ( int j = 20; i < 10 && j > 15; j -= 5)		// i global , j local
	{
		i++;
		cout << "For i = " << i << NEW_LINE;
		cout << "For j = " << j << NEW_LINE;
		i++;
	}

	// BREACK
	cout << "--------- BREACK FOR ---------" << NEW_LINE;

	cout << "Start for: " << NEW_LINE;
	for (int i = 0; true; i++)			// true = infinity
	{
		cout << "For i = " << i << NEW_LINE;
		if (i > 5)
		{
			break;
		}
	}
	cout << "Stop for" << NEW_LINE;


	cout << "--- BREACK WHILE ----" << NEW_LINE;
	cout << "Start while: " << NEW_LINE;
	int j = 0;
	while (true)
	{
		cout << "For j = " << j << NEW_LINE;
		j++;
		if (j > 5)
		{
			break;
		}
	}

	cout << "Stop while" << NEW_LINE;

	// Continue
	cout << "--------- CONTINUE ---------" << NEW_LINE;

	for (int i = 0; i < 10; i++)			 // i local
	{
		if (i == 5)
		{
			cout << "Pass " << i << NEW_LINE;		// Пропускать 
			continue;
		}
		cout << "For i = " << i << NEW_LINE;
	}

	// GOTO not recomendation
	cout << "--------- goto link: ---------" << NEW_LINE;

	cout << "1" << NEW_LINE;
	goto link;
	cout << "2" << NEW_LINE;
	link:
	cout << "3" << NEW_LINE;
	goto link_2;
	cout << "4" << NEW_LINE;
	cout << "5" << NEW_LINE;
	link_2:
	cout << "6" << NEW_LINE;

	// ARRAY
	cout << "--------- ARRAY: ---------" << NEW_LINE;

	const int LEN = 5;
	int mass[LEN]{45, 55, 66, 77, 3};

	for (int i = 0; i < LEN; i++)
	{
		cout << i << " Element: " << mass[i] << endl;
	}

	cout << "---- array ----" << NEW_LINE;

	const int LEN_ARR = 8;
	int arr[LEN_ARR];

	for (int i = 0; i < LEN_ARR; i++)
	{
		arr[i] = i * 100;
	}

	for (int i = 0; i < LEN_ARR; i++)
	{
		cout << i << " = " << arr[i] << NEW_LINE;
	}


	// SIZEOF
	cout << "--------- SIZEOF: ---------" << NEW_LINE;

	int size;

	cout << "size = " << sizeof(size) << " bites" << endl;

	cout << "----- SIZEOF: -----" << NEW_LINE;

	int arr_2[]{5, 10, 15, 20, 25};

	int sz_arr = sizeof(arr_2);
	int sz_int = sizeof(int);

	cout << sz_arr / sz_int << endl;

	cout << "--- SIZEOF: ---" << NEW_LINE;		// = 5

	int arr_3[]{ 5, 10, 15, 20, 25 };

	for (int i = 0; i < (sizeof(arr_3) / sizeof(arr_3[0])); i++)		// Not independen from array type (int, double, float)
	{
		cout << "arr_3[" << i << "] = " << arr_3[i] << endl;
	}

	// RAND INT
	cout << "--------- RAND int: ---------" << NEW_LINE;

	int t = time(NULL);			// random time
	srand(t);		// dot for rand()

	int arr_4[5]{};

	for (int i = 0; i < (sizeof(arr_4) / sizeof(arr_4[0])); i++)

	{
		arr_4[i] = rand() % 10 + 5;			// rand() % 10 + 5 = from 5 to 15
		cout << "arr_4[" << i << "] = " << arr_4[i] << endl;
	}

	// 2D ARRAY
	cout << "--------- 2D ARRAY: ---------" << NEW_LINE;

	const int ROW = 2;
	const int COL = 5;

	int arr_2d[ROW][COL]{};		// {} Инициализация с нольями

	/* array_2d[][3]			// [] Можно не указывать строки [ROW]
	{ 
		{1,2,3,4}, 
		{5,6,7,8} 
	};							//  Инициализация ручная
	*/

	for (int i = 0; i < ROW; i++)
	{
		
		for (int j = 0; j < COL; j++)
		{
			arr_2d[i][j] = rand() % 100;
			//arr_2d[i][j] = i + j;
			cout << "arr_2d[" << i << "][" << j << "] = " << arr_2d[i][j] << endl;
		}
	}

	system("pause");
}

