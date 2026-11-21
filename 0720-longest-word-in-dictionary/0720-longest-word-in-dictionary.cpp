class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> dict;
        stack<string> s;

        string longest = "";
        for(const string& word : words) {
            dict.insert(word);
        }


        s.push("");
        while(!s.empty()) {
            string top = s.top();
            s.pop();
            if(top.size() > longest.size()) {
                longest = top;
            }
            if(top.size() == longest.size()) {
                longest = min(top, longest);
            }

            for(char c = 'a'; c <= 'z'; c++){
                top += c;
                if(dict.contains(top)) {
                    s.push(top);
                }
                top.pop_back();
            }
        }

        return longest;
    }
};