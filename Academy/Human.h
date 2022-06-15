#pragma once
#include<iostream>
using namespace std;

class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	unsigned int get_age()const;
};
void set_last_name(const std::string& last_name);
void set_first_name(const std::string& first_name);
void set_age(unsigned int age);
	/////      Constructor   //////////
Human(HUMAN_TAKE_PARAMETERS);
virtual~Human();

	/////     Methods       /////////
virtual void print()const;
};
std::ostream& operator<<(std::ostream& os, const Human& obj);