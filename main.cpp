#include <iostream>
#include <algorithm>
#include <limits>
#include "Student.h"
#include "Utils.h"

using namespace std;

void clear_screen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pause_screen() {
	cout << "\nPress Enter To Return To The Menu...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	clear_screen();
}


int main() {
	vector<Student> students;
	const string filename = "Students.txt";

	load_students(students, filename);

	int choice;
	do {
		cout << "\n----Student Record Manager----\n";
		cout << "1. Add Student\n";
		cout << "2. View All Students\n";
		cout << "3. Search By ID\n";
		cout << "4. Update GPA\n";
		cout << "5. Delete Student\n";
		cout << "6. Save And Exit\n";

		while (true) {
			cout << "Enter Choice: ";
			if (cin >> choice) break;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input, Please Enter A Number 1-6: ";

		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		/*switch (choice) {
			case 1:

				break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break
		default:
			cout << "\nInvalid Choice. Please Enter A Number 1-6: "
		}*/
		if (choice == 1) {
			int id;
			string name, major;
			double gpa;
			cout << "\nEnter Student ID: ";
			cin >> id;
			cin.ignore();
			cout << "\nEnter Student Name: ";
			getline(cin, name);
			cout << "\nEnter Student GPA: ";
			cin >> gpa;
			cin.ignore();
			cout << "\nEnter Student Major: ";
			getline(cin, major);
			students.emplace_back(id, name, gpa, major);
			cout << "\nStudent Successfully Added!\n";

			pause_screen();
		}
		else if (choice == 2) {
			cout << "\nAll Student Records\n";
			for (const auto& s : students) {
				cout << s.to_string() << "\n";
			}
			pause_screen();
		}
		else if (choice == 3) {
			int id;
			cout << "\nEnter Student ID: ";
			cin >> id;
			bool found = false;
			for (const auto& s : students) {
				if (s.get_id() == id) {
					cout << s.to_string() << "\n";
					found = true;
					break;
				}
			}

			if (!found)
				cout << "\nStudent Not Found.\n";
			pause_screen();
		}
		else if (choice == 4) {
			int id;
			double gpa;
			cout << "\nEnter Student ID to Update GPA: ";
			cin >> id;
			cout << "\nEnter New GPA: ";
			cin >> gpa;
			bool updated = false;
			for (auto& s : students) {
				if (s.get_id() == id) {
					s.set_gpa(gpa);
					updated = true;
					cout << "\nGPA Successfully Updated!\n";
					break;
				}
			}
			if (!updated)
				cout << "\nStudent Not Found.\n";
			pause_screen();
		}
		else if (choice == 5) {
			int id;
			char ans;
			cout << "\nEnter Student ID to Delete Student: ";
			cin >> id;
			auto it = remove_if(students.begin(), students.end(), [id](const Student& s) {
				return s.get_id() == id;
				});
			if (it != students.end()) {
				students.erase(it, students.end());
				cout << "\nStudent Successfully Deleted.\n";
			}
			else
				cout << "\nStudent Not Found.\n";
			pause_screen();
		}
		else if (choice == 6) {
			save_students(students, filename);
			cout << "\nData Saved. Exiting...\n";
		}
		else{
			cout << "\nInvalid Choice.\n";
			pause_screen();
		}

	} while (choice != 6);
	return 0;
}

