#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // This function is currently just a placeholder
    int trap(const std::vector<int>& height)
    {
        int n = height.size();
        std::vector<int> max_L(n);
        std::vector<int> max_R(n);
        int total_water = 0;
        int curMaxL = 0;
        int curMaxR = 0;
        for(int i = 0; i < n; i++){
            max_L[i] = curMaxL;
            max_R[n - (i+1)] = curMaxR;
            if(height[i] > curMaxL)
                curMaxL = height[i];
            if(height[n - (i+1)] > curMaxR)
                curMaxR = height[n - (i+1)];
        }
        for(int i = 0; i < n; i++)
            total_water += max(0,min(max_L[i], max_R[i]) - height[i]);

        return total_water;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> testCases = {
        {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, // Example Test Case 1
        {4, 2, 0, 3, 2, 5},                  // Example Test Case 2
        {1, 2, 3, 4, 5}                      // Example Test Case 3
    };

    // Correctly reference the test case vectors as const
    for (const std::vector<int>& testCase : testCases) {
        std::cout << "Input: ";
        for (int h : testCase) std::cout << h << " ";
        std::cout << "\nOutput: " << solution.trap(testCase) << "\n\n";
    }

    return 0;
}



