#include<iostream>
#include<string>
#include<vector>

class textable {
public:
    virtual void writeText(std::string text) = 0;
    virtual std::string readText() = 0;
    ~textable() = default;
};

class Notizblock : public textable {
    std::string Seite;
public:
    void writeText(std::string text) override {
         this->Seite = text;
    }

    std::string readText() override {
        return this->Seite;
    }
};

class TextDatei : public textable {
    std::vector<std::string> fd;
public:
    void writeText(std::string text) override {
        this->fd.push_back(text);
    }

    std::string readText() override {
        std::string builder;
        for(const auto& entry : this->fd) builder += entry + "\n";

        return builder;
    }
};

int main() {
    Notizblock n;
    TextDatei t;

    n.writeText("Test");

    std::cout << n.readText() << '\n';

    n.writeText("Test 2");

    std::cout << n.readText() << '\n';

    t.writeText("Sample 1");
    t.writeText("Sample 2");
    t.writeText("Sample 3");

    std::cout << t.readText() << '\n';

    return 0;
}
