﻿#pragma warning(disable:4326)//убирает ошибку замены main на void
#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include<math.h>
using namespace std;

//#define CIRCLE
// enum (Enumeration - перечисление) -это набор целочисленных констант
//перечисления так же является типом данных
namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow=0x0000FFFF,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};

	enum Defaults
	{
		min_start_x = 10,
		max_start_x = 800,
		min_start_y = 10,
		max_start_y = 500,
		min_line_width = 5,
		max_line_width = 20
	};

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int  start_x)
		{
			if (start_x < Defaults::min_start_x)this->start_x = Defaults::min_start_x;
			else if (start_x > Defaults::max_start_x)this->start_x = Defaults::max_start_x;
			else this->start_x = start_x;
		}
		void set_start_y(int  start_y)
		{
			if (start_y < Defaults::min_start_y)this->start_y = Defaults::min_start_x;
			else if (start_y > Defaults::max_start_y)this->start_y = Defaults::max_start_x;
			else this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > Defaults::min_line_width)this->line_width = Defaults::min_line_width;
			else if (line_width > Defaults::max_line_width)this->line_width = Defaults::max_line_width;
			else this->line_width = line_width;
		}
		

		Shape(int start_x, int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			cout << typeid(*this).name() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side; //длина стороны
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 10;
			this->side = side;
		}
		Square(double side, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x,start_y,line_width,color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//в переменную hConsole сохраняем стандартный вывод текущего окна в консоли
			SetConsoleTextAttribute(hConsole, get_color());//для стандартного вывоа текущего окна задаем цвет текста и фона
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);//в переменную hConsole сохраняем стандартный вывод текущего окна в консоли
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата: " << get_side() << endl;
			Shape::info();
		}
	};

	class Rectangle :public Shape
	{
		double side_a, side_b;
	public:
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		void set_side_a(double a)
		{
			if (a <= 0)a = 20;
			this->side_a = side_a;
		}
		void set_side_b(double b)
		{
			if (b <= 0)b = 20;
			this->side_b = side_b;
		}
		Rectangle(double side_a, double side_b, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x,start_y,line_width,color)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}
		double get_area()const
		{
			return side_a * side_b;
		}
		double get_perimeter()const
		{
			return (side_a + side_b) * 2;
		}
		void draw()const
		{
			//1 Получаем окно консоли
			//HDND обработчик окна консоли
			HWND hwnd = GetConsoleWindow();
			//2 Для того чтобы рисовать. нужно создать контекст устройства
			HDC hdc = GetDC(hwnd);  //HDC(Handler to Device Context) это то на чем мы  будем рисовать
			//3  Слздадим инструменты, которыми мы будем рисоать
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
			//Для того чтобы применить заливку, нужна кисть
			HBRUSH hBrush = CreateSolidBrush(color);

			//4 Создать карандаш НЕ достаточно, его еще нужно выбрать и только тогда
			//мы сможем им рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5 Рисуем прямоугольник
			::Rectangle(hdc, start_x, start_y, start_x+side_a, start_y+side_b);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона А: " << side_a << endl;
			cout << "Сторона В: " << side_b << endl;
			Shape::info();
		}
	};

	class Circle :public Shape
	{
		double radius;
	
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius >= 10 && radius <= 500)this->radius = radius;
			else if (radius < 10)this->radius = 10;
			else this->radius = 500;
		}
#ifdef CIRCLE
		Circle(double radius, Color color) :Shape(color)
		{
			set_radius(radius);
		}
		~Circle() {}

		double get_area()const
		{
			return 3.14*(radius*radius);
		}
		double get_perimeter()const
		{
			return 3.14*(radius) * 2;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow(); //Окно консоли для обращения
			HDC hdc = GetDC(hConsole);   //Создание отдельного компонента(контекста)
			HPEN hPen = CreatePen(PS_SOLID, 10, color); //Создание карандаша v
			HBRUSH hBrush = CreateSolidBrush(color);  //Создание кисти
			SelectObject(hdc, hPen);   //Выбираем созданный карандаш
			SelectObject(hdc, hBrush); //Выбираем созданую кисть
			::Ellipse(hdc, 100, 10, 150, 60);
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hConsole, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус: " << radius << endl;
			Shape::info();
		}
#endif // CIRCL
		
	
		Circle(double radius, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x,start_y,line_width,color)
		{
			set_radius(radius);
		}
		~Circle(){}
		double get_area()const
		{
			return M_PI * radius*radius;
		}
		double get_perimeter()const
		{
			return M_PI * radius * 2;
		}
		void draw()const
		{
			HWND hConsole = GetConsoleWindow();
			HDC hdc = GetDC(hConsole);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x+radius*2, start_y+radius*2);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hConsole, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус: " << radius << endl;
			Shape::info();
		}

	};
	class Poligon
	{

	};

}



void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue);
	Geometry::Square square(5,50,10,5, Geometry::Color::console_red);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадт квадрата:       " << square.get_area() << endl;
	cout << "Периметр кадрата:       " << square.get_perimeter() << endl;
	square.draw();*/
	square.info();

	Geometry::Rectangle rect(150, 200,200,100,5, Geometry::Color::blue);
	rect.info();

	/*Geometry::Circle circle(50, Geometry::Color::green);
	circle.info();*/

	Geometry::Circle circle(150, 500,150,15, Geometry::Color::yellow);
	circle.info();
}