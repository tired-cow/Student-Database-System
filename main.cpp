#include <iostream>
#include <fstream>
#include <vector>
#include "Student.hpp"

Student CreateStudent();
Student SearchStudent(std::vector<Student>&);
void PrintStudentInfo(Student);

int main()
{
	std::vector<Student> Students;
	int MainMenuInput;

	while(MainMenuInput != 0)
	{
		std::cout << "\n\n\t\tSTUDENT DATABASE SYSTEM"
		<< "\n\n\t(3) Search Student ID"
		<< "\n\t(2) Edit Student"
		<< "\n\t(1) Add Student"
		<< "\n\t(0) Quit"
		<< "\n> ";

		std::cin >> MainMenuInput;

		switch(MainMenuInput)
		{
			case 1:
				Students.push_back(CreateStudent());
				break;
			case 2:
				{
					Student s = SearchStudent(Students);
					if (s.GetID() != -1)
					{
						for (size_t i{0}; i < Students.size(); i++)
						{
							if (Students.at(i).GetID() == s.GetID())
								Students.at(i) = CreateStudent();
						}
					}
				}
				break;
			case 3:
				PrintStudentInfo(SearchStudent(Students));
				break;
			default:
				break;
		};
	};

	return 0;
}

Student CreateStudent()
{
	std::string fn, ln;
	int yr, id;

	std::cout << "\n\n\t\tPlease Enter Student First Name" << "\n> ";
	std::cin >> fn;
	std::cout << "\n\n\t\tPlease Enter Student Last Name" << "\n> ";
	std::cin >> ln;
	std::cout << "\n\n\t\tPlease Enter Student Year" << "\n> ";
	std::cin >> yr;
	std::cout << "\n\n\t\tPlease Enter Student ID" << "\n> ";
	std::cin >> id;

	return Student(fn, ln, yr, id);
}

Student SearchStudent(std::vector<Student> &students)
{
	int SearchStudentID;
	
	std::cout << "\n\n\t\t Please Enter A Student ID to Search" << "\n>";
	std::cin >> SearchStudentID;

	for (Student s : students)
	{
		if (s.GetID() == SearchStudentID)
			return s;
	}

	std::cout << "\n\n\t\t No Student Found!";
	return Student();
}

void PrintStudentInfo(Student student)
{
	std::cout << "\n\n\t\t\t" << student.GetFName() << " " << student.GetLName() 
		<<  std::endl << "\n\t\tYear: " << student.GetYear() << "\n\t\tId: " << student.GetID();
}