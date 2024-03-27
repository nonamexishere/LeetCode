class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int counter = 0;
        int product = 1;
        int size = nums.size();
        while (l <= r) {
            if (k <= product) {
                product /= nums[l];
                l++;
                if (l < r) counter += r - l;
            }
            else if (product < k && r < size) {
                product *= nums[r];
                r++;
            }
            else if (r == size) {
                counter += r - l;
                l++;
            }
        }
        return counter;
    }
};