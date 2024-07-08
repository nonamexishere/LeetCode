class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> v(n + 1, 1);
        int num = n;
        int i = 1;
        int tmp_k = k;
        while (num != 1) {
            if (i > n) i = 1;
            if (!v[i]) {
                i++;
                continue;
            }
            if (tmp_k == 1) {
                v[i] = 0;
                cout << i << ' ';
                i++;
                tmp_k = k;
                num--;
            }
            else {
                i++;
                tmp_k--;
            }
        }
        for (int j = 1; j <= n; ++j) {
            if (v[j]) return j;
        }
        return 1;
    }
};