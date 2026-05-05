class DSU {
    vector<int> parent;
    vector<int> rank;
    public:
        DSU (int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
                rank.push_back(1);
            }
        }

        int getParent(int u) {
            if (parent[u] == u) {
                return u;
            }

            return parent[u] = getParent(parent[u]);
        }

        void findUnion(int u, int v) {
            if (getParent(u) == getParent(v)) {
                return;
            }

            int ulp_u = getParent(u);
            int ulp_v = getParent(v);

            if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }
            else if (rank[ulp_v] > rank[ulp_u]) {
                parent[ulp_u] = ulp_v;
            }
            else {
                rank[ulp_v]++;
                parent[ulp_u] = ulp_v;
            }
        }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int numberOfComponent = n;
        DSU * ds = new DSU(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            if (ds->getParent(u) != ds->getParent(v)) {
                ds->findUnion(u,v);
                numberOfComponent--;
            }
        }

        return numberOfComponent;
    }
};
