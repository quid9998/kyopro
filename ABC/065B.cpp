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
    vector<ll> A(n);
    rep(i, n)
    {
        ll a;
        cin >> a;
        a--;
        A[i] = a;
    }

    ll now = 0;
    ll cnt = 0;
    set<ll> S;
    rep(i, n + 1)
    {
        S.insert(now);
        now = A[now];
        cnt++;
        if (S.count(now))
        {
            cout << -1 << endl;
            return 0;
        }
        if (now == 1)
        {
            cout << cnt << endl;
            return 0;
        }
    }
}