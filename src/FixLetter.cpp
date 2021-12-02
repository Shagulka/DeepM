//
// Created by Asus on 02.11.2021.
//
#include <string>
#include "../include/FixLetter.h"

fixing::fixing(std::string _sym, double _chance, int _viewed) {
    sym = std::move(_sym);
    chance = _chance;
    viewed = _viewed;
}

fixing::~fixing() = default;

bool operator!=(fixing a, fixing b) {
    return a.sym != b.sym || a.viewed != b.viewed || a.chance != b.chance;
}

bool operator<(fixing l, fixing r) {
    if (l.chance == r.chance) {
        if (l.viewed == r.viewed) {
            return l.sym < r.sym;
        }
        return l.viewed > r.viewed;
    }
    return l.chance > r.chance;
}