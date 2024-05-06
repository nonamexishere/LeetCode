class Solution {
public:
    void gc(int n, vector<int>& vec) {
        if (n == 1) {
            vec.push_back(0);
            vec.push_back(1);
            return;
        }
        else {
            gc(n - 1, vec);
            int size = vec.size();
            for (int i = 0; i < size; ++i) {
                int multi = pow(2, n - 1);
                vec.push_back(vec[size - 1 - i] + multi);
            }
        }
    }
    vector<int> grayCode(int n) {
        vector<int> vec;
        gc(n, vec);
        return vec;
    }
};