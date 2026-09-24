#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // initial sum of taking k cards from the left side
        int currSum = 0;
        for (int i = 0; i < k; ++i) currSum += cardPoints[i];
        int maxSum = currSum;

        // slide the window: each step remove one from left part and add one from right part
        for (int i = k - 1, j = n - 1; i >= 0; --i, --j) {
            currSum -= cardPoints[i];   // remove leftmost taken card
            currSum += cardPoints[j];   // add rightmost card
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
