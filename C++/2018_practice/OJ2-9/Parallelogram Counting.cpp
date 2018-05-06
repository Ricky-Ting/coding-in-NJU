#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int x;
	int y;
};

void input(void);
void solve(void);
int zuheshu(int a);
bool cmp(const node &a, const node &b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	else
		return a.y<b.y;  
}           //cmp函数一开始写错

node nodes[1005];
node middle[500000];
int t,n;
int counter=-1;
int ans=0;
int main(void)
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		input();
		solve();
	}
}

void input(void)
{
	ans=0;
	counter=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>nodes[i].x>>nodes[i].y;

}

void solve(void)
{
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
		{
			counter++;
			middle[counter].x=nodes[i].x+nodes[j].x;
			middle[counter].y=nodes[i].y+nodes[j].y;
		}
	sort(middle,middle+counter+1,cmp);
/*
	for(int i=0;i<=counter;i++)
	{
		cout<<endl;
		cout<<middle[i].x<<" "<<middle[i].y<<endl;
	}
*/

	int tmp=1;
	for(int i=0;i<counter;i++)
	{
		if(middle[i].x==middle[i+1].x && middle[i].y==middle[i+1].y)
		{
			tmp++;
		}
		else
		{
			ans+=zuheshu(tmp);
			tmp=1;
		}
	}
	ans+=zuheshu(tmp);
	cout<<ans<<endl;
}

int zuheshu(int a)
{
	return (a*(a-1))/2;
}

