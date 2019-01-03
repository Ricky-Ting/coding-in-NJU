#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>
#define MAX_M 1005
#define MAX_N 105

using namespace std;

const int INF=1e9+100;
const int MAX_V=105;
int n,m,k;
int visited[MAX_M], stone[MAX_M], c[MAX_N], pre[MAX_M]; 
struct edge
{
    int to,cap,rev;//终点、容量、反向边
};
vector<edge>G[MAX_V];//图的邻接表表示
int level[MAX_V];//顶点到源点的距离标号
int iter[MAX_V];//当前弧，在其之前的边都已经没有用了
void add_edge(int from,int to,int cap)//向图中增加一条从from到to的容量为cap的边
{
    G[from].push_back((edge){to,cap,G[to].size()});
     G[to].push_back((edge){from,0,G[from].size()-1});
}
int qiandian(int i, int j) {
    return (i-1)*m+j;
}

int houdian(int i, int j) {
    return qiandian(i,j)+n*m;
}

void bfs(int s)//通过BFS计算从源点出发的距离标号
{
    memset(level,-1,sizeof(level));
    queue<int>que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0; i<G[v].size(); ++i)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f)//DFS寻找增广路
{
    if(v==t) return f;
    for(int &i=iter[v]; i<G[v].size(); ++i)
    {
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to])
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int Dinic(int s,int t)//求解s到t的最大流
{
    int maxflow=0;
    while(1)
    {
        bfs(s);
        if(level[t]<0) return maxflow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
            maxflow+=f;
    }
}

bool statisfy(int i, int j) {
    if(i<1 || i>n)
        return false;
    if(j<1 || j>m)
        return false;
    return true;
}

void init() {
    memset(pre,0,sizeof(pre));
    memset(stone,0,sizeof(stone));
    memset(visited,0,sizeof(visited));
    memset(c,0,sizeof(c));
}


void input(void) {
    init();
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&stone[i]);
    int N,tmp[MAX_M],b;
    for(int i=1;i<=n;i++) {
        scanf("%d",&N);
        for(int j=1;j<=N;j++) {
            scanf("%d",&tmp[j]);
        }
        scanf("%d",&b);
        for(int j=1;j<=N;j++) {
            if(!visited[tmp[j]]) {
                visited[tmp[j]]=true;
                pre[tmp[j]]=i;
                c[i]+=stone[tmp[j]];
            }
            else {
                add_edge(pre[tmp[j]],i,INF);
                pre[tmp[j]]=i;
            }
        }
        add_edge(i,n+1,b);
    }
    for(int i=1;i<=n;i++) 
        if(c[i])
            add_edge(0,i,c[i]);

}

void solve() {
    //printf("%d\n",Dinic(0,2*n*m+1));
    int ret=Dinic(0,n+1);
    printf("%d\n",ret);
}


int main()
{
	input();
	solve();
	return 0;
}