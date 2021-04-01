//解説動画見たけどムズイ
//加えてmとaをtで割る処理が必要っぽい，なんで？

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return b;
    return gcd(a % b, b);
}

//最小公倍数
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

//nが何回2で割れるか
ll f(ll n)
{
    ll res = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        res++;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    ll l = 1; //a/2の最小公倍数
    ll t = f(A[0]);
    rep(i, n)
    {
        if (f(A[i] != t))
        {
            //aが2で割れる回数が一致している必要がある
            cout << 0 << endl;
            return 0;
        }
        l = lcm(l, A[i] / 2);
        if (l > m)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 0;
    for (ll i = 1; i * l <= m; i += 2)
    {
        ans++;
    }

    cout << ans << endl;
}