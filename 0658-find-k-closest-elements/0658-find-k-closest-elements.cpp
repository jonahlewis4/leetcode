class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res(k);
        int dist = INT_MAX;
        int bestL = 0;
        int sum = 0;
        for(int i = 0; i < k - 1; i++){
            sum += abs(arr[i] - x);
        }
        for(int i = k-1; i < arr.size(); i++){
            int r = i;
            int l = i - k + 1;  
            sum += abs(arr[i]-x);
            if(sum < dist){
                dist = sum;
                bestL = l;
            }
            sum -= abs(arr[l]-x);
        }

        for(int i = bestL; i < bestL + k; i++){
            res[i - bestL] = arr[i];
        }
        return res;
    }
};