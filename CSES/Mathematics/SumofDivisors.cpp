#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
ll sigma(ll x)
{
    return ((x % MOD) * ((x + 1) % MOD) / 2) % MOD;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll N, sum = 0;
    cin >> N;
    for (ll l = 1; l <= N; l++)
    {
        ll r = N / (N / l);
        sum += (N / l) % MOD * (sigma(r) - sigma(l - 1) + MOD) % MOD;
        sum = (sum + MOD) % MOD;
        l = r;
    }
    cout << sum;
    return 0;
}