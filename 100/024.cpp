//自力AC
//DFS,タイムスタンプのひな形として参照
//グローバル変数，resizeの利用など(参照渡しは使わないスタイル)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

using Graph = vector<vector<ll>>;

//DFS→再帰の必要アリ
vector<ll> seen;
Graph G;
vector<ll> d, f;
ll now = 1;

void dfs(ll v)
{
    seen[v] = 1;
    d[v] = now;
    now++;
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(next_v);
    }
    f[v] = now;
    now++;
}

int main()
{
    ll n;
    cin >> n;
    seen.resize(n);
    G.resize(n);
    d.resize(n);
    f.resize(n);

    rep(i, n)
    {
        ll tmp, k;
        cin >> tmp >> k;
        rep(j, k)
        {
            ll v;
            cin >> v;
            v--;
            G[i].push_back(v); //有向グラフに注意
        }
    }

    //DFS部
    ll ok = 0;
    while (ok == 0)
    {
        ok = 1;
        rep(i, n)
        {
            if (seen[i] == 0)
            {
                dfs(i);
                ok = 0;
            }
        }
    }

    rep(i, n)
    {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}