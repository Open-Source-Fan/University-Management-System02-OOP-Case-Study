#include <iostream>
#include <string>

using namespace std;
void showError(string msg) {
    cout << "Error: " << msg << endl;
}


class Person {
protected:
    string name, contact;
    int age, id;
public:
    Person(string n, int a, int i, string c) {
        if (a <= 0 || a > 100) {
            showError("Invalid age.");
            age = 18; // default valid age
        } else {
            age = a;
        }

        if (i <= 0) {
            showError("Invalid ID.");
            id = 1;
        } else {
            id = i;
        }

        if (c.empty()) {
            showError("Invalid contact.");
            contact = "not_provided";
        } else {
            contact = c;
        }

        name = n;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << ", Contact: " << contact << endl;
    }

    virtual float calculatePayment() {
        return 0.0;
    }

    int getId() {
        return id;
    }
};

class Student : public Person {
protected:
    string program;
    float gpa;
public:
    Student(string n, int a, int i, string c, string p, float g) : Person(n, a, i, c) {
        if (g < 0.0 || g > 4.0) {
            showError("Invalid GPA.");
            gpa = 0.0;
        } else {
            gpa = g;
        }
        program = p;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << gpa << endl;
    }
};

class Professor : public Person {
protected:
    string dept;
    float salary;
public:
    Professor(string n, int a, int i, string c, string d, float s) : Person(n, a, i, c) {
        if (s <= 0) {
            showError("Invalid salary.");
            salary = 50000;
        } else {
            salary = s;
        }
        dept = d;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << dept << ", Salary: " << salary << endl;
    }

    float calculatePayment() override {
        return salary;
    }
};

class Course {
    string code, title;
    int credits, maxStudents;
public:
    Course(string c, string t, int cr, int maxS) {
        if (cr <= 0) {
            showError("Invalid credits.");
            credits = 3;
        } else {
            credits = cr;
        }
        code = c;
        title = t;
        maxStudents = maxS;
    }

    void enrollStudent() {
        cout << "Student enrolled in course: " << title << endl;
    }

    string getTitle() {
        return title;
    }
};

class GradeBook {
    int grades[100];
    int count;
public:
    GradeBook() {
        count = 0;
    }

    void addGrade(int g) {
        if (g < 0 || g > 100) {
            showError("Invalid grade.");
            return;
        }
        grades[count++] = g;
    }

    float calculateAverage() {
        if (count == 0) return 0;
        int sum = 0;
        for (int i = 0; i < count; ++i) {
            sum += grades[i];
        }
        return (float)sum / count;
    }
};

class UniversitySystem {
    Student* students[10];
    Professor* professors[10];
    Course* courses[10];
    int studentCount = 0, profCount = 0, courseCount = 0;
public:
    void addStudent(Student* s) {
        students[studentCount++] = s;
    }

    void addProfessor(Professor* p) {
        professors[profCount++] = p;
    }

    void addCourse(Course* c) {
        courses[courseCount++] = c;
    }

    void enroll(int studentId, int courseIndex) {
        if (courseIndex >= courseCount) {
            showError("Course not found.");
            return;
        }
        courses[courseIndex]->enrollStudent();
        cout << "Student " << studentId << " enrolled in " << courses[courseIndex]->getTitle() << endl;
    }

    void showReports() {
        cout << "--- University Report ---" << endl;
        for (int i = 0; i < studentCount; ++i)
            students[i]->displayDetails();
        for (int i = 0; i < profCount; ++i) {
            professors[i]->displayDetails();
            cout << "Payment: " << professors[i]->calculatePayment() << endl;
        }
    }
};

// ---------------------- Main Program ----------------------
int main() {
    UniversitySystem uni;

    Student* s1 = new Student("Rahul", 20, 101, "rahul@email.com", "AI",8);
    Professor* p1 = new Professor("Dr. Smith", 45, 201, "smith@email.com", "CSE", 80000);
    Course* c1 = new Course("CS101", "Intro to Programming", 3, 2);

    uni.addStudent(s1);
    uni.addProfessor(p1);
    uni.addCourse(c1);

    uni.enroll(s1->getId(), 0);

    GradeBook gb;
    gb.addGrade(90);
    gb.addGrade(85);
    cout << "Average Grade: " << gb.calculateAverage() << endl;

    uni.showReports();

    return 0;
}
