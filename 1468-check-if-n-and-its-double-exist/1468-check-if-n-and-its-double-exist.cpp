class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_set<int> map;

        for(int i = 0; i < arr.size(); i++){
            if(map.find(arr[i] * 2) != map.end()){
                return true;
            }
            if(arr[i] % 2 == 0 && map.find(arr[i] / 2) != map.end()){
                return true;
            }
            map.insert(arr[i]);
        }
        return false;
    }
};