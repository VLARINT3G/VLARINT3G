#include <Work.h>
#include <string>
using namespace std;

bool Work::isRazdel(char c, const string& razd) {
    return razd.find(c) != string::npos;
}

int Work::countWords(const string& str, const string& razd) {
    int count = 0;
    bool inWord = false;
    for (char c : str) {
        if (isRazdel(c, razd)) {
            inWord = false;
        } else if (!inWord) {
            count++;
            inWord = true;
        }
    }
    return count;
}

bool Work::isGlasnaya(char c) {
    string glasnye = "AIOEUYaioeuy";
    return glasnye.find(c) != string::npos;
}

void Work::changeText(string& str, char zamen, const string& razd) {
    if (countWords(str, razd) > 5) {
        for (char& c : str) {
            if (isGlasnaya(c)) {
                c = zamen;
            }
        }
    }
}

void Work::processText(Input& input) {
    for (string& line : input.text) {
        changeText(line, input.zamena, input.razdel);
    }
}
