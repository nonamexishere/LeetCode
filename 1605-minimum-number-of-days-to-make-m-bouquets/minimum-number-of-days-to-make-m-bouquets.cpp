class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if ((long long) m * k > size) return -1;
        int mx = 0;
        for (int& bloom : bloomDay) {
            mx = max(mx, bloom);
        }
        int l = 0;
        int r = mx;
        while (l <= r) {
            int mid = (l + r) / 2;
            int count = 0;
            int curr = 0;
            for (int i = 0; i < size; ++i) {
                if (bloomDay[i] <= mid) curr++;
                else curr = 0;
                if (curr == k) {
                    count++;
                    curr = 0;
                }
            }
            if (count >= m) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};