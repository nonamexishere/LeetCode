class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        int size = nums.size();
        int bm = 1 << size;
        for (int i = 0; i < bm; ++i) {
            vector<int> t_ans;
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) t_ans.push_back(nums[j]); 
            }
            sort(t_ans.begin(), t_ans.end());
            if (s.insert(t_ans).second) ans.push_back(t_ans);
        }
        return ans;
    }
};