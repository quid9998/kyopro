//自力AC,もうちょい整理できたかも

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

//前の点を中心に後ろの点を+-90度回転する関数
pair<ll, ll> add90(pair<ll, ll> AB, pair<ll, ll> CD)
{
    ll a = AB.first;
    ll b = AB.second;
    ll c = CD.first;
    ll d = CD.second;
    ll x = a + b - d;
    ll y = -a + b + c;
    return make_pair(x, y);
}

pair<ll, ll> sub90(pair<ll, ll> AB, pair<ll, ll> CD)
{
    ll a = AB.first;
    ll b = AB.second;
    ll c = CD.first;
    ll d = CD.second;
    ll x = a - b + d;
    ll y = a + b - c;
    return make_pair(x, y);
}

//2点から面積を計算する関数
ll cul_area(pair<ll, ll> AB, pair<ll, ll> CD)
{
    ll a = AB.first;
    ll b = AB.second;
    ll c = CD.first;
    ll d = CD.second;
    ll x = abs(a - c);
    ll y = abs(b - d);
    return (x + y) * (x + y) - 2 * x * y;
}

int main()
{
    ll n; //<=3000
    cin >> n;
    set<pair<ll, ll>> XY; //<=5000
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        XY.insert(make_pair(x, y));
    }
    ll ans = 0;
    for (auto p : XY)
    {
        for (auto q : XY)
        {
            if (XY.count(add90(p, q)) && XY.count(sub90(q, p)))
                ans = max(ans, cul_area(p, q));
            if (XY.count(add90(q, p)) && XY.count(sub90(p, q)))
                ans = max(ans, cul_area(p, q));
        }
    }
    cout << ans << endl;
}