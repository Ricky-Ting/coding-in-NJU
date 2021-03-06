#include<cstdio>
#include<cstring>
const int N=5000+5;
const int M=10000+5;

struct EDGE
{
    int v,next;
}edge[M*2];
int first[N],low[N],dfn[N],belong[N],degree[N],sta[M],instack[M];
int g,cnt,top,scc;
int min(int a,int b)
{
    return a<b?a:b;
}
void AddEdge(int u,int v)
{
    edge[g].v=v;
    edge[g].next=first[u];
    first[u]=g++;
}
void Tarjan(int u,int fa)
{
    int i,v;
    low[u]=dfn[u]=++cnt;
    sta[++top]=u;
    instack[u]=1;
    for(i=first[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(i==(fa^1))
            continue;
        if(!dfn[v])
        {
            Tarjan(v,i);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        scc++;
        while(1)
        {
            v=sta[top--];
            instack[v]=0;
            belong[v]=scc;
            if(v==u)
                break;
        }
    }
}
int main()
{
    int n,m,u,v,i,j;
    scanf("%d%d",&n,&m);
        g=cnt=top=scc=0;
        memset(first,-1,sizeof(first));
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        memset(instack,0,sizeof(instack));
        memset(degree,0,sizeof(degree));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            {
                AddEdge(u,v);
                AddEdge(v,u);
            }
        }
        //for(i=1;i<=n;i++)
           // if(!dfn[i])
                Tarjan(1,-1);
        for(i=1;i<=n;i++)
        {
            for(j=first[i];j!=-1;j=edge[j].next)
            {
                v=edge[j].v;
                if(belong[i]!=belong[v])
                    degree[belong[i]]++;
            }
        }
        int sum=0;
        for(i=1;i<=n;i++)
            if(degree[i]==1)
                sum++;
        int ans=(sum+1)/2;
        printf("%d\n",ans);
    return 0;
}