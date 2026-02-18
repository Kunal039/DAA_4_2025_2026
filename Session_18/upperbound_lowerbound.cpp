#include<bits/stdc++.h>
using namespace std;
int LowerBound(vector<int>& arr, int k) {
    int l = 0, r = arr.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] >= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
int UpperBound(vector<int>& arr, int k) {
    int l = 0, r = arr.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] > k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {3, 4, 4, 4, 7, 8};
    cout << LowerBound(arr, 4) << endl;
    cout << UpperBound(arr, 4) << endl;
    return 0;
}