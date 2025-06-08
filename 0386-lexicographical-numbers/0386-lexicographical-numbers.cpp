class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.push_back(1);

        for(int i = 0; i < n - 1; i++) {
            int tenX = ans.back() * 10;
            if(tenX <= n) {
                ans.push_back(tenX);
                continue;
            } 

            int inc = ans.back() + 1;
            if(inc % 10 != 0 && inc <= n){
                ans.push_back(inc);
                continue;
            }

            int base = ans.back() / 10  + 1;
            while(base % 10 == 0){
                base /= 10;
            }
            if(base <= n){
                ans.push_back(base);
                continue;
            }
        }
        return ans;
    }
};