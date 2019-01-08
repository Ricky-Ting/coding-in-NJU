#include<cstdio>
#include<vector>
#include<algorithm>

#define N 17
#define INF 999999999
#define SZ(x) (int)((x).size())

using namespace std;

int n, dis[N][N], deg[N], dp[1<<N];
vector<int> odd;

void floyd()
{
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++) if(dis[i][k] != INF)
            for(int j = 0; j < n; j++) if(dis[k][j] != INF)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
}

int dfs(int cb)
{
    if(cb == 0) return 0;
    if(dp[cb] != INF) return dp[cb];

    for(int i = 0; i < n; i++)
    {
        if(!(cb & (1<<i))) continue;
        for(int j = 0; j < n; j++)
        {
            if(i == j || !(cb & (1<<j))) continue;
            int v = dfs(cb^(1<<i)^(1<<j));
            dp[cb] = min(dp[cb], v+dis[odd[i]][odd[j]]);
        }
    }
    return dp[cb];
}

int main()
{
    while(scanf("%d", &n), n != 0)
    {
        int ans = 0, m;
        fill(deg, deg+n, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dis[i][j] = INF;

        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c); a--, b--;
            dis[a][b] = dis[b][a] = min(c, dis[a][b]);
            deg[a]++, deg[b]++, ans += c;
        }
        
        floyd();
        
        odd.clear();
        for(int i = 0; i < n; i++)
            if(deg[i]&1) odd.push_back(i);
        n = SZ(odd);

        for(int i = 0; i < (1<<n); i++) dp[i] = INF;
        printf("%d\n", ans + dfs((1<<n)-1));
    }
}