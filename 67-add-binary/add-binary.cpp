class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        int size_a = a.length();
        int size_b = b.length();
        string ans = "";
        bool aBig = size_a >= size_b;
        if (aBig) ans = string(size_a, '0'); 
        else ans = string(size_b, '0');
        if (aBig) {
            for (int i = 0; i < size_b; ++i) {
                if (a[size_a - 1 - i] == '1' && b[size_b - 1 - i] == '1') {
                    if (c) ans[size_a - 1 - i] = '1';
                    else ans[size_a - 1 - i] = '0';
                    c = 1;
                }
                else if ((a[size_a - 1 - i] == '0' && b[size_b - 1 - i] == '1') || (a[size_a - 1 - i] == '1' && b[size_b - 1 - i] == '0')) {
                    if (c) {ans[size_a - 1 - i] = '0';}
                    else ans[size_a - 1 - i] = '1';
                }
                else {
                    if (c) ans[size_a - 1 - i] = '1';
                    else ans[size_a - 1 - i] = '0';
                    c = 0;
                }
            }
            for (int i = size_b; i < size_a; ++i) {
                if (a[size_a - 1 - i] == '1') {
                    if (c) ans[size_a - 1 - i] = '0';
                    else ans[size_a - 1 - i] = '1';
                }
                else {
                    if (c) ans[size_a - 1 - i] = '1';
                    else ans[size_a - 1 - i] = '0';
                    c = 0;
                }
            }
        }
        else {
            for (int i = 0; i < size_a; ++i) {
                if (a[size_a - 1 - i] == '1' && b[size_b - 1 - i] == '1') {
                    if (c) ans[size_b - 1 - i] = '1';
                    else ans[size_b - 1 - i] = '0';
                    c = 1;
                }
                else if ((a[size_a - 1 - i] == '0' && b[size_b - 1 - i] == '1') || (a[size_a - 1 - i] == '1' && b[size_b - 1 - i] == '0')) {
                    if (c) ans[size_b - 1 - i] = '0';
                    else ans[size_b - 1 - i] = '1';
                }
                else {
                    if (c) ans[size_b - 1 - i] = '1';
                    else ans[size_b - 1 - i] = '0';
                    c = 0;
                }
            }
            for (int i = size_a; i < size_b; ++i) {
                if (b[size_b - 1 - i] == '1') {
                    if (c) ans[size_b - 1 - i] = '0';
                    else ans[size_b - 1 - i] = '1';
                }
                else {
                    if (c) ans[size_b - 1 - i] = '1';
                    else ans[size_b - 1 - i] = '0';
                    c = 0;
                }
            }
        }
        if (c) ans = "1" + ans;
        return ans;
    }
};