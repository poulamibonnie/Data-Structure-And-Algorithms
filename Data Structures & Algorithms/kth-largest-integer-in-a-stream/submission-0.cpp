class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            this->pq.push(num);
            if (this->pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        this->pq.push(val);
        if (this->pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};
