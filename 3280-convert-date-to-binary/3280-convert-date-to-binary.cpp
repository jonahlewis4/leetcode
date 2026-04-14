class Solution {
private:
    static string dec2Bin(const string& date) {
        int num = stoi(date);
        string bin;
        while(num > 0){
            bin += num % 2 + '0';
            num /= 2;
        }

        reverse(bin.begin(), bin.end());
        return bin;
    }
public:
    string convertDateToBinary(const string& date) {
        string cur;
        string res;
        for(const char c : date){
            if(c == '-'){
                res += dec2Bin(cur);
                res += "-";
                cur = "";
                continue;
            }
            cur += c;
        }

        res += dec2Bin(cur);
        return res;
    }
};