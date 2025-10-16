class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mexx(value + 1);
        for (int i = 0; i < nums.size(); ++i) {
            int cal = nums[i] % value;
            if (cal < 0) cal += value;
            mexx[cal % value]++;
        }
        int i;
        for (i = 0;; ++i) {
            if (!(mexx[i % value]--)) break;
        }
        return i;
    }
};