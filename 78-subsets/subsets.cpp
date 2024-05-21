class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int bm = 1 << size;
        vector<vector<int>> ans;
        for (int i = 0; i < bm; ++i) {
            vector<int> t_ans;
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) t_ans.push_back(nums[j]);
            }
            ans.push_back(t_ans);
        }
        return ans;
    }
};