class Solution {
public:
    string reverseStr(string s, int k) {
        int begin = 0;
        for(int kI = 0; kI < s.size();){
            int diff = kI - begin;
            if(diff + 1 == k){
                auto start = s.begin() + begin;
                auto end = start + k;
                reverse(start, end);

                kI = kI + k + 1;
                begin = kI;
            } else {
                kI++;
            }
        }

        reverse(s.begin() + begin, s.end());
        return s;
    }
};