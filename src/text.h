#ifndef TEXT_
#define TEXT_

#include <unordered_set>
#include <sstream>
#include "word.h"

class Text
{
public:
    Text(const std::string& fileName);
    Text() = default;
    ~Text() = default;
    std::unordered_set<Word, WordHash> getText() const;
    int getfileId() const;
private:
    std::unordered_set<Word, WordHash> text;
    int fileId;

};

#endif //TEXT_