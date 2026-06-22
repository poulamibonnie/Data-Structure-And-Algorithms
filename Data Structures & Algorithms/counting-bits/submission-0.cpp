class Solution {
    int helper(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += n%2;
            n = n/2;
        }
        return cnt;
    }
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            res[i] = helper(i);
        }

        return res;
    }
};
