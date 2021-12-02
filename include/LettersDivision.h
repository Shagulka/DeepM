//
// Created by Asus on 02.11.2021.
//

#ifndef DEEPM_LETTERSDIVISION_H
#define DEEPM_LETTERSDIVISION_H
#include <map>
#include <set>
#include <vector>
#include "../include/FixLetter.h"
#include "../include/Mistake.h"
extern std::map<std::string, std::set<fixing>> LettersAndChances;
extern double startVal;
extern int casesViewed;
void fill();
void update(Mistake &sth);
#endif //DEEPM_LETTERSDIVISION_H
