class Solution {
    struct leftRight {
        int leftMost; 
        int rightMost;
    };
public:
    int countPalindromicSubsequence(string s) {
        //get leftMost and RightMost of each charcter
        unordered_map<char, leftRight> poles;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            poles[c].rightMost = i;
        }

        for(int i = s.size() - 1; i >= 0; i--){
            char c = s[i];
            poles[c].leftMost = i;
        }





        int count = 0;

        for(char c = 'a'; c <= 'z'; c++){
            unordered_set<char> between;
            if(poles.find(c) == poles.end() || poles[c].leftMost == poles[c].rightMost){
                continue;
            }
            const auto & boundaries = poles[c];
            int leftMost = boundaries.leftMost;
            int rightMost = boundaries.rightMost;
            for(int i = leftMost + 1; i < rightMost; i++){
                between.insert(s[i]);
            }
            count += between.size();
        }

        return count;


    }
};