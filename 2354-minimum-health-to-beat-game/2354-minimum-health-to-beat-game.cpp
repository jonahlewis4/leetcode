class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int n = damage.size();
        int maxLeArmor = 0;

        long long hp = 1;
        for(int i = n - 1; i >= 0; i--){
            hp += damage[i];
            if(damage[i] > maxLeArmor){
                maxLeArmor = damage[i];
            }
        }
        hp -= min(maxLeArmor, armor);
        return hp;
    }
};