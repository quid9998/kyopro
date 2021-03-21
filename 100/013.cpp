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
    ll r, c;
    cin >> r >> c;
    ll sen[r][c];
    rep(i, r) rep(j, c) cin >> sen[i][j];

    ll ans = 0;
    //rが小さいのでひっくり返すrの組み合わせをbit全探索
    for (ll i = 0; i < (1 << r); i++)
    {
        ll sen_han[r][c]; //行をひっくり返し後
        for (ll j = 0; j < r; j++)
        {
            //j行目をひっくり返す
            if (i & (1 << j))
            {
                rep(p, c) sen_han[j][p] = 1 - sen[j][p];
            }
            else
            {
                rep(p, c) sen_han[j][p] = sen[j][p];
            }
        }
        ll sum = 0;
        rep(p, c)
        {
            //縦方向に1をカウント
            ll cnt = 0;
            rep(q, r)
            {
                if (sen_han[q][p])
                    cnt++;
            }
            sum += max(cnt, r - cnt);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}