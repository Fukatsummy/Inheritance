#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);
void to_upper(char str[]);
void to_lower(char st[]);

void main()
{
	setlocale(LC_ALL, "");
	//system("chcp 1251");
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку : ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(886);
	//cout << str << endl;
	//cout << sizeof(str) << endl;
	//cout << " : " << StringLength(str) << endl;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == str[i + 1] == 32)
		{
			do {
				str[i] = str[i + 1];
				i++;
			} while (str[i] == 32 && str[i + 1] != 32);
			
		}
		cout << str[i];
	}
}

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i] != 0; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; i < str[i]; i++)
	{
		str[i] >= 'а'&&str[i] <= 'я' ? str[i] -= 32 : str[i];
		str[i] >= 'А'&&str[i] <= 'Я' ? str[i] -= 32:str[i];
	}
}
void to_lower(char str[])
{
	for (int i = 0; i < str[i]; i++)
	{
		str[i] >= 65 && str[i] <= 90 ? str[i] += 32 : str[i];
	}
}