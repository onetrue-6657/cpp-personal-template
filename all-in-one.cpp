#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0); // No more scanf and printf
    cin.tie(0);              // No more binding with cout
    cout.tie(0);             // No more binding with cin

    return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; } // Greatest Common Divisor

ll mod;
ll PowerMod(ll a, ll n, ll m = mod)
{
    if (!n || a == 1)
        return 1ll;
    ll s = PowerMod(a, n >> 1, m);
    s = s * s % m;
    return n & 1 ? s * a % m : s;
}
// Fast Power Modulo

int o[], cnt, id[], size[], p[], dep[], eid[], first[], nxt[], to[];
void dfs(int x)
{
    int i, y;
    o[++cnt] = x, id[x] = cnt, size[x] = 1;
    for (i = first[x]; i; i = nxt[i])
        if ((y = to[i]) != p[x])
            p[y] = x, dep[y] = dep[x] + 1, dfs(y), size[x] += size[y];
    eid[x] = cnt;
}
// dfs

typedef std::pair<int, int> pr;

const int N = 100005; // or any appropriate value
struct Edge
{
    int v, w;
};
Edge e[];
int first[], nxt[], V;
int d[N];
std::priority_queue<pr, std::vector<pr>, std::greater<pr>> pq;

void Dijkstra(int s)
{
    int i, x, y, D;
    memset(d, 63, (V + 1) << 2);
    for (pq.emplace(d[s] = 0, s); !pq.empty();)
    {
        std::tie(D, x) = pq.top(), pq.pop();
        if (d[x] != D)
            continue;
        for (i = first[x]; i; i = nxt[i])
            if (D + e[i].w < d[y = e[i].v])
                pq.emplace(d[y] = D + e[i].w, y);
    }
}
// Dijkstra

int d[][];
void Floyd()
{
    int i, j, k;
    for (k = 1; k <= V; ++k)
        for (i = 1; i <= V; ++i)
            for (j = 1; j <= V; ++j)
                down(d[i][j], d[i][k] + d[k][j]);
}