//
// Created by michal on 05.03.22.
//

#include "Dictionary.h"

Dictionary::Dictionary(const std::string filePath) : filePath(filePath) {
    std::ifstream file(filePath);
    if (!file.is_open())
        throw std::invalid_argument("Dictionary file could not be opened.");

    std::string line;
    while (getline(file, line)) {
        std::string word;
        std::istringstream w(line);
        w >> word;
        w >> word;

        if (charCount(word) != 5)
            continue;

        dictionary.push_back(word);
    }

    file.close();
}

void Dictionary::printAll() const {
    for (const auto& word : dictionary) {
        std::cout << word << std::endl;
    }
}

int Dictionary::size() const {
    return dictionary.size();
}

int Dictionary::charCount(const std::string word) {
    int count = 0;
    for (auto character : word) {
        if ((character & 0x80) == 0 || (character & 0xc0) == 0xc0)
            ++count;
    }
    return count;
}

void Dictionary::find(const Searched searched) const {
    std::vector<std::string> possible;
    for (auto w : dictionary) {
        wordCompare(0, 0, w, searched.word, possible);
    }

    for (auto pos : possible) {
        std::cout << pos << std::endl;
    }
    std::cout << '\n' << std::endl;


}

bool Dictionary::wordCompare(int index, int indexDic, const std::string &w, const std::string word, std::vector<std::string> & possible) const {
    if (w[indexDic] != word[index] && word[index] != '?') {
        return false;
    }
    if (index == charCount(w)) {
        possible.push_back(w);
        return true;
    }
    if (wordCompare(index + 1, indexDic + 1, w, word, possible))
        return true;
    if (word[index] == '?')
        wordCompare(index + 1, indexDic + 2, w, word, possible);
    return true;
}
