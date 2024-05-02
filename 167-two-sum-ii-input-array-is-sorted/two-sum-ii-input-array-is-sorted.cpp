class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        int sum = -1001;
        while ((sum = numbers[l] + numbers[r]) != target) {
            if (sum > target) r--;
            if (sum < target) l++;
        } 
        vector<int> v;
        v.emplace_back(l + 1);
        v.emplace_back(r + 1);
        return v;
    }
};