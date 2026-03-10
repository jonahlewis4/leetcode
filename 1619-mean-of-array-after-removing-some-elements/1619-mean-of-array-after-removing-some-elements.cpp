class Solution {
public:
    double trimMean(vector<int>& arr) {
        int sum = 0;
        sort(arr.begin(), arr.end());
        int fivePercent = arr.size() / 20;

        for(int i = fivePercent; i < arr.size() - fivePercent; i++) {
            sum += arr[i];
        }

        return (double)sum / (arr.size() - fivePercent * 2);
        
    }
};