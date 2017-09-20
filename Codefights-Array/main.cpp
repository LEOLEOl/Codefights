#include <iostream>
#include <vector>
#include <map>
#include <cstdio>

using namespace std;

long stol(const string& str) {
    long ret;
    sscanf(str.c_str(), "%ld", &ret);
    return ret;
}

long toInt(string str, const map<char, char>& mSolution) {
    string r;
    for (char s : str)
        r += mSolution.at(s);
    return stol(r);
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    map<char, char> m;
    for (const auto& s : solution) m[s[0]] = s[1];

    for (int i = 0; i < crypt.size(); ++i)
        if (crypt[i].size() > 1 && m[crypt[i][0]] == '0') return false;

    return toInt(crypt[0], m) + toInt(crypt[1], m) == toInt(crypt[2], m);
}

bool isCryptSolution2(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    char map[26] = {'\0'};

    for (auto &v: solution) map[v[0] - 'A'] = v[1];

    for (string &s : crypt)
        for (char &c : s)
            c = map[c - 'A'];

    return (crypt[0][0] != '0' || crypt[0].size() == 1) && (crypt[1][0] != '0' || crypt[1].size() == 1) &&
           (crypt[2][0] != '0' || crypt[2].size() == 1) &&
           stol(crypt[0]) + stol(crypt[1]) == stol(crypt[2]);
}

int main() {
    bool b = isCryptSolution2({"SEND", "MORE", "MONEY"},
                             {{'O', '0'},
                              {'M', '1'},
                              {'Y', '2'},
                              {'E', '5'},
                              {'N', '6'},
                              {'D', '7'},
                              {'R', '8'},
                              {'S', '9'}}
    );
    return 0;
}