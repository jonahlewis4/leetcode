class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minDiff = arr[1] - arr[0];

        for(int i = 2; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            minDiff = min(diff, minDiff);
        }

        vector<vector<int>> res;
        for(int i = 1; i < arr.size(); i++){
            int diff = arr[i] - arr[i - 1];
            if(diff == minDiff) {
                res.push_back({arr[i-1], arr[i]});
            }
        }

        return res;
    }
};