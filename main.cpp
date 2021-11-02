#include <iostream>
#include "include/LettersDivision.h"

int main() {
    std::setlocale(LC_ALL, "russian");
    fill();
    for (auto& elem : Types){
        std::cout << elem.first << " ";
        for (auto& it : elem.second){
            std::cout << it.sym << " ";
        }
        std::cout << "\n";
    }
    std::string s;
    while (getline(std::cin, s)){
        Mistake tmp("", "");
        update(tmp);
    }
    return 0;
}
