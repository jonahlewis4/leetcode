class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> up(nums.size());
        vector<int> down(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            int upMax = 0;
            int downMax = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(upMax && downMax){
                    break;
                }

                if(nums[j] < nums[i]) {
                    upMax = max(down[j], upMax);
                }
                if(nums[j] > nums[i]) {
                    downMax =  max(up[j], downMax);
                }
            }
            upMax++;
            downMax++;
            up[i] = upMax;
            down[i] = downMax;
        }

        for(int i = 0; i < nums.size(); i++) {
            cout<<up[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < nums.size(); i++) {
            cout<<down[i]<<" ";
        }
        cout<<endl;
        return max(up.back(), down.back());
    }
};