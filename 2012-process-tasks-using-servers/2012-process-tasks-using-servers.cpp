class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // {weight, serverIndex}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>available;
        // {finishTime, weight, serverIndex}
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);
            // Release all servers that have finished
            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();
                available.push({weight, idx});
            }

            // If no server is available, wait
            if(available.empty()) {
                time = get<0>(busy.top());
                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();
                    available.push({weight, idx});
                }
            }

            // Select the best available server
            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);

            // Mark server as busy
            busy.push({(int)(time + tasks[i]),weight,idx});
        }
        return ans;
    }
};