#include "dataBase.h"

int main() {
    Text text1("1.txt");
    Text text2("2.txt");
    DataBase db({text1, text2}, "db.txt");
}