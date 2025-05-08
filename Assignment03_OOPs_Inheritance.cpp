#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string Name;
    int Age;
    string id;
public:
    Person(string n = "", int a = 0, string i = "") : Name(n), Age(a), id(i) {}
    virtual void displayDetails() {
        cout << "Name: " << Name << "\nAge: " << Age << "\nID: " << id << endl;
    }
    virtual float calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
protected:
    string program;
    float gpa;
public:
    Student(string n = "", int a = 0, string i = "", string p = "", float g = 0.0)
        : Person(n, a, i), program(p), gpa(g) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << "\nGPA: " << gpa << endl;
    }
};

class UndergraduateStudent : public Student {
    string major, minor;
    string gradDate;
public:
    UndergraduateStudent(string n, int a, string i, string p, float g, string mj, string mn, string gd)
        : Student(n, a, i, p, g), major(mj), minor(mn), gradDate(gd) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << "\nMinor: " << minor << "\nGraduation Date: " << gradDate << endl;
    }
};

class GraduateStudent : public Student {
    string topic, advisor, thesis;
public:
    GraduateStudent(string n, int a, string i, string p, float g, string t, string adv, string th)
        : Student(n, a, i, p, g), topic(t), advisor(adv), thesis(th) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Research Topic: " << topic << "\nAdvisor: " << advisor << "\nThesis: " << thesis << endl;
    }
};

class Professor : public Person {
protected:
    string department, specialization;
    int yearsOfService;
public:
    Professor(string n, int a, string i, string d, string s, int y)
        : Person(n, a, i), department(d), specialization(s), yearsOfService(y) {}
    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << "\nSpecialization: " << specialization << endl;
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string i, string d, string s, int y)
        : Professor(n, a, i, d, s, y) {}
    float calculatePayment() override {
        return 50000 + (yearsOfService * 1000);
    }
};

class AssociateProfessor : public Professor {
public:
    AssociateProfessor(string n, int a, string i, string d, string s, int y)
        : Professor(n, a, i, d, s, y) {}
    float calculatePayment() override {
        return 70000 + (yearsOfService * 1500);
    }
};

class FullProfessor : public Professor {
public:
    FullProfessor(string n, int a, string i, string d, string s, int y)
        : Professor(n, a, i, d, s, y) {}
    float calculatePayment() override {
        return 90000 + (yearsOfService * 2000);
    }
};

class Department {
    string Name, location;
    float budget;
public:
    Department(string n, string l, float b) : Name(n), location(l), budget(b) {}
    void show() {
        cout << "Department: " << Name << ", Location: " << location << ", Budget: " << budget << endl;
    }
};

class Course {
    string code, title;
    int credits;
    string description;
    Professor* instructor;
public:
    Course(string c, string t, int cr, string d, Professor* prof)
        : code(c), title(t), credits(cr), description(d), instructor(prof) {}
    void showCourse() {
        cout << "Course Code: " << code << ", Title: " << title << ", Credits: " << credits << endl;
        instructor->displayDetails();
    }
};

class Classroom {
    string roomNumber;
    int capacity;
public:
    Classroom(string r, int c) : roomNumber(r), capacity(c) {}
    void showRoom() {
        cout << "Room: " << roomNumber << ", Capacity: " << capacity << endl;
    }
};

class Schedule {
    string timeSlot;
    Course* course;
    Classroom* classroom;
public:
    Schedule(string t, Course* c, Classroom* cl)
        : timeSlot(t), course(c), classroom(cl) {}
    void showSchedule() {
        cout << "Time Slot: " << timeSlot << endl;
        course->showCourse();
        classroom->showRoom();
    }
};

int main() {
    UndergraduateStudent u1("Rahul", 19, "U101", "B.Tech", 3.6, "CS", "Math", "2027");
    GraduateStudent g1("Ram", 24, "G102", "M.Tech", 3.8, "AI", "Dr. Smith", "AI Ethics");

    AssistantProfessor ap("Dr. Shyam", 35, "P201", "CS", "AI", 3);
    AssociateProfessor asp("Dr. Neha", 45, "P202", "CS", "ML", 8);
    FullProfessor fp("Dr. John", 55, "P203", "CS", "Systems", 15);

    Department csDept("Computer Science", "Block A", 1000000);
    csDept.show();

    Course course1("CS101", "Intro to CS", 4, "Basics of CS", &ap);
    Classroom room1("B101", 60);
    Schedule sched1("9:00 AM - 10:00 AM", &course1, &room1);
    
    u1.displayDetails();
    cout << endl;
    g1.displayDetails();
    cout << endl;
    ap.displayDetails();
    cout << "Payment: Rs. " << ap.calculatePayment() << endl;
    cout << endl;
    sched1.showSchedule();

    return 0;
}