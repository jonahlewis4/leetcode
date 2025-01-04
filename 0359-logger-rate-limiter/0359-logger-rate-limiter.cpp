class Logger {
private:     
    unordered_map<string, int> map;

public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(map.find(message) == map.end() || timestamp - map[message] >= 10){
            map[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */