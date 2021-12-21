#pragma once
#include <string>
#include "student.h"
class roster
{
public: 
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentDataArray[numStudents];
// constructor is added byt default
public:
	void parse(string row);

	void add(string studentId,
		string fName,
		string lName,
		string emailAdd,
		int age, 
		double day1,
		double day2,
		double day3,
		DegreeType dt);

	void printAll(); /* calls the print method from the student class for each student*/
	void printByDegreeType(DegreeType dt);/*this is where the degree type is added*/
	void printInvalidEmails();/* this function is in roster and checks for invalid emails*/
	void printAverageDays(string studentId);/* this prints the average days in roster.cpp to show each students average day to complete the last 3 courses*/
	void removeStudentbyID(string studentId); /*this is to find the student by supplied ID and remove it*/
	~roster();

};
