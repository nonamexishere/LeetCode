class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (numbers[l] + numbers[r] != target) {
            if (numbers[l] + numbers[r] > target) r--;
            if (numbers[l] + numbers[r] < target) l++;
        } 
        vector<int> v(2);
        v[0] = l + 1;
        v[1] = r + 1;
        return v;
    }
};