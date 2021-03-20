//自力AC，だがエスパー
//要証明確認
//y=|x-a1|+|x-a2|+|x-a3|...を最小にするxはaiの中央値(全て整数値)

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
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    //A,Bの中央値なのでは？というエスパー
    ll start, goal;
    if (n % 2)
    {
        start = A[n / 2];
        goal = B[n / 2];
    }
    else
    {
        start = (A[n / 2] + A[n / 2 - 1]) / 2;
        goal = (B[n / 2] + B[n / 2 - 1]) / 2;
    }

    ll ans = 0;
    //順番は元に戻さなくてもいっしょ
    rep(i, n)
    {
        if (A[i] <= start)
            ans += 2 * (start - A[i]);
        ans += goal - start;
        if (goal <= B[i])
            ans += 2 * (B[i] - goal);
    }
    cout << ans << endl;
}