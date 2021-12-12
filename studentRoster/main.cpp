#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	std::cout << "Scripting and Programming Applications C867" << std::endl;
	std::cout << "This Programming was written using C++" << std::endl;
	std::cout << " Written By Daniel Hansen-Jones" << std::endl;
	std::cout << " Student ID# 004636371" << std::endl; 
	cout << endl << endl << endl;
}


int main()
{
	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Daniel, Hansen-Jones,dhan134@wgu.edu,35, 1,3,12,COMPSCI"

	
	};

	const int numStudents = 5;
	roster roster;
	
	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Dispaying all students:" << std::endl;
	roster.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)

	{
		cout << "Displaying by Degree Type:" << DegreeTypeStrings[i] << std::endl;
		roster.printByDegreeType((DegreeType)i);
	}
	
	cout << "Displaying Students with Invalid IDs:" << std::endl;
	roster.printInvalidIds();
	cout << std::endl;

	cout << "Displaying Average Days for last three courses:" << std::endl;
	roster.printAverageDays();

	cout << "Removing Student by ID N_W1:" << std::endl;
	roster.removeStudentbyID("N_W1");
		cout << std::endl;

	cout << "Removing Student by ID N_W1:" << std::endl;
	roster.removeStudentbyID("N_W1");
		cout << std::endl;

		system("pause");
		return 0;
}
	
	