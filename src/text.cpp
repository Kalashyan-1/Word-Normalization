#include "text.h"

int Text::getfileId() const {return fileId;}

std::unordered_set<Word, WordHash> Text::getText() const {return text;}

Text::Text(const std::string& str) {
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
