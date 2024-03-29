﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	const int SIZE = 256;
	char sz_filename[SIZE] = {};
	cout << "Введите имя файла: ";
	cin.getline(sz_filename, SIZE);
	//strcmp- String compare(сравнение строк)
	//int strcmp(char* str1,char* str2)
	//Если функция вернула 0бзначит строки идентичны,
	//значение отличное от нуля - строки разные
	if (strcmp(sz_filename + strlen(sz_filename) - 4, ".txt"))
		//strlen(str) возвращает размер строки в символах
		strcat(sz_filename, ".txt");
	std::ofstream fout;   //Создаем поток
	fout.open(sz_filename, std::ios_base::app); // Открываем поток
	char sz_contents[SIZE] = {};
	cout << "Введите содержимое файла: ";
	cin.getline(sz_contents, SIZE);
	//fout << "Hello World!\n";// Используем поток/Выводим в поток
	fout << sz_contents;
	fout.close();// Закрываем поток
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	//Функция strcat(char* str1, char* str2) выполняет конкатенация(слияние) строк
	//к содержимому первой строки добавляется содержимое второй строки
	system(sz_command);
#endif // WRITE_TO_FILE

	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		// to read file
		const int n = 256;
		char buffer[n] = {};
		while (!fin.eof()) //eof - end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	system("notepad File.txt");
	
}