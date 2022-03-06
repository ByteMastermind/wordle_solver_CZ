//
// Created by michal on 05.03.22.
//

#include "Dictionary.h"

Dictionary::Dictionary(const std::string filePath) : filePath(filePath) {
    loadDictionary(filePath);
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
    for (const auto & w : dictionary) {
        wordCompare(0, 0, 0, w, searched.word, possible);
    }
    std::vector<std::string> possible_2;
    if (!searched.chars.empty()) {
        for (const auto &w: possible) {
            contain(w, searched.chars, possible_2);
        }
    }
    if (!searched.Nchars.empty()) {
        if (searched.chars.empty()) {
            possible_2 = possible;
        }
        possible.clear();
        for (const auto &w: possible_2) {
            Ncontain(w, searched.Nchars, possible);
        }
    }
    if (searched.Nchars.empty() && !searched.chars.empty()) {
        possible = possible_2;
    }

    std::cout << "Results:\n" << std::endl;
    for (const auto & def : possible) {
        std::cout << def << std::endl;
    }
    std::cout << '\n' << "Total: " << possible.size() << std::endl;
    std::cout << "*********************************************************" << std::endl;


}

void Dictionary::wordCompare(int index, int indexDic, int c, const std::string &w, const std::string word, std::vector<std::string> & possible) const {
    if ((w[indexDic] != word[index] || (w[indexDic] == word[index] && (word[index] & 0xc0) == 0xc0 && w[indexDic + 1] != word[index + 1])) && word[index] != '?')
        return;

    if (c == charCount(w) - 1) {
        possible.push_back(w);
        return;
    }

    if ((w[indexDic] & 0xc0) == 0xc0 && (word[index] & 0xc0) == 0xc0)
        wordCompare(index + 2, indexDic + 2, c + 1, w, word, possible);

    if ((w[indexDic] & 0xc0) == 0xc0 && (word[index] & 0x80) == 0)
        wordCompare(index + 1, indexDic + 2, c + 1, w , word, possible);

    if ((w[indexDic] & 0x80) == 0 && (word[index] & 0x80) == 0)
        wordCompare(index + 1, indexDic + 1, c + 1,  w, word, possible);

}

void Dictionary::contain(const std::string & w, const std::vector<std::string> & chars,
                          std::vector<std::string> & possible) const {

    for (auto c : chars) {
        bool contains = false;
        unsigned i = 0;
        while (i < w.length()) {
            if ((w[i] & 0x80) == 0) {
                if (c[0] == w[i]) {
                    contains = true;
                    break;
                }
                i++;
            }
            if ((w[i] & 0xc0) == 0xc0) {
                if (c[0] == w[i] && c[1] == w[i + 1]) {
                    contains = true;
                    break;
                }
                i += 2;
            }
        }
        if (!contains)
            return;
    }
    possible.push_back(w);

}

void Dictionary::loadDictionary(const std::string filePath) {
    this->filePath = filePath;
    std::ifstream file(filePath);
    if (!file.is_open())
        throw std::invalid_argument("Error: Dictionary file could not be opened.\n");

    std::string line;
    while (getline(file, line)) {
        std::string word;
        std::istringstream w(line);
        w >> word;

        if (charCount(word) != 5)
            continue;

        dictionary.push_back(word);
    }

    file.close();
}

void Dictionary::Ncontain(const std::string &w, const std::vector<std::string> &chars,
                          std::vector<std::string> & possible) const {

    for (auto c : chars) {
        bool contains = false;
        unsigned i = 0;
        while (i < w.length()) {
            if ((w[i] & 0x80) == 0) {
                if (c[0] == w[i]) {
                    contains = true;
                    break;
                }
                i++;
            }
            if ((w[i] & 0xc0) == 0xc0) {
                if (c[0] == w[i] && c[1] == w[i + 1]) {
                    contains = true;
                    break;
                }
                i += 2;
            }
        }
        if (contains)
            return;
    }
    possible.push_back(w);

}
