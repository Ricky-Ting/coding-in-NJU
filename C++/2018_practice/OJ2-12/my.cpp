#include<iostream>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<cstdio>
int tmp[10];
int snowflake[100001][7];
int x,y;
int n;
void input(void)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++)
			scanf("%d",&snowflake[i][j]);

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

void solve(void)
{
	for(int i=1;i<=20000000;i++)
	{
		x=rand()%n;
		y=rand()%n;
		if(x!=y)
			if(cmp(x,y))
			{
				printf("Twin snowflakes found.\n");
				return;
			}
	}
	printf("No two snowflakes are alike.\n");
}
int main(void)
{
	srand(time(NULL));
	input();
	solve();
}
