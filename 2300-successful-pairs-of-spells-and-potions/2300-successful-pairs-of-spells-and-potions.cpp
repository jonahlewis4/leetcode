class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<pair<int, int>> spellsAndIs(spells.size());
        for(int i = 0; i < spellsAndIs.size(); i++) {
            spellsAndIs[i] = {
                spells[i],
                i
            };
        }
        sort(spellsAndIs.begin(), spellsAndIs.end());

        vector<int> res(spells.size());
        int potionI = potions.size() - 1;
        for(int i = 0; i < spellsAndIs.size(); i++) {
            long long spell = (long long)spellsAndIs[i].first;
            int idx = spellsAndIs[i].second;

            while(potionI >= 0 && spell * potions[potionI] >= success){
                potionI--;
            }

            int diff = potions.size() - potionI - 1;
            res[idx] = diff;
        }

        return res;

    }
};