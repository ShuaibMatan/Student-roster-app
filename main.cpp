// Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will contain the required function calls to achieve the following results:
#include <iostream>
#include "roster.h"

int main()
{

//Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

	cout << "School project" << "\n";
	cout << "In C++" << "\n";
	cout << "Student ID: #12345" << "\n";
	cout << "Shuaib Matan" << "\n";

	// Modify the “studentData Table” to include your personal information as the last item.
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm il.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Shuaib,Matan,smatan@school.edu,22,40,35,90,SOFTWARE"
	};

	cout << "\n";

	// For looping through all the students in the data table
	const int numStudents = 5;

	//Create an instance of the Roster class called classRoster.
	Roster roster;

	// Parsing all the students in the data table
	int i = 0;
	while (i < numStudents) 
	{
		roster.parse(studentData[i]);
		i++;
	}
	
	//Convert the following pseudo code to complete the rest of the  main() function:

	//classRoster.printAll();
	cout << "Showcasing All The Students In The Roster: " << "\n";
	roster.printAll();
	cout << "\n";

	//classRoster.printInvalidEmails();
	cout << "Student With Invalid Emails" << "\n";
	roster.printInvalidEmails();
	cout << "\n";

	//loop through classRosterArrayand for each element:

	//classRoster.printAverageDaysInCourse
	cout << "Average Days Spent In Courses: " << "\n";
	for (int i = 0; i < numStudents; i++)
	{
		roster.printAverageDaysInCourse(roster.getClassRosterArray()[i]->getStudentID());
	}
	cout << "\n";

	//classRoster.printByDegreeProgram(SOFTWARE);
	cout << "Degree Program: SECURITY: " << "\n";
	roster.printByDegreeProgram(DegreeProgram::SECURITY);
	cout << "\n";

	cout << "Degree Program: NETWORK: " << "\n";
	roster.printByDegreeProgram(DegreeProgram::NETWORK);
	cout << "\n";

	cout << "Degree Program: SOFTWARE: " << "\n";
	roster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n";

	//classRoster.remove("A3");
	cout << "Removing Student A3: " << "\n";
	roster.remove("A3");
	cout << "\n";
	
	// classRoster.printAll(); A Second Time
	roster.printAll();
	cout << "\n";

	//classRoster.remove("A3"); A Second Time
	cout << "Removing Student A3: " << "\n";
	roster.remove("A3");
	cout << "\n";

	//expected: the above line should print a message saying such a student with this ID was not found.


	system("pause");
	return 0;

}

