//自力AC，実装ムズめ
//多重ループでのフラグの置き方とか複雑→どうすれば整理できる？

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
    vector<vector<ll>> SS(m);
    rep(i, m)
    {
        ll k;
        cin >> k;
        vector<ll> S(k);
        rep(j, k)
        {
            ll s;
            cin >> s;
            s--;
            S[j] = s;
        }
        SS[i] = S;
    }
    vector<ll> P(m);
    rep(i, m) cin >> P[i];

    //制約が小さいのでn個のスイッチすべての組み合わせを検証(bit全探索)
    ll ans = 0;
    //スイッチの全ての組み合わせ
    for (ll i = 0; i < (1 << n); i++)
    {
        ll ok = 1; //全部点灯するか？
        //個々の電球について
        rep(j, m)
        {
            ll cnt = 0; //onになってるスイッチの個数
            rep(k, SS[j].size())
            {
                if (i & (1 << SS[j][k]))
                    cnt++;
            }
            if (cnt % 2 != P[j])
                ok = 0;
        }
        if (ok)
            ans++;
    }

    cout << ans << endl;
}