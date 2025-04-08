class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dict;
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++){
            dict[wordList[i]] = i;
        }

        if(dict.find(endWord) == dict.end()){
            return 0;
        }
        int targetIdx = dict[endWord];
        queue<int> q;
        q.push(dict[beginWord]);
        int length = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int idx = q.front();
                q.pop();
                if(idx == targetIdx){
                    return length;
                }
                string s = wordList[idx];
                dict[s] = -1;
                for(int i = 0; i < s.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        char oldC = s[i];
                        s[i] = c;
                        if(dict.find(s) != dict.end() && dict[s] != -1){
                            q.push(dict[s]);
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