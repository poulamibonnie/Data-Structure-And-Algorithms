class Solution {
public:
    void getFrequency(unordered_map<int,int> &freqCounter, vector<int>& nums) {
        for (int num : nums) {
            freqCounter[num]++;
        }
        return;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int,int> freqCounter;
        vector<int> res;

        getFrequency(freqCounter, nums);

        for (auto item : freqCounter) {
            pq.push({item.second, item.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
