//自力AC，復習不要
//set使うだけ

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
    ll n, q;
    set<ll> S, T;
    cin >> n;
    rep(i, n)
    {
        ll s;
        cin >> s;
        S.insert(s);
    }
    cin >> q;
    rep(i, q)
    {
        ll t;
        cin >> t;
        T.insert(t);
    }

    ll ans = 0;
    for (auto s : S)
    {
        if (T.count(s))
            ans++;
    }

    cout << ans << endl;
}