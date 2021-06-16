#pragma once

#include <string>

class Student
{
private:
    std::string first_name;
    std::string last_name;
    int year;
    int student_id;

public:
    Student(std::string fn = "NO FIRST", std::string ln = "NO LAST", int yr = -1, int id = -1);
    std::string GetFName() const;
    std::string GetLName() const;
    int GetYear() const;
    int GetID() const;
};