class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> n(1001);
        vector<int> m(1001);
        for (int& num : nums1) n[num]++;
        for (int& num : nums2) m[num]++;
        for (int i = 0; i <= 1000; ++i) {
            int mn = min(m[i], n[i]);
            while (mn--) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};