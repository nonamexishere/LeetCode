class Solution {
public:
    int passThePillow(int n, int time) {
        bool dir = true;
        int i = 1;
        while (time > 0) {
            if (i == n) dir = 0;
            if (i == 1) dir = 1;
            time -= 1;
            if (dir) i++;
            else i--;
        }
        return i;
    }
};