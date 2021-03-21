//自力AC，復習不要
//初期atcoderだとこれが水diffなのか...

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
    set<pair<ll, ll>> XY;
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        XY.insert(make_pair(x, y));
        XY.insert(make_pair(y, x));
    }

    //nが12と小さいのでbit全探索を発想
    //1が派閥に含む
    ll ans = 0;
    for (ll i = 0; i < (1 << n); i++)
    {
        vector<ll> giins; //派閥に属する議員の配列
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
                giins.push_back(j);
        }
        //仲良しチェック
        ll ok = 1;
        for (auto p : giins)
        {
            for (auto q : giins)
            {
                if (p == q)
                    break;
                if (!XY.count(make_pair(p, q)))
                    ok = 0;
            }
        }
        if (ok)
            ans = max(ans, (ll)giins.size());
    }

    cout << ans << endl;
}