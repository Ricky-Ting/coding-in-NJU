#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


#define MAXM 1000006

int n,m;
int a[MAXM];
int dp[MAXM][4][4];

int ans;

int maxi(int x, int y) {
	return (x>y)?x:y;
}
void get_ans(int idx, int i, int j, int sum, int minus);
int mini(int i, int j, int k) {
	int ret=2;
	if(i>0)
		ret = (ret<a[i])?ret:a[i];
	if(j>0)
		ret = (ret<a[j])?ret:a[j];
	ret = (ret<a[k])?ret:a[k];
	return ret;
}
int main() {
	scanf("%d%d\n", &n,&m);
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	int index;
	for(int i=0;i<n;i++) {
		scanf("%d",&index);
		a[index]++;
	}
	for(int i=1; i<=m;i++) {
		for(int j=0;j<=mini(i-3,i-2,i-1);j++ ) {
			for(int k=0; k<=mini(i-2,i-1,i);k++) {
				for(int l=0; l<=mini(i-1,i,i+1); l++) {
					if(j+k+l>a[i-1])
						break;
					if(k+l>a[i])
						break;
					if( (i>2) && (k+j >a[i-2] ) )
						break;
					dp[i][k][l]=maxi(dp[i][k][l],dp[i-1][j][k]+l+(a[i-1]-j-k-l)/3);
				}
			}
		}
	}
	ans=0;
	/*
	for(int i=0;i<=2;i++)
		for(int j=0;j<=2;j++)
			get_ans(1,i,j,dp[1][i][j],j);
	*/
	
	for(int i=0;i<=2;i++)
			ans=maxi(ans,dp[m][i][0] + (a[m]-i)/3 );
	printf("%d\n",ans);

}

void get_ans(int idx, int i, int j, int sum, int minus){
	if( (idx+1)==m ) {
		for(int k=0;k<=2;k++)
			ans=maxi( (sum+dp[idx+1][j][k]-minus), ans );
		return;
	}

	for(int k=0;k<=2;k++) {
		get_ans(idx+1,j,k,sum+dp[idx+1][j][k],minus+k);
	}
}



