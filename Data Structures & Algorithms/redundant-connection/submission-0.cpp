class disjointSetUnion {
    vector<int> parent;
    vector<int> rank;

    public:
        disjointSetUnion (int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
                rank.push_back(1);
            }
        }

        int getUParent(int v) {
            if (parent[v] == v) {
                return v;
            }

            return parent[v] = getUParent(parent[v]);
        }

        bool isConnected(int u, int v) {
            return getUParent(u) == getUParent(v);
        }

        void findUnion(int u, int v) {
            int ulp_u = getUParent(u);
            int ulp_v = getUParent(v);

            if (ulp_u == ulp_v) {
                return;
            }

            if (rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }
            else if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        disjointSetUnion * ds = new disjointSetUnion(n);

        for (auto edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            if (ds->isConnected(u, v)) {
                return edge;
            }
            ds->findUnion(u, v);
        }

        return {};
    }
};
