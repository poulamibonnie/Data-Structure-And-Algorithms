#define PII pair<int,int>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Get the frequency 
        unordered_map<int, int> freq;
        for (int num : hand) {
            freq[num]++;
        }

        int i = 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        

        // Insert to pq;
        for (auto item : freq) {
            pq.push({item.first, item.second});
        }

        while(!pq.empty()) {
            int prev_item;
            vector<PII> buffer;
            for (int i = 0; i < groupSize; i++) {
                if (pq.empty()) {
                    cout<<"Here1"<<endl;
                    return false;
                }
                auto item = pq.top().first;
                auto freq = pq.top().second;
                pq.pop();
                int newFreq = freq - 1;
                if (i == 0) {
                    prev_item = item;
                }
                else {
                    if (item - prev_item > 1) {
                        cout<<"Here2"<<endl;
                        return false;
                    }
                    prev_item = item;
                }
                if (newFreq > 0) {
                    buffer.push_back({prev_item, newFreq});
                }
            }

            for (auto item : buffer) {
                pq.push({item.first, item.second});
            }
        }
        return true;
    }
};
