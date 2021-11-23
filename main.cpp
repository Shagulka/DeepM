#include <iostream>
#include "include/LettersDivision.h"

int main() {
    std::setlocale(LC_ALL, "russian");
    fill();
    std::string s;
    //TODO
    while (getline(std::cin, s)){
        //здесь надо брать данные из жсона
        Mistake tmp(s, s);
        update(tmp);
    }
    return 0;
}
