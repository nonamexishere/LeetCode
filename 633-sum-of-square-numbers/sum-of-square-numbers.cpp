class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<unsigned int> squares;
        for (long long i = 0; i * i <= c; ++i) {
            squares.push_back(i * i);
        }
        long long ans = c;
        int l = 0, r = squares.size() - 1;
        while (l <= r) {
            if (squares[l] + squares[r] == ans) return true;
            else if (squares[l] + squares[r] < ans) l++;
            else r--; 
        }
        return false;
    }
};