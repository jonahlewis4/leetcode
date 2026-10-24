class Solution {
    class Trie{
    public:
        bool isEnd=false;
        array<Trie*, 26> children{};
        Trie(){}

        void insert(const string& s){
            return insert(s, 0);
        }

        void insert(const string& s, int i){
            if(i >= s.size()){
                isEnd=true;
                return;
            }

            char c = s[i];
            int idx = c - 'a';
            if(!children[idx]){
                children[idx] = new Trie();
            }
            children[idx]->insert(s, i+1);
        }

        string firstPrefix(const string& s){
            string res;
            firstPrefix(s, res, 0);
            return res;
        }

        void firstPrefix(const string& s, string& res, int i) {
            if(i >= s.size()) {
                return;
            }

            if(isEnd){
                return;
            }

            char c = s[i];
            int idx = c - 'a';
            if(!children[idx]){
                res=s;
                return;
            }
            
            res += c;
            children[idx]->firstPrefix(s, res, i + 1);
        }   
        ~Trie() {
            for(Trie* const child : children) {
                delete child;
            }
        }
    };

    class Parser{
        const string& s;
        int i = 0;
    public:
        Parser(const string& s) : s(s){}
        int hasNext() const {
            return i < s.size();
        }
        string getNext() {
            int delim = s.find(' ', i);
            int oldI = i;

            if(delim == string::npos){
                i = s.size();
                return s.substr(oldI);
            }

            i = delim + 1;
            return s.substr(oldI, delim - oldI);
        }
    };
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        Parser p(sentence);
        for(const string& s : dictionary) {
            t.insert(s);
        }  

        string res;
        while(p.hasNext()) {
            const string& s = p.getNext();
            res += t.firstPrefix(s);
            res.push_back(' ');
        }

        res.pop_back();
        return res;
    }
};