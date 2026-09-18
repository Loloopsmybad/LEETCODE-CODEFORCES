#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int curr = h * w;
            maxWater = max(maxWater, curr);
            
            // debug
            // printf("left=%d right=%d h=%d w=%d curr=%d max=%d\n", left, right, h, w, curr, maxWater);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
