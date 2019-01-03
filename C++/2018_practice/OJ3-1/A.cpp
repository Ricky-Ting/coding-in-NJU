#include<iostream>
using namespace std;
int T,n;
int a[3001];
int b[3001]={0};
int Max;
void solve(void);
int main(void)
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);

		solve();
		printf("%d\n",n-Max);
	}
	
}


void solve(void)
{
	Max=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=1;
		for(int j=i-1;j>=1;j--)
		{
			if(a[j]<a[i] && a[i]-a[j]>=i-j && b[i]<=b[j])
				b[i]=b[j]+1;
		}
		if(b[i]>Max)
			Max=b[i];
	}

}

