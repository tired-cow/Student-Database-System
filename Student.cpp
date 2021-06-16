#include "Student.hpp"

Student::Student(std::string fn, std::string ln, int yr, int id)
  : first_name{fn}, last_name{ln}, year{yr}, student_id{id}
{

}

std::string Student::GetFName() const
{
	return first_name;
}

std::string Student::GetLName() const
{
	return last_name;
}

int Student::GetYear() const
{
	return year;
}

int Student::GetID() const
{
	return student_id;
}