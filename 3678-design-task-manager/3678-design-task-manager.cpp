class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    
    set<Task, decltype([](const auto & a, const auto &b){
        if(a.priority < b.priority) {
            return true;
        }
        if(a.priority > b.priority){
            return false;
        }
        return a.taskId < b.taskId;
    })> map;
    unordered_map<int, set<Task>::iterator> itOfTask;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(const vector<int>& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Task newTask = {
            .priority = priority,
            .taskId = taskId,
            .userId = userId
        };

        map.insert(newTask);
        itOfTask[taskId] = map.find(newTask);
    }
    
    void edit(int taskId, int newPriority) {
        auto& itr = itOfTask[taskId];
        Task task = *itr;
        task.priority = newPriority;
        rmv(task.taskId);
        add(task.userId, task.taskId, task.priority);
    }
    
    void rmv(int taskId) {
        auto& itr = itOfTask[taskId];
        map.erase(itr);
        itOfTask.erase(taskId);

    }
    
    int execTop() {
        const auto& itr = map.rbegin();
        if(itr == map.rend()){
            return -1;
        }
        int returnVal = itr->userId;

        rmv(itr->taskId);
        return returnVal;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */