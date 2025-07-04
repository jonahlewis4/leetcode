class Solution {
private:   
    std::vector<string> ans;
    string s;
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        string cur = "";
        add(0, cur, 0, 0);
        return ans;
    }
    void add(int i, string cur, int curNum, int count){
        if(i > s.size()) {
            return;
        }
        
        if(i == s.size() && count == 4) {
            cur.pop_back();
            ans.push_back(cur);
            return;
        }
        if(count >= 4) {
            return;
        }

        int digit = s[i] - '0';
        if(curNum == 0 && digit == 0) {
            add(i + 1, cur + "0.", 0, count + 1);
            return;
        }
        curNum *= 10;
        curNum += digit;
        if(curNum > 255) {
            return;
        }
        add(i + 1, cur + to_string(curNum) + '.', 0, count + 1);
        add(i + 1, cur, curNum, count);
    }
};