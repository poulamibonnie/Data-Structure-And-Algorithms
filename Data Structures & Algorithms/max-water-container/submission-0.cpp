class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxArea = 0, s = 0, e = heights.size() - 1;

        while (s < e) {
            mxArea = max(mxArea, (e - s) * min(heights[s], heights[e]));
            if (heights[s] < heights[e]) {
                s++;
            }
            else {
                e--;
            }
        }
        return mxArea;
    }
};
