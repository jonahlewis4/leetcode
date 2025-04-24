class Solution {
public:
    long long minEnd(int n, int x) {
        //strictly increasing array of size n that ands to x.

        //and not monotonic.
        
        //only way

        int found = 1;
        long long num = x;
        while(found < n){
            num++;
            num |= x;
            found++;
        }
        return num;
        
    }
};