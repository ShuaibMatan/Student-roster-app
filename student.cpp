#include <iostream>
#include "student.h"

//Empty Default Constructor 
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;

	int i = 0;
	while(i < courseAmount)
	{
		this->daysToCompleteCourse[i] = 0;
		i++;
	}
	this->degreeProgram = DegreeProgram::UNDETERMINED;
}

//constructor using all of the input parameters provided in the table 
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	
	int i = 0;
	while (i < courseAmount) 
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
		i++;
	}
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {

}

//Accessors ( getter )
string Student::getStudentID() { 
	return studentID; 
}

string Student::getFirstName() {
	return firstName; 
}

string Student::getLastName() { 
	return lastName; 
}

string Student::getEmailAddress() { 
	return emailAddress;
}

int Student::getAge() { 
	return age; 
}

const int* Student::getDaysToCompleteCourse() { 
	return daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram() { 
	return degreeProgram; 
}


//Mutators ( setters )
void Student::setStudentID(string ID) { 
	this->studentID = ID; 
}

void Student::setFirstName(string firstName) { 
	this->firstName = firstName;
}

void Student::setLastName(string lastName) { 
	this->lastName = lastName; 
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompleteCourse(const int daysToCompleteCourse[])
{
	int i = 0;
	while (i < courseAmount)
	{
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
		i++;
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


/*public void printAll() that prints a complete tab - separated list of student data in the provided format :
A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student. */

void Student::print()
{
	cout << studentID << '\t'
	<< "First Name- " << firstName << '\t'
	<< "Last Name- " << lastName << '\t'
	<< "Email- " << emailAddress << '\t'
	<< "Age- " << age << '\t'
	<< "Days In Courses- " << "{" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1] << ", " << daysToCompleteCourse[2] << "}" << '\t'
	<< "Degree Type- " << degreeProgramStrings[(int)this->degreeProgram];
	cout << "\n";
	
}
