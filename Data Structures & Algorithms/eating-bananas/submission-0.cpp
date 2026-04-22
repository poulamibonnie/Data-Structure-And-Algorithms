class Solution {
public:
    bool helper(vector<int> &piles, int h, int k) {
        int timeTaken = 0;
        for (int pile : piles) {
            timeTaken += ceil((double) pile / k);
            if (timeTaken > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(), piles.end());

        while (s <= e) {
            int mid = (s + e)/2;
            if (helper(piles, h, mid)) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return s;
    }
};
