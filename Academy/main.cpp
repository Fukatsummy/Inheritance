#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string&first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name,age



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
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
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
std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	return os << (Human&)obj
		<< " " << obj.get_specialty()
		<< " " << obj.get_group()
		<< " " << obj.get_year()
		<< " " << obj.get_rating()
		<< " " << obj.get_attendance();
}
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
std::ostream& operator<<(std::ostream& os, const Teacher& obj)
{
	return os << (Human&)obj
		<< " " << obj.get_specialty()
		<< " " << obj.get_experience();
}
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
		double rating, double attendance, const std::string subject,const std::string diploma
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
//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK

	Human human("Montana", "Antonio", 25);
	human.print();

	Student pinkman("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 85);
	pinkman.print();

	Teacher man("Ichigo", "Kurosaki", 36, "Professional in his field", 10);
	man.print();

	Graduate dip("Jhon", "Constantin", 25, "Chemistry", "SS_152", 1, 90, 85, "Ecología", "Laboratory work");
	dip.print();
#endif // INHERITANCE_CHECK

	//Generalisation(объеденили  одном месте)
	Human* group[] =
	{
		new Student("Pinkman","Jassie",23,"Chemistry","WW_220",1,80,90),
		new Teacher("White", "Walter",50,"Chemistry",25),
		new Graduate("Schreder","Hank",40,"Criminalistics","WW_220",5,95,80,"How to catch Heisenberg", "Walter White"),
		new Student("Vercetti","Tomas",30,"Theft","Vice",3,90,85),
		new Teacher("Diaz","Ricardo",50,"Weapons distribution",20),
		new Teacher("Einstein","Albert",143,"Astronomy",100)
	};
    cout << "...................................\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		
		//cout << typeid(*group[i]).name() << endl;
		group[i]->print();
		cout << *group[i] << endl;
		if(typeid(*group[i])==typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) << endl;
		if (typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]) << endl;
		cout << "...................................\n";
		
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}
