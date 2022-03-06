#include <iostream>
#include "Dictionary.h"
#include "Interface.h"

int main () {
    Dictionary dictionary;
    try {
        dictionary.loadDictionary("../data/syn2015_word_abc_utf8.tsv");
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    Interface interface;
    while (1) {
        try {
            dictionary.find(interface.find());
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}