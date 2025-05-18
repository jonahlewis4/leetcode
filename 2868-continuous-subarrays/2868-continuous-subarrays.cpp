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

                auto accept = [&total, &r, &l, rValue, &smallest, &largest, this](){
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
                };
                
                if(smallest.empty() || largest.empty()){
                    accept();
                    continue;
                }
                
                int smallestVal = nums[smallest.front()];
                int largestVal = nums[largest.front()];

                if(dist(rValue, smallestVal) <= 2 && dist(rValue, largestVal) <= 2){
                    accept();
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
public:
    long long continuousSubarrays(vector<int>& nums) {
        return Monotonic(nums).solution();
    }
};