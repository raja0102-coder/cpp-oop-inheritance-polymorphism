#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string n, int i, double s) : name(n), id(i), baseSalary(s) {}

    // Virtual function for runtime polymorphism
    virtual double calculateEarnings() const {
        return baseSalary;
    }

    virtual void displayDetails() const {
        cout << "    ID: " << id << " | Name: " << name << " | Total Pay: Rs. " << calculateEarnings() << endl;
    }

    virtual ~Employee() {} // Virtual destructor for safe polymorphic cleanup
};

// Derived Class 1: Manager
class Manager : public Employee {
private:
    double bonus;

    public:
    Manager(string n, int i, double s, double b) : Employee(n, i, s), bonus(b) {}

    double calculateEarnings() const override {
        return baseSalary + bonus;
    }

    void displayDetails() const override {
        cout << "    [MANAGER]   ID: " << id << " | Name: " << name << " | Total Pay: Rs. " << calculateEarnings() << " (Includes Bonus)" << endl;
    }
};

// Derived Class 2: Developer
class Developer : public Employee {
private:
    double overtimePay;

public:
    Developer(string n, int i, double s, double ot) : Employee(n, i, s), overtimePay(ot) {}

    double calculateEarnings() const override {
        return baseSalary + overtimePay;
    }

    void displayDetails() const override {
        cout << "    [DEVELOPER] ID: " << id << " | Name: " << name << " | Total Pay: Rs. " << calculateEarnings() << " (Includes Overtime)" << endl;
    }
};

int main() {
    cout << "==================================================\n";
    cout << "    C++ INHERITANCE & POLYMORPHISM ENGINE         \n";
    cout << "==================================================\n\n";

    cout << "[1] POLYMORPHIC EMPLOYEE PAYROLL SYSTEM:\n";
    vector<Employee*> staff;
    staff.push_back(new Manager("Raja Babu", 201, 75000, 15000));
    staff.push_back(new Developer("Aarav Sharma", 202, 60000, 8000));
    staff.push_back(new Developer("Priya Singh", 203, 62000, 9500));

    for (size_t i = 0; i < staff.size(); ++i) {
        staff[i]->displayDetails();
    }

    // Clean up heap memory
    for (size_t i = 0; i < staff.size(); ++i) {
        delete staff[i];
    }

    cout << "\n==================================================\n";

    return 0;
}
