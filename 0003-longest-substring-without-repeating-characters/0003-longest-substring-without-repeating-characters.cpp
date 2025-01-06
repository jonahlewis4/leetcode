class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        
        std::unordered_map<char, int> map;
        int l = 0;
        int r = 0;

        int longest = 0;

        while(r < s.size()){
            cout<<"l: "<<l<<" is "<<s[l]<<endl;
            cout<<"r: "<<r<<" is "<<s[r]<<endl;
            cout<<endl;
            //longest = max(longest, r - l );
            if(map.find(s[r]) == map.end()){
                cout<<"not in map"<<endl;
                map[s[r]] = r;
            } else {
                int newL = (map[s[r]]) + 1;
                if(longest < r - l){
                    cout<<"new longest: "<<r - l<<endl;
                }
                longest = max(longest, r - l);

                cout<<"newL: "<<newL<<endl;
                while(l < newL){
                    if(l < newL  - 1){
                        map.erase(map[s[l]]);

                    }
                    l++;
                }
                map[s[r]] = r;
            }
            r++;
        }
        longest = max(longest, r - l );

        return longest;
    }
};