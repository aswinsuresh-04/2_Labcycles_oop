#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) {
        name = n;
        cout << "Person constructor called" << " " << name << endl;
    }
};

class Employee {
protected:
    int empID;
public:
    Employee(int id) {
        empID = id;
        cout << "Employee id called" << " " << id << endl;
    }
};

class Manager : public Person, public Employee {
public:
    Manager(string n, int id) : Person(n), Employee(id) {
        cout << "Manager constructor called" << " " << name <<endl;
    }
};

class DepartmentManager : public Manager {
protected:
    string department;
public:
    DepartmentManager(string n, int id, string dept) : Manager(n, id), department(dept) {
        cout << "Department constructor called" << " " << dept <<endl;
    }
};

int main() {
    string name, dept;
    int id;

    cout << "Enter the name of the department manager: ";
    cin >> name;

    cout << "Enter the employee ID of the department manager: ";
    cin >> id;

    cout << "Enter the department of the department manager: ";
    cin >> dept;

    DepartmentManager myManager(name, id, dept);
    return 0;
}
