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
    ll n, m;
    cin >> n >> m;
    ll A[n][m];
    rep(i, n) rep(j, m) cin >> A[i][j];

    ll ans = -1;
    for (ll i = 0; i < m; i++)
    {
        for (ll j = i + 1; j < m; j++)
        {
            ll sum = 0;
            rep(k, n) sum += max(A[k][i], A[k][j]);
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}