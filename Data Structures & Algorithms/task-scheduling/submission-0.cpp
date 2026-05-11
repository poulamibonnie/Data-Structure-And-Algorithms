#define PII pair<int,int> 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for (int task : tasks){
            freq[task - 'A']++;
        }

        //get the frequency in priority queue (Max Heap)
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        //Start processing the priority queue.
        //As a job is used insert its updated frequency with next available time in queue
        queue<PII> buffer;
        int time = 0;

        while (!pq.empty() || !buffer.empty()) {
            time++;
            if (!pq.empty()) {
                int currFreq = pq.top();
                pq.pop();
                if (currFreq > 1) {
                    buffer.push({currFreq - 1, time + n});
                }
            }
            if (!buffer.empty() && buffer.front().second == time) {
                pq.push(buffer.front().first);
                buffer.pop();
            }
        }
        return time;

    }
};
