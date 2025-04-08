class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> dict;

        for(const auto & s : wordList){
            dict[s] = true;
        }
        dict[beginWord] = true;

        if(dict.find(endWord) == dict.end()){
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int length = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string s = q.front();
                q.pop();
                if(s == endWord){
                    return length;
                }
                dict[s] = false;
                for(int i = 0; i < s.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        char oldC = s[i];
                        s[i] = c;
                        if(dict.find(s) != dict.end() && dict[s] == true){
                            q.push(s);
                        }
                        s[i] = oldC;
                    }
                }
            }
            length++;
        }    



        return 0;
    }
};