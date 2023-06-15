# Word Normalization Program

This program performs word normalization by reading words from .txt and .pdf files and normalizing them according to a word_alph.txt file. The normalized words are then stored in a db.txt file.

## Description

The Word Normalization Program is designed to process text files and normalize the words found within them. It utilizes the following files:

- `word_alph.txt`: This file contains the normalization rules for words. Each line in the file consists of a word and its normalized form.


- `1.txt`, `2.txt` and `3.pdf`: These files are the input files from which words are read for normalization.

- `db.txt`: This file stores the normalized words and their corresponding file references. The format of each line in the file is as follows: word:1,2,3


where `normalized_word` is the normalized form of a `word`, and `1`, `2`, etc., are the names of the files that contain the word.

## Usage

1. Make sure you have the following files in the program directory:
 - `word_alph.txt`: Contains the normalization rules for words.
 - `input.txt` and `input.pdf`: Input files that contain the words to be normalized.
 - `db.txt`: The output file that will store the normalized words and their file references.

2. Run the program by executing the `word_normalization.exe` file (or compile and run the `word_normalization.cpp` source code if using a compiler).

3. The program will read the words from `input.txt` and `input.pdf` files, normalize them according to the rules in `word_alph.txt`, and store the normalized words in the `db.txt` file.

4. Open the `db.txt` file to view the normalized words and their corresponding file references.

