class TaskManager {
    struct Compare {
        bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) const {
            auto [pa, ta, ua] = a;
            auto [pb, tb, ub] = b;
            if (pa != pb) return pa > pb;   
            if (ta != tb) return ta > tb;   
            return ua < ub;                 
        }
    };
    set<tuple<int,int,int>, Compare> tasks; 
    unordered_map<int, pair<int,int>> taskInfo; 
public:
    TaskManager(vector<vector<int>>& init) {
        for (auto &t : init) {
            int userId = t[0], taskId = t[1], priority = t[2];
            tasks.insert({priority, taskId, userId});
            taskInfo[taskId] = {userId, priority};
        }
    }
    void add(int userId, int taskId, int priority) {
        tasks.insert({priority, taskId, userId});
        taskInfo[taskId] = {userId, priority};
    }
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        tasks.erase({oldPriority, taskId, userId}); 
        tasks.insert({newPriority, taskId, userId}); 
        taskInfo[taskId] = {userId, newPriority};
    }
    void rmv(int taskId) {
        auto [userId, priority] = taskInfo[taskId];
        tasks.erase({priority, taskId, userId});
        taskInfo.erase(taskId);
    }
    int execTop() {
        if (tasks.empty()) return -1;
        auto [priority, taskId, userId] = *tasks.begin(); 
        tasks.erase(tasks.begin());
        taskInfo.erase(taskId);
        return userId;
    }
};
