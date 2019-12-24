// task11. Даны два файла произвольного типа.
//С помощью процедуры Rename поменять местами их содержимое.

#include <iostream>
#include <locale.h>
#include <cstdio>
#include <fstream>
#include <ctime>

using namespace std;

void create_files(const char *first_f, const char *second_f) // Создание бинарных файлов
{
	ofstream fout_1(first_f, ios::binary);
	ofstream fout_2(second_f, ios::binary);

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 10;
		fout_1.write((char*)&x, sizeof(x));
	}
	fout_1.close();

	for (int i = 0; i < 10; i++)
	{
		int x = rand() % 10;
		fout_2.write((char*)&x, sizeof(x));
	}
	fout_2.close();
}

void change(const char *first_f, const char *second_f) // замена
{
	const char *data_1 = "data_1.txt";
	const char *data_2 = "data_2.txt";

	rename(first_f, data_1);
	rename(second_f, data_2);

	rename(data_1, second_f);
	rename(data_2, first_f);
}

void show(const char *file_name)
{
	ifstream fin(file_name, ios::binary);
	int x = 0;
	for (int i = 0; i < 10; i++)
	{
		fin.read((char*)&x, sizeof(x));
		cout << x << " ";
	}
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "ru");

	const char *first_f = "FIRST.txt";
	const char *second_f = "SECOND.txt";

	create_files(first_f, second_f);

	cout << "Файлы до обработки:" << endl << endl;
	cout << "First file:" << endl;
	show(first_f);
	cout << "\nSecond file:" << endl;
	show(second_f);
	cout << endl << endl;

	change(first_f, second_f);

	cout << "Файлы после обработки:" << endl << endl;
	cout << "First file:" << endl;
	show(first_f);

	cout << "\nSecond file:" << endl;
	show(second_f);
	cout << endl;

	return 0;
}