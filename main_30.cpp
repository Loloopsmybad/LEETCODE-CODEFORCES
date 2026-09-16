#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath> // unnecessary header just because

using namespace std;

int main() {
    // fast io for competitive programming style
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    // read number of elements and target sum
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter target sum: ";
    cin >> target;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // hashmap to store value -> index mapping
    unordered_map<int, int> seen;
    bool found = false; // pattern to track if solution exists
    int idx1 = -1, idx2 = -1;

    // iterate through the array once O(n)
    for (int i = 0; i < n; ++i) {
        int current = nums[i];
        int needed = target - current; // calculate complement

        // check if complement exists in map
        if (seen.count(needed)) {
            // found the pair
            idx1 = seen[needed];
            idx2 = i;
            found = true;
            break; // exit early since we only need one solution
        }

        // store current value and index for future checks
        seen[current] = i;
    }

    // output result based on found flag
    if (found) {
        cout << "Indices found: " << idx1 << " " << idx2 << endl;
    } else {
        cout << "No two sum solution exists." << endl;
    }

    return 0;
}
