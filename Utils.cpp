#include "Utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

void load_students(std::vector<Student>& students, const std::string& filename) {
	std::ifstream file(filename);
	if (!file)
		return;

	std::string line;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string id_str, name, gpa_str, major;
		std::getline(ss, id_str, '|');
		std::getline(ss, name, '|');
		std::getline(ss, gpa_str, '|');
		std::getline(ss, major);

		if (!id_str.empty()) {
			students.emplace_back(std::stoi(id_str), name, std::stod(gpa_str), major);
		}
	}
	file.close();
}

void save_students(const std::vector<Student>& students, const std::string& filename) {
	std::ofstream file(filename);
	if (!file) {
		std::cerr << "Error: Could Not Open File For Writing: " << filename << "\n";
		return;
	}

	std::cout << "\nSaving to: " << filename << "\n";

	for (const auto& s : students) {
		file << s.get_id() << "|" << s.get_name() << "|" << s.get_gpa() << "|" << s.get_major() << "\n";
	}
	file.close();
}