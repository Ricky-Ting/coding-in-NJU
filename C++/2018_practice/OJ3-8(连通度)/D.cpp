#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 5001
#define MAXM 10005
 
 
struct node {
    int vertice;
    int next;
};
int head[MAXN+1];
node V[2*MAXM+1];
bool isvis[MAXN+1];
int dfn[MAXN+1];
int low[MAXN+1];
int mystack[MAXN+1];
int belong[MAXN+1];
int counter;
int cnt;
int n,m;
int num;
int myindex;
int degree[MAXN+1];
 
 
 
int maxi(int a, int b){
    return (a>b)?a:b;
}
int mini(int a, int b){
    return (a<b)?a:b;
}
void addv(int from, int to) {
    V[counter].vertice=to;
    if(head[from]==-1)
        head[from]=counter;
    else {
        int tmp=head[from];
        while(V[tmp].next!=-1)
            tmp=V[tmp].next;
        V[tmp].next=counter;
    }
    counter++;
}
void init(){
    counter=0;
    cnt=0;
    num=0;
    myindex=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(head,-1,sizeof(head));
    memset(degree,0,sizeof(degree));
 
    for(int i=0;i<=2*m+2;i++) {
        V[i].next=-1;
    }
    for(int i=1;i<=n;i++) {
        isvis[i]=false;
    }
}
 
void input() {
    scanf("%d%d",&n,&m);
    init();
    int from,to;
    for(int i=0;i<m;i++){
        scanf("%d%d",&from,&to);
        addv(from,to);
        addv(to,from);
    }
}
 
 
 
 
/*
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    isvis[u]=true;
    mystack[++myindex]=u;
    for(int i=head[u];i!=-1;i=V[i].next) {
        int v=V[i].vertice;
        if(!dfn[v]) {
            tarjan(v);
            low[u]=mini(low[u],low[v]);
        } else if(isvis[v])
            low[u]=mini(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]) {
        num++;
        do{
            belong[mystack[myindex]]=num;
            isvis[mystack[myindex]]=false;
            myindex--;
        } while(u!=mystack[myindex+1]);
    }
    return;
}
*/
void tarjan(int u,int fa)
{
    int i,v;
    low[u]=dfn[u]=++cnt;
    mystack[++myindex]=u;
    isvis[u]=true;
    for(i=head[u];i!=-1;i=V[i].next)
    {
        v=V[i].vertice;
        if(i==(fa^1))
            continue;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
        }
        else if(isvis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        num++;
        while(1)
        {
            v=mystack[myindex--];
            isvis[v]=false;
            belong[v]=num;
            if(v==u)
                break;
        }
    }
}
void solve(void) {
    tarjan(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=head[i];j!=-1;j=V[j].next) {
            int v=V[j].vertice;
            if(belong[i]!=belong[v])
                degree[belong[i]]++;
        }
    }
    for(int i=1;i<=n;i++)
        if(degree[i]==1)
            ans++;
    ans=(ans+1)/2;
    printf("%d\n",ans);
    return;
}
 
int main() {
    input();
    solve();
}