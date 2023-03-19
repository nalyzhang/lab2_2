#include "words.h"


char **Word::getWord() const {
    return reinterpret_cast<char **>(this->word);
}

void Word::setWord(const char *w, const int n) {
    if (n > 0 && n <= this->getCount()) {
        delete this->word;
        this->word = new char[n];
        for (int i = 0; i < n; i++) this->word[i] = w[i];
    }
}

void Word::setWordA(char *w, int i) {
    this->word[i] = *w;
}

int Word::getCount(){
    return this->count;
}

void Word::newWord(int n) {
    delete this->word;
    this->word = new char[n];
}

void Word::setCount(int c) {
    this->count = c;
}


bool Word::equal(Word w){
    int a = 0;
    if (this->getCount() == w.getCount()) {
        for (int i = 0; i < this->getCount(); i++) if (this->getWord()[i] == w.getWord()[i]) a++;
    }
    if (a == w.getCount()) return true;
    else return false;
}

int Word::getLength() const {
    return length;
}

void Word::setLength(int l) {
    Word::length = l;
}
