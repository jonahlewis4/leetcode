class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        
        std::unordered_map<char, vector<int>> f1;
        std::unordered_map<char, vector<int>> f2;
        
        for(int i = 0; i < s.size(); i++){
            f1[s[i]].push_back(i);
            f2[t[i]].push_back(i);
        }

        for(const auto & keyPair : f1){
            char c1 = keyPair.first;
            char c2 = t[keyPair.second[0]];
            if(keyPair.second.size() != f2[c2].size()){
                return false;
            }

            for(int i = 0; i < keyPair.second.size(); i++){
                if(keyPair.second[i] != f2[c2][i]){
                    return false;
                }
            }
        }
        return true;


    }
};