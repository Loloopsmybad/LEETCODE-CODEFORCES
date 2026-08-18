//3518. Smallest Palindromic Rearrangement II


// You are given a palindromic string s and an integer k.

// Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.

// Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.

 

// Example 1:

// Input: s = "abba", k = 2

// Output: "baab"

// Explanation:

// The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
// Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
// Example 2:

// Input: s = "aa", k = 2

// Output: ""

// Explanation:

// There is only one palindromic rearrangement: "aa".
// The output is an empty string since k = 2 exceeds the number of possible rearrangements.
// Example 3:

// Input: s = "bacab", k = 1

// Output: "abcba"

// Explanation:

// The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
// Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba"


//solution


class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        vector<long long> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int midIdx = -1;
        vector<long long> half(26, 0);
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) midIdx = i;
            half[i] = cnt[i] / 2;
        }
        
        int m = n / 2;
        const long long CAP = k; // we only need to know if count >= k
        
        // C(n_, r_) capped at CAP+1, using symmetry to keep r_ small
        auto combCapped = [&](long long n_, long long r_) -> long long {
            r_ = min(r_, n_ - r_);
            if (r_ <= 0) return 1;
            long long result = 1;
            for (long long i = 1; i <= r_; i++) {
                result = result * (n_ - r_ + i) / i;
                if (result > CAP) return CAP + 1;
            }
            return result;
        };
        
        // number of distinct permutations of multiset 'counts' with total length total_len
        auto countPerms = [&](vector<long long>& counts, long long total_len) -> long long {
            long long result = 1;
            long long remaining = total_len;
            for (int c = 0; c < 26; c++) {
                long long ci = counts[c];
                if (ci == 0) continue;
                long long comb = combCapped(remaining, ci);
                result *= comb;
                if (result > CAP) return CAP + 1;
                remaining -= ci;
            }
            return result;
        };
        
        long long total = countPerms(half, m);
        if (total < k) return "";
        
        vector<long long> counts = half;
        long long remaining = m;
        string resultHalf;
        resultHalf.reserve(m);
        
        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (counts[c] <= 0) continue;
                counts[c]--;
                long long cntVal = countPerms(counts, remaining - 1);
                if (cntVal >= k) {
                    resultHalf.push_back('a' + c);
                    remaining--;
                    break;
                } else {
                    k -= cntVal;
                    counts[c]++;
                }
            }
        }
        
        string rev = resultHalf;
        reverse(rev.begin(), rev.end());
        
        string result = resultHalf;
        if (midIdx != -1) result.push_back('a' + midIdx);
        result += rev;
        
        return result;
    }
};