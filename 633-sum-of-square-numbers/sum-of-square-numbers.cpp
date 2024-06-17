class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> squares;
        for (long long i = 0; i * i <= c; ++i) {
            squares.push_back(i * i);
        }
        for (int& sq : squares) {
            auto it = lower_bound(squares.begin(), squares.end(), c - sq);
            if (it != squares.end() && *it == c - sq) return true;
        }
        return false;
    }
};