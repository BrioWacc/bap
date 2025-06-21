#include<iostream>
#include<string>
#include<vector>

class Employee {
    int id;
    int salary;
    std::string birthdate;
    std::string bankDetails;
    std::string name;
public:
    Employee(int id, int salary, std::string birthdate, std::string bankDetails, std::string name) 
        : id(id), salary(salary), birthdate(birthdate), bankDetails(bankDetails), name(name) {}

    int getId() const { return this->id; }
    int getSalary() const { return this->salary; }
    std::string getBirthdate() const { return this->birthdate; }
    std::string getBankDetails() const { return this->bankDetails; }
    std::string getName() const { return this->name; }

    void setId(int id) { this->id = id; }
    void setSalary(int salary) { this->salary = salary; }
    void setBirthdate(std::string birthdate) { this->birthdate = birthdate; }
    void setBankDetails(std::string bankDetails) { this->bankDetails = bankDetails; }
    void setName(std::string name) { this->name = name; }
};

class EmployeeManager {
    std::vector<Employee> employees;
public:
    void Create() {
        int id, salary;
        std::string birthdate, bankDetails, name;

        std::cout << "id: ";
        std::cin >> id;
        std::cout << "salary: ";
        std::cin >> salary;
        std::cout << "birthdate: ";
        std::getline(std::cin >> std::ws, birthdate);
        std::cout << "bankDetails: ";
        std::getline(std::cin >> std::ws, bankDetails);
        std::cout << "name: ";
        std::getline(std::cin >> std::ws, name);

        Employee e(id, salary, birthdate, bankDetails, name);
        this->employees.push_back(e);
    }

    void Modify(int i) {
        int salary;
        std::string bankDetails, name;

        std::cout << "salary: ";
        std::cin >> salary;
        std::cout << "bankDetails: ";
        std::getline(std::cin >> std::ws, bankDetails); 
        std::cout << "name: ";
        std::getline(std::cin >> std::ws, name);

        this->employees[i].setSalary(salary);
        this->employees[i].setBankDetails(bankDetails);
        this->employees[i].setName(name);
    }

    void View() {
        std::cout << "---------" << std::endl;
        int i = 0;
        for(Employee e : this->employees) {
            std::cout << i++
                      << "\nID: " << e.getId()
                      << "\nSalary: " << e.getSalary()
                      << "\nBirthdate: " << e.getBirthdate()
                      << "\nBank detail: " << e.getBankDetails()
                      << "\nName: " << e.getName() << "\n\n";
        }
        std::cout << "---------" << std::endl;
    }
};

int main() {
    EmployeeManager mg;

    while(1) {
        std::cout << "1 | Create\n"
                  << "2 | Modify\n"
                  << "3 | View\n"
                  << "4 | Stop\n"
                  << "-> ";

        int decision;
        std::cin >> decision;
        std::cout << decision << std::endl;
        
        switch(decision) {
            case 1:
                mg.Create();
                break;
            
            case 2:
                int index;
                std::cout << "Employee index: ";
                std::cin >> index;
                mg.Modify(index);
                break;

            case 3:
                mg.View();
                break;

            case 4:
                return 0;
            
            default:
                std::cout << "Unknown decision" << std::endl;
        }
    }

    return 0;
}
