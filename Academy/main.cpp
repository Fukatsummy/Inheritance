#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	/////     Methods       /////////
	virtual std::ostream& print(std::ostream& os /*= std::cout*/)const
	{
		return os << last_name << " " << first_name << " " << age << " years.\n";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(20);
		ofs << std::left;
		ofs << last_name + " " + first_name;
		ofs.width(4);
		ofs << std::right;
		ofs << age;
		return ofs;
	}
	virtual std::istream& scan(std::istream& ifs)
	{
		std::string buffer;
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}
std::istream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

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
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << specialty + " " + group << " " << year << " " << rating << " " << attendance << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs)<<" ";
		ofs.width(20);
		ofs << std::left;
		ofs << specialty;
		ofs.width(8);
		ofs << group << " " << year;
		ofs.width(8);
		ofs << std::right;
		ofs << std::setprecision(2) << std::fixed;
		ofs<< " " << rating << " " << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		ifs >> specialty;
		ifs >> group;
		ifs >> year;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
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
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << specialty << " " << experience << endl;
	}
	std::ofstream& print(std::ofstream& ofs) const
	{
		Human::print(ofs) << " ";
		ofs.width(25);
		ofs << std::left;
		ofs << specialty << " ";
		ofs.width(4);
		ofs << std::right;
		ofs<< experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		//ifs >> specialty;
		const int n = 25;
		char specialty[n] = {};
		ifs.read(specialty, n);
		for (int i = n - 1; specialty[i] == ' '; i--)specialty[i] = 0;
		set_specialty(specialty);
		ifs >> experience;
		return ifs;
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
	std::ostream& print(std::ostream& os)const
	{
		//Student::print(os);
		return Student::print(os) << subject << diploma << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs);
		ofs.width(25);
		ofs << std::right;
		ofs << subject;
		ofs.width(5);
		ofs<< " " << diploma;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, this->diploma);
		return ifs;
	}
};
Human* HumanFactory(const std::string& type)
{
	if (type.find("class Student")!=std::string::npos)return new Student("","",0, "","",0,0, 0);
	if (type.find("class Graduate")!=std::string::npos)return new Graduate("", "",0,"","",0,0,0,"","");
	if (type.find("class Teacher")!=std::string::npos)return new Teacher("", "", 0, "", 0);
}
Human** load(const std::string& filename,int& n)
{
	Human** group;  //массив
	//int n = 0;  //размер массиа
	std::ifstream fin(filename);

	if (fin.is_open())
	{
		std::string buffer;
		//Определяем размер массива
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			n++;
		}
		n--;
		//Выделяем память для участнико группы(создаем массив)
		group = new Human*[n] {};
		//Возвращаемся в начало файла
		fin.clear();
		fin.seekg(0);
		
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
		return nullptr;
	}
	fin.close();
	return group;
}

//#define INHERITANCE_CHECK
//#define WRITE_TO_FILE


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

#ifdef WRITE_TO_FILE
	//Generalisation(объеденили  одном месте)
	Human* group[] =
	{
		new Student("Pinkman","Jassie",23,"Chemistry","WW_220",1,91.2,90),
		new Teacher("White", "Walter",50,"Chemistry",25),
		new Graduate("Schreder","Hank",40,"Criminalistics","WW_220",5,82.7,80,"How to catch Heisenberg", "Walter White"),
		new Student("Vercetti","Tomas",30,"Theft","Vice",3,90,85),
		new Teacher("Diaz","Ricardo",50,"Weapons distribution",20),
		new Teacher("Einstein","Albert",143,"Astronomy",100)
	};
	std::ofstream fout("Academy.txt");
	cout << "...................................\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		cout << typeid(*group[i]).name() << endl;
		
		//group[i]->print();
		cout << *group[i] << endl;
		cout << "...................................\n";
         cout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	system("start notepad Academy.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // !WRITE_TO_FILE

	int n = 0;
	Human** group = load("Academy.txt",n);

	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}

	delete[]group;

}
