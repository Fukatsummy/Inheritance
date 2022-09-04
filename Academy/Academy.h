#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string&first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name,age

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
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(unsigned int age);
	/////      Constructor   //////////
	Human(HUMAN_TAKE_PARAMETERS);
	~Human();

	/////     Methods       /////////
	virtual void print()const;
};

std::ostream& operator<<(std::ostream& os, const Human& obj);

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS  last_name,  first_name,  age,specialty,  group, year,  rating, attendance





