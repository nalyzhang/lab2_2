#ifndef LAB2_2_WORDS_H
#define LAB2_2_WORDS_H


class Word {
private:
    char* word;
    int count{};
    int length{};
public:

    explicit Word(const char *text = " ", int size = 1){
        this->word = new char[size];
        for (int i = 0; i < size; i++) this->word[i] = text[i];
        this->setCount(size);
    }

    ~Word() {
        delete[] this->word;
    }

    char **getWord() const;

    void setWord(const char *word, int n);

    int getCount();

    void setCount(int count);

    bool equal(Word w);

    void setWordA(char* w, int i);

    int getLength() const;

    void setLength(int length);

    void newWord(int n);
};


#endif
