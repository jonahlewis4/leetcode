class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int found = 0;
        unordered_map<string, int> set;
        for(const string& s : arr) {
            set[s]++;
            
        }

        for(string&s : arr) {
            if(set[s] == 1) {
                found++;
            }

            if(found == k) {
                return s;
            }
        }

        return "";
    }
};