class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxProduct = max(maxProduct, nums[i]);
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            int previousProduct = nums[i];
            for(int j = i - 1; j >= 0; j--){
                int product = nums[j] * previousProduct;
                maxProduct = max(maxProduct, product);
                previousProduct = product;
            }
        }

        return maxProduct;
    }
};