class Solution {
public:
    long long minimumSteps(const string &s) {
        

        int num1 = 0;
        long long sum = 0;
        for(int i = 0; i  < s.size(); i++){
            if(s[i] == '1'){
                num1++;
            } else {
                sum += num1;
            }
        }
        return sum;

    }
};