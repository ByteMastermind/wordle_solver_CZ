//
// Created by michal on 05.03.22.
//

#include "Interface.h"

Dictionary::Searched Interface::find() const {
    Dictionary::Searched searched;
    std::cout << "Enter the searched word." << std::endl << "Write fixed known characters and unknown replace with '?'." << std::endl;
    std::cout << "Example: " << "'ko?ka' " << "for 'kočka'." << std::endl;
    std::cout << "Then enter known characters with space between them." << std::endl;
    std::string word;
    do {
        std::cin >> word;
    } while (Dictionary::charCount(word) != 5);
    std::cout << "Proceeding to find: " << word << '\n' << std::endl;
    std::string line;
    getline(std::cin, line);
    std::istringstream iss (line);
    std::string character;
    while (iss >> character) {
        searched.chars.push_back(character);
    }
    searched.word = word;
    return searched;
}

