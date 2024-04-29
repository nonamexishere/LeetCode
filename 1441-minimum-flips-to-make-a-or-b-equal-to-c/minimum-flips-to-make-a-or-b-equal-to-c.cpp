class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = (a & b);
        int y = (b ^ a) ^ c ^ x;
        if ((a | b) == c) return 0;
        int counter = 0;
        int tmp_c = c;
        while (x) {
            if (x & 1 && !(tmp_c & 1)) {
                counter++;
            }
            tmp_c >>= 1;
            x >>= 1;
        }
        while (y) {
            counter += (y & 1);
            y >>= 1;
        }
        return counter;
    }
};