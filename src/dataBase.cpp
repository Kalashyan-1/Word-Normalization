#include "dataBase.h"

DataBase::DataBase(std::initializer_list<FileReader> texts, const std::string& fileName) 
    : DBFileName {fileName}
{
    for (auto it = texts.begin(); it != texts.end(); ++it) {
        for (auto text : it->getCnvertor()->getText()) {
            dataBase[text.getWord()].push_back(it->getCnvertor()->getfileId());
        }
    }
    std::ofstream file(DBFileName);
    for (auto pair : dataBase) {
        file << pair.first << ':' << ' ';
        for (const auto& fileIndex : pair.second) {
            file << fileIndex << ',';
        }
        file.seekp(-1, std::ios_base::end);
        file << '\n';
    }
}

DataBase::~DataBase()
{
}
