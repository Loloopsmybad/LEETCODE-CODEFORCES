class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> distinct(nums.begin(), nums.end());
        int best = -1;
        
        for (int x : distinct) {
            int cnt = 0;
            for (int start = 0; start <= n - k; start++) {
                bool found = false;
                for (int i = start; i < start + k; i++) {
                    if (nums[i] == x) {
                        found = true;
                        break;
                    }
                }
                if (found) cnt++;
            }
            if (cnt == 1) {
                best = max(best, x);
            }
        }
        
        return best;
    }
};