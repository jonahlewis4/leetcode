class Solution {
public:
    int ladderLength(const string &beginWord, const string &endWord, vector<string>& wordList) {
        unordered_map<string, int> dict;
        wordList.push_back(beginWord);

        for(int i = 0; i < wordList.size(); i++){
            dict[wordList[i]] = i;
        }
        if(dict.find(endWord) == dict.end()){
            return 0;
        }
        int i = 1;
        int goalI = dict[endWord];
        queue<int> q;
        q.push(dict[beginWord]);

        int length = 1;

        while(!q.empty()){
            int n = q.size(); 
            for(int i = 0; i < n; i++){
                int idx = q.front();
                q.pop();
                if(idx == goalI){
                    return length;
                }

                string s = wordList[idx];
                for(int i = 0; i < s.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        char old = s[i];
                        s[i] = c;
                        if(dict.find(s) == dict.end() || dict[s] == -1){
                            s[i] = old;
                            continue;
                        }
                        q.push(dict[s]);
                        dict[s] = -1;
                        s[i] = old;
                    }
                }
            }
            length++;
        }

        return 0;
        
    }
};