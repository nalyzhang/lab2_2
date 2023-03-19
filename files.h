#ifndef LAB2_2_FILES_H
#define LAB2_2_FILES_H
#include <fstream>
#include <iostream>
#include "StrText.h"
#include "StrL.h"
#include "words.h"

class files {

public:

    std::ifstream inL;
    std::ifstream newWord;
    std::ifstream oldWord;
    std::ofstream out;

    int largest();

    explicit files(const char in[] = "inL.txt", const char ouT[] = "out.txt", const char nw[] = "new word.txt", const char ow[] = "old word.txt") {
        this->inL.open(in);
        this->out.open(ouT);
        this->newWord.open(nw);
        this->oldWord.open(ow);
    }

    ~files() {
        this->inL.close();
        this->out.close();
        this->newWord.close();
        this->oldWord.close();
    }

    StrText readIn();

    StrL readNew();

    StrL readOld();

    void result();

    int Count();

};


#endif
