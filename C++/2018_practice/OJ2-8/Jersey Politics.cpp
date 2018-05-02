#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct population
{
	int people;
	int city;
	bool operator <(const population &xx)const
    {
    	return people>xx.people;
	}
};


population census[220];
int K;
bool flag;
int sum[220];
bool use[220];

void dfs(int t,int ret, int ans);



bool cmp(const population &i, const population &j)
{
	return i.people<j.people;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	cin>>K;
	for(int i=1;i<=3*K;i++)
	{
		cin>>census[i].people;
		census[i].city=i;
	}
	
	sort(census+1,census+3*K+1);
	sort(census+1,census+2*K+1,cmp);
	for(int i=2*K+1;i<=3*K;i++)
		cout<<census[i].city<<endl; //k个最小的归为一组
	sum[0]=0;
	for(int i=1;i<=2*K;i++)
		sum[i]=sum[i-1]+census[i].people; //计算前i个的和

	flag=false;
	memset(use,0,sizeof(use));
	dfs(K+K,0,0);
	return 0;

}

void dfs(int t,int ret, int ans)
{
	if(flag)
		return;
	if(ret==K)
	{
		if(ans>K*500 && sum[2*K]-ans>K*500)
		{
			for(int i=1;i<=K*2;i++)
				if(use[i])
					cout<<census[i].city<<endl;
			for(int i=1;i<=2*K;i++)
				if(!use[i])
					cout<<census[i].city<<endl;
			flag=true;
		}
		return ;
	}
	
	
	if(ans+sum[t]-sum[t-(K-ret)]<=K*500)
		return;
	if(sum[K*2]-(ans+sum[K-ret])<=K*500)
		return;
	for(int i=t;i>=K-ret;i--)
	{
		use[i]=1;
		dfs(i-1,ret+1,ans+census[i].people);
		use[i]=0;
	}
}
