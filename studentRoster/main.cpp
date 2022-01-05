#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	std::cout << "This is a program for storing a student roster." << std::endl;
	std::cout << "This Programming was written using C++" << std::endl;
	std::cout << " It contains information on the students, the degrees they are taking." << std::endl;
	std::cout << "Also email addresses and IDs." << std::endl; 
	cout << endl << endl << endl;



	/*strings that need to be parsed to make students into objects*/

	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,David,Smith,dsmith@wgu.edu,35,1,3,12,COMPSCI"

	};

	const int numStudents = 5;
	roster roster;
	
	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Dispaying all students:" << std::endl;
	roster.printAll();
	cout << std::endl;
	cout << std::endl;

	for (int i = 0; i < 5; i++)

	{
		cout << "Displaying by Degree Type:" << DegreeTypeStrings[i] << std::endl;
		roster.printByDegreeType((DegreeType)i);
	}
	
	cout << "Displaying Students with Invalid Emails:" << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying Average Days for last three courses:" << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		roster.printAverageDays(roster.studentDataArray[i]->getSid());
	}
	cout << "Removing Student by ID A3:" << std::endl;
	roster.removeStudentbyID("A3");
		cout << std::endl;

	cout << "Removing Student by ID A3:" << std::endl;
	roster.removeStudentbyID("A3");
		cout << std::endl;

		system("pause");
		return 0;
}
	
	