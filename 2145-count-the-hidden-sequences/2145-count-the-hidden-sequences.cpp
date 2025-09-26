class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini = 0;
        long long maxi = 0;
        long long sum = 0;
        for(const int i : differences){
            sum += i;
            mini = min(sum, mini);
            maxi = max(sum, maxi);
        }
        long long delta = maxi - mini;
        return max(upper - (lower + delta) + 1, 0ll);
    }
};