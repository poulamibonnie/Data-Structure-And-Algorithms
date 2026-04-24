class Solution {
    queue<int> q;
    deque<int> dq;

    void qPush(int num) {
        while (!dq.empty() && dq.back() < num) {
            dq.pop_back();
        }
        q.push(num);
        dq.push_back(num);
    }

    void qPop() {
        if (q.front() == dq.front()) {
            dq.pop_front();
        }
        q.pop();
    }

    int getMax() {
        return dq.front();
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            qPush(nums[i]);
        }
        res.push_back(getMax());
        qPop();

        for (int i = k; i < n; i++) {
            qPush(nums[i]);
            res.push_back(getMax());
            qPop();
        }
        return res;
    }
};
