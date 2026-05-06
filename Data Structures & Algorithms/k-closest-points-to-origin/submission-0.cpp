struct Compare {
    bool operator() (const vector<int> &a, const vector<int> &b) const {
        return (a[0]* a[0]) + (a[1]*a[1]) < (b[0]* b[0]) + (b[1]*b[1]);
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for (vector<int> point : points) {
            pq.push(point);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
