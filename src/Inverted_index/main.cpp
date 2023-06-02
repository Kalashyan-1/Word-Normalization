#include "index.hpp"

int main() {
    Text text1("1.txt");
    Text text2("2.txt");
    Index index({text1, text2});
    index.print();
}