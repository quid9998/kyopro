//自力AC，復習不要
//C++配列同士の比較は==だけでおｋっぽい？

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
    vector<ll> P(n), Q(n), R(n);
    rep(i, n) R[i] = i + 1;
    rep(i, n) cin >> P[i];
    rep(i, n) cin >> Q[i];

    ll cnt = 0, a, b;
    do
    {
        //R==Pでもいけるっぽい？c++の仕様がよーわからん
        if (equal(R.begin(), R.end(), P.begin(), P.end()))
            a = cnt;
        if (equal(R.begin(), R.end(), Q.begin(), Q.end()))
            b = cnt;
        cnt++;
    } while (next_permutation(R.begin(), R.end()));

    cout << abs(a - b) << endl;
}