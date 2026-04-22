class Solution {
public:
    vector<int> rseHelper(vector<int>& heights) {
        int n = heights.size();
        int edge = n;
        vector<int> res(n, edge);

        stack<pair<int, int>> store;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!store.empty() && store.top().first >= heights[i]) {
                store.pop();
            }
            if (store.empty()) {
                res[i] = edge;
            }
            else {
                res[i] = store.top().second;
            }
            store.push({heights[i], i});
        }

        return res;
    }

    vector<int> lseHelper(vector<int>& heights) {
        int n = heights.size();
        int edge = -1;
        vector<int> res(n, edge);
        stack<pair<int, int>> store;

        for (int i = 0; i < n; i++) {
            while (!store.empty() && store.top().first >= heights[i]) {
                store.pop();
            }
            if (store.empty()) {
                res[i] = edge;
            }
            else {
                res[i] = store.top().second;
            }
            store.push({heights[i], i});
        }

        return res;

    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> rse = rseHelper(heights);
        vector<int> lse = lseHelper(heights);

        int mxArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            mxArea = max(mxArea, heights[i] * (rse[i] - lse[i] - 1));
        }

        return mxArea;

    }
};
