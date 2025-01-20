// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long badVersion = INT_MAX;
        int bot = 1;
        int top = n;
        while(bot <= top){
            long long mid = ((long long)bot + top) / 2;
            if(isBadVersion(mid)){
                badVersion = min(badVersion, mid);
                top = mid - 1;
            } else {
                bot = mid + 1;
            }
        }
        return badVersion;
    }
};