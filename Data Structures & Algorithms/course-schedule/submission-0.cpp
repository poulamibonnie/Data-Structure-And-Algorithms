class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int crs = prerequisites[i][0];
            int pcrs = prerequisites[i][1];
            adjList[pcrs].push_back(crs);
            indegree[crs]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int crsTaken = 0;
        while (!q.empty()) {
            int currCrs = q.front();
            q.pop();
            crsTaken++;

            for (int nextCrs : adjList[currCrs]) {
                indegree[nextCrs]--;
                if (indegree[nextCrs] == 0) {
                    q.push(nextCrs);
                }
            }
        }

        return (crsTaken == numCourses) ? true : false;
    }
};
