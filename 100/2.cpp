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
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i += 2)
    {
        ll cnt = 0;
        for (ll j = 1; j <= n; j++)
        {
            if (i % j == 0)
                cnt++;
        }
        if (cnt == 8)
            ans++;
    }
    cout << ans << endl;
}