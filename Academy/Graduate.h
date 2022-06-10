#pragma once
#include"Student.h"

class Graduate :public Student
{
	std::string subject;
	std::string diploma;
public:
	const std::string& get_subject()const;
	const std::string& get_diploma()const;
	void set_subject(const std::string& subject);
	void set_diploma(const std::string& diploma);
	/////    Constructor   ////////
	Graduate
	(const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, const std::string& group, unsigned int year,
		double rating, double attendance, const std::string subject, const std::string diploma
	);
	~Graduate();
	void print()const;
};
