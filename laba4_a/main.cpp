
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class Employee {
public:
//private:
    std::string name;
    int year;
    std::string position;
    std::string unit;
//public:
    Employee(const std::string& name, int year, const std::string& position, const std::string& unit)
        : name(name), year(year), position(position), unit(unit) {}
    ~Employee() {}

    std::string getname() const { return name; }
    int getyear() const { return year; }
    std::string getposition() const { return position; }
    std::string getunit() const { return unit; }
};

int main() {
    setlocale(LC_ALL, "Russian");
        std::vector<Employee> employees;
        std::ifstream File("employees.txt");

        if (File.is_open()) {
            std::string line;
            while (std::getline(File, line)) {
                std::string name;
                int year;
                std::string position;
                std::string unit;

                std:: stringstream ssline(line);

                std::getline(ssline, name, ',');
                ssline >> year;
                std::getline(ssline, position, ',');
                std::getline(ssline, position, ',');
                std::getline(ssline, unit);

                employees.emplace_back(name, year, position, unit);

            }
            File.close();
        }
        else {
            std::cout << "Unable to open file\n";
            return 0;
        }

        std::cout << "Данные обо всех инженерах:\n";
        for (const auto& employee : employees) {
            if (employee.position == " инженер") {
                std::cout << "ФИО: " << employee.getname() << ", Год рождения: " << employee.getyear()
                    << ", Должность: " << employee.getposition() << ", Структурная единица: " << employee.getunit() << std::endl;
            }
        }

        std::sort(employees.begin(), employees.end(), [](const Employee& p1, const Employee& p2) {
            return p1.year > p2.year;
            });

        std::cout << "Данные обо всех не председателях, отсортированные по дате рождения:\n";
        for (const auto& employee : employees) {
            if (employee.position != " председатель") {
                std::cout << "ФИО: " << employee.getname() << ", Год рождения: " << employee.getyear()
                    << ", Должность: " << employee.getposition() << ", Структурная единица: " << employee.getunit() << std::endl;
            }
        }
           

        return 0;
        }