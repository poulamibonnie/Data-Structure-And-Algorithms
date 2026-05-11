class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) {
            return 0;
        }

        // Sort based on end time
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
        }
        );
        int removedMeets = 0;
        vector<int> buffer = intervals[0];

        for (int i = 1; i < n; i++) {
            cout << "start->" <<  intervals[i][0];
            cout << " end->" <<  intervals[i][1] <<endl;;
            if (buffer[1] > intervals[i][0]) {
                removedMeets++;
            }
            else {
                buffer = intervals[i];
            }
        }

        return removedMeets;
    }
};
