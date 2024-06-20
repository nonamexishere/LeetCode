class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int size = position.size();
        int l = 1;
        int r = (position[size - 1] - position[0]) / (m - 1);
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int b = 1;
            int last = position[0];
            bool check = false;
            for (int i = 0; i < size; ++i) {
                if (position[i] - last >= mid) {
                    b++;
                    last = position[i];
                }
                if (m <= b) {check = true; break;}
            }
            if (check) {l = mid + 1; ans = mid;}
            else r = mid - 1;
        }
        return ans;
    }
};