//
// Created by Asus on 02.11.2021.
//

#ifndef DEEPM_FIXLETTER_H
#define DEEPM_FIXLETTER_H
struct fixing{
    std::string sym;
    double chance;
    int viewed;
    fixing(std::string _sym, double _chance, int _viewed);
    ~fixing();
};
bool operator!=(fixing a, fixing b);
bool operator<(fixing l, fixing r);
#endif //DEEPM_FIXLETTER_H
