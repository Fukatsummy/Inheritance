#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//system("chcp 1251");
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << " : ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(886);
	cout << str << endl;
	//cout << sizeof(str) << endl;
	cout << " : " << StringLength(str) << endl;
}

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i] != 0; i++);
	return i;
}