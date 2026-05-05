class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adjList;
        vector<int> res;

        for (auto  prerequisite : prerequisites) {
            auto crs = prerequisite[0];
            auto pcrs = prerequisite[1];

            adjList[pcrs].push_back(crs);
            indegree[crs]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto currCrs = q.front(); 
            q.pop();

            res.push_back(currCrs);

            for (int nxtCrs : adjList[currCrs]) {
                indegree[nxtCrs]--;
                if (indegree[nxtCrs] == 0) {
                    q.push(nxtCrs);
                }
            }
        }

        if (res.size() != numCourses) {
            return {};
        }

        return res;
    }
};
