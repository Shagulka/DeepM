//
// Created by Asus on 01.11.2021.
//

#include "../include/Generator.h"
#include "../include/Mistake.h"


Mistake::Mistake(std::string _input, const std::string& _word) {
    MatveyInput = std::move(_input);
    if (_word.empty()) {
        RealWord = generateRealWord(MatveyInput);
    }
    RealWord = _word;
}

Mistake::~Mistake() = default;

std::string Mistake::getMistakenWord() { return MatveyInput; }

std::string Mistake::getRightWord() { return RealWord; }

int Mistake::firstPos() {
    for (int i = 0; i < (int) MatveyInput.size() && i < (int) RealWord.size(); ++i) {
        if (MatveyInput[i] != RealWord[i]) {
            return i;
        }
    }
    return std::min((int) RealWord.size(), (int) MatveyInput.size()) + 1;
}

void Mistake::fixMistake() {
    MatveyInput = RealWord;
}

