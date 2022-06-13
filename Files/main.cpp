#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;



void main()
{
	setlocale(LC_ALL, "");
	std::ofstream fout;   //Создаем поток
	fout.open("File.txt",std::ios_base::app); // Открываем поток
	fout << "Hello World!\n";// Используем поток/Выводим в поток
	fout.close();// Закрываем поток

	system("notepad File.txt");
}