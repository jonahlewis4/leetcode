class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        for(int i = 0; i < preorder.size(); i++){
            for(int j = i + 2; j < preorder.size(); j++) {
                if(preorder[j - 1] > preorder[i] && preorder[j] < preorder[i]){
                    return false;
                }
            }
        }
        return true;
    }
};