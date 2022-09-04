#include"Academy.h"
#include"Student.h"
#include"Teaher.h"
#include"Graduate.h"


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
	/*for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}*/
}
