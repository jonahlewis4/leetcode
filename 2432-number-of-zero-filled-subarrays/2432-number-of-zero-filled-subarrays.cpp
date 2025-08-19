class Solution {
    static long long combinate(long long streak) {
        return (streak * (streak + 1)) / 2;
    }
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int streak = 0;
        for(const auto & num : nums) {
            if(num == 0) {
                streak++;
            } else {
                ans += combinate(streak);
                streak = 0;
            }
        }
        ans += combinate(streak);
        return ans;
    }
};

// 1 -> 1
// 2 -> 3
// 3 -> 6
//