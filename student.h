#pragma once
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:
	const static int courseAmount = 3;

	//All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
private:
	//Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourse[courseAmount];
	DegreeProgram degreeProgram;


public:
	//constructor using all of the input parameters provided in the table 
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram);
	~Student();

	// Create each of the following functions in the Student class:
	
	//an accessor (i.e., getter) for each instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	const int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();


	// a mutator (i.e., setter) for each instance variable from part D1
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteCourse(const int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	//print() to print specific student data
	void print();


};
