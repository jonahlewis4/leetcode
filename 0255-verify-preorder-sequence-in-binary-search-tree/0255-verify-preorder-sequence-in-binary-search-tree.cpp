class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int smol = INT_MIN;
        int stkSize = 1;
        for(int i = 1; i < preorder.size(); i++) {
            if(preorder[i] <= smol){
                return false;
            }
            
            while(stkSize > 0 && preorder[stkSize - 1] < preorder[i]){
                smol = preorder[stkSize - 1];
                stkSize--;
            }
            preorder[stkSize] = preorder[i];
            stkSize++;
        }
        return true;
    }
};