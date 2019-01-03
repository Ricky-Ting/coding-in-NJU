#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>

using namespace std;

const int INF=1e9+100;
const int MAX_V=1000;
int n,f,d;
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

void input(void) {
	scanf("%d%d%d",&n,&f,&d);
	int fi,di,food,drink;
    for(int i=1;i<=f;i++)
        add_edge(0,i,1);
    for(int i=1;i<=d;i++)
        add_edge(f+i,2*n+f+d+1,1);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&fi,&di);
        for(int j=1;j<=fi;j++) {
            scanf("%d",&food);
            add_edge(food,i+f+d,1);
        }
        add_edge(i+f+d,n+f+d+i,1);
        for(int j=1; j<=di;j++) {
            scanf("%d",&drink);
            add_edge(n+f+d+i,f+drink,1);
        }
		
	}
}

void solve() {
	printf("%d\n",Dinic(0,2*n+f+d+1));
}


int main()
{
	input();
	solve();
	return 0;
}