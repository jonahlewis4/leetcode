class StringIterator {
    int i = 0;
    int numNext = 0;
    char letter;
    string compressedString;
public:
    StringIterator(string compressedString) {
        this->compressedString = compressedString;
        parseNextEncoding();
    }

    void parseNextEncoding() {
        if(!hasNext()) {
            return;
        }

        letter = compressedString[i];
        i++;

        int count = 0;
        while(i < compressedString.size() && isdigit(compressedString[i])){
            count *= 10;
            count += compressedString[i] - '0';
            i++;
        }

        numNext = count;
    }
    
    char next() {
        if(!hasNext()) {
            return ' ';
        }
        char oldLetter = letter;
        numNext--;
        if(numNext == 0) {
            parseNextEncoding();
        }

        return oldLetter;
    }
    
    bool hasNext() {
        return !(numNext == 0 && i == compressedString.size());
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */