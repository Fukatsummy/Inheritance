#include"Student.h"

class Graduate :public Student
{
	std::string subject;
	std::string diploma;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	const std::string& get_diploma()const
	{
		return diploma;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_diploma(const std::string& diploma)
	{
		this->diploma = diploma;
	}
	/////    Constructor   ////////
	Graduate
	(const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, const std::string& group, unsigned int year,
		double rating, double attendance, const std::string subject, const std::string diploma
	) :Student(last_name, first_name, age, specialty, group, year, rating, attendance)
	{
		set_subject(subject);
		set_diploma(diploma);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << diploma << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const Graduate& obj)
{
	return os << (Student&)obj << " " << obj.get_diploma() << " " << obj.get_subject();
}