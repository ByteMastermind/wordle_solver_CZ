//
// Created by michal on 05.03.22.
//

#ifndef WORDLE_SOLVER_DICTIONARY_H
#define WORDLE_SOLVER_DICTIONARY_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class Dictionary {
public:
    struct Searched {
        std::string word;
        std::vector<std::string> chars;
    };

    explicit Dictionary(std::string filePath);
    void printAll() const;
    int size() const;
    void find(Searched word) const;
    static int charCount(std::string word);

private:
    std::string filePath;
    std::vector<std::string> dictionary;

    bool wordCompare(int index, int indexDic, const std::string & w, std::string word, std::vector<std::string> & possible) const;
};


#endif //WORDLE_SOLVER_DICTIONARY_H
