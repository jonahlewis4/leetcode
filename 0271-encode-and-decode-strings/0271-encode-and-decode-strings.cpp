class Codec {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(const auto & str : strs){
            for(const auto & c : str){
                res += encode(c);
            }
            res += "#.";

        }
        return res;
    }

    vector<string> decode(string s) {
        cout<<s<<endl;
        vector<string> res;
        string cur = "";
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c != '#'){
                cur += c;
            } else if(i + 1 < s.size()){
                if(s[i + 1] == '.'){
                    res.push_back(cur);
                    cur = "";
                    i++;
                } else if(s[i + 1] == '#'){
                    cur += c;
                    i++;
                }
            }
        }
        return res;
    }

    string encode(char c){
        if(c != '#'){
            string res;
            res += c;
            return res;
        }
        return "##";
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));