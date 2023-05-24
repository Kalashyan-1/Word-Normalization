#ifndef DATA_BASE_
#define DATA_BASE_

#include "text.h"
#include <unordered_map>
#include <vector>

class DataBase
{
private:
    std::unordered_map<std::string, std::vector<int>> dataBase;
    std::string DBFileName;
public:
    DataBase(std::initializer_list<Text>, const std::string& fileName);
    ~DataBase();
};

#endif  //DATA_BASE_
