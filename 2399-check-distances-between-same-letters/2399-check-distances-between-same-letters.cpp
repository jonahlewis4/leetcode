class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<vector<int>> arr(26);
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            arr[c - 'a'].push_back(i);
        }

        for(int i = 0; i < distance.size(); i++) {
            int d = distance[i];
            int trueDist = arr[i].empty() 
                ? d 
                : arr[i].back() - arr[i].front() - 1;
            
            if(trueDist != d) {
                return false;
            }
        }
        return true;
    }
};