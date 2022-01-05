#include "roster.h"
#include <iostream>
#include <string>
/*this parses all the data in the studentData table from main.cpp creating studentData*/
void roster::parse(string studentData)
{
	int rhs = studentData.find(",");
	string SID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string FNE = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string LNE = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string EA = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int AE = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d1 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double d3 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDt = studentData.substr(lhs, rhs - lhs);

	/*this sets the degree type*/
	DegreeType dt = DegreeType::UNDECIDED;
	if (strDt == "SECURITY") {
		dt = DegreeType::SECURITY;
	}
	if (strDt == "NETWORK") {
		dt = DegreeType::NETWORK;
	}
	if (strDt == "SOFTWARE") {
		dt = DegreeType::SOFTWARE;
	}
	if (strDt == "COMPSCI") {
		dt = DegreeType::COMPSCI;
	}

	else DegreeType degreetype = DegreeType::UNDECIDED;

	/*this adds the information parsed*/
	add(SID, FNE, LNE, EA, AE, d1, d2, d3, dt);
	
}

void roster::add(string SID, string FNE, string LNE, string EA, int AE, double day1, double day2, double day3, DegreeType dt)
	{
	/*set the days for duration*/
		double dur[3] = { day1,day2,day3 };

		studentDataArray[++lastIndex] = new Student(SID, FNE, LNE, EA, AE, dur, dt);

	}
/*printing the student data array in proper format*/
	void roster::printAll()
	{
		Student::printHeader();
		for (int i = 0; i <= roster::lastIndex; i++)

		{
			studentDataArray[i]->print();
			//cout << studentDataArray[i]->getSid(); cout << '\t';
			//cout << studentDataArray[i]->getFname(); cout << '\t';
			//cout << studentDataArray[i]->getLname(); cout << '\t';
			//cout << studentDataArray[i]->getEmailAdd(); cout << '\t';
			//cout << studentDataArray[i]->getAge(); cout << '\t';
			//cout << studentDataArray[i]->getDays()[0]; cout << '\t';
			//cout << studentDataArray[i]->getDays()[1]; cout << '\t';
			//cout << studentDataArray[i]->getDays()[2]; cout << '\t';
			//cout << DegreeTypeStrings[studentDataArray[i]->getDegreeType()]<< std::endl;
			
		}
	}
	/*function to print the degrees*/
	void roster::printByDegreeType(DegreeType dt)
	{
		Student::printHeader();
		for (int i = 0; i <= roster::lastIndex; i++) {
			if (roster::studentDataArray[i]->getDegreeType() == dt) studentDataArray[i]->print();
		}
		cout << std::endl;
		}

	/*function for the invalid emails*/
	void roster::printInvalidEmails()
	{
		bool any = true;
		for (int i = 0; i <= roster::lastIndex; i++)
		{
			string EA = (studentDataArray[i]->getEmailAdd());
			if (EA.find(' ') != string::npos||(EA.find('.') == string::npos or EA.find('@') == string::npos))
		
			{
				any = false;
				cout << studentDataArray[i]->getSid() << "  " << "Has an Invalid Emaild address:" << "  " << EA << std::endl;

			}
			if (!any) cout << "NONE" << std::endl;

		
			
		}
	}
	/*average days function logic*/
		void roster::printAverageDays(string studentId)
		{
				for (int i = 0; i <= roster::lastIndex; i++)
				{
					if (studentDataArray[i]->getSid() == studentId)
					{
						cout << studentId << ":";
						cout << studentDataArray[i]->getDays()[0]+
							 studentDataArray[i]->getDays()[1]+
							 studentDataArray[i]->getDays()[2] / 3.0 << std::endl;
					}
			}

			cout << std::endl;
		}
		/*removing student by id logic*/
		void roster::removeStudentbyID(string studentId)

		{
			bool success = false;
			for (int i = 0; i <= roster::lastIndex; i++)
			{
				if (studentDataArray[i]->getSid() == studentId)
				{
					success = true;/*found that ID*/
					if (i < numStudents - 1)
					{
						Student* temp = studentDataArray[i];/* swap it with the last student*/
						studentDataArray[i] = studentDataArray[numStudents - 1];
						studentDataArray[numStudents - 1] = temp;
					}

					roster::lastIndex--;

				}
			}

			if (success) /*found id*/
			{
				cout << studentId << "removed from repository." << std::endl;
				this->printAll();
			}
			else cout << studentId << " " << "not found." << std::endl; /* no id in that number*/

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
