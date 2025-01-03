class Codec {
    #define delim '$'
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(const auto & str : strs){
            res += to_string(str.size());
            res += delim;
            res += str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i++){
            string newString = "";

            int j = i;
            string len = "";
            while(s[j] != delim){
                len += s[j];
                j++;
            }
            int length = stoi(len);
            for(int k = j + 1; k < (j + 1) + length; k++){
                newString += s[k];
            }
            ans.push_back(newString);
            i = j + 1 + length - 1;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));