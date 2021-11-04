//
// Created by Asus on 02.11.2021.
//

#include <map>
#include <set>
#include <vector>
#include "../include/FixLetter.h"
#include "../include/LettersDivision.h"
std::map<std::string, std::set<fixing>> Types;
/* первый элемент - буква, которую надо исправить
 * в сете хранятся варианты исправления как пара буква-вероятность того, что она подходит и число случаев, где она подходила,
 * чтобы пересчитывать вероятность
 */
double startVal = 0.0;
int casesViewed = 0;
void fill() {
    std::vector <std::string> letters = {"й", "ц", "у", "к", "е", "н", "г", "ш", "щ", "з", "х", "ъ", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "я", "ч", "с", "м", "и", "т", "ь", "б", "ю", " ", "."};
    for (int i = 0; i < letters.size(); ++i){
        for (int j = 0; j < letters.size(); ++j){
            if (i != j){
                Types[letters[i]].insert(fixing(letters[j], startVal, casesViewed));
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
