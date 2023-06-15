#include "dataBase.h"
#include "pdfConvert.h"
#include "fileReader.h"
int main() {
    PdfConvert conv("3.pdf");
    Text text1("1.txt");
    Text text2("2.txt");
    FileReader reader1(&conv);
    FileReader reader2(&text1);
    FileReader reader3(&text2);
    DataBase db({reader1, reader2, reader3}, "db.txt");
}