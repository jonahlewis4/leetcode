class Solution {
public:
    vector<int> minOperations(string boxes) {
        int leftSum = 0;
        int leftCumulation = 0;
        vector<int> ans(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); i++) {
            ans[i] += leftCumulation;
            leftSum += boxes[i] - '0';
            leftCumulation += leftSum;
        }

        int rightSum = 0;
        int rightCumulation = 0;
        for(int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += rightCumulation;
            rightSum += boxes[i] - '0';
            rightCumulation += rightSum;
        }

        return ans;
    }
};