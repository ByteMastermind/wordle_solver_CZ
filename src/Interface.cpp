//
// Created by michal on 05.03.22.
//

#include "Interface.h"

Dictionary::Searched Interface::find() const {
    std::cout << "Enter the searched word." << std::endl << "Write fixed known characters and unknown replace with '?'." << std::endl;
    std::cout << "Example: " << "'ko?ka' " << "for 'kočka'." << std::endl;
    std::cout << "Then enter known characters with space between them." << std::endl;
    std::cout << "'q' for quit." << '\n' << std::endl;

    std::string line;
    getline(std::cin, line);
    std::istringstream iss (line);
    std::string word;
    iss >> word;
    if (word[0] == 'q' && word.length() == 1) {
        exit(0);
    }
    if (Dictionary::charCount(word) != 5)
        throw std::invalid_argument("Error: Word must contain 5 characters.\n");

    std::string character;
    Dictionary::Searched searched;
    while (iss >> character) {
        if (character.length() > 2 || (character.length() == 2 && (character[0] & 0x80) == 0))
            throw std::invalid_argument("Error: Put empty spaces between the characters that the word contains.\n");
        searched.chars.push_back(character);
    }
    searched.word = word;
    return searched;
}

