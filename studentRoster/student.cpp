#include "student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	this->studentId = "";
	this->fName = "";
	this->lName = "";
	this->emailAdd = "";
	this->age = 0;
	for (int i = 0; i < numDaystoComp; i++) this->days[i] = 0;
	this->degreeType = DegreeType::UNDECIDED;

}

Student::Student(string studentId1, string fName, string lName, string emailAdd, int age, double days[], DegreeType degreeType)
{
	this->studentId = studentId1;
	this->fName = fName;
	this->lName = lName;
	this->emailAdd = emailAdd; 
	this->age = age;
	for (int i = 0; i < numDaystoComp; i++) this->days[i] = days[i];
	this->degreeType = degreeType;

}

Student::~Student() {}

string Student::getSid() { return this->studentId; }
string Student::getFname() { return this->fName; }
string Student::getLname() { return this->lName; }
string Student::getEmailAdd() { return this->emailAdd; }
int Student::getAge() { return this->age; }
double* Student::getDays() { return this->days; }
DegreeType Student::getDegreeType() {return this->degreeType; }

void Student::setSid(string ID) { this->studentId = ID; }
void Student::setFname(string first) { this->fName = first; }
void Student::setLname(string last) { this->lName = last; }
void Student::setEmailAdd(string email) { this->emailAdd = email; }
void Student::setAge(int ag) { this->age = ag; }
void Student::setDays(double days[])

{
	for (int i = 0; i < numDaystoComp; i++) this->days[i] = days[i];
}
void Student::setDegreeType(DegreeType dt) { this->degreeType = dt; }


void Student::printHeader()
{
	cout << "Output format:" << std:: endl;
	cout << "SID | First Name | Last Name | Email Address | Age | Days to finish 3 courses | Degree Program"; 
	cout << std::endl;
	cout << std::endl;
}

void Student::print()
{
	cout << this->getSid() << '\t';
	cout << this->getFname() << '\t';
	cout << this->getLname() << '\t';
	cout << this->getEmailAdd() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << DegreeTypeStrings[this->getDegreeType()] << '\n';
}