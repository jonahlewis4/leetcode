class Solution {
public:
    string alienOrder(vector<string>& words) {
        //topological sort.

        unordered_map<char, unordered_set<char>> after;
        unordered_map<char, int> indegree;
        for(const auto & word : words){
            for(const auto & c : word){
                indegree[c] = 0;
            }
        }
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                //find first letter they differ by. 
                int smallWordI = 0;
                int bigWordI = 0;
                const string &smallWord = words[i];
                const string &bigWord = words[j];
                if(smallWord == bigWord){
                    continue;
                }
                while(smallWordI < smallWord.size() && bigWordI < bigWord.size() 
                    && smallWord[smallWordI] == bigWord[bigWordI]){
                    smallWordI++;
                    bigWordI++;
                }
                if(smallWordI >= smallWord.size()){
                    //if we reach the end of the first word but find no differences, continue
                    continue;
                } else if (bigWordI < bigWord.size()){
                    //add edge
                    char beforeChar = smallWord[smallWordI];
                    char afterChar = bigWord[bigWordI];
                    if(after[beforeChar].find(afterChar) == after[beforeChar].end()){
                        indegree[afterChar]++;
                    }                    
                    after[beforeChar].insert(afterChar);
                    if(after[afterChar].find(beforeChar) != after[afterChar].end()){
                        return "";
                    }
        
                } 
                else {
                    //otherwise the second word is a prefix of the first which is not valid lexicographically.
                    return "";
                }
            }
        }
        

        string res = "";
        queue<char> q;
        for(const auto & cInd : indegree) {
            auto [c, in] = cInd;
            if(in == 0){
                q.push(c);
            }
        }

        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                char c = q.front();
                q.pop();
                res.push_back(c);
                for(char nextC : after[c]){
                    int& in = indegree[nextC];
                    in--;
                    if(in == 0){
                        q.push(nextC);
                    }
                    
                }
            }
        }

        return res;
    }
};