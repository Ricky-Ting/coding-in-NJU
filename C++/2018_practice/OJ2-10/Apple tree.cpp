#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > tree(100001);
int start[100001],endp[100001];
int f[100001],bit[100001];
int N,u,v,M,x,step;

void dfs(int x);

int lowbit(int x)
{
	return x&(-x);
}

void add(int pos, int x);

int sum(int pos);

int main()
{
	char type;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
	}
	step=1;
	dfs(1);
	for(int i=1;i<=N;i++)
	{
		add(start[i],1);
		f[i]=1;
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		scanf(" %c%d",&type,&x);
		if(type=='C')
		{
			add(start[x],(f[x]^1)-f[x]);
			f[x]^=1;
		}
		else printf("%d\n",sum(endp[x])-sum(start[x]-1));

	}
}

void dfs(int x)
{
	start[x]=step;
	for(int i=0;i<tree[x].size();i++)
	{
		step++;
		dfs(tree[x][i]);
	}
	endp[x]=step;
	return;
}

void add(int pos,int x)
{
	while(pos<=N)
	{
		bit[pos]+=x;
		pos+=lowbit(pos);
	}
	return;
}

int sum(int pos)
{
	int ans=0;
	while(pos>0)
	{
		ans+=bit[pos];
		pos-=lowbit(pos);
	}
	return ans;
}