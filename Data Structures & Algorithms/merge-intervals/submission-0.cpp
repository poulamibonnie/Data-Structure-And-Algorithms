class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        vector<int> buffer = intervals[0];

        for (auto interval : intervals) {
            if (buffer[1] >= interval[0]) {
                buffer[1] = max(buffer[1], interval[1]);
            }
            else {
                res.push_back(buffer);
                buffer = interval;
            }
        }

        res.push_back(buffer);

        return res;
    }
};
