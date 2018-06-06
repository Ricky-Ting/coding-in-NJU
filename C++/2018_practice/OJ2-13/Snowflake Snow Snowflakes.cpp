#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
const int prime=99991;
int x,y;
int n;
int tmp[10];
int snowflake[100001][7];
long long sum,key;
void solve(void);
bool cmp(int a, int b);
vector<int> hsh[prime];
int main(void)
{
	solve();
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			scanf("%d",&snowflake[i][j]);
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=0;j<6;j++)
			sum+=snowflake[i][j];
		key=sum%prime;
		for(int k=0;k<hsh[key].size();k++)
			if(cmp(i,hsh[key][k]))
			{
				printf("Twin snowflakes found.\n");
				return;
			}
		hsh[key].push_back(i);
	}
	printf("No two snowflakes are alike.\n");
}

bool cmp(int a, int b)
{
	for(int i=0;i<6;i++)
	{
		if(
			(snowflake[a][0]==snowflake[b][i] && snowflake[a][1]==snowflake[b][(i+1)%6] &&
			snowflake[a][2]==snowflake[b][(i+2)%6] && snowflake[a][3]==snowflake[b][(i+3)%6] &&
			snowflake[a][4]==snowflake[b][(i+4)%6] && snowflake[a][5]==snowflake[b][(i+5)%6] )
			||
			(snowflake[a][0]==snowflake[b][i] && snowflake[a][1]==snowflake[b][(i+5)%6] &&
			snowflake[a][2]==snowflake[b][(i+4)%6] && snowflake[a][3]==snowflake[b][(i+3)%6] &&
			snowflake[a][4]==snowflake[b][(i+2)%6] && snowflake[a][5]==snowflake[b][(i+1)%6] )
			)
			return true;
	}
	return false;
}