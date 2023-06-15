#include "pdfConvert.h"

PdfConvert::PdfConvert(const std::string& str) {
    convert(str);
}

std::string PdfConvert::readTextFromPDF(const std::string& filePath) {
  std::string fileNmae = "output.txt";
  std::ofstream outfile(fileNmae);
  try {
    poppler::document* pdfDocument = poppler::document::load_from_file(filePath);
    if (!pdfDocument || pdfDocument->is_locked()) {
      throw std::invalid_argument("Error: Failed to open or load the PDF file.");
      return fileNmae;
    }

    int numPages = pdfDocument->pages();

    for (int i = 0; i < numPages; ++i) {
      poppler::page* pdfPage = pdfDocument->create_page(i);
      poppler::page_renderer pdfRenderer;
      poppler::byte_array pageTextBytes = pdfPage->text().to_utf8();
      std::string pageText(pageTextBytes.begin(), pageTextBytes.end());
      outfile << pageText << std::endl;
    //   text += pageText;
    }

    delete pdfDocument;
  } catch (std::exception& ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
  }
  outfile.close();
  return fileNmae;
}

void PdfConvert::convert(const std::string& str) {
    
    std::string check(str.end() - 4, str.end());
    std::cout << check;
    if (check != ".pdf") {throw std::invalid_argument("Given file must be in .pdf format");}

    std::string filePath = readTextFromPDF(str);

    std::stringstream s(str);
    s >> fileId;
    std::ifstream file(filePath);
    if (!file.is_open()) {throw "can not open file";}
    std::string tmp;
    std::string word;
    while (std::getline(file, tmp)) {
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == '-') {
                tmp[i] = ' ';
            }
        }
        std::stringstream ss(tmp);
        while(std::getline(ss, word, ' ')) {
         std::stringstream ss2(word);
            Word w(word);
            if (w.getWord().empty()) {
                continue;
            }
            text.insert(w);
        }
    }
    std::remove(filePath.c_str()); 
}