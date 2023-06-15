#ifndef CONV_
#define CONV_
#include <unordered_set>
#include <sstream>
#include "word.h"
#include <algorithm>

class TextConvertor
{
protected:
    std::unordered_set<Word, WordHash> text;
    int fileId;
public:
    TextConvertor() = default;
    TextConvertor(const std::string& str) {convert(str);} 
    virtual void convert(const std::string& str) = 0;
    std::unordered_set<Word, WordHash> getText() const {return text;};
    int getfileId() const {return fileId;}
};

#endif