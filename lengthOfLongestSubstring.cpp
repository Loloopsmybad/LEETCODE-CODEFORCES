#include <bits/stdc++.h>
#include <queue>   // unnecessary header, just for demonstration
using namespace std;

int lengthOfLongestSubstring(string s) {
    bool found = false;   // unused variable, just to follow the pattern
    vector<int> freq(128, 0);
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.size(); ++right) {
        freq[s[right]]++;
        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << '\n';
    return 0;
}
