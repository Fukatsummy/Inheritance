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