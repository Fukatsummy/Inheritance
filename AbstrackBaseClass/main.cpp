#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;//����������� �����
};
class GroundVehicle :public Vehicle
{

};
class Car :public GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� 4 ������(��� �������)" << endl;
	}
	//���������� �����
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "�������� ���� �� 2 ������� " << endl;
	}
};
class AirVehicle:public Vehicle
{
	int Height;
public:
	virtual void take_off() = 0;
};
class Helicopter : public AirVehicle
{
public:
	void move()
	{
		cout << "�������� ����� �� �����" << endl;
	}
	void take_off()
	{
		cout << "������������ ����" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;  �� �������� ������� ��������� ������������ ������
	//GroundVehicle gv;
	Car bmw;
	Bike hd;
	bmw.move();
	hd.move();

	Helicopter apache;
	apache.take_off();
	apache.move();
}