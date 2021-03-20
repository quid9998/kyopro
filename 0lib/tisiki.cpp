#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//グラフ(重みなし)
using Graph = vector<vector<int>>; // グラフ型

//グラフ(重み付き)
struct Edge
{
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

//最大公約数(引数の型に注意)
//0代入するとエラーでるので注意
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

//組み合わせの数nCrを計算
ll nCr(ll n, ll r)
{
    ll num = 1;
    for (ll i = 1; i <= r; i++)
    {
        num = num * (n - i + 1) / i;
    }
    return num;
}

//popcount
ll popcount(ll n)
{
    return __builtin_popcount(n);
}

//因数分解→map<素因数,それぞれいくつか>の形に格納
map<ll, ll> prime; //素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n)
{
    if (n <= 1)
        return;
    ll l = sqrt(n);
    for (ll i = 2; i <= l; i++)
    {
        if (n % i == 0)
        {
            prime_factorize(i);
            prime_factorize(ll(n / i));
            return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;
    return;
}

//エラトステネスのふるい
std::vector<bool> IsPrime;

void sieve(size_t max)
{
    if (max + 1 > IsPrime.size())
    {                                  // resizeで要素数が減らないように
        IsPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for (size_t i = 2; i * i <= max; ++i)         // 0からsqrt(max)まで調べる
        if (IsPrime[i])                           // iが素数ならば
            for (size_t j = 2; i * j <= max; ++j) // (max以下の)iの倍数は
                IsPrime[i * j] = false;           // 素数ではない
}

// a^n mod を高速に計算する(O(log n))
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//けんちょん式 Union-Find
struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

//ダイクストラ法
vector<ll> dijkstra(int n, Graph G, int s)
{
    vector<ll> d(n, LLONG_MAX / 10);
    d[s] = 0;
    priority_queue<pair<ll, int>> que;
    que.push(make_pair(0ll, s));
    while (!que.empty())
    {
        auto p = que.top();
        que.pop();
        int u = p.second;
        ll dist = -p.first;
        if (dist > d[u])
            continue;
        for (Edge e : G[u])
        {
            if (d[e.to] > d[u] + e.weight)
            {
                d[e.to] = d[u] + e.weight;
                que.push(make_pair(-d[e.to], e.to));
            }
        }
    }
    return d;
}

int main()
{
    //割り算切り上げ
    int a = 17, b = 7;
    cout << (a + (b - 1)) / b << endl; //3

    //小数点以下桁数指定
    cout << fixed << setprecision(10) << 1 / 3.0 << endl;

    //pair型vetorの扱い
    vector<pair<int, int>> V; //backで入れるときは初期化しない！
    V.emplace_back(5, 17);
    cout << V[0].first << " " << V[0].second << endl;

    //昇順ソート
    vector<int> G = {5, 3, 6, 2, 9};
    sort(G.begin(), G.end(), greater<int>());
    for (auto g : G)
        cout << g << endl;

    //小さい順priority_queue
    priority_queue<int, vector<int>, greater<int>> que;

    //２次元配列宣言
    vector<vector<ll>> V(a, vector<ll>(b));

    //にぶたん
    //upper_boundはkeyより大きい
    //lower_boundはkey以上
    vector<int> A = {1, 2, 3, 4, 5, 6};
    auto it = upper_bound(A.begin(), A.end(), 3);
    cout << *it << endl;               //要素を表示
    cout << it - A.begin() << endl;    //indexを表示
    cout << A[it - A.begin()] << endl; //要素を表示

    //空白文字で分割表示
    string line = "AAA BBB CCC";
    istringstream iss(line);
    string s;
    while (iss >> s)
    {
        cout << s << endl;
    }
}