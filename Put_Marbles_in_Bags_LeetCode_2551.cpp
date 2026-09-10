Put Marbles in Bags (LeetCode #2551)
```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;
        
        vector<long long> adjacentSums;
        adjacentSums.reserve(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            adjacentSums.push_back((long long)weights[i] + weights[i + 1]);
        }
        
        sort(adjacentSums.begin(), adjacentSums.end());
        
        long long minScore = 0, maxScore = 0;
        for (int i = 0; i < k - 1; ++i) {
            minScore += adjacentSums[i];
            maxScore += adjacentSums[adjacentSums.size() - 1 - i];
        }
        
        return maxScore - minScore;
    }
};
```

Time/Space complexity: O(n log n) time, O(n) space

Brief approach explanation: The score of a partition equals the sum of weights at partition boundaries (weights[i] + weights[i+1] for each cut). With k bags we need k-1 cuts. To maximize the score difference, we select the k-1 largest adjacent sums for maximum score and k-1 smallest for minimum score. The answer is simply the difference between these two sums.
