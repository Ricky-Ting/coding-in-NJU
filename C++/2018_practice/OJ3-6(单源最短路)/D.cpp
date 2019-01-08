//
//  main.cpp
//  debug
//
//  Created by 丁保荣 on 2018/11/13.
//  Copyright © 2018 丁保荣. All rights reserved.
//

#include<cstdio>
#include<vector>
using namespace std;
#define INF 1e8
int n,m,s,t;
struct edge{
    int to;
    int w;
    edge(int myto,int myw):to(myto),w(myw){} //构造函数
};
struct vertex{
    int prev;
    long long val;
    bool isvis;
};
vector<edge> E[1000];
vertex V[1002];
int My_Extract_Min(void) ;
void input(void);
void solve(void);
void RELAX(int u, int v);

int main() {
    input();
    solve();
    
}

void input(){
    scanf("%d%d",&n,&m);
    int from,to,weight;
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&from,&to,&weight);
        E[from].push_back(edge(to,weight));
    }
    for(int i=1;i<=n;i++) {
        V[i].prev=-1;
        V[i].val=INF;
        V[i].isvis=false;
    }
    scanf("%d%d",&s,&t);
    V[s].val=0;
}

void RELAX(int u, int v, int w) {
    if(V[u].val==INF) {
        return;
    }
    if(V[v].val>V[u].val+w) {
        V[v].val=V[u].val+w;
        V[v].prev=u;
    }
}

void solve() {
    int cnt=0;
    while(cnt!=n) {
        int u=My_Extract_Min();
        V[u].isvis=true;
        cnt++;
        for(int i=0;i<E[u].size();i++) {
            RELAX(u,E[u][i].to,E[u][i].w);
        }
    }
    if(V[t].val==INF) {
        printf("-1\n");
        return;
    }
    printf("%lld\n",V[t].val);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            printf("%lld ",V[j].val-V[i].val);
        }
        printf("\n");
    }
}

int My_Extract_Min(void) {
    int i=1;
    while(V[i].isvis)
        i++;
    long long tmpmin=V[i].val;
    int tmpans=i;
    for(;i<=n;i++) {
        if(V[i].isvis)
            continue;
        if(V[i].val<V[tmpans].val) {
            tmpmin=V[i].val;
            tmpans=i;
        }
    }
    return tmpans;
}


