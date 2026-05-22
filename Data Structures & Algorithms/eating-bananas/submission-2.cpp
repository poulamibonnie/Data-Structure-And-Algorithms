class Solution {
    bool isValid(vector<int>& piles, int h, int speed) {
        int totalTime = 0;

        for (int i = 0; i < piles.size(); i++) {
            totalTime += ceil((double) piles[i]/speed);
            if (totalTime > h) {
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = *max_element(piles.begin(), piles.end());

        while (s < e) {
            int mid = (s + e)/2;
            if (isValid(piles, h, mid)) {
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }

        return s;
    }
};
