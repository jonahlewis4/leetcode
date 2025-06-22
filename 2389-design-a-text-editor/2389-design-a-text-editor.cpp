class TextEditor {
    list<char> list;
    std::list<char>::iterator position;
public:
    TextEditor() {
        position = list.end();
    }
    
    void addText(string text) {
        const auto & _list = list;
        for(const auto &c : text){
            list.insert(position, c);
        }
    }
    
    int deleteText(int k) {
        const auto & _list = list;

        if(list.size() == 0){
            return 0;
        }

        int actuallyDeleted = 0;
        for(int i = 0; i < k; i++) {
            if(position == list.begin()){
                return actuallyDeleted;
            }
            list.erase(prev(position));
            actuallyDeleted++;
        }
        return actuallyDeleted;
    }
    
    string cursorLeft(int k) {
        const auto & _list = list;

        if(list.size() == 0){
            return "";
        }
        for(int i = 0; i < k; i++) {
            if(position == list.begin()){
                break;
            }
            position = prev(position);
        }
        return tenLeft();
    }
    
    string cursorRight(int k) {
        const auto & _list = list;
        for(int i = 0; i < k; i++) {
            if(position == list.end()){
                break;
            }
            position = next(position);
        }
        return tenLeft();
    }

    string tenLeft() const {
        auto itr = position;
        string reversed = "";
        for(int i = 0; i < 10; i++) {
            if(itr == list.begin()){
                reverse(reversed.begin(), reversed.end());
                return reversed;
            }
            itr = prev(itr);
            reversed += *itr;
        }
        reverse(reversed.begin(), reversed.end());
        return reversed;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */