#ifndef PDF_
#define PDF_

#include </usr/include/poppler/cpp/poppler-document.h>
#include </usr/include/poppler/cpp/poppler-page.h>
#include </usr/include/poppler/cpp/poppler-global.h>
#include </usr/include/poppler/cpp/poppler-page-renderer.h>
#include <regex>

#include "textConvertor.h"

class PdfConvert : public TextConvertor {
private:
    std::string readTextFromPDF(const std::string& filePath);
public:
    PdfConvert(const std::string& str);
    PdfConvert() = default;  
    void convert(const std::string&  str) override;
};
#endif  //PDF_