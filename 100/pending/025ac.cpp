//なんかダメなぜ？？
//マス目DFSの典型
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//あとでresizeできるようvectorとして宣言
vector<vector<ll>> C, seen;
ll w, h;

vector<ll> ANS;

//DFS
void dfs(ll x, ll y)
{
    seen[x][y] = 1;
    rep(i, 4)
    {

        rep(j, 4)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[j];

            // 場外アウトしたり、移動先が壁の場合はスルー
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;

            //海の場合
            if (C[nx][ny] == 0)
                continue;

            // 移動先が探索済の場合
            if (seen[nx][ny])
                continue;

            // 再帰的に探索
            dfs(nx, ny);
        }
    }
}

void toi()
{
    //二次元配列のresize
    C.resize(h, vector<ll>(w));
    seen.resize(h, vector<ll>(w));

    rep(i, h) rep(j, w) cin >> C[i][j];
    rep(i, h) rep(j, w) seen[i][j] = 0;

    ll ans = 0;
    while (1)
    {
        ll ok = 1;
        rep(i, h)
        {
            rep(j, w)
            {
                //未探索の陸が存在した場合
                if (seen[i][j] == 0 && C[i][j] == 1)
                {
                    ok = 0;
                    dfs(i, j);
                    ans++;
                }
            }
        }
        if (ok)
            break;
    }
    ANS.push_back(ans);
}

int main()
{
    while (1)
    {
        cin >> w >> h;
        if (h == 0 && w == 0)
            return 0;
        toi();
    }
    for (auto ans : ANS)
        cout << ans << endl;
}