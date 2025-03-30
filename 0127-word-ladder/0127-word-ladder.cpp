class Solution {
public:
    int ladderLength(string &beginWord, const string &endWord, vector<string>& wordList) {
        unordered_map<string, int> words;


        int targetI = -1;
        for(int i = 0; i < wordList.size(); i++){
            string & word = wordList[i];
            if(word == endWord){
                targetI = i;
            }
            words[word] = i;
        }
        if(targetI == -1){
            return 0;
        }
        vector<vector<int>> adjList(wordList.size());
        for(int i = 0; i < wordList.size(); i++){
            for(int j = 0; j < wordList[i].size(); j++){
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == wordList[i][j]){
                        continue;
                    }
                    char oldC = wordList[i][j];
                    wordList[i][j] = c;
                    if(words.find(wordList[i]) != words.end()){
                        adjList[i].push_back(words[wordList[i]]);
                    }
                    wordList[i][j] = oldC;
                }
            }
        }        

        queue<int> q;
        for(int j = 0; j < beginWord.size(); j++){
            for(char c = 'a'; c <= 'z'; c++){
                if(c == beginWord[j]){
                    continue;
                }
                char oldC = beginWord[j];
                beginWord[j] = c;
                if(words.find(beginWord) != words.end()){
                    q.push(words[beginWord]);
                }
                beginWord[j] = oldC;
            }
        } 
        int dst = 1;

        vector<bool> visited(wordList.size(), false);
        while(!q.empty()){
            int n = q.size();
            dst++;

            for(int i = 0; i < n; i++){
                int node = q.front();
                q.pop();
                
                visited[node] = true;
                if(node == targetI){
                    return dst;
                }
                for(int neigh : adjList[node]){
                    if(!visited[neigh]){
                        q.push(neigh);
                    }
                }
            }
        }


        return 0;

    }
};