#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 10004
char fig[MAXN][MAXN];
int n,m;
int dp[MAXN];
int isvis[MAXN];
int dfs(int v);

int main() {

	scanf("%d%d",&n,&m);
	//printf("%d %d\n",n,m);
	memset(dp,0,sizeof(dp));
	memset(fig,0,sizeof(fig));
	int f,t;
	
	for(int i=0;i<m;i++) {
		scanf("%d%d",&f,&t);
		//printf("%d %d\n",f,t);
		fig[f][t] = 1;
	}

	
	//memset(isvis,0,sizeof(isvis));
	
	for(int i=1;i<=n;i++) {
		memset(isvis,0,sizeof(isvis));
		memset(dp,0,sizeof(dp));
		printf("%d ",dfs(i));
	}
}

int maxi(int a, int b) {
	return (a>b)?a:b;
}

int dfs(int v){
	
	if(dp[v]!=0)
		return dp[v];
	isvis[v] = 1;

	int ret = 0;
	for(int i=1;i<=n;i++) {
		if(fig[v][i]!=0 && isvis[i]==0) {
			ret = maxi(ret, dfs(i));
		}
	}
	dp[v]=maxi(ret,v);
	return dp[v];
}