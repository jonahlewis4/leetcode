class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int longestLength = s.size() / k;
        unordered_map<char, int> freq;
        for(const auto & c : s) {
            freq[c]++;
        }
        unordered_set<char> pool;
        for(const auto & c : s) {
            if(freq[c] >= k) {
                pool.insert(c);
            }
        }
        vector<char> sortPool(pool.size());
        {
            int i = 0;
            for(const auto & key : pool){
                sortPool[i] = key;
                i++;
            }
        }

        sort(sortPool.begin(), sortPool.end());

        //bfs all possible strings
        queue<string> q;
        for(int i = sortPool.size() - 1; i >=0; i--) {
            q.push({sortPool[i]});
        }

        string best = "";
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < q.size(); i++) {
                string cur = q.front();
                q.pop();

                if(kRepeating(cur, s, k)){
                    if(cur.size() > best.size()){
                        best = cur;
                    }
                    if(best.size() == longestLength){
                        return best;
                    }
                    if(cur.size() == longestLength){
                        continue;
                    }

                    for(int i = sortPool.size() - 1; i >= 0; i--) {
                        q.push(cur + sortPool[i]);
                    }
                }
            }   
        }

        return best;



        
    }
    bool kRepeating(const string& cur, const string&s, int k) const {
        int curI = 0;
        int sI = 0;
        int repeats = 0;
        while(sI < s.size()){
            if(cur[curI] == s[sI]) {
                curI++;
                if(curI >= cur.size()){
                    repeats++;
                    if(repeats == k) {
                        return true;
                    }
                    curI = 0;
                    
                }
            }
            sI++;
        }
        return repeats >= k;
    }
};