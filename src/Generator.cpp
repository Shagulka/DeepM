//
// Created by Asus on 02.11.2021.
//

#include <string>
#include <map>
#include "../include/Generator.h"
#include "../include/LettersDivision.h"

std::string generateRealWord(std::string input) {
    std::string ans;
    for (int i = 0; i < input.size(); ++i) {
        std::string tmp;
        tmp.push_back(input[i]);
        ans += LettersAndChances[tmp].begin()->sym;
    }
    return ans;
}

std::string findMistake(std::string word) {

}

std::string getRussianWord(const std::string &word) {
    const std::map<char, std::string> engrus = {{'q',  "й"},
                                                {'w',  "ц"},
                                                {'e',  "у"},
                                                {'r',  "к"},
                                                {'t',  "е"},
                                                {'y',  "н"},
                                                {'u',  "г"},
                                                {'i',  "г"},
                                                {'o',  "щ"},
                                                {'p',  "з"},
                                                {'a',  "ф"},
                                                {'s',  "ы"},
                                                {'d',  "в"},
                                                {'f',  "а"},
                                                {'g',  "п"},
                                                {'h',  "р"},
                                                {'j',  "о"},
                                                {'k',  "л"},
                                                {'l',  "д"},
                                                {'z',  "я"},
                                                {'x',  "ч"},
                                                {'c',  "с"},
                                                {'v',  "м"},
                                                {'b',  "и"},
                                                {'n',  "т"},
                                                {'m',  "ь"},
                                                {'[',  "х"},
                                                {']',  "ъ"},
                                                {';',  "ж"},
                                                {'\'', "э"},
                                                {'.',  "ю"},
                                                {',',  "б"}};
    std::string ans;
    for (auto letter : word) {
        ans += engrus.find(letter)->second;
    }
    return ans;
}
