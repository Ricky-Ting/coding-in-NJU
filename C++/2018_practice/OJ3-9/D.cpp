#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 1000

int dp[MAXN][MAXN];
int n,m;
int matching[MAXN];
int check[MAXN];

void init() {
	memset(dp,0,sizeof(dp));
}

void input(){
	init();
	int from,to;
	for(int i=0;i<m;i++){
		scanf("%d%D",&from,&to);
		dp[from][to]=1;
	}
}

void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][k] && dp[k][j])
					dp[i][j]=1;
}



bool dfs(int u)
{
    for (int i =1; i <=n; ++i) {
        int v;
       	if(dp[u][i])
       		v=i;
       	else
       		continue;
        if (!check[v]) {     
            check[v] = true; 
            if (matching[v] == -1 || dfs(matching[v])) {
                matching[v] = u;
                return true;
            }
        }
    }
    return false; 
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=1; u <= n; ++u) {
        
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    
    return ans;
}

void solve(){
	floyd();
	printf("%d\n",n-hungarian());
}


int main(){
	while(1) {
		scanf("%d%d",&n,&m);
		//printf("%d %d\n",n,m);
		if(n==0)
			return 0;
		input();
		solve();
	}
}