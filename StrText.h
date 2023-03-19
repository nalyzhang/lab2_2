#ifndef LAB2_2_STRTEXT_H
#define LAB2_2_STRTEXT_H
#include "StrL.h"

class StrText {
private:
    StrL* *textArray;
    int L;

public:

    explicit StrText(int n) {
        this->textArray = new StrL* [n];
        for (int i = 0; i < n; ++i) this->textArray[i] = new StrL;
        this->setL(n);
    }

    ~StrText() {
        for (int i = 0; i < this->L; ++i) delete this->textArray[i];
        delete[] this->textArray;
    }

    StrL** getTextArray();

    int getL();

    void setL(int l);

    void setItem(StrL* str, const int i);
};

#endif