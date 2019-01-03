#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<queue>
#include<string>

using namespace std;

const int INF=1e9+100;
const int MAX_V=900;
int n,m,d;
int counter=0;
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

void init(void) {
    for(int i=0;i<MAX_V;i++)
        G[i].clear();
}

void input(void) {
    init();
    int dire[4][2] = { 1,0, -1,0, 0,-1, 0,1 };
    int dire2[12][2] = { 1,0, -1,0, 0,-1, 0,1 ,   0,2, 0,-2, 1,1, 1,-1, 2,0, -1,1, -1,-1, -2,0 };
    int dire3[24][2] = { 1,0, -1,0, 0,-1, 0,1 ,  0,2, 0,-2, 1,1, 1,-1, 2,0, -1,1 -1,-1, -2,0  ,  0,3, 0,-3, 1,2, 1,-2, 2,1, 2,-1, 3,0, -1,2 -1,-2, -2,1, -2,-1, -3,0 };
	
    cin>>n>>d;
    counter=0;
    string s;



    for(int i=1;i<=n;i++) {
        cin>>s;
        m=s.length();
        for(int j=0;j<s.length();j++)
            if(s[j]!='0') {
                add_edge(qiandian(i,j+1),houdian(i,j+1),s[j]-'0');
                 //cout<<qiandian(i,j+1)<<" "<<houdian(i,j+1)<<" "<<int(s[j]-'0')<<endl;
            }
    }

    if(d==1) {
        for(int i=1; i<=n; i++)
            for(int j=1;j<=m; j++) {
                bool flag=false;
                for(int k=0;k<4;k++)
                    if(statisfy(i+dire[k][0],j+dire[k][1]))
                        add_edge(houdian(i,j),qiandian(i+dire[k][0],j+dire[k][1]),INF); 
                    else {
                        if(!flag) {
                            add_edge(houdian(i,j),2*n*m+1,INF);
                            flag=true;
                        }
                    }

            }
    }
    else if(d==2) {
        for(int i=1; i<=n; i++)
            for(int j=1;j<=m; j++) {
                bool flag=false;
                for(int k=0;k<12;k++)
                    if(statisfy(i+dire2[k][0],j+dire2[k][1])) {
                        //printf("%d %d\n",dire2[k][0],dire2[k][1]);
                        add_edge(houdian(i,j),qiandian(i+dire2[k][0],j+dire2[k][1]),INF); 
                        //cout<<houdian(i,j)<<" "<<qiandian(i+dire2[k][0],j+dire2[k][1])<<" "<<INF<<endl;
                    }
                    else {
                        if(!flag){
                            add_edge(houdian(i,j),2*n*m+1,INF);
                           // cout<<houdian(i,j)<<" "<<2*n*m+1<<" "<<INF<<endl;
                            flag=true;
                        }
                    }

            }   
    }
    else {
        for(int i=1; i<=n; i++)
            for(int j=1;j<=m; j++) {
                bool flag=false;
                for(int k=0;k<24;k++)
                    if(statisfy(i+dire3[k][0],j+dire3[k][1]))
                        add_edge(houdian(i,j),qiandian(i+dire3[k][0],j+dire3[k][1]),INF); 
                    else {
                        if(!flag) {
                            add_edge(houdian(i,j),2*n*m+1,INF);
                            flag=true;
                        }
                    }
        }
    }


    for(int i=1;i<=n;i++) {
        cin>>s;
        for(int j=0;j<s.length();j++)
            if(s[j]=='L') {
                counter++;
                add_edge(0,qiandian(i,j+1),1);
                //cout<<0<<" "<<qiandian(i,j+1)<<" "<<1<<endl;
            }
    }
    /*
    for(int i=1;i<=n;i++)
        for(int j=1; j<=m;j++) {
            if(i==1 || i==n || j==1 || j==m)  {
                add_edge(houdian(i,j),2*n*m+1,INF);
                //cout<<houdian(i,j)<<" "<<2*n*m+1<<" "<<INF<<endl;
            }
        }
       */ 

}

int solve() {
    //printf("%d\n",Dinic(0,2*n*m+1));
    int ret=Dinic(0,2*n*m+1);
   // cout<<counter<<endl;
    //cout<<ret<<endl;
    return counter-ret;

}


int main()
{   
    int T;
    cin>>T;
    for(int i=1;i<=T;i++) {
        input();
        int ret=solve();
        if(ret ==0)
            cout<<"Case #"<<i<<": "<<"no"<<" gift was left behind."<<endl;
        else if(ret==1)
            cout<<"Case #"<<i<<": "<<ret<<" gift was left behind."<<endl;
        else
            cout<<"Case #"<<i<<": "<<ret<<" gifts were left behind."<<endl;
    }
	return 0;
}