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

        //set of the palindromes? map of chars to set where the set contains the surrounding ones. 

        unordered_map<char, unordered_set<char>> pals;



        //at each letter check to see if it is surrounded by a pair.
        // if for a given letter the leftMost is < i and rightMost > i, we have a palindrome
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            for(char c = 'a'; c <= 'z'; c++){
                const auto & border = poles[c];
                if(border.leftMost < i && border.rightMost > i){
                    if(pals[s[i]].find(c) == pals[s[i]].end()){
                        pals[s[i]].insert(c);
                        count++;
                    }
                }
            }
        }

        //result is the number of sets in map. 
        return count;


    }
};