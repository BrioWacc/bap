#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class Mitglied {
    std::string name;

public:
    Mitglied(std::string name) : name(name) {}

    std::string getName() {
        return this->name;
    }
};

class Verein {
    std::vector<Mitglied> mitglieder;

public:
    void beitreten(const Mitglied& m) {
        this->mitglieder.push_back(m);
    }

    void austreten(const std::string& name) {
        auto it = std::find_if(this->mitglieder.begin(), this->mitglieder.end(), 
                [&name](Mitglied& m) {return name.compare(m.getName()) == 0;});
    
        if(it != this->mitglieder.end()) {
            std::cout << name << " ist ausgetreten" << std::endl;
            this->mitglieder.erase(it);
        } else {
            std::cout << "Es gibt kein Mitglied mit dem Namen " << name << std::endl;
        }
    }

    void zaehleMitglieder() {
        std::cout << "Mitglieder: " << this->mitglieder.size() << std::endl;
    }
};

int main() {
    Mitglied m1("Max"), m2("Peter"), m3("Torben");
    Verein v1;

    v1.zaehleMitglieder();

    v1.beitreten(m1);

    v1.zaehleMitglieder();
    
    v1.beitreten(m2);
    v1.beitreten(m3);

    v1.austreten("Peter");

    v1.zaehleMitglieder();
   
    v1.austreten("Peter");

    return 0;
}
