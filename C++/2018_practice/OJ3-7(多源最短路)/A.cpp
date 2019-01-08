#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;
#define INF 10000000
int n,m;

string A[101];
int dp[101][101];

int maxi(int a,int b) {
	return (a>b)?a:b;
}
int mini(int a,int b) {
	return (a<b)?a:b;
}



int hanming(string a, string b) {
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i])
			cnt++;
	}
	return cnt*cnt;
}

void input() {
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) {
			dp[i][j]=dp[j][i]=hanming(A[i],A[j]);
		}
}


void solve(void){
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dp[i][j]=mini(dp[i][j],dp[i][k]+dp[k][j]);
	}
	int ans=INF;
	for(int i=0;i<n;i++) {
		int maximum=0;
		for(int j=0;j<n;j++) {
			maximum=maxi(maximum,dp[i][j]);
		}
		ans=mini(maximum,ans);
	}
	cout<<ans<<endl;

}
int main(void) {
	input();
	solve();
}