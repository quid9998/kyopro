//自力AC，復習不要

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int check(string s)
{
    int ok = 1;
    rep(i, s.size())
    {
        if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T')
            ok = 0;
    }
    return ok;
}

int main()
{
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        for (ll j = i; j < s.size(); j++)
        {
            string tmp = s.substr(i, j - i + 1);
            if (check(tmp))
                ans = max((ll)tmp.size(), ans);
        }
    }
    cout << ans << endl;
}