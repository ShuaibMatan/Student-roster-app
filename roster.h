#pragma once
#include "student.h"
#include "string.h"

class Roster
{
public:
	// Parse each set of data identified in the “studentData Table.”
	void parse(string row);
	//Add each student object to classRosterArray.
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void printAll(); // prints all the students in the roster
	void remove(string studentID); //Removes a student from the roster
	void printAverageDaysInCourse(string studentID); // Prints the average days spents in their courses
	void printInvalidEmails(); // Prints invalid emails used in the data table
	void printByDegreeProgram(DegreeProgram dp); // Displays which program the student is enrolled in 
	
	~Roster(); //Destructor to release the memory that was allocated dynamically in Roster


public:
	
	//Create a student object for each student in the data table and populate classRosterArray.

	int lastIndex = -1; // No students added to the roster yet
	const static int numStudents = 5; // Constant array that loops through all the students in the data table
	Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
	Student** getClassRosterArray(); // Getter for the pointer to the array of objects 


};