class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> ans;
        unordered_map<int, int> m;
        for (int& num : nums1) {
            m[num]++;
        }
        for (int& num : nums2) {
            if (m[num] > 0) {
                m[num]--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};