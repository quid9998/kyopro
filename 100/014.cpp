//自力AC，方針おｋ
//色々ごちゃってたのでまた解いてもいいかも
//条件の整理，図でなんとなくでなく言語化して整理

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
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll ans = INF;
    for (ll bit = 0; bit < (1 << n); bit++)
    {
        vector<ll> selected;
        for (ll i = 0; i < n; i++)
        {
            if (bit & (1 << i))
                selected.push_back(i);
        }

        if (selected.size() == k)
        {
            ll now_max = 0;
            ll now_selected = 0;
            ll tmp = 0;
            for (ll i = 0; i < n; i++)
            {
                if (i == selected[now_selected])
                {
                    if (!(now_max < A[i]))
                    {
                        tmp += now_max + 1 - A[i];
                        now_max++;
                    }
                    else
                    {
                        now_max = A[i];
                    }
                    now_selected++;
                }
                else
                {
                    now_max = max(now_max, A[i]);
                }
            }
            ans = min(tmp, ans);
        }
    }
    cout << ans << endl;
}