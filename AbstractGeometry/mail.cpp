﻿#pragma warning(disable:4326)//убирает ошибку замены main на void
#define _USE_MATH_DEFINES
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<math.h>
using namespace std;

#define RAND rand()%500
#define COLOR RGB(rand(), rand(), rand())

//#define CIRCLE
// enum (Enumeration - перечисление) -это набор целочисленных констант
//перечисления так же является типом данных
/*namespace Geometry*/
/*{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};

	enum Defaults
	{
		min_start_x = 100,
		max_start_x = 1000,
		min_start_y = 50,
		max_start_y = 800,
		min_line_width = 5,
		max_line_width = 20,
		min_line_length = 10,
		max_line_length = 500
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
			:Shape(start_x, start_y, line_width, color)
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
			:Shape(start_x, start_y, line_width, color)
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
			::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

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


		/*Circle(double radius, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}
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

			::Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);

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
	class Triangle :public Shape
	{
		//double height;
	public:
		virtual double get_height()const = 0;
		Triangle(int start_x, int start_y, unsigned int line_widt, Color color) :Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}

	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)this->side = min_line_length;
			else if (side > Defaults::max_line_length)this->side = Defaults::max_line_length;
			else this->side = side;
		}
		EquilateralTriangle(double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}

		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
		}
		double get_area()const
		{
			return side * get_height() / 2;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			const POINT verticies[] =
			{
				{start_x,start_y + side },
				{start_x + side,start_y + side},
				{start_x + side / 2,start_y + side - get_height()}
			};

			::Polygon(hdc, verticies, sizeof(verticies) / sizeof(verticies[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class IsoscelesTriangle :public Triangle //Равнобедренный треугольник
	{
		double base;
		double side;
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base <= Defaults::min_line_length)base = Defaults::min_line_length;
			else if (base > Defaults::max_line_length)base = Defaults::max_line_length;
			//if (base >= side * 2)base /= 2;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side <= Defaults::min_line_length)side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length)side = Defaults::max_line_length;
			if (side * 2 <= base)side = base;
			this->side = side;
		}
		IsoscelesTriangle& operator()(double base, double side)
		{
			if (base >= side * 2)base = side;
			set_base(base);
			set_side(side);
			return *this;
		}
		IsoscelesTriangle(double base, double side, int start_x, int start_y, unsigned int line_width, Color color)
			: Triangle(start_x, start_y, line_width, color)
		{
			operator()(base, side);
		}
		~IsoscelesTriangle() {}

		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base * get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			const POINT verticies[] =
			{
				{start_x,start_y + side },
				{start_x + base,start_y + side},
				{start_x + base / 2,start_y + side - get_height()}
			};
			
			::Polygon(hdc, verticies, sizeof(verticies) / sizeof(verticies[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Основаие треугольника: " << base << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треугольника: " << get_height() << endl;
			Shape::info();
		}
	};
	class RightTriamgle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= Defaults::min_line_length)side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length)side = Defaults::max_line_length;
			this->side = side;
		}
		RightTriamgle(double side, int start_x, int start_y, unsigned int line_width, Color color) :
			Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~RightTriamgle() {}
		double get_height()const
		{
			return sqrt(side*side - (pow(((sqrt(pow(side, 2) + pow(side, 2))) / 2), 2)));
		}
		double get_area()const
		{
			return (side*side) / 2;
		}
		double get_perimeter()const
		{
			return (sqrt(pow(side, 2) + pow(side, 2))) + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID , line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			const POINT verticies[] =
			{
				{start_x,start_y},
			{start_x,start_y + side},
			{start_x + side, start_y + side}
			};

			::Polygon(hdc, verticies, sizeof(verticies) / sizeof(verticies[0]));
			 
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Сторона треугольника: " << side << endl;
			cout << "Высота треуголька: " << get_height() << endl;
			cout << "Площадь треугольника: " << get_area() << endl;
			cout << "Периметр треугольника: " << get_perimeter() << endl;
			Shape::info();
		}
	};

}


void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue);
	Geometry::Square square(5, 50, 10, 5, Geometry::Color::console_red);
	/*cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадт квадрата:       " << square.get_area() << endl;
	cout << "Периметр кадрата:       " << square.get_perimeter() << endl;
	square.draw();*/
	/*square.info();

	Geometry::Rectangle rect(150, 300, 200, 100, 5, Geometry::Color::blue);
	rect.info();

	/*Geometry::Circle circle(50, Geometry::Color::green);
	circle.info();*/

	/*Geometry::Circle circle(150, 500, 150, 15, Geometry::Color::yellow);
	circle.info();

	Geometry::EquilateralTriangle qtri(200, 200, 200, 5, Geometry::Color::green);
	qtri.info();

	Geometry::IsoscelesTriangle itri1(100, 150, 200, 200, 5, Geometry::Color::blue);
	itri1.info();

	Geometry::IsoscelesTriangle itri2(100, 75, 900, 200, 5, Geometry::Color::blue);
	itri2.info();

	Geometry::RightTriamgle ritri( 250, 700, 200, 5, Geometry::Color::red);
	ritri.info();
}*/
namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000AAFF,
		white = 0x00FFFFFF,
		grey = 0x00AAAAAA,
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
	};
	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 800)start_x = 800;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y > 500)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 30)line_width = 30;
			this->line_width = line_width;
		}
		Shape(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :color(color)
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
			cout << "Периметр фигуры:" << get_perimeter() << endl;
			draw();
		}
	};
	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 5)side = 5;
			if (side > 20)side = 20;
			this->side = side;
		}
		//				Constructors:
		Square(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :
			Shape(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата: " << side << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width < 30)width = 30;
			if (width > 300)width = 300;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 20)length = 20;
			if (length > 200) length = 200;
			this->length = length;
		}
		Rectangle(double width, double length, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}
		double get_area()const override
		{
			return width * length;
		}
		double get_perimeter()const override
		{
			return (width + length) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/
			//1) Получаем окно консоли:
			HWND hwnd = GetConsoleWindow();
			//2) Получаем контекст устройства для окна консоли:
			HDC hdc = GetDC(hwnd);	//это то, на чем мы будем рисовать
			//3) Создаем карандаш - это то, чем мы будем рисорвать (карандаш рисует линии):
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//4) Создаем кисть. Кисть рисует заливку в замкнутой фигуре
			HBRUSH hBrush = CreateSolidBrush(color);
			//5) Выбираем чем, и на чем мы будем рисорвать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//6) Рисуем прямоугольник:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + length);
			//Удаляем карандаш:
			DeleteObject(hPen);
			DeleteObject(hBrush);
			//Освобождаем контекст устройства:
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина: " << width << endl;
			cout << "Длина:  " << length << endl;
			@@ - 312, 11 + 316, 11 @@
				SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vert[] =
				POINT vert[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};
			::Polygon(hdc, vert, 3);

			@@ - 331, 13 + 335, 29 @@ namespace Geometry
				Triangle::info();
		}
	};

	Shape* Factory(int type)
	{
		switch (type)
		{
			//case 1: return new Square(rand(), rand(), rand(), rand(), (Color)rand()); break;
		case 0: return new Circle(RAND, rand() % 500, rand() % 500, RAND, (Color)COLOR);				break;
		case 1: return new Rectangle(RAND, RAND, rand() % 500, rand() % 500, RAND, (Color)COLOR);	break;
		case 2: return new EquilateralTriangle(RAND, rand() % 500, rand() % 500, RAND, (Color)COLOR); break;
		}
	}
}

void main()
{
	setlocale(LC_ALL, "");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	//Shape shape;
	Geometry::Square square(8, 100, 100, 11, Geometry::Color::console_red);
	/*Geometry::Square square(8, 100, 100, 11, Geometry::Color::console_red);
	square.info();
	Geometry::Rectangle rect(150, 70, 300, 100, 11, Geometry::Color::grey);
@@ -347,5 +367,26 @@ void main()
	circle.info();
	Geometry::EquilateralTriangle e_try(170, 350, 200, 8, Geometry::Color::green);
	e_try.info();
	e_try.info();*/

	srand(time(NULL));	//задает начальную точку для генерации случайных чисел.
	//В качестве точки отсчет берется текущее время.

	const int n = 10;
	Geometry::Shape* shape[n];
	for (int i = 0; i < n; i++)
	{
		shape[i] = Geometry::Factory(rand() % 3);
	}

	for (int i = 0; i < n; i++)
	{
		shape[i]->draw();
		Sleep(100);
	}

	for (int i = 0; i < n; i++)
	{
		delete shape[i];
	}
}