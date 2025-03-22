class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {

        int largest = INT_MIN;
        vector<int> res;
        res.push_back(heights.size() - 1);
        for(int i = heights.size() - 1; i>=1 ; i--){
            largest = max(largest, heights[i]);
            if(heights[i - 1] > largest){
                res.push_back(i - 1);
            }
        }  
        reverse(res.begin(), res.end());
        return res;
    }
};