class Solution {
public:
    bool helper(vector<int>& piles, int h, int k) {
        int totalTime = 0;
        for (int pile : piles) {
            totalTime += (ceil) ((double) pile/k);
            if (totalTime > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(), piles.end());
        int mid;

        while (s < e) {
            mid = (s + e)/2;
            if (helper(piles, h, mid)) {
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }
        return s;
    }
};
