#pragma once
#include"Teaher.h"

class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string get_specialty()const;
	const std::string get_group()const;
	unsigned int get_year()const;
	double get_rating()const;
	double get_attendance()const;
	void set_specialty(const std::string& specialty);
	void set_group(const std::string& group);
	void set_year(unsigned int year);
	void set_rating(double rating);
	void set_attendance(double attendance);
	////    Constructor    /////
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS);
	~Student();
	//////    Methods    /////
	void print()const;
};
