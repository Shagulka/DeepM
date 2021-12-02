#include <iostream>
#include "include/Generator.h"
#include "include/LettersDivision.h"
#include <document.h>
#include <writer.h>
#include <stringbuffer.h>
#include <fstream>
#include <ostreamwrapper.h>
#include <istreamwrapper.h>

using namespace rapidjson;
int main() {
    std::setlocale(LC_ALL, "russian");
    fill();
    std::string s;
    std::ifstream input("words.json");
    IStreamWrapper wrap(input);
    Document d;
    d.ParseStream(wrap);
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    std::string jsonStr(buffer.GetString());
    while (jsonStr != "null"){
        std::string key;
        Mistake tmp("", "");
        for (int i = 0; i < jsonStr.size(); ++i) {
            key += jsonStr[i];
            if (jsonStr[i] == '[') {
                eraseOdd(key);
                tmp.setRealWord(key);
                std::string t;
                for (int j = i; j < jsonStr.size(); ++j){
                    t += jsonStr[j];
                    if (jsonStr[j] == ','){
                        eraseOdd(t);
                        tmp.setMatveyInput(t);
                        update(tmp);
                        std::cout << t << "\n";
                        t.clear();
                    }
                }
            }
        }
        jsonStr = buffer.GetString();
    }
    return 0;
}
