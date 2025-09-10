#pragma once
#include <string>

class Student {
	int id;
	std::string name;
	double gpa;
	std::string major;

public:
	// Constructors
	Student();
	Student(int id, std::string name, double gpa, std::string major);

	// Getters
	int get_id() const;

	std::string get_name() const;

	double get_gpa() const;

	std::string get_major() const;

	// Setters
	void set_gpa(double new_gpa);

	//Util
	std::string to_string() const;
};
