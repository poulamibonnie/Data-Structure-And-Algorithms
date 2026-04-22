class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> store;

        vector<int> res(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!store.empty() && store.top().first <= temperatures[i]) {
                store.pop();
            }
            if (!store.empty()) {
                res[i] = store.top().second - i;
            }
            store.push({temperatures[i],i});
        }

        return res;
    }
};
