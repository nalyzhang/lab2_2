#ifndef LAB2_2_STRL_H
#define LAB2_2_STRL_H
#include "words.h"

class StrL {
private:
    char* strArray;
    int length;

public:
    explicit StrL(const char* text = " ", const int size = 1) {
        this->strArray = new char[size];
        for (int i = 0; i < size; i++) this->strArray[i] = text[i];
        this->setSize(size);
    }

    ~StrL() {
        delete[] this->strArray;
    }

    void setArray(const char* str, int len);

    int getSize();

    char getChar(int i);

    void setSize(int size);

    char *getArray();

    Word formWord();

    Word *breakIntoWords();
};

#endif
