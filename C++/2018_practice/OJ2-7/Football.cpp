#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

double dp[150][200];
double a[200][200];
int n;
int main(void)
{
	while(~scanf("%d",&n),n+1)
	{
		int m=1<<n;
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				scanf("%lf",&a[i][j]);				
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++) 
			dp[0][i]=1;
		for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    int p=k>>(i-1);
                    int q=j>>(i-1);  
                    if(p&1)
                    {
                        p--;
                        if(p==q)
                        {
                            dp[i][j]+=dp[i-1][j]*dp[i-1][k]*a[j][k];
                        }
                    }
                    else
                    {
                        p++;
                        if(p==q)
                        {
                            dp[i][j]+=dp[i-1][j]*dp[i-1][k]*a[j][k];
                        }
                    }
                }
            }
        }
		int ans=0;
        for(int i=0;i<m;i++)
        {
            if(dp[n][i]>dp[n][ans])
            {
                ans=i;
            }
        }
        ans++;
		cout<<ans<<endl;
	}
		
	return 0;
}