#pragma once
#include <string>
#include "student.h"
class roster
{
private: 
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentDataArray[numStudents];

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

	void printAll();
	void printByDegreeType(DegreeType dt);
	void printInvalidIds();
	void printAverageDays();
	void removeStudentbyID(string studentId);
	~roster();

};
