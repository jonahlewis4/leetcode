class Router {
    struct Packet{
        int src;
        int dest;
        int time;
    };

    queue<Packet> q;

    unordered_map<int, unordered_set<int>> recents;
    int lastTimeStamp = -1; 

    unordered_map<int, vector<int>> times;
    unordered_map<int, int> starts;

    int maxLen;
public:
    Router(int memoryLimit) {
        maxLen = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet newPacket = {
            .src = source,
            .dest = destination,
            .time = timestamp
        };

        if(lastTimeStamp != timestamp) {
            recents.clear();
            lastTimeStamp = timestamp;
        }
        if(q.empty() || recents[source].find(destination) == recents[source].end()){
            //add packet
            q.push(newPacket);
            recents[source].insert(destination);
            if(q.size() > maxLen){
                forwardPacket();
            }
            
            
            times[destination].push_back(timestamp);
            return true;
        }

        return false;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) {
            return {};
        }

        Packet front = q.front();
        q.pop();
        if(front.time == lastTimeStamp) {
            recents[front.src].erase(front.dest);
        }

        starts[front.dest]++;

        /////////////////////////////////////////////////
        // if(starts[front.dest] >= times[front.dest].size()) {
        //     starts.erase(front.dest);
        //     times.erase(front.dest);
        // }
        /////////////////////////////////////////////////


        return {
            front.src,
            front.dest,
            front.time
        };
    }
    
    int getCount(int destination, int startTime, int endTime) {
        const auto& begin = times[destination].begin() + starts[destination];
        const auto & end = times[destination].end();

        const auto& firstInRange = lower_bound(begin, end, startTime);
        const auto& lastInRange = upper_bound(begin, end, endTime);
        return (lastInRange - firstInRange);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */