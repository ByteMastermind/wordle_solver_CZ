//
// Created by michal on 05.03.22.
//

#ifndef WORDLE_SOLVER_INTERFACE_H
#define WORDLE_SOLVER_INTERFACE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Dictionary.h"

class Interface {
public:
    Dictionary::Searched find() const;
};


#endif //WORDLE_SOLVER_INTERFACE_H
