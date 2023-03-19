#include "StrL.h"

void StrL::setSize(const int size) {
    this->length = size;
}

void StrL::setArray(const char* str, const int len) {
    delete[] this->strArray;
    this->strArray = new char[len];
    for (int i = 0; i < len; i++) this->strArray[i] = str[i];
    this->setSize(len);
}

int StrL::getSize() {
    return this->length;
}

char StrL::getChar(int i) {
    if (i >= 0 && i < this->length) return this->strArray[i];
}

char* StrL::getArray() {
    return this->strArray;
}

bool isItPoint(char a){
    switch(a){
        case '\n': return true;
        case ' ': return true;
        case ',': return true;
        case '.': return true;
        case'!': return true;
        case '?': return true;
        default: return false;
    }
}

Word* StrL::breakIntoWords() {
    Word *words;
    words = new Word[this->getSize()];
    char *a;
    a = new char[this->getSize()];
    int j = 0, l = 0;
    for (int i = 0; i < this->getSize(); i++) {
        if (i > 0) {
            if (isItPoint(this->getChar(i))) {
                if ((isItPoint(this->getChar(i))) && (isItPoint(this->getChar(i - 1)))) {
                    a[l++] = this->getChar(i);
                }
                else if ((isItPoint(this->getChar(i))) && !(isItPoint(this->getChar(i - 1)))) {
                    words[j].setCount(l);
                    words[j++].setWord(a,l);
                    delete[] a;
                    a = new char[this->getSize()];
                    l = 0;
                    a[l++] = this->getChar(i);
                }
                else if (!(isItPoint(this->getChar(i))) && !(isItPoint(this->getChar(i - 1)))) {
                    a[l++] = this->getChar(i);
                    l++;
                }
                else {
                    words[j].setCount(l);
                    words[j++].setWord(a,l);
                    delete[] a;
                    a = new char[this->getSize()];
                    l = 0;
                    a[l++] = this->getChar(i);
                }
            }
        }
        else {
            a[l] = this->getChar(i);
        }
    }
    j++;
    for (int i = 0; i < j; i++) words[i].setLength(j);
    return words;
}

Word StrL::formWord(){
    Word word;
    word.setCount(this->getSize());
    for(int i = 0; i < this->getSize(); i++) {
        if (isItPoint(this->getChar(i))) break;
        word.setWordA(reinterpret_cast<char *>(this->getChar(i)), i);
    }
    return word;
}

