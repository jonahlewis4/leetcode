class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false;
        bool second = false;
        bool third = false;
        
        int targ1 = target[0];
        int targ2 = target[1];
        int targ3 = target[2];
        
        for(const vector<int>& triplet : triplets) {
            int opt1 = triplet[0];
            int opt2 = triplet[1];
            int opt3 = triplet[2];

            
            //if all opts <= target
            if(opt1 <= targ1 && opt2 <= targ2 && opt3 <= targ3) {
                first |= opt1 == targ1;
                second |= opt2 == targ2;
                third |= opt3 == targ3;
            }

            if(first && second && third) {
                return true;
            }
        }

        return false;
    }
};