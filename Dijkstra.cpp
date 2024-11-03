#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;    // 假设最大顶点数为1000
const int maxl = INT_MAX; // 用于表示无穷大

int a[maxn][maxn]; // 邻接矩阵
int d[maxn];       // 距离数组
bool v[maxn];      // 标记数组

int main()
{
    int n, m; // 顶点数和边数
    cin >> n >> m;

    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = (i == j) ? 0 : maxl;

    // 读取边的信息
    for (int i = 0; i < m; i++)
    {
        int x, y, dis;
        cin >> x >> y >> dis;
        if (dis < a[x][y])
        {
            a[x][y] = dis;
            a[y][x] = dis;
        }
    }

    // 初始化距离数组
    for (int i = 1; i <= n; i++)
        d[i] = a[1][i];
    v[1] = 1;

    // Dijkstra算法
    for (int i = 1; i <= n; i++)
    {
        int min = maxl, l = 0;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[j] < min)
            {
                min = d[j];
                l = j;
            }
        if (l == 0)
            break;
        v[l] = 1;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[l] + a[l][j] < d[j])
                d[j] = d[l] + a[l][j];
    }

    // 输出从起点到终点的最短路径
    cout << d[n] << endl;

    return 0;
}