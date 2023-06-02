#ifndef INDEX_
#define INDEX_

#include <vector>
#include <initializer_list>
#include "/home/khachik/Word-Normalization/src/text.h"
#include "/home/khachik/Word-Normalization/src/Inverted_index/BST/src/bst.hpp"

class Index
{
private:
    struct Element {
        static int cc;
        int id;
        std::string word;
        std::vector<int> fileNames;
        bool operator!=(const Element& el) {return word != el.word;}
        bool operator<(const Element& el) {return cc < id;}
        bool operator>(const Element& el) {return cc > id;}
        bool operator==(const Element& el) {return word == el.word;}
        Element(int file, const std::string& w) : word{w} {fileNames.push_back(file);id = cc; ++cc;}
        Element(const std::string& w)  : word{w} {id = cc; ++cc;}
        friend std::ostream& operator<<(std::ostream& stream, const Element& el) {
            stream << el.word << ": ";
            for (auto a: el.fileNames) {
                stream << a << " ";
            }
            return stream;
        }
    };
    std::vector<BST<Element>> table;
public:
    Index(std::initializer_list<Text>);
    ~Index() = default;
    int hash(std::string word);
    BST<Element>& operator[](std::string word);
    void print();
};

#endif //INDEX_
