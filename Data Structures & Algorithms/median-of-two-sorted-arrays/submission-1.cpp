class Solution {
public:
    double helper(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int s = 0, e = n, l1, r1, l2, r2, cut1, cut2;

        while (s <= e) {
            cut1 = (s + e)/2;
            cut2 = (n + m)/2 - cut1;

            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            if (l1 > r2) {
                e = cut1 - 1;
            }
            else if (l2 > r1) {
                s = cut1 + 1;
            }
            else {
                if ((n + m)%2 == 0) {
                    return (double) ((max(l1,l2) + min(r1,r2)))/2.0;
                }
                else {
                    return min(r1,r2);
                }
            }
        } 
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (m < n) {
            swap(nums1, nums2);
        }
        return helper(nums1, nums2);
    }
};
