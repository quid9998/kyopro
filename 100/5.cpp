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
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    //AとBの共通枚数分
    ll z = min(x, y);

    ll ans = 0;
    ans += min(c * 2 * z, a * z + b * z);
    if (x >= y)
        ans += min((x - y) * a, (x - y) * 2 * c);
    else
        ans += min((y - x) * b, (y - x) * 2 * c);

    cout << ans << endl;
}