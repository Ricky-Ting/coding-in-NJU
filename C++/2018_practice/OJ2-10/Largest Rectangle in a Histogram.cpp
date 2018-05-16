#include<iostream>         //单调栈
#include<cstdio>
#
using namespace std;
 

int h[100001];
int L[100001];
int R[100001];
long long maxi;
int mystack[100001];
int n;
void input(void);
void solve(void);
long long max(long long a, long long b)
{
	return (a>b) ? a : b;
}
int main(void)
{
	scanf("%d",&n);
	while(n!=0)
	{
		input();
		solve();
		scanf("%d",&n);
	}
}

void input(void)
{
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
}

void solve(void)
{
	//求左边界
	int t=0;
	for(int i=0;i<n;i++)
	{
		while(t>0 && h[i]<=h[mystack[t-1]])
			t--;
		if(t==0)
			L[i]=0;
		else
			L[i]=mystack[t-1]+1;
		mystack[t]=i;
		t++;
	}

	//求右边界
	t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0 && h[i]<=h[mystack[t-1]])
			t--;
		if(t==0)
			R[i]=n;
		else
			R[i]=mystack[t-1];
		mystack[t]=i;
		t++;
	}
	maxi=0;
	// 求maxi
	for(int i=0;i<n;i++)
	{
		maxi=max(maxi,(long long)h[i]*(R[i]-L[i])); //要先转换
	}
	printf("%lld\n",maxi);
}
