class Solution {
private: 
    int total;
public:
    int minNumberOperations(vector<int>& target) {
        for(int i = 0; i < target.size(); i++){
            if(i == 0 || target[i] > target[i - 1]){
                if(i == 0){
                    total += target[i];
                } else {
                    total += target[i] - target[i - 1];
                }
            }
        }        
        return total;
    }
    




};