//自力AC,復習不要

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main()
{
    vector<ll> N, X;
    while (1)
    {
        ll n, x;
        cin >> n >> x;
        if (n == 0 && x == 0)
            break;
        N.push_back(n);
        X.push_back(x);
    }

    for (ll p = 0; p < N.size(); p++)
    {
        ll ans = 0;
        ll n = N[p];
        ll x = X[p];
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = i + 1; j <= n; j++)
            {
                if (x - i - j > j && x - i - j <= n)
                    ans++;
            }
        }
        cout << ans << endl;
    }
}