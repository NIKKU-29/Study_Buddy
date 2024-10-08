#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // For memset

using namespace std;

int getSmallestSubarrayLength(int k, vector<int>& amount) {
    int n = amount.size();
    int minLength = n + 1;  
    for (int left = 0; left < n; ++left) {
        vector<bool> dp(k + 1, false); 
        dp[0] = true; 
        int currentSum = 0;     
        for (int right = left; right < n; ++right) {
            currentSum += amount[right];  
        
            for (int sum = k; sum >= amount[right]; --sum) {
                if (dp[sum - amount[right]]) {
                    dp[sum] = true;
                }
            }
            if (dp[k]) {
                minLength = min(minLength, right - left + 1);
                break; 
            }
        }
    }
    return (minLength == n + 1) ? -1 : minLength;
}

int main() {
    // Sample Input 1
    vector<int> amount1 = {12, 42, 11, 2, 28, 6, 61, 88};
    int k1 = 100;
    cout << "Smallest subarray length for amount 100: " << getSmallestSubarrayLength(k1, amount1) << endl; // Expected: 5

    // Sample Input 2
    vector<int> amount2 = {3, 2, 3, 12, 11};
    int k2 = 14;
    cout << "Smallest subarray length for amount 14: " << getSmallestSubarrayLength(k2, amount2) << endl; // Expected: 3

    return 0;
}
