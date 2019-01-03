#include<iostream>
#include<cstdio>
using namespace std;
#define INF 10000000
int n,m,w;
int dp[400][400];
int dp2[400][400];
int rule[400][400]; //w*n;


static inline int mini(int a,int b) {
	return (a<b)?a:b;
}

void input() {
	scanf("%d%d%d",&n,&m,&w);
	int from,to,c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=INF;
	for(int i=1;i<=n;i++)
		dp[i][i]=0;


	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&from,&to,&c);
		dp[from][to]=c;
	}
	for(int i=1;i<=w;i++) {
		for(int j=1;j<=n;j++)
			scanf("%d",&rule[i][j]);
	}
}

int isin(int a, int b, int c) {
	int dp3[400][400];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp3[i][j]=dp2[i][j];
	for(int i=1;i<=n;i++) {
		dp3[b][i]=dp3[i][b]=INF;
	}

	int dis[400];
	bool vis[400];
	for(int i=1;i<=n;i++) {
		vis[i]=false;
		dis[i]=INF;
	}
	dis[a]=0;
	for(int i=0;i<n;i++){
		int v;
		int minimum=INF;
		for(int j=1;j<=n;j++) {
			if(!vis[j] && dis[j]<=minimum) {
				v=j;
				minimum=dis[j];
			}
		}
		vis[v]=true;
		for(int j=1;j<=n;j++) {
			int vv=j;
			dis[vv]=mini(dis[vv],dis[v]+dp3[v][vv]);
		}
	}

	return dis[c];

	
}

void solve() {
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp2[i][j]=dp[i][j];


	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=mini(dp[i][j],dp[i][k]+dp[k][j]);
	}
	for(int i=1;i<=w;i++) {
		int minimum=INF;
		for(int j=1;j<=n;j++) {
			int a,b,c;
			a=j;
			b=rule[i][a];
			c=rule[i][b];
			if(b==a)
				minimum=0;
			else if(c==b)
				minimum=mini(minimum,dp[a][b]);
			else if(c==a)
				minimum=mini(minimum,dp[a][b]+dp[b][a]);
			else {
				minimum=mini(minimum,isin(a,b,c)+dp[c][b]+dp[b][c]);
			}
		}
		if(minimum==INF)
			printf("bug\n");
		else
			printf("%d\n",minimum);
	}
}
int main() {
	input();
	solve();
}