//
// Created by Asus on 02.11.2021.
//

#include <map>
#include <set>
#include "../include/FixLetter.h"
#include "../include/LettersDivision.h"
std::map<std::string, std::set<fixing>> Types;
/* первый элемент - буква, которую надо исправить
 * в сете хранятся варианты исправления как пара буква-вероятность того, что она подходит
 */
double startVal = 0.0;
int casesViewed = 0;
void fill() {
    Types["ы"] = {fixing("й", startVal, casesViewed),
                  fixing("у", startVal, casesViewed),
                  fixing("в", startVal, casesViewed),
                  fixing("ц", startVal, casesViewed),
                  fixing("ф", startVal, casesViewed),
                  fixing("я", startVal, casesViewed),
                  fixing("ч", startVal, casesViewed)};

    Types["п"] = {fixing("к", startVal, casesViewed),
                  fixing("е", startVal, casesViewed),
                  fixing("н", startVal, casesViewed),
                  fixing("р", startVal, casesViewed),
                  fixing("и", startVal, casesViewed),
                  fixing("м", startVal, casesViewed),
                  fixing("с", startVal, casesViewed),
                  fixing("а", startVal, casesViewed)};

    Types["л"] = {fixing("г", startVal, casesViewed),
                  fixing("о", startVal, casesViewed),
                  fixing("т", startVal, casesViewed),
                  fixing("ь", startVal, casesViewed),
                  fixing("б", startVal, casesViewed),
                  fixing("д", startVal, casesViewed),
                  fixing("щ", startVal, casesViewed),
                  fixing("ш", startVal, casesViewed)};

    Types["ж"] = {fixing("з", startVal, casesViewed),
                  fixing("х", startVal, casesViewed),
                  fixing("э", startVal, casesViewed),
                  fixing("ю", startVal, casesViewed),
                  fixing("щ", startVal, casesViewed),
                  fixing("д", startVal, casesViewed),
                  fixing("б", startVal, casesViewed)};

    Types[" "] = {fixing("с", startVal, casesViewed),
                  fixing("м", startVal, casesViewed),
                  fixing("и", startVal, casesViewed),
                  fixing("т", startVal, casesViewed),
                  fixing("ь", startVal, casesViewed)};
    for (const auto& elem : Types) {
        for (const auto& next : elem.second) {
            Types[next.sym].insert(fixing(elem.first, startVal, casesViewed));
            for (const auto& it : elem.second) {
                if (it != next) {
                    Types[next.sym].insert(it);
                }
            }
        }
    }
}

void update(Mistake &sth) {
    int pos = sth.firstPos();
    std::string tmp, tmp1;
    tmp.push_back(sth.getMistakenWord()[pos]);
    tmp1.push_back(sth.getRightWord()[pos]);
    casesViewed++;
    for (auto it : Types[tmp]) {
        if (it.sym == tmp1){
            it.viewed++;
            it.chance = (double)it.viewed / (double)casesViewed;
        }
    }
}