#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;  //逐行处理 观察n与每一行长度n的联系

int T,n,m;
priority_queue<int> heap;
int a1[10000];
int a2[10000];

void solve(void)
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a1[i]);
	sort(a1+1,a1+n+1);
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%d",&a2[j]);
		sort(a2+1,a2+n+1);
		for(int j=1;j<=n;j++)
			heap.push(a1[1]+a2[j]);
		for(int j=2;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(a1[j]+a2[k]<heap.top())
				{
					heap.pop();
					heap.push(a1[j]+a2[k]);
				}
				else
					break;
		for(int j=n;j>=1;j--)
		{
			a1[j]=heap.top();
			heap.pop();
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a1[i]);
	printf("\n");
}



int main(void)
{
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		solve();
	}
}

