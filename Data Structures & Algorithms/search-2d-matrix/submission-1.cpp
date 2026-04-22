class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();

        int s = 0, e = R * C - 1;

        while (s <= e) {
            int mid = (s + e)/2;
            if (matrix[mid/C][mid%C] == target) {
                return true;
            }
            else if (matrix[mid/C][mid%C] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return false;
    }
};
