#include <iostream>
#include <string>

class RecursiveDescentParser {
public:
    void parse(const std::string& input);
private:
    int index;
    std::string token;
    std::string input;

    bool match(const std::string& expectedToken);
    void E();
    void EPrime();
};
void RecursiveDescentParser::parse(const std::string& input) {
    this->index = 0;
    this->input = input;
    this->token = input.substr(index, 1);

    E();

    if (match(";")) {
        std::cout << "Parse succeeded" << std::endl;
    } else {
        std::cout << "Parse failed" << std::endl;
    }
}

bool RecursiveDescentParser::match(const std::string& expectedToken) {
    if (token == expectedToken) {
        index++;
        if (index < input.size()) {
            token = input.substr(index, 1);
        } else {
            token = "";
        }
        return true;
    } else {
        std::cout << "Error: expected " << expectedToken << ", got " << token << std::endl;
        exit(1);
    }
}

void RecursiveDescentParser::E() {
    std::cout << "E -> i";
    match("i");
    EPrime();
    std::cout << std::endl;
}

void RecursiveDescentParser::EPrime() {
    if (token == "+") {
        std::cout << "\nE' -> + i";
        match("+");
        match("i");
        EPrime();
    } else if (token == "-") {
        std::cout << "\nE' -> - i";
        match("-");
        match("i");
        EPrime();
    } else {
        std::cout << "\nE' -> e";
    }
}
