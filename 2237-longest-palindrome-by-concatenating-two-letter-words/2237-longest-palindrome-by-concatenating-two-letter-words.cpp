class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int longest = 0;


        unordered_map<string, int> map;



        //if pair in map : 
            //decrease pair count and DON'T add this guy.
            //also increase the size of longest by 4
        // otherwise increase count of the current word.

        for(const auto & word : words){
            string pair = {word[1], word[0]};

            if(map.find(pair) != map.end()){
                map[pair]--;
                if(map[pair] == 0){
                    map.erase(pair);
                }
                longest += 4;
            } else {
                map[word]++;
            }

        }



        //final loop through and see if any of the words which have NOT been used yet are palindromes. If there is one,
        //it can go at the center of the result and so we increase longest by 2. 

        for(auto [key, _] : map) {
            
            if(key[0] == key[1]){
                longest += 2;
                break;
            }
        }

        return longest;
    }
};