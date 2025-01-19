class Solution {
public:
    string removeKdigits(string num, int k) {
        std::deque<char> dq;

        int removals = 0;
        for(const char c : num){
            while(!dq.empty() && dq.back() > c){
                if(removals >= k){
                    break;
                }
                dq.pop_back();
                removals++;
            }
            dq.push_back(c);
        }


        while(removals < k){
            removals++;
            dq.pop_back();
        }



        string ans = "0";
        while(!dq.empty()){
            ans += dq.front();
            dq.pop_front();
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};