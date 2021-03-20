//自力AC，復習不要

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

//数値を0埋めしたstringに変換
string ume(ll n)
{
    string tmp = to_string(n);
    if (tmp.size() == 1)
        return "00" + tmp;
    if (tmp.size() == 2)
        return "0" + tmp;
    return tmp;
}

int main()
{
    ll n;
    string s;
    cin >> n >> s;

    //候補を検証
    ll ans = 0;
    for (ll i = 0; i <= 999; i++)
    {
        string si = ume(i);
        ll now = 0;
        rep(j, n)
        {
            if (si[now] == s[j])
                now++;
            if (now == 3)
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}