#pragma once

#include <vector>
#include <string>

class Course
{
private:
    std::string course_name;
    int course_code;
    int max_enrollment;
    int currently_enrolled;
    std::vector<int> enrolled_ids;
};