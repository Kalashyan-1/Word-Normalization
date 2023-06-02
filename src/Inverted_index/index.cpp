#include "index.hpp"

int Index::Element::cc = 0;

Index::Index(std::initializer_list<Text> texts) : table(500)
{   
    for (auto it = texts.begin(); it != texts.end(); ++it) {
        for (auto text : it->getText()) {
            if (table[hash(text.getWord())].empty())  {
                table[hash(text.getWord())].insert(Element(it->getfileId(), text.getWord()));
            } else {
                if (!table[hash(text.getWord())].find(Element(text.getWord()))) {
                  table[hash(text.getWord())].insert(Element(it->getfileId(), text.getWord()));
                } else {
                    Element el(text.getWord());
                    Element elem = table[hash(text.getWord())].getData(el);
                    bool b = false;
                    for ( auto a : elem.fileNames) {
                        if (a != it->getfileId()) {
                            b = true;
                            break;
                        }
                    }
                    if (b) {
                        elem.fileNames.push_back( it->getfileId());
                        table[hash(text.getWord())].modeify(elem);
                    }
                }
            }
        }
    }
}

BST<Index::Element>& Index::operator[](std::string word) {
    return table[hash(word)];
}

int Index::hash(std::string word) {
    int res = 5612;
    for (int i = 0; i < word.size(); ++i) {
        res = (((res << 5) + res) + static_cast<unsigned char>(word[i])) % table.capacity();
    }
    return res;
}

void Index::print() {
    for (auto a: table)  {
        if (a.empty()) {
            std::cout << "empty" << std::endl;
        } else {
            a.levelorder() ;
        }
    }
}