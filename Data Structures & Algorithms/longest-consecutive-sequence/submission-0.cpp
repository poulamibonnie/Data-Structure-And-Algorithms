class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store;
        int mxLen = 0;

        for (int num : nums) {
            store.insert(num);
        }

        for (int item : store) {
            if (store.count(item - 1)) {
                continue;
            }
            int cnt = 0;
            int x = item;
            while(store.count(x)) {
                x++;
                cnt++;
            }
            mxLen = max(mxLen, cnt);
            
        }
        return mxLen;
    }
};
