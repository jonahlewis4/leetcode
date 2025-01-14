class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> counts;
        for(const char c : s){
            counts[c]++;
        }
        priority_queue<pair<char, int>> pq;
        for(const auto p : counts){
            pq.push({p.first, p.second});
        }

        int repeats = 0;
        char prev = '\0';
        string res = "";
        while(!pq.empty()){
            pair<char, int> top = pq.top();
            pq.pop();
            if(top.first == prev){
                repeats++;
                if(repeats == repeatLimit){
                    if(pq.empty()){
                        break;
                    }
                    pair<char, int> secondTop = pq.top();
                    pq.pop();
                    pq.push(top);
                    top = secondTop;
                    repeats = 0;
                }
            } else {
                repeats = 0;
            }
            res += top.first;
            top.second--;
            if(top.second > 0){
                pq.push(top);
            }
            prev = top.first;
        }
        return res;
    }
};