#ifndef WORD_
#define WORD_

#include <string>
#include <fstream>
#include <iostream>
#include <functional>

class Word {
private:
    std::string word;
    std::string normalise(std::string& str);
public:
    Word(std::string& str);
    Word() = default;
    ~Word() = default;
    friend std::ostream& operator<<(std::ostream& stream, const Word& w);
    std::string getWord() const {return word;}
    friend bool operator==(const Word& lhs, const Word& rhs);
};

struct WordHash {
    std::size_t operator()(const Word& w) const {
        return std::hash<std::string>()(w.getWord());
    }
};

#endif // WORD_