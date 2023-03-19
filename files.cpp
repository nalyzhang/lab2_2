#include "files.h"


int files::largest() {
    int count = 0, maxi = 0;
    char tmp;
    if (this->inL.is_open()) {
        this->inL.unsetf(std::ios::skipws);
        while (!(this->inL.eof())) {
            this->inL >> tmp;
            if (tmp == '\n') {
                if (count > maxi) maxi = count;
                count = 0;
            }
            else count++;
        }
    }
    return maxi;
}

int files::Count() {
    int count = 0;
    char a;
    this->inL.unsetf(std::ios::skipws);
    if(this->inL.is_open()) {
        while (!this->inL.eof()){
            this->inL >> a;
            if (a == '\n') count++;
        }
        if (count == 0) count++;
    }
    return count;
}

Word* processing(StrL text, StrL ow, StrL nw) {
    Word* words;
    Word newWord = nw.formWord();
    words = text.breakIntoWords();
    int count = words[0].getLength();
    for (int i = 0; i < count; i++) {
        if (words[i].equal(ow.formWord())) {
            words[i].setCount(newWord.getCount());
            words[i].setWord(reinterpret_cast<const char *>(newWord.getWord()), newWord.getCount());
        }
    }
    return words;
}

StrText files::readIn(){
    files f, f1, f3;
    int l = f.Count(), n = f1.largest();
    StrText text(l);
    StrL ar[l];
    for (int j = 0; j < l; j++) {
        f3.inL.unsetf(std::ios::skipws);
        if (f3.inL.is_open()) {
            char* array;
            array = new char[n];
            char a;
            int i = 0;
            while (true) {
                f3.inL >> a;
                array[i++] = a;
                if ((a == '\n')||(f3.inL.eof()))
                    break;
            }
            ar[j].setSize(i);
            ar[j].setArray(array, i);
            delete[] array;
        } else l = 0;
    }
    text.setL(l);
    for (int i = 0; i < l; i++) text.setItem(&ar[i],i);
    return text;
}

StrL files::readNew() {
    StrL ar;
    int n = this->largest();
    this->newWord.unsetf(std::ios::skipws);
    if (this->newWord.is_open()) {
        char array[n];
        char a;
        int i = 0;
        this->newWord >> array[i++];
        if (!this->newWord.eof()) {
            while (true) {
                this->newWord >> a;
                if ((a == '\n') || this->newWord.eof()) break;
                array[i] = a;
                i++;
            }
        }
        ar.setSize(i);
        ar.setArray(array, i);
    } else ar.setSize(0);
    return ar;
}

StrL files::readOld() {
    StrL ar;
    int n = this->largest();
    this->oldWord.unsetf(std::ios::skipws);
    if (this->oldWord.is_open()) {
        char* array;
        array = new char[n];
        char a;
        int i = 0;
        this->oldWord >> array[i++];
        if (!this->oldWord.eof()) {
            while (true) {
                this->oldWord >> a;
                if ((a == '\n') || this->oldWord.eof()) break;
                array[i] = a;
                i++;
            }
        }
        ar.setSize(i);
        ar.setArray(array, i);
        delete[] array;
    } else ar.setSize(0);
    return ar;
}

void files::result() {
    int n = this->largest();
    StrL nw = this->readNew(), ow = this->readOld();
    StrText text = this->readIn();
    Word word1, word2;
    Word* words;
    word1.setCount(ow.getSize());
    word2.setCount(nw.getSize());
    for (int i = 0; i < ow.getSize(); i++) word1.setWordA(reinterpret_cast<char *>(ow.getChar(i)), i);
    for (int i = 0; i < nw.getSize(); i++) word2.setWordA(reinterpret_cast<char *>(nw.getChar(i)), i);
    if (out.is_open()) {
        out << "Панина Анастасия \n2309 \nИндивидуальное задание №2 \n|\nБыл задан текст: \n";
        for (int i = 0; i < text.getL(); i++) {
            int j = 0;
            while (j < text.getTextArray()[i]->getSize()) {
                out << text.getTextArray()[i]->getChar(j++);
            }
        }
        out << "|\nСлово, которое нужно заменить: \n";
        for (int i = 0; i < ow.getSize(); i++) out << ow.getChar(i);
        out << "\n|\nЗаданное слово:\n";
        for (int i = 0; i < nw.getSize(); i++) out << nw.getChar(i);
        out << "\n|\n Отредактированный текст:\n";
        for (int i = 0; i < text.getL(); i++) {
            words = processing(*text.getTextArray()[i], ow, nw);
            for (int j = 0; j < words[0].getLength(); j++){
                for (int k = 0; k < words[j].getCount(); k++) out << words[j].getWord()[k];
            }
            out << "\n";
        }
    }
}