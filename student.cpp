/*******************************************************************************
 * Filename: student.cpp
 * Author  : Aaren Patel
 * Version : 1.0
 * Date    : September 14, 2023
 * Description: Student class
 * Pledge  : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Student {
    public:
        Student(const string &first, const string &last, const float gpa, const int id) : first_(first), last_(last), gpa_(gpa), id_(id) { }
        string  full_name() const {
            return first_ + " " + last_;
        }
        int id() const {
            return id_;
        }
        float gpa() const {
            return gpa_;
        }
        void print_info() const {
            cout << full_name() << ", GPA: " << setprecision(2) << fixed << gpa() << ", ID: " << id() << endl;
        }


    private:
        string first_, last_;
        float gpa_;
        int id_;

};

/**
* Takes a vector of Student objects, and returns a new vector
* with all Students whose GPA is < 1.0.
*/
vector<Student> find_failing_students(const vector<Student> &students) {
    vector<Student> failing_students;
    for (vector<Student>::const_iterator iter = students.begin(); iter != students.end(); iter++) {
        if (iter->gpa() < 1) {
            failing_students.push_back(*iter);
        }
    }
    return failing_students;
}

/**
* Takes a vector of Student objects and prints them to the screen.
*/
void print_students(const vector<Student> &students) {
    for (vector<Student>::const_iterator iter = students.begin(); iter != students.end(); iter++) {
        iter->print_info();
    }

}

/**
* Allows the user to enter information for multiple students, then
* find those students whose GPA is below 1.0 and prints them to the
* screen. */
int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;
    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
            while (gpa < 0 || gpa > 4) {
                cout << "Enter student's GPA (0.0-4.0): ";
                cin >> gpa;
            }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    }
    while (repeat == 'Y' || repeat == 'y');
    cout << endl << "All students:" << endl;
    print_students(students);
    cout << endl << "Failing students:";
    vector<Student> fail_students = find_failing_students(students);
    if (fail_students.size() == 0) {
        cout << " None" << endl;
    }
    else {
        cout << endl;
        print_students(fail_students);
    }
    return 0;
}
