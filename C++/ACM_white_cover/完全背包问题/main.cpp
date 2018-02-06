#include <iostream>
using namespace std;
int n;
int w;
int maxv;
struct thing
{
	int value;
	int weight;
};
thing things[101];
int dp[3403][12881]={0};
void input(void);
void process(void);

int main(void)
{
	input();
	process();
	cout<<maxv;
	return 0;
}

void input(void)
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>things[i].weight>>things[i].value;
	}
	return;
}

void process(void)
{
	int temp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=w;j++)
		{
			if(j>=things[i].weight)
			{
				dp[i][j]=max(dp[i][j-things[i].weight]+things[i].value,dp[i-1][j]);
				if (dp[i][j]>maxv)
					maxv=dp[i][j];
			}	
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	return;
}
