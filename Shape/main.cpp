#include<iostream>
using namespace std;

class Shape
{
	int line;


public:
	virtual void move() = 0;
};
class Square :public Shape
{
	double side;
public:
	void move()
	{
		cout << "Квадрат" << endl;
		//....side*4...perimeter
		//cout << "Perimeter" << side * 4 << endl;
	}
	/*void print()const
	{
		int n;
		cout << "Введите длину одной стороны: "; cin >> n;
		cout << "Perimeter =" << n * 4 << endl;
	}*/
};

class Rectangle :public Shape
{
	double width;
	double length;
public:
	void move()
	{
		cout << "Прямоугольник" << endl;
	}
};

class Circle :public Shape
{
	double radius;
public:
	void move()
	{
		cout << "Круг " << endl;
	}
};

class Triangle :public Square
{
	int height;
public:
	void move()
	{
		cout << "Треугольник" << endl;
	}

};

void main()
{
	setlocale(LC_ALL, "");

	/*srand(time(NULL));
	for (int i = 0;; i < n; i++)
	{
		arr[i] = rand() % n;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}*/

	Square Malevich;
	Malevich.move();
	double side = 5;
	cout << "Perimeter " << side * 4 << endl;
	cout << "Area " << side * side << endl;
#define delimiter "\n------------------\n"

	Rectangle Geometry;
	Geometry.move();
	double width = 3;
	double length = 4;
	cout << "Perimeter " << (width + length) * 2 << endl;
	cout << "Area " << width * length << endl;
#define delimiter "\n------------------\n"

	Circle Solar;
	Solar.move();
	double radius = 2.5;
	cout << "Perimeter " << 3.14*(radius) * 2 << endl;
	cout << "Area " << 3.14*(radius*radius) << endl;
#define delimiter "\n------------------\n"

	Triangle Bermudian;
	Bermudian.move();
	double height = 4.2;
	cout << "Perimeter " << side + side + side << endl;
	cout << "Area " << (side*height) / 2 << endl;
}