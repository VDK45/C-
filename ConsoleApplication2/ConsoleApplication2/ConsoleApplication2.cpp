#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int COLS = 5;		// Global name space

//  Default Parameters
void Def_parameters(int a, int b = 5) 
{
	for (int i = 0; i < a; i++)
	{
		cout << "Parameters a = "<< a << endl;
		for (int j = 0; j < b; j++)
		{
			cout << "Default 5 parameters b = " << b << endl;
		}
	}
}


void foo()
{
	cout << "Func foo called" << endl;
}

void Fake(int a)
{
	++a;
}

int Sum(int a, int b)
{
	int result;
	result = a + b;
	return result;
}


void FillArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}


void PrintArray(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

// 2d array
void Fill_2d_Array(int arr[][COLS], const int rows, const int cols)		// Как передать cols в функцию????????
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print_2d_Array(int arr[][COLS], const int rows, const int cols)		// Как передать cols в функцию????????
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Array_2D[" << i << "][" << j << "] = " << arr[i][j] << endl;
		}
	}
}

// Prototype
void Prototype(int a, int b);

// Перезагрузка

int Sum_p(int a, int b)		// type int 
{
	return a + b;
}

int Sum_p(int a, int b, int c)	// parameters
{
	return a + b + c;
}

double Sum_p(double a, double b)	// type double
{
	return a + b;
}


// Шаблоные функции разные типы
template <typename T, typename T2>
T2 Sum_T(T a, T2 b)
{
	return a + b;
}
// class
template <class T, class T2>
void Cout_Class(T old, T2 str)
{
	cout << str << " " << old << " лет!" << endl;
}


// Recursion
int recursion(int a)
{
	if (a < 1)
		return 0;
	cout << a << endl;
	a--;

	return recursion(a);
}


// Factorial
int Factorial(int N)
{
	if (N == 0)
	{
		return 0;
	}
	if (N == 1)
	{
		return 1;
	}
	return N * Factorial(N - 1);
}

int All_p(int num) 
{
	if (num == 0)
	{
		return 0;
	}
	
	return num + All_p(num - 1);
}

// Передача аргументов в функцию по указателю
void Func_by_pointer(int *pointer_a)
{
	(*pointer_a)++;		/*		Приоритет операции 
							1/ из указателя получить данные 
							2/ данные ++
						*/
}

// Возврат несколько значении функции через указатель
void return_values(int *pointer_num_1, int *pointer_num_2, int *pointer_num_3)
{
	(*pointer_num_1) = 10;
	(*pointer_num_2)++;
	(*pointer_num_3) = (*pointer_num_1) - (*pointer_num_2);
}

void a_b(int *a, int *b)
{
	int temp = (*a);
	(*a) = (*b);
	(*b) = temp;
}

// Передача аргументов в функцию по ссылке

void Func_by_link(int &link)
{
	link += 100;

}

// Возврат несколько значении функции через ссылки
void Func_link_many_parametrs(int &link_1, int &link_2, int &link_3)
{
	link_1 = 10;
	link_2 += 100;
	link_3 -= 50;
}

// Example sample one TYPE
template <typename Type>
void Sample(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b = temp;
}

// Копировать динамический массив

