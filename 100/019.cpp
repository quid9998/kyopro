//自力AC
//lower_bound,upper_boundの扱い(めぐる式不要)
//探索したいkey("以上の"/"より大きい")配列のポインタを返す

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
    ll d, n, m;
    cin >> d >> n >> m;

    vector<ll> S(n + 1); //本店を両端に加える
    S[0] = 0;
    for (ll i = 1; i < n; i++)
        cin >> S[i];
    S[n] = d;
    sort(S.begin(), S.end());

    vector<ll> T(m); //宅配先
    rep(i, m) cin >> T[i];

    ll ans = 0;
    for (auto t : T)
    {
        //それぞれ宅配先についてにぶたん
        auto it = upper_bound(S.begin(), S.end(), t);
        ans += min(*it - t, t - *(it - 1));
    }

    cout << ans << endl;
}