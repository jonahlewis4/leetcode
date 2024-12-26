class Solution {
private:
    class Compare{
        public: 
        bool operator() (const vector<int>&a, const vector<int>& b) {
            //true means LOWER priority

            if(a[0] > b[0]){
                return true;
            } else if((a[0] == b[0]) && (a[1] > b[1])){
                return true;
            }
            return false;
        }
    };
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        /*
            sort intervals and queries
            remember the old positions of queries

            for each query, push each interval that starts before it to a priority queue.
            the order for the queue will be the size. Tiebreaker is where it ends. 

            pop each interval that ends BEFORE the current query
            the top will now be the answer for that query.
        */

        //setup
        std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });

        //first item in a sortQ is the value. second is the index of the original.
        std::vector<vector<int>> sortQs(queries.size(), vector<int>(2,0));
        for(int i = 0; i < queries.size(); i++){
            sortQs[i][0] = queries[i];
            sortQs[i][1] = i;
        }
        std::sort(sortQs.begin(), sortQs.end(), [](auto &a, auto &b){
            return a[0] < b[0];
        });
        
        std::priority_queue<std::vector<int>, std::vector<vector<int>>, Compare> pq;

        std::vector<int> result(queries.size());

        int intervalIdx = 0;
        for(int i = 0; i < sortQs.size(); i++){
            int q = sortQs[i][0];
            
            while(intervalIdx < intervals.size() && intervals[intervalIdx][0] <= q){
                int distance = intervals[intervalIdx][1] - intervals[intervalIdx][0] + 1;
                int end = intervals[intervalIdx][1];
                pq.push({distance, end});
                intervalIdx++;
            }

            while(!pq.empty() && pq.top()[1] < q){
                pq.pop();
            }
            if(pq.empty()){
                result[sortQs[i][1]] = -1;
                continue;
            }
            cout<<"query at index "<<sortQs[i][1]<<": "<<q<<". The min size is "<<pq.top()[0]<<endl;
            
            result[sortQs[i][1]] = pq.top()[0];
        }


        return result;


    }
};