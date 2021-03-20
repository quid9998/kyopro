//自力AC，復習不要

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
    cin >> m;
    set<pair<ll, ll>> seiza, tizu;
    rep(i, m)
    {
        ll x, y;
        cin >> x >> y;
        seiza.insert(make_pair(x, y));
    }
    cin >> n;
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        tizu.insert(make_pair(x, y));
    }

    for (auto s : seiza)
    {
        for (auto t : tizu)
        {
            //s,tが同じ星だとすると
            ll move_x = t.first - s.first;
            ll move_y = t.second - s.second;
            ll ok = 1;
            for (auto u : seiza)
            {
                pair<ll, ll> tmp = make_pair(u.first + move_x, u.second + move_y);
                if (!tizu.count(tmp))
                    ok = 0;
            }
            if (ok)
            {
                cout << move_x << " " << move_y << endl;
                return 0;
            }
        }
    }
}