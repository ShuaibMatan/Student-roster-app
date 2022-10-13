#include <iostream>
#include <vector>
#include <regex>
#include "roster.h"

using std::vector;
using std::regex;

//Getter for the pointer to the array of objects 
Student** Roster::getClassRosterArray() {
	return Roster::classRosterArray;
}

// Parses the student data table using regular expressions 
void Roster::parse(string row)
{
	regex regex("\\,");
	vector <string> seperate(
		std::sregex_token_iterator(row.begin(), row.end(), regex, -1), std::sregex_token_iterator()
	);

	DegreeProgram degreeProgram = DegreeProgram::UNDETERMINED;
	if (seperate.at(8).back() == 'Y') degreeProgram = DegreeProgram::SECURITY;
	if (seperate.at(8).back() == 'K') degreeProgram = DegreeProgram::NETWORK;
	if (seperate.at(8).back() == 'E') degreeProgram = DegreeProgram::SOFTWARE;
	add(seperate.at(0), seperate.at(1), seperate.at(2), seperate.at(3), stod(seperate.at(4)), stod(seperate.at(5)), stod(seperate.at(6)), stod(seperate.at(7)), degreeProgram);

}

// Adds a new student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
}

// Removes a student from the roster
void Roster::remove(string studentID)
{
	bool idSpotted = false;
	int i = 0;
	while(i < lastIndex)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			idSpotted = true;
			Student* temporary = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temporary;
			
			lastIndex--;
		}
		i++;
	}

	if (idSpotted) {
		cout << "Student ID: " << studentID << "- Removed" << "\n";
		printAll();
	}
	else cout << "Warning: Student with this ID could not be found" << "\n";

}

// Prints all the students in the roster 
void Roster::printAll() {
	int i = 0;
	while (i <= lastIndex) {
		classRosterArray[i]->print();
	i++;
	}
	return;
}

// Prints the average days spents in their courses
void Roster::printAverageDaysInCourse(string studentID)
{
	int i = 0;
	while(i <= lastIndex)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << "Student ID " << classRosterArray[i]->getStudentID();
		const int* daysInCourse = classRosterArray[i]->getDaysToCompleteCourse();
		cout << ": " <<  (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3 << "\n";
		}
		i++;
	}
	return;
}

// Prints invalid emails used in the data table
void Roster::printInvalidEmails()
{
	int i = 0;
	while (i <= lastIndex) 
	{
		string email = getClassRosterArray()[i]->getEmailAddress();
		if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
			cout << email << " is invalid" << "\n";
		i++;
	}
	return;
}

// Displays which program the student is enrolled in 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	int i = 0;
	while (i <= lastIndex) 
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
		classRosterArray[i]->print();
		}
		i++;
	}
	return;
}

//Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster()
{
	int i = 0;
	while(i < numStudents)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
		i++;
	}
	return;
}


