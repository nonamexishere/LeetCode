class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int size1 = nums1.size();
        int size2 = nums2.size();
        int l1 = 0, l2= 0;
        while (l1 < size1 && l2 < size2) {
            if (nums1[l1] > nums2[l2]) {
                l2++;
            }
            else if (nums1[l1] < nums2[l2]) {
                l1++;
            }
            else {
                ans.push_back(nums1[l1]);
                l1++;
                l2++;
            }
        }
        return ans;
    }
};