class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;
        for(const string& log : logs) {
            if(log == "./"){
                continue;
            }
            if(log == "../"){
                ops = max(0, ops - 1);
                continue;
            } else {
                ops++;
            }
        }
        return ops;
    }
};