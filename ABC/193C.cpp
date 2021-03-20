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
    set<ll> S;
    for (ll a = 2; pow(a, 2) <= n; a++)
    {
        for (ll b = 2; pow(a, b) <= n; b++)
        {
            S.insert(pow(a, b));
        }
    }
    cout << n - S.size() << endl;
}