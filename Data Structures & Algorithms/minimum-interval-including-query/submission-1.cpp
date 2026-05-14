#define PII pair<int, int>

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<int> res(queries.size(), -1);
        vector<PII> qrs;

        // Store the location of each query
        for (int i = 0; i < queries.size(); i++) {
           qrs.push_back({queries[i], i});
        }

        // Sort the query
        sort(qrs.begin(), qrs.end());

        // Sort the interval on startTime
        sort(intervals.begin(), intervals.end());

        int i = 0;
        for (auto q : qrs) {
            int query = q.first;
            
            while (i < intervals.size() && query >= intervals[i][0]) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                int interval = end - start + 1;
                // cout<<"Start->"<<start<<" query->"<<query<<endl;
                pq.push({interval, end});
                i++;
            }

            // Clean up the minHeap
            while (!pq.empty() && pq.top().second < query) {
                    pq.pop();
            }
            
            int idx = q.second;
            if (!pq.empty()) {
                res[idx] = pq.top().first;
            }

            
        }
        

        return res;

    }
};
