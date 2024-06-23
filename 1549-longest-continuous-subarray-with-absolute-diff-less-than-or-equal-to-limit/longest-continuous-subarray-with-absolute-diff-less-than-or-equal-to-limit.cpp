class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> m;
        int ans = 0;
        int l = 0, r = 0;
        int size = nums.size();
        m[nums[l]]++;
        while (l <= r && r != size) {
            auto it = --m.end();
            auto it2 = m.begin();
            if (it->first - it2->first <= limit) {
                r++;
                if (r != size) m[nums[r]]++;
            }
            else {
                m[nums[l]]--;
                if(!m[nums[l]]) {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};