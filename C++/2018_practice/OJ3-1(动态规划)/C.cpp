#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long h[40][40];
int n,m;
string s[40];
int main(void)
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	memset(h,0,sizeof(h));
	h[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=m;j++)
		{
			if(j!=0)
			{
				if(s[i][j-1]=='R')
				{
					for(int k=m-1;k>j-1;k--)
					{
						if(s[i][k]=='B')
						{
							cout<<0<<endl;
							return 0;
						}
					}
					break;
				}
				else if(s[i][j-1]=='B')
				{
					for(int k=0;k<j;k++)
						h[i][k]=0;
				}
			}
			for(int k=0;k<=j;k++)
			{
				h[i][j]+=h[i+1][k];
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=m;i++)
		ans+=h[1][i];
	cout<<ans<<endl;
}




