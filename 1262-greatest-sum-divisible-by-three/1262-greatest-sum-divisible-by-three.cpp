class Solution {
using pq = priority_queue<int, vector<int>, less<int>>;

public:
    int maxSumDivThree(vector<int>& nums) {
        //add all up

        //if rem = 0, return it

        //if rem = 1 -> remove a 1 or two 2's

        //if rem = 2 -> remove a 2 or two 1's

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 3 == 0) {
            return sum;
        }

        pq ones;
        pq twos;

        for(const int num : nums) {
            if(num % 3 == 0) {
                continue;
            }

            if(num % 3 == 1) {
                if(ones.size() < 2 || num <= ones.top()) {
                    ones.push(num);
                    if(ones.size() > 2) {
                        ones.pop();
                    }
                }
                continue;
            }

            if(twos.size() < 2 || num <= twos.top()) {
                twos.push(num);
                if(twos.size() > 2) {
                    twos.pop();
                }
            }
        }

        if(sum % 3 == 1) {
            int one = biggestIn(ones);
            int two = twoBiggestIn(twos);

            return sum - min(one, two);
        }

        int one = twoBiggestIn(ones);
        int two = biggestIn(twos);
        return sum - min(one, two);
    }

    int biggestIn(pq& q){
        if(q.empty()) {
            return INT_MAX;
        }
        if(q.size() == 1){
            return q.top();
        }
        q.pop();
        return q.top();
    }
    int twoBiggestIn(pq& q) {
        if(q.size() <= 1) {
            return INT_MAX;
        }
        int sum = q.top();
        q.pop();
        sum += q.top();
        return sum;
    }
};