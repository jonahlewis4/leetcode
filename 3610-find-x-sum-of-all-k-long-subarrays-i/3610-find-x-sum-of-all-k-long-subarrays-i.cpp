class Solution {
    using PairSet = set<pair<int, int>, greater<pair<int, int>> >;

    class KTree{
        int k;
        long long _sum = 0;

        PairSet::iterator kth;

        PairSet set;
        unordered_map<int, PairSet::iterator> itFor;
    public:
        KTree(int k) {
            this->k = k;
        }

        void inc(int val) {
            const auto &s = set;
            const auto& it4 = itFor;
            const auto& kth_ = kth;
            const auto& sm = _sum;

            const auto& itr = itFor.find(val);

            pair<int, int> newP = itr == itFor.end() ? pair<int, int>(1, val) : pair<int, int>(itr->second->first + 1, val);
            bool dontHaveK = set.size() < k;
            bool newInK = dontHaveK || newP > *kth;
            if(newInK){
                _sum += (long long)newP.first * val;
            }

            pair<int, int> oldP = {newP.first - 1, val};

            bool oldExists = itr != itFor.end();
            bool oldInK = oldExists && (dontHaveK || oldP >= *kth);
            if(oldInK){
                _sum -= (long long)oldP.first * val;
            }

            bool oldWasKth = oldInK && (!dontHaveK && *kth == oldP);
            set.insert(newP);
            if(oldWasKth) {
                kth = prev(kth);
            }

            if(newInK && !oldInK && !dontHaveK){
                _sum -= (long long)kth->first * kth->second;
                kth = prev(kth);
            }

            if(oldExists) {
                set.erase(oldP);
            }

            if(set.size() == k && !oldWasKth) {
                kth = prev(set.end());
            }


            itFor[val] = set.find(newP);
        }

        void dec(int val) {
            const auto &s = set;
            const auto& it4 = itFor;
            const auto& kth_ = kth;
            const auto& sm = _sum;
            pair<int ,int> oldP = *itFor[val];

            bool oldLeft = set.size() < k || oldP >= *kth;
            if(oldLeft){
                _sum -= (long long)oldP.first * val;
            }

            pair<int, int> newP = {oldP.first - 1, val};
            
            /*if(newP.first != 0)*/ set.insert(newP);
            
            bool wasKth = set.size() > k && oldP == *kth;
            if(wasKth) {
                kth = next(kth);
                _sum += (long long)kth->first * kth->second;
            }

            set.erase(oldP);

            itFor[val] = set.find(newP);
            if(newP.first == 0) {
                itFor.erase(val);
                set.erase(newP);
            }
            bool newLeft = set.size() < k || newP >= *kth;
            if(newLeft && !wasKth){
                _sum += (long long)newP.first * val;
            }

            

            if(set.size() == k) {
                kth = prev(set.end());
                if(oldLeft && !newLeft && !wasKth){
                    _sum += (long long)kth->first * kth->second;
                }
                return;
            }

            if(set.size() < k) {
                return;
            }          


            //if old was left, but now right, kth is next
            if(oldLeft && !newLeft && !wasKth) {
                kth = next(kth);
                _sum += (long long)kth->first * kth->second;
            }
        }

        long long sum() const {
            return _sum;
        }
    };
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res(nums.size() - k + 1);

        KTree ktree(x);

        for(int i = 0; i < nums.size(); i++) {
            int l = i - k;

            if(l >= 0) {
                ktree.dec(nums[l]);
            }
            ktree.inc(nums[i]);

            if(l + 1 >= 0) {
                res[l + 1] = ktree.sum();
            }
        }

        return res;
    }
};