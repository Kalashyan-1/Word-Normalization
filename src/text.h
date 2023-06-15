#ifndef TEXT_
#define TEXT_

#include "textConvertor.h"

class Text : public TextConvertor
{
public:
    Text(const std::string& fileName);
    Text() = default;

    void convert(const std::string& str) override;
};

#endif //TEXT_