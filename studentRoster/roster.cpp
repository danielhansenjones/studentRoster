#include "roster.h"
#include <iostream>
#include <string>

void roster::parse(string studentData)
{
	DegreeType dt = UNDECIDED; 
	if (studentData.at(0) == 'S') dt = SECURITY;
	if (studentData.at(1) == 'N') dt = NETWORK;
	if (studentData.at(2) == 'W') dt = SOFTWARE;
	if (studentData.at(3) == 'C')  dt = COMPSCI;
	if (studentData.at(4) == 'U') dt = UNDECIDED;
	

	int rhs = studentData.find(",");
	string SID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FNE = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1; 
	rhs = studentData.find("," ,lhs);
	string LNE= studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EA = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find("," ,lhs);
	double AE = stod(studentData.substr(lhs, rhs - lhs));

	lhs= rhs + 1;
	rhs = studentData.find("," ,lhs);
	double d1 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d3 = stod(studentData.substr(lhs, rhs - lhs));


	add(SID, FNE, LNE, EA, AE, d1, d2, d3, dt);
	
}

void roster::add(string SID, string FNE, string LNE, string EA, int AE, double day1, double day2, double day3, DegreeType dt)
	{

		double dur[3] = { day1,day2,day3 };

		studentDataArray[++lastIndex] = new Student(studentId, fName, lName, emailAdd, age, dur, dt);

	}

	void roster::printAll()
	{
		Student::printHeader();
		for (int i = 0; i <= roster::lastIndex; i++)

		{
			cout << studentDataArray[i]->getSid(); cout << 't';
			cout << studentDataArray[i]->getFname(); cout << 't';
			cout << studentDataArray[i]->getLname(); cout << 't';
			cout << studentDataArray[i]->getEmailAdd(); cout << 't';
			cout << studentDataArray[i]->getAge(); cout << 't';
			cout << studentDataArray[i]->getDays()[1]; cout << 't';
			cout << studentDataArray[i]->getDays()[2]; cout << 't';
			cout << studentDataArray[i]->getDays()[3]; cout << 't';
			cout << DegreeTypeStrings[studentDataArray[i]->getDegreeType()]<< std::endl;

		}
	}

	void roster::printByDegreeType(DegreeType dt)
	{
		Student::printHeader();
		for (int i = 0; i <= roster::lastIndex; i++) {
			if (roster:: studentDataArray[i]->getDegreeType() == dt) studentDataArray[i]->print();
		}
		cout << std::endl;
		}


	void roster::printInvalidIds()
	{
		bool any = false;
		for (int i = 0; i <= roster::lastIndex; i++)
		{
			string sID = (studentDataArray[i]->getSid());
			if (sID.find('_') == string::npos || (sID.find('X') == string::npos && sID.find('x') == string::npos))
			{
				any = true;
				cout << sID << ":" << studentDataArray[i]->getFname() << std::endl;

			}
				if (!any) cout << "NONE" << std::endl;


			}
		}


		void roster::printAverageDays()
		{
			for (int i = 0; i <= roster::lastIndex; i++) {
				cout << studentDataArray[i]->getSid() << ":";
				cout << studentDataArray[i] ->getDays()[0]
					+ studentDataArray[i]  ->getDays()[1]
					+ studentDataArray[i]  ->getDays()[2] / 3.0 << std::endl;

			}

			cout << std::endl;
		}

		void roster::removeStudentbyID(string studentId)

		{
			bool success = false;
			for (int i = 0; i <= roster::lastIndex; i++)
			{
				if (studentDataArray[i]->getSid() == studentId)
				{
					success = true;
					if (i < numStudents - 1)
					{
						Student* temp = studentDataArray[i];
						studentDataArray[i] = studentDataArray[numStudents - 1];
						studentDataArray[numStudents - 1] = temp;
					}

					roster::lastIndex--;

				}
			}

			if (success)
			{
				cout << studentId << "removed from repository." << std::endl;
				this->printAll();
			}
			else cout << studentId << "not found." << std::endl;

		}
			roster::~roster()
			{
				cout << "DESTRUCTOR CALLED WARNING!!" << std::endl << std::endl;
				for (int i = 0; i < numStudents; i++)

				{
					cout << "Destroying student id#" << i + 1 << std::endl;
					delete studentDataArray[i];
					studentDataArray[i] = nullptr;
				}
			}
