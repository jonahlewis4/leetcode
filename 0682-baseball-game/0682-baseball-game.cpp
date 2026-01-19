class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        int sum = 0;
        for(const string& s : operations) {
            if(s.front() == '+') {
                stk.push_back(stk.back() + stk[stk.size() - 2]);
                sum += stk.back();
            } else if (s.front() == 'D') {
                stk.push_back(stk.back() * 2);
                sum += stk.back();
            } else if (s.front() == 'C') {
                sum -= stk.back();
                stk.pop_back();
            } else {
                stk.push_back(stoi(s));
                sum += stk.back();
            }
        }

        return sum;
    }
};