class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        short l = 0;
        short r = numbers.size() - 1;
        short sum = -1001;
        while ((sum = numbers[l] + numbers[r]) != target) {
            if (sum > target) r--;
            if (sum < target) l++;
        } 
        vector<int> v;
        v.push_back(l + 1);
        v.push_back(r + 1);
        return v;
    }
};