#pragma once
#include "Student.h"
#include <vector>
#include <string>

void load_students(std::vector<Student>& students, const std::string& filename);

void save_students(const std::vector<Student>& students, const std::string& filename);