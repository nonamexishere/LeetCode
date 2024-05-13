class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        vector<int> ans(2);

        priority_queue<tuple<double,int,int>> pq;
        int size = arr.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                pq.push({(arr[i] * -1.0)/(arr[j] * 1.0), arr[i], arr[j]});
            }
        }
        
        while (k > 1) {
            k--;
            pq.pop();        
        }
        auto top = pq.top();
        ans[0] = get<1>(top);
        ans[1] = get<2>(top);
        return ans;
    }
};