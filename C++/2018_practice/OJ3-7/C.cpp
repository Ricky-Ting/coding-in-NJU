#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1001
#define MAXM 50005

struct edge
{
	int u;
	int v;
};
edge E[MAXM+1];
struct node {
	int vertice;
	int next;
};
int head[MAXN+1];
node V[2*MAXM+1];
bool isvis[MAXN+1];
bool isgedian[MAXN+1];
int dfn[MAXN+1];
int low[MAXN+1];
int fa[MAXN+1];
int counter;
int cnt,cnt2;
int n,m;

bool cmp(edge x, edge y) {
	return (x.u<y.u) || ((x.u==y.u) && (x.v<y.v) );
}

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
	cnt2=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(fa,0,sizeof(fa));
	memset(head,-1,sizeof(head));
	for(int i=0;i<=2*m+2;i++) {
		V[i].next=-1;
	}
	for(int i=1;i<=n;i++) {
		isvis[i]=isgedian[i]=false;
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





void tarjan(int u) {
	int son=0;
	isvis[u]=true;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];i!=-1;i=V[i].next) {
		int v=V[i].vertice;
		if(!dfn[v]) {
			son++;
			fa[v]=u;
			tarjan(v);
			low[u]=mini(low[u],low[v]);
			if(fa[u]==0 && son>1) {
				isgedian[u]=true;
			}
			if(fa[u]!=0 && low[v]>=dfn[u]) {
				isgedian[u]=true;
			}
			if(low[v]>dfn[u]) {
				E[cnt2].u=mini(u,v);
				E[cnt2].v=maxi(u,v);
				cnt2++;
			}

		}
		else if(v !=fa[u])
			low[u]=min(low[u],dfn[v]);
	}
}

void solve(void) {
	tarjan(1);
	bool flag=false;
	for(int i=1;i<=n;i++)
		if(isgedian[i]) {
			printf("%d ",i);
			flag=true;
		}
	if(flag)
		printf("\n");
	else
		printf("Null\n");
	sort(E,E+cnt2,cmp);
	for(int i=0;i<cnt2;i++)
		printf("%d %d\n",E[i].u,E[i].v);
}

int main() {
	input();
	solve();
}

