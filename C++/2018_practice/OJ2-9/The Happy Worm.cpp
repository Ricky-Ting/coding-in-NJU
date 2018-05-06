#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x;
	int y;
};

bool cmp1(const node &a, const node &b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;
}

bool cmp2(const node &a, const node &b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	else
		return a.x<b.x;
}

void input(void);
void solve(void);

int m,n,k,t,newk,ans;
node stone[1310730];

int main(void)
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		input();
		solve();
		cout<<ans<<endl;
	}
}

void input(void)
{
	ans=0;
	scanf("%d",&m);
	scanf("%d",&n);
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&stone[i].x);
		scanf("%d",&stone[i].y);
	}

}

void solve(void)
{
	stone[0].x=1;
	stone[0].y=0;
	stone[k+1].x=m;
	stone[k+1].y=n+1;
	sort(stone+1,stone+k+1,cmp1);
	for(int i=1;i<=k+1;i++)
	{
		if(stone[i-1].x==stone[i].x)
		{
			if(stone[i].y-stone[i-1].y>=3)
				ans++;
		}
		else
		{
			ans+=stone[i].x-stone[i-1].x-1;
			if(n-stone[i-1].y>=2)
				ans++;
			if(stone[i].y-1>=2)
				ans++;
		}
	}
	stone[0].x=0; stone[0].y=1; stone[k+1].x=m+1; stone[k+1].y=n;
	sort(stone+1,stone+k+1,cmp2);
	for(int i=1;i<=k+1;i++)
	{
		if(stone[i-1].y==stone[i].y)
		{
			if(stone[i].x-stone[i-1].x>=3)
				ans++;
		}
		else
		{
			ans+=stone[i].y-stone[i-1].y-1;
			if(m-stone[i-1].x>=2)
				ans++;
			if(stone[i].x-1>=2)
				ans++;
		}

	}
}