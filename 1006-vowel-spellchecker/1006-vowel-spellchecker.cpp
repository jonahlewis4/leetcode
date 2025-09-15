class Solution {
private: 

    static bool isVowel(char c) {
        c = std::tolower(c);
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
        }
        return false;
    }

    unordered_set<string> exactSet;
    unordered_map<string, string> insenMap;
    unordered_map<string, string> vMap;


    void pre(const vector<string>& wordlist) {
        const auto & exact = exactSet;
        const auto & insen = insenMap;
        const auto & v = vMap;
        for(const auto & word : wordlist) {
            exactSet.insert(word);

            string lower = tolower(word);
            if(insenMap.find(lower) == insenMap.end()) {
                insenMap[lower] = word;
            }

            string star = vStar(word);
            if(vMap.find(star) == vMap.end()) {
                vMap[star] = word;
            }
        }

        string x;
    }
    static string tolower(string s) {
        for(char& c: s) {
            c = std::tolower(c);
        }
        return s;
    }
    static string vStar(string s) {
        for(char& c : s) {
            if(isVowel(c)){
                c = '*';
            }
        }
        return tolower(s);
    }


    
    string exactMatch(const string& s) {
        if(exactSet.find(s) != exactSet.end()) {
            return s;
        }
        return "";
    }

    string insenMatch(string s) {
        const auto & exact = exactSet;
        const auto & insen = insenMap;
        const auto & v = vMap;
        s = tolower(s);
        if(insenMap.find(s) != insenMap.end()){
            return insenMap[s];
        }
        return "";
    }

    string vMatch(string s) {
        s = vStar(s);
        const auto & exact = exactSet;
        const auto & insen = insenMap;
        const auto & v = vMap;
        if(vMap.find(s) != vMap.end()) {
            return vMap[s];
        }
        return "";
    }





public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        pre(wordlist);

        vector<string> res(queries.size());

        for(int i = 0; i < queries.size(); i++){
            const string& q = queries[i];

            string exact = exactMatch(q);
            if(exact != "") {
                res[i] = exact;
                continue;
            }

            string insen = insenMatch(q);
            if(insen != "") {
                res[i] = insen;
                continue;
            }

            string vowelReplace = vMatch(q);
            res[i] = vowelReplace;
        }

        return res;
    }
};