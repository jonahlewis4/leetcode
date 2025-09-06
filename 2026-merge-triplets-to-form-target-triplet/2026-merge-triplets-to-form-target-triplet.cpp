class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //go through each and see if theres one with matching column and none of the 
        //ones in the find are greater than the target.
        int n = target.size();
        for(int i = 0; i < n; i++){
            bool ithMatch = false;
            for(int r = 0; r < triplets.size(); r++){
                if(triplets[r][i] == target[i]){
                    bool canUse = true;
                    for(int j = 0; j < n; j++){
                        if(triplets[r][j] > target[j]){
                            canUse = false;
                            break;
                        }
                    }
                    if(canUse){
                        ithMatch = true;
                        break;
                    }
                }
            }
            if(!ithMatch){
                return false;
            }
        }
        return true;
    }
};