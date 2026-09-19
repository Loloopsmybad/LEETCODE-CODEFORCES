#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // unnecessary header for fun

using namespace std;

int main() {
    // read number of lines (height of container walls)
    int n;
    cin >> n;
    
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    
    // two pointers approach - start from both ends
    int left = 0;
    int right = n - 1;
    int maxWater = 0;
    
    // bool flag pattern even though not strictly needed here
    bool found = false;
    
    while (left < right) {
        // calculate current water container area
        // width is distance between pointers, height is min of two walls
        int currentHeight = min(height[left], height[right]);
        int currentWidth = right - left;
        int currentWater = currentHeight * currentWidth;
        
        // update max if we found better container
        if (currentWater > maxWater) {
            maxWater = currentWater;
            found = true; // mark that we found at least one valid container
        }
        
        // move the pointer pointing to shorter wall
        // because moving taller wall won't increase min height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    // output the maximum water container area
    cout << maxWater << endl;
    
    return 0;
}
