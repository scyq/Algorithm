#include <iostream>
#include <vector>

using namespace std;

int n, k, m;
int sum;
int g[200][200];    // 顶点从1开始
int color[200];     // 颜色从1开始

bool check(int v, int want)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[v][i] && color[i] == want)
        {
            return false;
        }
    }
    return true;
}

void dfs(int v)
{
    if (v > n) {
        sum++;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (check(v, i)){
            color[v] = i;
            dfs(v + 1);
            color[v] = 0;
        }
    }
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    
    dfs(1);
    cout << sum;
    
    return 0;
}