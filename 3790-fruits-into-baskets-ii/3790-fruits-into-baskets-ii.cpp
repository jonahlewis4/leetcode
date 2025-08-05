class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int unplaced = 0;
        for(auto fruit : fruits) {
            for(auto & basket : baskets) {
                if(fruit <= basket) {
                    basket = -1;
                    fruit = -1;
                    break;
                }
            }
            if(fruit != -1){
                unplaced++;
            }
        }
        return unplaced;
    }
};