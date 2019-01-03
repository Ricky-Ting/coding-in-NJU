#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 10000000

using namespace std;
struct node
{
	int men;
	int suipian;
};

static inline int mini(int a,int b) {
	return (a<b)?a:b;
}

int n,m1,m2;
int T,K;
node choice[200];
int dp1[200][200];
int dp2[200][200];
int ans[200];

void input() {
	scanf("%d%d%d",&n,&m1,&m2);
	scanf("%d%d",&T,&K);

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp1[i][j]=dp2[i][j]=INF;
	for(int i=1;i<=n;i++)
		dp1[i][i]=dp2[i][i]=0;

	for(int i=0;i<T;i++)
		scanf("%d",&choice[i].men);
	for(int i=0;i<T;i++)
		scanf("%d",&choice[i].suipian);
	int from,to,c;
	for(int i=1;i<=m1;i++) {
		scanf("%d%d%d",&from,&to,&c);
		dp1[from][to]=c;
	}
	for(int i=1;i<=m2;i++) {
		scanf("%d%d%d",&from,&to,&c);
		dp2[from][to]=c;
	}

}

void solve() {
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp1[i][j]=mini(dp1[i][j],dp1[i][k]+dp1[k][j]);
	}

	
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp2[i][j]=mini(dp2[i][j],dp2[i][k]+dp2[k][j]);
	}
	for(int i=0;i<T;i++) {
		ans[i]=dp1[1][choice[i].men]+dp2[choice[i].men][choice[i].suipian];
		//printf("%d ",ans[i]);
	}
	sort(ans,ans+T);
	int output=0;
	for(int i=0;i<K;i++)
		output+=ans[i];
	if(output>=INF)
		printf("-1\n");
	else
		printf("%d\n",output);
}

int main() {
	input();
	solve();
	return 0;
}