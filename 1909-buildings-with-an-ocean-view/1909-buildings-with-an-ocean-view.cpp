class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {

        vector<int> largestAfter(heights.size());
        largestAfter[heights.size() - 1] = INT_MIN;
        int largest = INT_MIN;
        for(int i = heights.size() - 1; i>=1 ; i--){
            largest = max(largest, heights[i]);
            largestAfter[i - 1] = largest;
        }  

        vector<int> res;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] > largestAfter[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};