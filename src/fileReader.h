#ifndef READER_
#define READER_
#include "textConvertor.h"

class FileReader {
private:
    TextConvertor* convertor;
public:
    FileReader(TextConvertor* conv) : convertor{conv} {}
    TextConvertor* getCnvertor() const {return convertor;}
};


#endif