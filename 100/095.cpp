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
    ll a, b, k;
    cin >> a >> b >> k;

    if (k >= a + b)
        cout << 0 << " " << 0 << endl;
    else if (k >= a)
        cout << 0 << " " << b - (k - a) << endl;
    else
        cout << a - k << " " << b << endl;
}