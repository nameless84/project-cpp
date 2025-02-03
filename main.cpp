#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    double grade;
    string name;
    int unit;
};

struct Student {
    string fullname;
    int id;
    string major;
    double avg;
    int countoflessons;
    Course c[20];
};

Student s[100];

void read_student(int countstudent) {
    for (int i = 0; i < countstudent; i++) {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, s[i].fullname);

        while (true) {
            cout << "Enter id: ";
            cin >> s[i].id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, try again!" << endl;
            } else {
                break;
            }
        }

        cout << "Enter major: ";
        cin.ignore();
        getline(cin, s[i].major);

        while (true) {
            cout << "Enter number of lessons: ";
            cin >> s[i].countoflessons;
            if (cin.fail() || s[i].countoflessons < 0 || s[i].countoflessons > 20) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, try again!" << endl;
            } else {
                break;
            }
        }

        for (int j = 0; j < s[i].countoflessons; j++) {
            cout << "Enter course name: ";
            cin.ignore();
            getline(cin, s[i].c[j].name);

            while (true) {
                cout << "Enter grade for " << s[i].c[j].name << ": ";
                cin >> s[i].c[j].grade;
                if (cin.fail() || s[i].c[j].grade < 0 || s[i].c[j].grade > 20) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input, try again!" << endl;
                } else {
                    break;
                }
}

            while (true) {
                cout << "Enter units for " << s[i].c[j].name << ": ";
                cin >> s[i].c[j].unit;
                if (cin.fail() || s[i].c[j].unit <= 0) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input, try again!" << endl;
                } else {
                    break;}}}

        double totalGrades = 0;
        int totalUnits = 0;
        for (int j = 0; j < s[i].countoflessons; j++) {
            totalGrades += s[i].c[j].grade * s[i].c[j].unit;
            totalUnits += s[i].c[j].unit;
        }

        s[i].avg = (totalUnits > 0) ? totalGrades / totalUnits : 0;}}

void sort_students_by_avg(int countstudent) {
    for (int i = 0; i < countstudent - 1; i++) {
        for (int j = i + 1; j < countstudent; j++) {
            if (s[i].avg < s[j].avg) {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;}}}}

void show_all_students(int countstudent) {
    cout << "\nList of all students:\n";
    for (int i = 0; i < countstudent; i++) {
        cout << "Name: " << s[i].fullname << ", ID: " << s[i].id << ", Major: " << s[i].major << ", GPA: " << s[i].avg << endl;
    }
}

void show_students_by_major(int countstudent) {
    string major;
    cout << "Enter major to filter students: ";
    cin.ignore();
    getline(cin, major);

    cout << "\nStudents in major " << major << ":\n";
    bool found = false;
    for (int i = 0; i < countstudent; i++) {
        if (s[i].major == major) {
            found = true;
            cout << "Name: " << s[i].fullname << ", ID: " << s[i].id << ", GPA: " << s[i].avg << endl;
        }
    }
    if (!found) {
        cout << "No students found in this major." << endl;
    }
}

void show_report_card(int countstudent) {
    string name;
    cout << "Enter student's name to show report card: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < countstudent; i++) {
        if (s[i].fullname == name) {
            found = true;
            cout << "\nReport Card for " << s[i].fullname << " (" << s[i].id << ")\n";
            cout << "Course Name" << setw(25) << "Grade" << setw(10) << "Units" << setw(10)<< endl;
            cout << "-------------------------------------------------------------\n";
            for (int j = 0; j < s[i].countoflessons; j++) {
                double totalPoints = s[i].c[j].grade * s[i].c[j].unit;
                cout << setw(15) << s[i].c[j].name
                     << setw(15) << s[i].c[j].grade
                     << setw(10) << s[i].c[j].unit<<endl;}
            cout << "\nGPA: " << s[i].avg << endl;
        }
    }

    if (!found) {
        cout << "No student found with the name " << name << endl;
    }
}
int main() {
    int numberstudent;
    while (true) {
        cout << "Enter number of students: ";
        cin >> numberstudent;
        if (cin.fail() || numberstudent <= 0 || numberstudent > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, try again!" << endl;
        } else {
            break;
        }
    }
    read_student(numberstudent);
    int choice;
    while (true) {
        cout << "\n1. Show all students\n2. Show students by major\n3. Show report card by student name\nEnter your choice: ";
        cin >> choice;
        if (cin.fail() || (choice < 1 || choice > 3)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, try again!" << endl;
        } else {
            break;
        }
    }

    sort_students_by_avg(numberstudent);

    if      (choice == 1) show_all_students(numberstudent);
    else if (choice == 2) show_students_by_major(numberstudent);
    else if (choice == 3) show_report_card(numberstudent);
}
