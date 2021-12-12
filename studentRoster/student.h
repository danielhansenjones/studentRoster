#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;
/*below a class is created this is used to associate a number of assigned variables to an object in this case the object is a student */
class Student
{
public:
	const static int numDaystoComp = 3;

private:
	int studentId;
	string fName;
	string lName;
	string emailAdd;
	int age;
	int days[numDaystoComp];
	DegreeType degreeType;

public:
	Student(); /*this sets the values to default*/
	Student(string studentId, string fName, string lName, string emailAdd, int age, int days[], DegreeType degreetype); /* this is the constructor it adds the values to the student class variables created above*/ 
	~Student(); /*this is the destructor and it removes values from within the variables*/

/*this set of code is to find the data within the variables ie the getters AKA accessors*/
	int getSid();
	string getFname();
	string getLname();
	string getEmailAdd();
	int getAge();
	int getDays();
	DegreeType getDegreeType();

/*this set of code is to set or change the values ie setters or mutators*/

	void setSid(int ID);
	void setFname(string first);
	void setLname(string last);
	void setEmailAdd(string email);
	void setAge(int ag);
	void setDays(int day);
	DegreeType setDegreeType(DegreeType dt);

	static void printheader(); /*displays a header for the data*/
	
	/* this function prints out this student*/
	void print(); 

};

