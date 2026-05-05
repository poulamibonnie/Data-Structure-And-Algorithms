class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>  &adjList, int parent, vector<int> &visited, int node) {
        if (visited[node]) {
            return true;
        }
        visited[node] = 1;

        for (int child : adjList[node]) {
            if (child == parent) {
                continue;
            }

            if (dfs(adjList, node, visited, child)) {
                return true;
            }
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>  adjList;

        int m = edges.size();

        if (n != m + 1) {
            return false;
        }

        // Build adjacency List
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // Check for cycle starting each node
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            if (dfs(adjList, INT_MIN, visited, i)) {
                return false;
            }
        }

        return true;
    }
};
