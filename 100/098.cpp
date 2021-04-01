//解説AC，実装おｋ
//no数学の発想問題→解けてもよかった気がする...

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
    rep(i, n) cin >> A[i];

    map<ll, ll> M; //状態管理
    M[0] = 3;
    ll ans = 1;
    rep(i, n)
    {
        //ありえないパターン
        if (M[A[i]] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        ans = (ans * (M[A[i]] % MOD)) % MOD;
        M[A[i]]--;
        M[A[i] + 1]++;
    }

    cout << ans << endl;
}