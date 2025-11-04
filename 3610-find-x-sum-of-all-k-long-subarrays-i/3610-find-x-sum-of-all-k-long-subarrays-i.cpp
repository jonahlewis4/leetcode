class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res(nums.size() - k + 1);
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            int l = i - k;
            if(l >= 0){
                freq[nums[l]]--;
            }

            freq[nums[i]]++;
            if(l + 1 >= 0){
                res[l + 1] = xLargestSum(freq, x);
            }
        }

        return res;
    }

    int xSum(const vector<int>& nums, int begin, int end, int x) {
        unordered_map<int, int> freq;
        for(int i = begin; i < end; i++) {
            freq[nums[i]]++;
        }

        int sum = xLargestSum(freq, x);
        return sum;
    }

    int xLargestSum(unordered_map<int, int>& freq, int x) {

        const auto &cmp = [&freq](const int a, const int b){
            int c1 = freq[a];
            int c2 = freq[b];

            if(c1 < c2) {
                return false;
            }
            if(c1 > c2) {
                return true;
            }

            return a > b;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);


        for(const auto & [num, count] : freq) {
            if(pq.size() < x) {
                pq.push(num);
            } else {
                int topNum = pq.top();
                int topCount = freq[topNum];
                
                if(count > topCount || (count == topCount && num > topNum)){
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    
        int sum = 0;
        while(!pq.empty()){
            int num = pq.top();
            pq.pop();
            int count = freq[num];
            int localSum = num * count;
            sum += localSum;
        }

        return sum;
    }
};