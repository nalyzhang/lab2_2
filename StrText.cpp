#include "StrText.h"

StrL** StrText::getTextArray() {
    return this->textArray;
}

int StrText::getL() {
    return this->L;
}

void StrText::setL(int l) {
    this->L = l;
}

void StrText::setItem(StrL* str, const int i) {
    if (i >= 0 && i < this->getL()) {
        delete this->textArray[i];
        this->textArray[i] = new StrL;
        this->textArray[i]->setArray(str->getArray(), str->getSize());
    }
}