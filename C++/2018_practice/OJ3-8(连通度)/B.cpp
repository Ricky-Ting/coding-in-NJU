#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 10005

struct node {
	int vertice;
	int next;
};
int head[MAXN];
int n,m;
node V[20006];
int counter;
int sub[MAXN];
int low[MAXN];
int dfn[MAXN];
bool isvis[MAXN];
int cnt;
int f;
int flag;
int T;

int mini(int a, int b){
	return (a<b)?a:b;
}
int maxi(int a, int b){
	return (a>b)?a:b;
}

void input() {
	counter=0;
	for(int i=0;i<=20005;i++)
		V[i].next=-1;
	for(int i=1;i<=1005;i++) {
		head[i]=-1;
	}
	
	int to,from;
	while(1) {
		scanf("%d",&from);
		//printf("from:%d\n",from);
		if(from==0) {
			//printf("in\n");
			if(f==0){
				flag=2;
				//printf("flag2\n");
				return;
			}
			else {
				scanf("%d",&to);
				flag=1;
				f=to;
				//printf("flag1\n");
				return;
			}
		}
		scanf("%d",&to);
		f=to;
		n=maxi(n,from);
		n=maxi(n,to);
		V[counter].vertice=to;
		if(head[from]==-1)
			head[from]=counter;
		else {
			int tmp=head[from];
			while(V[tmp].next!=-1) {
				tmp=V[tmp].next;
			}
			V[tmp].next=counter;
		}
		counter++;
		V[counter].vertice=from;
		if(head[to]==-1)
			head[to]=counter;
		else {
			int tmp=head[to];
			while(V[tmp].next!=-1) {
				tmp=V[tmp].next;
			}
			V[tmp].next=counter;
		}
		counter++;
	}
}

void tarjan(int x) {
	isvis[x]=true;
	dfn[x]=low[x]= ++cnt;
	for(int i=head[x];i!=-1;i=V[i].next) {
		int v=V[i].vertice;
		if(!isvis[v]) {
			tarjan(v);
			low[x]=mini(low[x],low[v]);
			if(low[v]>=dfn[x]) {
					sub[x]++;
			}
		}
		else
			low[x]=mini(low[x],dfn[v]);
	}
	return;
}

void solve() {
	for(int i=1;i<=n;i++) {
		sub[i]=dfn[i]=low[i]=0;
		isvis[i]=false;
	}
	cnt=0;
	tarjan(1);
	bool hassub=false;
	printf("Network #%d\n",T);
	if(sub[1]>1) 
		sub[1]-=1;
	else
		sub[1]=0;
	for(int i=1;i<=n;i++) {
		if(sub[i]!=0) {
			hassub=true;
			sub[i]+=1;
			printf("SPF node %d leaves %d subnets\n",i,sub[i]);
		}
	}
	if(!hassub)
		printf("No SPF nodes\n");
	return;
}

int main() {
	T=1;
	f=1;
	flag=0;
	n=-1;
	while(1) {
		input();
		if(flag==2) 
			return 0;
		//printf("inn\n");
		solve();
		T++;
	}
	
	
}