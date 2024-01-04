#include <iostream>
#include <cctype>
#include <string>
#include <array>
#include <vector>

using namespace std;

array<int, 26> scoreParDecalage = {};

bool testMot(const string& ch, const vector<string>& motsFrequents) {
    for (const auto& mot : motsFrequents) {
        if (ch == mot) {
            return true;
        }
    }
    return false;
}

bool testTout(const string& mot) {
    static const vector<string> mots2Lettres = {"le", "la", "il", "me", "te", "se", "ma", "si", "je", "on", "de", "un", "du", "ce"};
    static const vector<string> mots3Lettres = {"pas", "son", "mon", "nos", "une"};
    static const vector<string> mots4Lettres = {"elle", "celle", "ceux", "plus", "onze", "quel"};

    switch (mot.length()) {
        case 1: return mot == "a";
        case 2: return testMot(mot, mots2Lettres);
        case 3: return testMot(mot, mots3Lettres);
        case 4: return testMot(mot, mots4Lettres);
        default: return false;
    }
}

string decodageParDecalage(const string& mot, int dec) {
    string result = mot;
    for (char& c : result) {
        if (isalpha(c)) {
            bool isMaj = isupper(c);
            c = tolower(c);
            c = (((c - 'a' + dec + 26) % 26) + 'a');
            if (isMaj) {
                c = toupper(c);
            }
        }
    }
    return result;
}

int meilleurDecalage() {
    int maxVal = -1, meilleurDec = -1;
    for (int i = 0; i < 26; i++) {
        if (scoreParDecalage[i] > maxVal) {
            maxVal = scoreParDecalage[i];
            meilleurDec = i;
        }
    }
    return meilleurDec;
}

int main() {
    string texte, mot;
    getline(cin, texte);

    for (char c : texte) {
        if (isalpha(c)) {
            mot += c;
        } else if (!mot.empty()) {
            for (int dec = 0; dec < 26; dec++) {
                if (testTout(decodageParDecalage(mot, dec))) {
                    scoreParDecalage[dec]++;
                }
            }
            mot.clear();
        }
    }

    string texteDecode = decodageParDecalage(texte, meilleurDecalage());
    cout << texteDecode;

    return 0;
}
