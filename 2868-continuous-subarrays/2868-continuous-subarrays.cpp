class Solution {
    class NSquared{
    private:
        const vector<int> &nums;
        int dist(int a, int b) const {
            return abs(a - b);
        }
    public:
        NSquared(const vector<int> &nums) : nums(nums) {};
        long long solution() const {
            long long total = 0;

            for(int i = 0; i < nums.size(); i++){
                int maximum = nums[i];
                int minimum = nums[i];
                for(int j = i; j < nums.size(); j++){
                    int newVal = nums[j];
                    if(dist(maximum, newVal) > 2){
                        break;
                    }
                    if(dist(minimum, newVal) > 2){
                        break;
                    }

                    maximum = max(maximum, newVal);
                    minimum = min(minimum, newVal);

                    total++;
                }
            }

            return total;
        }
    };
    class SW{
    private:
        const vector<int> &nums;
        int dist(int a, int b) const {
            return abs(a - b);
        }
    public:
        SW(const vector<int> &nums) : nums(nums) {};
        long long solution() const {
            int l = 0;
            int r = 0;
            
            long long total = 0;
            multiset<int> set;

            
            while(r < nums.size()){
                int rNum = nums[r];
                int lNum = nums[l];

                auto accept = [&total, &r, &set, l, &rNum]{
                    total += r - l + 1;
                    r++;
                    set.insert(rNum);
                };


                if(set.empty()){
                    accept();
                    continue;
                }

                auto largestNum = prev(set.end());
                auto smallestNum = set.begin();

                if(dist(rNum, *largestNum) > 2 || dist(rNum, *smallestNum) > 2) {
                    set.erase(set.find(lNum));
                    l++;
                } else {
                    accept();
                }

            }
            return total;
        }
    };
public:
    long long continuousSubarrays(vector<int>& nums) {
        return SW(nums).solution();
    }
};