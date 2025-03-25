class Solution {
private: 
public:
    int tupleSameProduct(vector<int>& nums) {
        std::unordered_map<int, int> products;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i == j){
                    continue;
                }
                int num1 = nums[i];
                int num2 = nums[j];
                products[num1 * num2]++;
            }
        }

        int total = 0;
        for(const auto & p : products){
            auto [_, count] = p;
            total += count * (count - 2);
        }

        return total;
    }

};