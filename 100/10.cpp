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
    ll n, q;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];
    cin >> q;
    vector<ll> M(q);
    rep(i, q) cin >> M[i];

    //n<=20よりaについて使うor使わないのbit全探索
    set<ll> ok_num;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll tmp = 0;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
                tmp += A[j];
        }
        ok_num.insert(tmp);
    }

    rep(i, q)
    {
        if (ok_num.count(M[i]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}