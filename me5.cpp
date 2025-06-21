#include<iostream>
#include<vector>
#include<string>

class Kurs {
public:
    std::string name;

    Kurs(std::string name) : name(name) {}
};

class Student {
public:
    std::string name;
    std::string matrikelnummer;
    std::vector<Kurs> kurse;
    
    Student(std::string name, std::string matrikelnummer, std::vector<Kurs> kurse) 
        : name(name), matrikelnummer(matrikelnummer), kurse(kurse) {}

    Student(const Student& other) 
        : name(other.name), matrikelnummer(other.matrikelnummer), kurse(other.kurse) {}

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << "Name: " << s.name << '\n'
           << "Matrikelnummer: " << s.matrikelnummer << '\n';

        for(const auto& kurs : s.kurse) os << kurs.name << '\n';

        return os;
    }
};

int main() {
    std::vector<Kurs> kurse({Kurs("Mathe"), Kurs("Physik")});

    Student s1("Peter", "49835", kurse);

    Student s2(s1);

    std::cout << "s1\n" << s1 << "\n\n";
    std::cout << "s2\n" << s2 << "\n\n";
    return 0;
}
