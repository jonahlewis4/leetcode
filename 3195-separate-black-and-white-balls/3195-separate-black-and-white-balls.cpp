class Solution {
public:
    long long minimumSteps(const string &s) {
        

        int num0 = 0;
        long long sum = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0'){
                num0++;
            } else {
                sum += num0;
            }
        }
        return sum;

    }
};