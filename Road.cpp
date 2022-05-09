//
// Created by Dvir on 14/12/2021.
//

#include "Road.h"

Road &Road::operator++() {
    double k = this->tox / this->len;
    this->totalTox = this->totalTox + k;
    return *this;
}

Road Road::operator++(int) {
    Road temp = *this;
    double k = this->tox / this->len;
    this->totalTox = this->totalTox + k;
    return temp;
}
