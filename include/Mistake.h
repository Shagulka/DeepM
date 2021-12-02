//
// Created by Asus on 02.11.2021.
//

#ifndef DEEPM_MISTAKE_H
#define DEEPM_MISTAKE_H

#endif //DEEPM_MISTAKE_H
class Mistake{
private:
    std::string MatveyInput;
    std::string RealWord;
public:
    Mistake(std::string _input, const std::string& _word);
    ~Mistake();
    std::string getMistakenWord();
    std::string getRightWord();
    int firstPos();
    void fixMistake();
    void setRealWord(const std::string& w);
    void setMatveyInput(const std::string& w);
};