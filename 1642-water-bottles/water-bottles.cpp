class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int empty = 0;
        int ans = 0;
        while (numBottles) {
            ans += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }
        return ans + numBottles;
    }
};