class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(const int num : nums) {
            if(pq.size() < 2) {
                pq.push(num);
            } else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }

        int num1 = pq.top() - 1;
        pq.pop();
        int num2 = pq.top() - 1;
        return num1 * num2;
    }
};