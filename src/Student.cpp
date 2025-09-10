#include "Student.h"
#include <sstream>

Student::Student() : id(0), gpa(0.0) {};

Student::Student(int id, std::string name, double gpa, std::string major) : id(id), name(name), gpa(gpa), major(major) {};

int Student::get_id() const {
	return id;
}
std::string Student::get_name() const {
	return name;
}
double Student::get_gpa() const {
	return gpa;
}
std::string Student::get_major() const {
	return major;
}
void Student::set_gpa(double new_gpa) {
	gpa = new_gpa;
}

std::string Student::to_string() const {
	std::ostringstream oss;
	oss << id << "|" << name << "|" << gpa << "|" << major;
	return oss.str();
}