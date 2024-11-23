#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>   
using namespace std;

class Employee {
    string Name;
    int WorkedHours;
    double HourlyRate;

public:
    Employee(string name = "", int hours = 0, double rate = 0.0)
        : Name(name), WorkedHours(hours), HourlyRate(rate) {}

    double CalculateSalary() const {
        return WorkedHours * HourlyRate;
    }

    friend ostream& operator<<(ostream& os, const Employee& E) {
        os << "Name: " << E.Name
            << "\tWorked Hours: " << E.WorkedHours
            << "\tHourly Rate: " << E.HourlyRate
            << "\tSalary: " << E.CalculateSalary() << endl;
        return os;
    }

    static Employee* GenerateRandomEmployee(const string& name) {
        int hours = rand() % 161;
        double rate = (rand() % 1000 + 1000) / 100.0;
        return new Employee(name, hours, rate);
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Employee*> employees;

    vector<string> names = { "Olexiy", "Anastasiya", "Igor", "Svitlana", "Vasyl" };

    for (const string& name : names) {
        employees.push_back(Employee::GenerateRandomEmployee(name));
    }

    cout << "Employee Data:" << endl;
    for (const Employee* emp : employees) {
        cout << *emp;
    }

    double totalCost = 0.0;
    for (const Employee* emp : employees) {
        totalCost += emp->CalculateSalary();
    }
    cout << "Total company labor cost: " << totalCost << endl;

    for (Employee* emp : employees) {
        delete emp;
    }

    return 0;
}