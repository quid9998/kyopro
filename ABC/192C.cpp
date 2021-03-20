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

    string sn = to_string(n);

    rep(i, k)
    {
        vector<ll> tmp;
        for (ll j = 0; j < sn.length(); j++)
        {
            tmp.push_back(sn[j] - '0');
        }
        ll a = 0, b = 0;
        sort(tmp.begin(), tmp.end());
        for (ll j = 0; j < tmp.size(); j++)
        {
            a = a * 10 + tmp[j];
        }
        sort(tmp.begin(), tmp.end(), greater<ll>());
        for (ll j = 0; j < tmp.size(); j++)
        {
            b = b * 10 + tmp[j];
        }
        n = b - a;
        sn = to_string(n);
    }
    cout << n << endl;
}