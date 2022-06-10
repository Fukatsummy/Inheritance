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
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	/////      Constructor   //////////
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	/////     Methods       /////////
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years.\n";
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS  last_name,  first_name,  age,specialty,  group, year,  rating, attendance
class Student :public Human
{
	std::string specialty;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string get_specialty()const
	{
		return this->specialty;
	}
	const std::string get_group()const
	{
		return this->group;
	}
	unsigned int get_year()const
	{
		return year;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	////    Constructor    /////
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//////    Methods    /////
	void print()const
	{
		Human::print();
		cout << specialty + " " + group << " " << year << " " << rating << " " << attendance << endl;
	}
};

class Teacher :public Human
{
	std::string specialty;
	unsigned int experience;
public:
	const std::string get_specialty()const
	{
		return this->specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	////////    Constructor    /////////
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << specialty << " " << experience << endl;
	}
};

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