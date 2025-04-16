class Solution {
public:
    int maxScore(string s) {
        vector<int> leftZero(s.size(), 0);
        vector<int> rightOne(s.size(), 0);
        int zCount = 0;
        for(int i = 0; i < s.size(); i++){
            leftZero[i] = zCount;
            if(s[i] == '0'){
                zCount++;
            }
        }
        int oneCount = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '1'){
                oneCount++;
            }
            rightOne[i] = oneCount;
        }
        int res = 0;
        for(int i = 1; i < s.size(); i++){
            int left0s = leftZero[i];
            int right1s = rightOne[i];
            res = max(left0s + right1s, res);
        }
        return res;

    }
};