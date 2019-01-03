#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;
int n,m;
#define MAXN 18
#define INF 1000000000
int zt[1<<MAXN];
int dp[MAXN][MAXN];
int total=0;
int degree[MAXN];
int a;
vector<int> v;


int mini(int a, int b) {
	return (a<b)?a:b;
}

void input() {
	scanf("%d%d",&n,&m);
	bool output=false;
	//printf("%d %d\n",n,m);
	//if(n==2 && m==9)
	//	output=true;
	total=0;
	for(int i=0;i<1<<MAXN;i++)
		zt[i]=INF;
	memset(degree,0,sizeof(degree));
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			dp[i][j]=INF;
	for(int i=0;i<MAXN;i++) 
		dp[i][i]=0;	
	int from,to,w;
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",&from,&to,&w);
		if(output)
			printf("%d %d %d\n",from,to,w);
		from--; to--;
		if(w<dp[from][to])
			dp[from][to]=dp[to][from]=w;
		total+=w;
		degree[from]++;
		degree[to]++;
	}
}

int myget(int x) {
	if(x==0)
		return 0;
	if(zt[x]!=INF)
		return zt[x];
	for(int i=0;i<n;i++)
		if((1<<i)&x)
			for(int j=0;j<n;j++)
				if((1<<j)&x && i!=j)
					zt[x]=mini(zt[x],myget(x^(1<<i)^(1<<j))+dp[v[i]][v[j]]);
	return zt[x];
}



void solve() {
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=mini(dp[i][j],dp[i][k]+dp[k][j]);
	}
	v.clear();
	for(int i=0;i<n;i++) {
		if(degree[i]&1)
			v.push_back(i);
	}
	a=(1<<(int)(v.size()))-1;
	total=total+myget(a);
	printf("%d\n",total);
}

int main() {
	input();
	solve();
}
