#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> findSubsetSum(int n, vector<int> &arr, int sum)
{
    vector<vector<int>> res;
    for (int i = 0; i < (1 << n); i++)
    {
        int s = 0;
        vector<int> subSet(n, 0);
        for (int b = 0; b < n; b++)
        {
            if (i & (1 << b))
            {
                s += arr[b];
                subSet[b] = 1;
            }
        }
        if (s == sum)
        {
            res.push_back(subSet);
        }
    }
    if (res.size() == 0)
        cout << "-1";
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int sum;
    cin >> sum;
    for (auto x : findSubsetSum(n, arr, sum))
    {
        int pos=0;
        for (auto y : x)
        {
            if(y)
            cout << arr[pos] << " ";
            pos++;
        }
        cout << endl;
    }

    return 0;
}