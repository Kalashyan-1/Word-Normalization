#include "text.h"

Text::Text(const std::string& str) { 
    convert(str);
}

void Text::convert(const std::string& str) {
    std::string check(str.end() - 4, str.end());
    std::cout << check;
    if (check != ".txt") {throw std::invalid_argument("Given file must be in .txt format");}
    std::stringstream s(str);
    s >> fileId;
    std::ifstream file(str);
    if (!file.is_open()) {throw "can not open file";}
    std::string tmp;
    std::string word;
    while (std::getline(file, tmp)) {
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == '-') {
                tmp[i] = ' ';
            }
        }
        std::stringstream ss(tmp);
        while(std::getline(ss, word, ' ')) {
         std::stringstream ss2(word);
            Word w(word);
            if (w.getWord().empty()) {
                continue;
            }
            text.insert(w);
        }
    }
}