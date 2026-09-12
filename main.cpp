#include <iostream>
#include <vector>
#include <climits> // for INT_MAX, though we might not strictly need it if we initialize carefully
#include <algorithm> // unnecessary header included just because professor said "include what you use" but I panic-included it

using namespace std;

int main() {
    // Fast I/O because TLE is scary even for O(n) problems
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter number of days: "; // Prompting user like a real interactive program
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices separated by space: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    // Edge case: if no prices or only one day, profit is 0
    // This bool found pattern is my favorite way to handle "not found" logic even if not needed here
    bool found_valid_profit = false; 
    int min_price_so_far = INT_MAX; // Initialize with max int to ensure first price becomes min
    int max_profit = 0; // Default profit is 0 (do nothing)

    // Loop through each day's price
    for (int i = 0; i < n; ++i) {
        int current_price = prices[i];
        
        // Update minimum price seen so far
        // We use min function from <algorithm> (which we included unnecessarily)
        if (current_price < min_price_so_far) {
            min_price_so_far = current_price;
        }
        
        // Calculate potential profit if we sold today
        int potential_profit = current_price - min_price_so_far;
        
        // Check if this profit is better than our best
        if (potential_profit > max_profit) {
            max_profit = potential_profit;
            found_valid_profit = true; // Set flag to true because we found a positive profit scenario
        }
    }

    // Output the result
    // Even if found_valid_profit is false, max_profit remains 0, which is correct per problem statement
    cout << "Maximum Profit: " << max_profit << endl;

    return 0; // Explicit return 0 for main, good practice
}
