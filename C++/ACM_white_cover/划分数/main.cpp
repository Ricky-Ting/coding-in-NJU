#include<iostream>
using namespace std;

int dp[1001][1001]={0};
int main(void)
{
	int n,m,M;
	cin>>n>>m>>M;
	dp[0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<=n;j++)
		{
			if(j-i<0)
				dp[i][j]=dp[i-1][j]%M;
			else
			
				dp[i][j]=(dp[i][j-i]+dp[i-1][j])%M;	
		}
	cout<<dp[m][n];
	
	return 0;
}

