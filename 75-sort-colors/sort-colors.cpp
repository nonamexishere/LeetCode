class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }
        nums.clear();
        for (auto& p : mp) {
            while (p.second--) {
                nums.push_back(p.first);
            }
        }
    }
};