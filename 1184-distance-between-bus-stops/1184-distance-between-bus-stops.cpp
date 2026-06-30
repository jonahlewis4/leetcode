class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int forward = 0;
        for(int i = start; i != destination; ++i%=distance.size()){
            forward += distance[i];
        }
        int backward = 0;
        for(int i = destination; i != start; ++i%=distance.size()) {
            backward += distance[i];
        }
        return min(forward, backward);
    }
};