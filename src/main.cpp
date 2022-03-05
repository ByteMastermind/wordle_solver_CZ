#include <iostream>
#include "Dictionary.h"
#include "Interface.h"

int main () {
    // TODO: try catch
    Dictionary dictionary("../data/syn2015_word_abc_utf8.tsv");
    Interface interface;
    while (1) {
        dictionary.find(interface.find());
    }

    return 0;
}