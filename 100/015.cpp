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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> XY(n);
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        XY[i] = make_pair(x, y);
    }

    long double sum = 0;
    ll div = 0;
    sort(XY.begin(), XY.end());
    do
    {
        div++;
        for (ll i = 1; i < n; i++)
        {
            long double a = XY[i - 1].first;
            long double b = XY[i - 1].second;
            long double c = XY[i].first;
            long double d = XY[i].second;
            sum += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        }
    } while (next_permutation(XY.begin(), XY.end()));

    cout << fixed << setprecision(10) << sum / div << endl;
}