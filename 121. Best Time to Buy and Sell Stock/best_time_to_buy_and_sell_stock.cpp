#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // LeetCode signature — implement your logic here
    int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int smallest = prices[0];
            int largestProfit = -1;
            int i = 1;

            while(i < n){
                if(prices[i] < smallest)
                    smallest = prices[i];
                if(prices[i] - smallest > largestProfit)
                    largestProfit = prices[i] - smallest; 

                i++;
            }

            if(largestProfit < 0)
                largestProfit = 0;

            return largestProfit;
    }
};

static void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    Solution sol;

    // Test case 1 (LeetCode example): expected 5
    std::vector<int> t1{7, 1, 5, 3, 6, 4};
    std::cout << "Prices: "; printVec(t1);
    std::cout << "\nOutput: " << sol.maxProfit(t1) << " (expected 5)\n\n";

    // Test case 2 (LeetCode example): expected 0
    std::vector<int> t2{7, 6, 4, 3, 1};
    std::cout << "Prices: "; printVec(t2);
    std::cout << "\nOutput: " << sol.maxProfit(t2) << " (expected 0)\n\n";

    // Test case 3: expected 1
    std::vector<int> t3{1, 2};
    std::cout << "Prices: "; printVec(t3);
    std::cout << "\nOutput: " << sol.maxProfit(t3) << " (expected 1)\n\n";

    return 0;
}
