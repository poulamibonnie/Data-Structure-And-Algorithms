class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> store;
        

        int n = temperatures.size();
        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!store.empty() && store.top().first <= temperatures[i]) {
                store.pop();
            }
            if (store.empty()) {
                res[i] = 0;
            }
            else {
                res[i] = store.top().second - i;
            }
            store.push({temperatures[i], i});
        }

        return res;
    }
};
