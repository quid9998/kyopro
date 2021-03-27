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
    ll n;
    cin >> n;
    vector<ll> A(n), B(n), C(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];
    rep(i, n) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    //B[i]に繋げられるAの個数
    vector<ll> D(n);
    //AとBの組み合わせ
    rep(i, n)
    {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        D[i] = it - A.begin();
    }

    ll ans = 0;
    //BとCの組み合わせ
    rep(i, n)
    {
        auto it = upper_bound(C.begin(), C.end(), B[i]);
        ll tmp = n - (it - C.begin());
        ans += tmp * D[i];
    }

    cout << ans << endl;
}