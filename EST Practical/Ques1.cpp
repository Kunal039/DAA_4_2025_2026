#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    
    vector<int> dp;
    
    for (int num : nums) {
        
        auto it = lower_bound(dp.begin(), dp.end(), num);
        
        if (it == dp.end()) {
            
            dp.push_back(num);
        } else {
            
            *it = num;
        }
    }
    
    return dp.size();
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "\nArray: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\n";
    
    int result = lengthOfLIS(nums);
    cout << "Length of Longest Strictly Increasing Subsequence: " << result << "\n";
    
    return 0;
}


