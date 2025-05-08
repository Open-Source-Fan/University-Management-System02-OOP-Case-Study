// Assignment 2: Classes, Encapsulation, and Polymorphism
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string Name;
    int Age;
    string ID;
    string contact;

public:
    Person() {
        Name = "";
        Age = 0;
        ID = "";
        contact = "";
    }

    Person(string n, int a, string id, string c) {
        setName(n);
        setAge(a);
        ID = id;
        contact = c;
    }

    void setName(string n) {
        if (n != "") Name = n;
    }
    void setAge(int a) {
        if (a > 0 && a < 120) Age = a;
    }
    void setID(string id) { ID = id; }
    void setContact(string c) { contact = c; }

    string getName() { return Name; }
    int getAge() { return Age; }
    string getID() { return ID; }
    string getContact() { return contact; }

    virtual void displayDetails() {
        cout << "Name: " << Name << ", Age: " << Age << ", ID: " << ID << ", Contact: " << contact << endl;
    }

    virtual float calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
private:
    string program;
    float GPA;
    string enrollmentDate;

public:
    Student() : Person() {
        program = "";
        GPA = 0.0;
        enrollmentDate = "";
    }

    Student(string n, int a, string id, string c, string prog, float gpa, string ed)
        : Person(n, a, id, c) {
        program = prog;
        setGPA(gpa);
        enrollmentDate = ed;
    }

    void setGPA(float g) {
        if (g >= 0.0 && g <= 4.0) GPA = g;
    }

    float getGPA() { return GPA; }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Program: " << program << ", GPA: " << GPA << ", Enrollment Date: " << enrollmentDate << endl;
    }

    float calculatePayment() override {
        return 5000.0;
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor() : Person() {
        department = specialization = hireDate = "";
    }

    Professor(string n, int a, string id, string c, string dept, string spec, string hd)
        : Person(n, a, id, c) {
        department = dept;
        specialization = spec;
        hireDate = hd;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Department: " << department << ", Specialization: " << specialization << ", Hire Date: " << hireDate << endl;
    }

    float calculatePayment() override {
        return 10000.0;
    }
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;

public:
    Course() {
        code = title = description = "";
        credits = 0;
    }

    Course(string c, string t, int cr, string d) {
        code = c;
        title = t;
        setCredits(cr);
        description = d;
    }

    void setCredits(int c) {
        if (c > 0) credits = c;
    }

    void displayCourse() {
        cout << "Code: " << code << ", Title: " << title << ", Credits: " << credits << ", Description: " << description << endl;
    }
};

class Department {
private:
    string Name;
    string location;
    float budget;

public:
    Department() {
        Name = location = "";
        budget = 0.0;
    }

    Department(string n, string l, float b) {
        Name = n;
        location = l;
        budget = b;
    }

    void displayDepartment() {
        cout << "Department: " << Name << ", Location: " << location << ", Budget: " << budget << endl;
    }
};

class GradeBook {
private:
    int studentIDs[5];
    float grades[5];
    int count;

public:
    GradeBook() {
        count = 0;
    }

    void addGrade(int id, float grade) {
        if (count < 5 && grade >= 0 && grade <= 100) {
            studentIDs[count] = id;
            grades[count] = grade;
            count++;
        }
    }

    float calculateAverageGrade() {
        float sum = 0;
        for (int i = 0; i < count; i++) sum += grades[i];
        return count > 0 ? sum / count : 0;
    }

    float getHighestGrade() {
        float max = 0;
        for (int i = 0; i < count; i++) if (grades[i] > max) max = grades[i];
        return max;
    }

    void getFailingStudents() {
        cout << "Failing Students (Grade < 40): ";
        for (int i = 0; i < count; i++) if (grades[i] < 40) cout << studentIDs[i] << " ";
        cout << endl;
    }
};
 
class EnrollmentManager {
private:
    int enrollments[5];
    int count;

public:
    EnrollmentManager() { count = 0; }

    void enrollStudent(int studentID) {
        if (count < 5) enrollments[count++] = studentID;
    }

    void dropStudent(int studentID) {
        for (int i = 0; i < count; i++) {
            if (enrollments[i] == studentID) {
                for (int j = i; j < count - 1; j++) enrollments[j] = enrollments[j + 1];
                count--;
                break;
            }
        }
    }

    int getEnrollmentCount() {
        return count;
    }
};

// ----------------------------- MAIN PROGRAM -----------------------------

int main() {
    Student s1("Rahul", 20, "S101", "rahul@email.com", "CSE", 8, "2023-08-01");
    Student s2("Ram", 21, "S102", "ram@email.com", "ECE", 7.4, "2023-08-01");

    Professor p1("Dr. Shyam", 45, "P201", "shyam@email.com", "CS", "AI", "2010-06-01");
    Professor p2("Dr. Neha", 50, "P202", "neha@email.com", "ECE", "Robotics", "2008-03-01");

    Course c1("CSE101", "Intro to CS", 3, "Basics of programming");
    Department d1("Computer Science", "Block A", 500000);

    GradeBook gb;
    gb.addGrade(101, 85);
    gb.addGrade(102, 35);
    gb.addGrade(103, 90);

    EnrollmentManager em;
    em.enrollStudent(101);
    em.enrollStudent(102);

    s1.displayDetails();
    p1.displayDetails();
    c1.displayCourse();
    d1.displayDepartment();

    cout << "\nAverage Grade: " << gb.calculateAverageGrade();
    cout << "\nHighest Grade: " << gb.getHighestGrade() << endl;
    gb.getFailingStudents();

    cout << "\nEnrollment Count: " << em.getEnrollmentCount() << endl;

    Person* people[2] = { &s2, &p2 };
    for (int i = 0; i < 2; i++) {
        people[i]->displayDetails();
        cout << "Payment: Rs. " << people[i]->calculatePayment() << "\n";
    }

    return 0;
}