void CopyArray(int* const arr, const int  size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

// Добавить элемент в  динамический массив
void Fill_Array(int* const arr, const int  size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void Show_Array(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void push_back(int *&arr, int &size, const int value)
{
	int *new_array = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = arr[i];
	}

	new_array[size] = value;	// add new value in to last new_array

	size++;

	delete[] arr;				//

	arr = new_array;			// Change pointer
}








//-------------------------------------------------------------
//-------------------------------------------------------------
void main()
{
	setlocale(LC_ALL, "Rus");

	foo();
	int x = 45;
	int y = 5;
	int c;
	c = Sum(x, y);
	cout << x << " + " << y << " = " << c << endl;
	cout << x << " + " << y << " = " << Sum(x, y) << endl;

	// Fake()
	int a = 1;
	Fake(a);
	cout << "Fake(1) = " << a << endl;

	// array in func
	cout << "------ array ------" << endl;
	//const int SIZE = 10;
	const int S = 4;
	int arr[S]{};
	int SIZE;
	SIZE = sizeof(arr) / sizeof(arr[0]);
	cout << "SIDE = " << SIZE << endl;

	FillArray(arr, SIZE);
	PrintArray(arr, SIZE);

	// 2D array
	cout << "------ 2D array ------" << endl;
	const int ROWS = 3;
	//const int COLS = 5;		// Name space global = COLS
	int arr_2D[ROWS][COLS]{};

	Fill_2d_Array(arr_2D, ROWS, COLS);
	Print_2d_Array(arr_2D, ROWS, COLS);

	// prototype
	cout << "------ prototype ------" << endl;
	Prototype(5, 6);

	// Name space 
	cout << "--- Name space ---" << endl;
	{
		cout << "Local ame space" << endl;
	}

	// Defaul parameters
	cout << "------ Parameters b = 3 ------" << endl;
	Def_parameters(2, 3);		
	cout << "------ Defaul parameters = 5 ------" << endl;
	Def_parameters(2);


	// Перезагрузка
	cout << "Перезагрузка типа int = " << Sum_p(5, 6) << endl;
	cout << "Перезагрузка типа double = " << Sum_p(5.5, 6.555555) << endl;
	cout << "Перезагрузка количества параметров = " << Sum_p(5, 6, 7) << endl;

	// Шаблоный функции разные типы
	cout << "------ Шаблоный функции ------" << endl;
	cout << "Шаблоный функции int = " << Sum_T(4, 6) <<endl;
	cout << "Шаблоный функции double = " << Sum_T(4.9, 6.4) << endl;
	cout << "Шаблоный функции different = " << Sum_T(4, 6.4) << endl;
	cout << "--- template <class > ---" << endl;
	Cout_Class(46, "Мне уже ");
	Cout_Class(46, 460.9);		// Concat

	// Recursion
	cout << "------ Рекурсия ------" << endl;
	recursion(8);

	// Factorial
	cout << "------ Факториал ------" << endl;
	const int NUM = 7;
	cout << "Factorial " << NUM << " = " << Factorial(NUM) << endl;
	// --------
	cout << "Сумма всех чисел до " << NUM << " = " << All_p(NUM) << endl;

	// Static & dynamic memory
	cout << "------ Static & dynamic memory ------" << endl;

	// Указатель 
	cout << "------ Указатель ------" << endl;
	int number = 5;				//
	int *p_number = &number;	// Указатель: number
	cout << "Адрес (number) = (" << *p_number <<") в памяти: " << p_number << " в шеснадцатиричном формате" << endl;
	int *p_number2 = &number;
	cout << "Адрес p_number  = " << p_number << endl;
	cout << "Адрес p_number2 = " << p_number2 << endl;
	*p_number2 = 2;
	cout << "p_number  = " << *p_number << endl;
	cout << "------ Арифметика указателей ------" << endl;
	int arr_p[4]{45, 5, 11, 99};
	cout << "arr_p[0] = " << *arr_p << " / pointer = " << arr_p << endl;
	cout << "arr_p[1] = " << *(arr_p + 1) << " / pointer = " << arr_p + 1 << endl;
	cout << "arr_p[2] = " << *(arr_p + 2) << " / pointer = " << arr_p + 2 << endl;
	cout << "arr_p[3] = " << *(arr_p + 3) << " / pointer = " << arr_p + 3 << endl;
	cout << "--- for ----" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "arr_p[" << i << "] = " << *(arr_p + i) << " / pointer = " << arr_p + i << endl;
	}

	// Передача аргументов в функцию по указателю
	cout << "------ Передача аргументов в функцию по указателю ------" << endl;
	int pnt_a = 0;
	cout << "pnt_a = " << pnt_a << endl;
	Func_by_pointer(&pnt_a);
	cout << "pnt_a = " << pnt_a << endl;

	// Возврат несколько значении функции через указатель
	cout << "------ Возврат несколько значении функции через указатель------" << endl;
	int num_1 = 0, num_2 = 0, num_3 = 0;
	cout << "num_1 = " << num_1 << endl;
	cout << "num_2 = " << num_2 << endl;
	cout << "num_3 = " << num_3 << endl;

	cout << "return_values(&num_1, &num_2, &num_3);" << endl;
	return_values(&num_1, &num_2, &num_3);

	cout << "num_1 = " << num_1 << endl;
	cout << "num_2 = " << num_2 << endl;
	cout << "num_3 = " << num_3 << endl;
	
	// Example Pointer
	cout << "____ Example pointer ____" << endl;

	int num_a = 45, num_b = 99;
	cout << "num_a = " << num_a << endl;
	cout << "num_b = " << num_b << endl;
	cout << "____ a_b(&num_a, &num_b); ____" << endl;
	a_b(&num_a, &num_b);
	cout << "num_a = " << num_a << endl;
	cout << "num_b = " << num_b << endl;

	// Передача аргументов в функцию по ссылке
	cout << "____ Передача аргументов в функцию по ссылке ____" << endl;
	int link = 5;
	cout << "link = " << link << endl;
	Func_by_link(link);
	cout << "Func_by_link(link) = " << link << endl;

	// Возврат несколько значении функции через ссылки
	cout << "------ Возврат несколько значении функции через ссылки ------" << endl;
	int link_1 = 1, link_2 = 10, link_3 = 100;
	cout << "link_1 = " << link_1 << endl;
	cout << "link_2 = " << link_2 << endl;
	cout << "link_3 = " << link_3 << endl;

	Func_link_many_parametrs(link_1, link_2, link_3);
	cout << "Func_link_many_parametrs(link_1, link_2, link_3);" << endl;

	cout << "link_1 = " << link_1 << endl;
	cout << "link_2 = " << link_2 << endl;
	cout << "link_3 = " << link_3 << endl;

	// Example link Шаблоная функция 1 тип
	cout << "____ Link Example Шаблоная функция 1 тип ____" << endl;

	float link_a = 45;
	float link_b = 99;
	string link_c = "Hello!";
	string link_d = "Bue!";

	cout << "link_a = " << link_a << " / link_b = " << link_b << endl;
	cout << "link_c = " << link_c << " / link_d = " << link_d << endl;

	cout << "Call Sample " << endl;
	Sample(link_a, link_b);
	Sample(link_c, link_d);

	cout << "link_a = " << link_a << " / link_b = " << link_b << endl;
	cout << "link_c = " << link_c << " / link_d = " << link_d <<  endl;

	// Динамическая память new / delete
	cout << "_________ Динамическая память new / delete ___________ " << endl;

	int *point_new = new int;  // new
	*point_new = 10;
	cout << *point_new << endl;
	cout << "Delete point_new" << endl;

 	delete point_new;				 //  delete
	// point_new = 0;				//  Старая запись
	// point_new = NULL;			//  Старая запись
	point_new = nullptr;			// NULL pointer

	if (point_new != nullptr)
	{
		cout << "point_new != nullptr" << *point_new << endl;
	}
	cout << "point_new = " << point_new << endl;
	
	// Динамический массив
	cout << "_________ Динамический массив ___________ " << endl;

	int len = 10;
	cout << "Enter number: ";
	cin >> len ;
	int *dinamic_array = new int[len];
	for (int i = 0; i < len; i++)
	{
		dinamic_array[i] = rand() % 100;			// random(0, 100)
		cout << i << "/ ";
		cout << "dinamic_array[" << dinamic_array[i] << "]" << "\t";
		cout << " (int = 4 bit) adress element: " << dinamic_array + i << endl;
	}
	// Выход за массив (Error) 
	cout << "Выход за массив (Error)" << endl;
	cout << len << "/ ";
	cout << "dinamic_array[" << dinamic_array[len] << "]" << "\t";
	cout << " (int = 4 bit) adress element: " << dinamic_array + len << endl;

	delete[] dinamic_array;						// Удаление выделеной памяти под массив

	// Двумерный динамический массив
	cout << "______ Двумерный динамический массив ______" << endl;
	/////// Создание ////////
	int rows_a;
	int cols_a;

	cout << "Enter rows:\t";
	cin >> rows_a;
	cout << "Enter colums:\t";
	cin >> cols_a;

	int **array_a = new int* [rows_a];

	for (int i = 0; i < rows_a; i++)
	{
		array_a[i] = new int[cols_a];
	}

	///////////// Вывод ///////////////

	for (int i = 0; i < rows_a; i++)
	{
		for (int j = 0; j < cols_a; j++)
		{
			array_a[i][j] = rand() % 100;
			cout << "array_a[" << i << "][" << j << "] = " << array_a[i][j] << "\t";
		}
		cout << endl;
	}

	///////////// Удаление ////////////////
	for (int i = 0; i < rows_a; i++)
	{
		delete [] array_a[i];	// delete rows_a
	}
	delete [] array_a;			// delete cols_a

	// Копировать динамический массив
	cout << "_______ Копировать динамический массив _______" << endl;
	
	int size_copy = 5;
	int *firstArray = new int[size_copy];
	int *secondArray = new int[size_copy];

	CopyArray(firstArray, size_copy);
	CopyArray(secondArray, size_copy);

	cout << "First array = \t";
	ShowArray(firstArray, size_copy);
	cout << "Second array = \t";
	ShowArray(secondArray, size_copy);

	delete[] firstArray;
	firstArray = new int[size_copy];

	for (int i = 0; i < size_copy; i++)
	{
		firstArray[i] = secondArray[i];
	}

	cout << "_______ firstArray = secondArray; _______" << endl;

	cout << "First array = \t";
	ShowArray(firstArray, size_copy);
	cout << "Second array = \t";
	ShowArray(secondArray, size_copy);

	delete[] firstArray;
	delete[] secondArray;
	
	// Добавить элемент в  динамический массив
	cout << "_______ Добавить элемент в  динамический массив _______" << endl;

	int size_c = 5;
	int *arr_c = new int[size_c];

	Fill_Array(arr_c, size_c);
	Show_Array(arr_c, size_c);
	cout << " Добавить 45 в конце динамического массива" << endl;
	push_back(arr_c, size_c, 45);
	Show_Array(arr_c, size_c);

	delete[] arr_c;







	system("Pause");
}

void Prototype(int a, int b)
{
	cout << "Func Prototype " << endl;
}