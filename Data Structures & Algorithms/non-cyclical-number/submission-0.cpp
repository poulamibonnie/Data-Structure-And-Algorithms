class Solution {
    int helper(int n) {
        int res = 0;
        while (n > 0) {
            res += pow((n%10), 2);
            n = n/10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> store;

        while(n != 1) {
            n = helper(n);
            if (store.count(n)) {
                return false;
            }
            store.insert(n);
        }
        return true;
    }
};
