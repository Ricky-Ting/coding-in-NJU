#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1000050;
const long long INF = 1e17+7;

struct qnode
{
    int v;
    long long c;
    qnode(int _v=0,long long _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int to,w,MIN;
    Edge(int _to,int _w,int _MIN):to(_to),w(_w),MIN(_MIN){}
};

vector<Edge>E[maxn];
bool vis[maxn];
long long dis[maxn];

void Dijstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    dis[start] = 1;
    que.push(qnode(start,1));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])
            continue;
        vis[u] = true;
        for(int i=0;i<E[u].size();i++)
        {
            int v = E[u][i].to;
            int w = E[u][i].w;
            if(log2((dis[u]+w*1.0) / dis[u]*1.0)<E[u][i].MIN)
                continue;
            if(!vis[v]&&dis[v]>dis[u]+w)
            {
                dis[v] = dis[u] + w;
                que.push(qnode(v,dis[v]));
            }
        }
    }
    //cout<<dis[n]<<endl;
    if(dis[n]==INF)
        printf("-1\n");
    else
        printf("%d\n",(int)log2(dis[n]));
}

int main()
{
    int t,m,i,a,b,c,d,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            E[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            E[a].push_back(Edge(b,c,d));
        }
        Dijstra(n,1);
    }
    return 0;
}