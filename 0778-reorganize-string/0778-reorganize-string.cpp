class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> letters;
        for(const char c : s){
            letters[c]++;
        }


        priority_queue<pair<int, char>> pq;
        for(const auto & p : letters){
            pq.push({p.second, p.first});
        }

        char prev = '\0';

        string res = "";
        while(!pq.empty()){
            pair<int , char> top = pq.top();
            pq.pop();
            if(!pq.empty() && top.second == prev){
                pair<int, char> secondTop = pq.top();
                pq.pop();
                pq.push(top);
                top = secondTop;
            } 

            top.first--;

            if(res.size() > 0 && res.back() == top.second){
                return "";
            }
            res += top.second;


            if(top.first > 0){
                pq.push(top);
            }
            prev = top.second;
        }
        return res;
        

        

    }
    
};