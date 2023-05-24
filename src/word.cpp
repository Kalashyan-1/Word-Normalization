#include "word.h"

bool operator==(const Word& lhs, const Word& rhs) {
    return lhs.word == rhs.word;
}


Word::Word(std::string& str) {
    std::string res = "";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] |= 32; 
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            res += str[i];
        }
    }
   word = normalise(res);
}

std::string Word::normalise(std::string& str) {
    std::ifstream file("words_alpha.txt");
    std::string tmp;
    std::string min;
    std::string res = str;
    bool c = false;
    int diff = (tmp.size() > str.size())? tmp.size() : str.size();
    char ch = 0;
    int k = 0;
    while (std::getline(file, tmp)) {
        tmp.pop_back();
        ch = 0;
        if (tmp.size() == str.size()) {
            diff = tmp.size();
            for (int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] == str[i]) {
                    --diff;
                }
            }
            if (diff == 0) {
                res = tmp;
                break;
            }
            if (diff == 1) {
                res = tmp;
            }
        } else if (abs(tmp.size() - str.size()) == 1) {
            bool b = false;
            std::string max = (tmp.size() > str.size())? tmp : str;
            for (int i = 0; i < tmp.size(); ++i) {
                ch ^= tmp[i];
            }

            for (int i = 0; i < str.size(); ++i) {
                ch ^= str[i];
            }
            for (int i = 0; i < max.size(); ++i) {
                if (ch == max[i]) {
                    if (tmp.size() < str.size()) {
                        min = tmp;
                        min.insert(min.begin() + i, ch);
                        if (min == tmp) {
                            res = min;
                            diff = 0;
                            break;
                        }
                    } else if (str.size() < tmp.size()) {
                        min = str;
                        min.insert(min.begin() + i, ch);
                        if (min == str) {
                            res = min;
                            diff = 0;
                            break;
                        }
                    } else {
                       diff = 1;
                       res = tmp;
                    }
                    
                }
            }
        }
        if (diff == 0) {
            min = "";
            break;
        } 
    }
    file.close();
    return res;
}

std::ostream& operator<<(std::ostream& stream, const Word& w) {
    stream << w.word;
    return stream;
}

