class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());
        
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break; // no more letters used
            int cost = i / 8 + 1;
            total += freq[i] * cost;
        }
        
        return total;
    }
};