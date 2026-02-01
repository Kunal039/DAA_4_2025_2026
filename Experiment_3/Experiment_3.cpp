#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<char> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0, ans = 0;

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 'P')
            sum += 1;
        else
            sum -= 1;

        if (mp.find(sum) != mp.end())
            ans = max(ans, i - mp[sum]);
        else
            mp[sum] = i;
    }

    cout << ans;
    return 0;
}