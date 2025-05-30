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
    class Multiset{
    private:
        const vector<int> &nums;
        int dist(int a, int b) const {
            return abs(a - b);
        }
    public:
        Multiset(const vector<int> &nums) : nums(nums) {};
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
    class Monotonic {
    private:
        const vector<int>& nums;

        void accept (long long &total, int &r, int &l, int rValue, deque<int> &smallest, deque<int> &largest, const vector<int> &nums) const{
            total += r - l + 1;
            while(!smallest.empty() && nums[smallest.back()] >= rValue){
                smallest.pop_back();
            }
            smallest.push_back(r);
            while(!largest.empty() && nums[largest.back()] <= rValue) {
                largest.pop_back();
            }
            largest.push_back(r);
            r++;
        }
    public:
        Monotonic(const vector<int>& nums) : nums(nums){}
        long long solution() const {
            auto dist = [](int a, int b) {
                return abs(a - b);
            };

            deque<int> smallest;
            deque<int> largest;

            int l = 0;
            int r = 0;
            long long total = 0;
            while(r < nums.size()){
                int lValue = nums[l];
                int rValue = nums[r];

                
                
                if(smallest.empty() || largest.empty()){
                    accept(total, r, l, rValue, smallest, largest, nums);
                    continue;
                }
                
                int smallestVal = nums[smallest.front()];
                int largestVal = nums[largest.front()];

                if(dist(rValue, smallestVal) <= 2 && dist(rValue, largestVal) <= 2){
                    accept(total, r, l, rValue, smallest, largest, nums);
                    continue;
                }

                //move until smallest and largest are within r value.
                while(!smallest.empty() && dist(nums[smallest.front()], rValue) > 2){
                    l = smallest.front() + 1;
                    smallest.pop_front();
                }

                while(!largest.empty() && dist(nums[largest.front()], rValue) > 2){
                    l = max(l, largest.front() + 1);
                    largest.pop_front();
                }

                


            }
            return total;
        }

    };

    class TwoPointer {
    private:
        const vector<int> &nums;

        inline void accept(long long &total, int &r, int l, int &smallest, int& greatest) const{
            total += r - l + 1;
            smallest = min(smallest, nums[r]);
            greatest = max(greatest, nums[r]);
            r++;
        }

        int dist(int a, int b) const {
            return abs(a - b);
        }
    public:
        TwoPointer(const vector<int>& num) : nums(num) {}

        long long solution() const{
            int l = 0;
            int r = 0;

            int smallest = INT_MAX;
            int greatest = INT_MIN;
            long long total = 0;
            while(r < nums.size()){
                if(smallest == INT_MAX || greatest == INT_MIN){
                    accept(total, r, l, smallest, greatest);
                    continue;
                }


                if(dist(nums[r], smallest) > 2 || dist(nums[r], greatest) > 2){
                    int newL = r;
                    int newGreatest = nums[newL];
                    int newSmallest = nums[newL];
                    
                    while(newL - 1 >= l && dist(nums[newL - 1] ,nums[r]) <= 2){
                        newL--;
                        newGreatest = max(newGreatest, nums[newL]);
                        newSmallest = min(newSmallest, nums[newL]);
                    }

                    l = newL;
                    smallest = newSmallest;
                    greatest = newGreatest;
                }
                accept(total, r, l, smallest, greatest);
            }

            return total;
        }
    };
public:
    long long continuousSubarrays(const vector<int>& nums) {
        return TwoPointer(nums).solution();
    }
};