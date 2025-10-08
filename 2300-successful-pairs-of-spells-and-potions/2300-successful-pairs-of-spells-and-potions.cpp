class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> res(spells.size());
        for(int i = 0; i < spells.size(); i++) {
            int spell = spells[i];
            long long minPotion = ceil((double)success / spell);

            //get iterator to first value minPotion or greater
            auto itr = lower_bound(potions.begin(), potions.end(), minPotion);
            //itr is the first valid option

            int usable = potions.end() - itr;
            res[i] = usable;
        }

        return res;

    }
};