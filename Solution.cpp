#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int ans = 0;
        while (l < r) {
            int area = min(h[l], h[r]) * (r - l);
            ans = max(ans, area);
            if (h[l] < h[r]) l++;
            else r--;
        }
        return ans;
    }
};

// TODO: test with edge cases like [1,1] or decreasing heights
