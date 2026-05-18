#define PII pair<int,int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        unordered_map<int, vector<PII>> adjList;

        // Build adjList
        for (auto obj : times) {
            int u = obj[0], v = obj[1], t = obj[2];
            adjList[u].push_back({t,v});
        }
        pq.push({0, k});

        unordered_set<int> visited;

        int delay = 0;

        while (!pq.empty()) {
            
            auto time = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            if (visited.count(node)) {
                continue;
            }
            visited.insert(node);
            delay = time;

            for (auto nbr : adjList[node]) {
                int nnode = nbr.second;
                int ntime = nbr.first;
                pq.push({time + ntime, nnode});
            }
        }

        return (visited.size() == n) ? delay : -1;
    }
};
