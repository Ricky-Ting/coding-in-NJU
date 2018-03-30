#include<iostream>
using namespace std;

#define money 1000;
struct house_property
{
	int price;
	int area;
	int whether_buy;	
};

struct city
{
	house_property house[16];
	int num;
};

struct situation
{
	int citysit[6][2];
	int area;
};

void initialize(situation dp[6][1001]);
void input_area(city cities[]);
void input_price(city cities[]);

int main(void)
{
	city cities[6];
	situation dp[6][1001];
	initialize(dp);
	input_area(cities);
	input_price(cities);
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			for(int k=1;k<=cities[i].num;k++)
			{
				if(cities[i].house[k].price<=j && dp[i][j-cities[i].house[k].price].citysit[i][1]==0 && dp[i][j-cities[i].house[k].price].citysit[i][0]!=k )
				{
					if(dp[i-1][j].area>=dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area && dp[i-1][j].area>=dp[i][j-1].area && dp[i-1][j].area>=dp[i][j].area)
					{
						dp[i][j]=dp[i-1][j];
					}
					else if(dp[i-1][j].area>=dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area && dp[i-1][j].area>=dp[i][j].area && dp[i-1][j].area>=dp[i][j-1].area && dp[i-1][j].area>=dp[i][j].area)
					{
						dp[i][j]=dp[i][j-1];
					}
					else if(dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area>dp[i][j].area && dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area>dp[i-1][j].area && dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area>dp[i][j-1].area && dp[i][j-cities[i].house[k].price].citysit[i][1]==0)
					{
						dp[i][j]=dp[i][j-cities[i].house[k].price];
						dp[i][j].area=dp[i][j-cities[i].house[k].price].area+cities[i].house[k].area;
						if(dp[i][j].citysit[i][0]==0)
							dp[i][j].citysit[i][0]=k;
						else
							dp[i][j].citysit[i][1]=k;
					}
					else
					{
						;
					}
					

				}
				else
				{
					if(dp[i-1][j].area>=dp[i][j-1].area && dp[i-1][j].area>=dp[i][j].area)       //如果相等怎么办
						dp[i][j]=dp[i-1][j];
					else if(dp[i][j-1].area>=dp[i-1][j].area && dp[i][j-1].area>=dp[i][j].area)  //???
						dp[i][j]=dp[i][j-1];
				}
			}
		}
	}

	for(int i=1;i<=5;i++)
		for(int j=0;j<=1;j++)
			if(dp[5][1000].citysit[i][j]!=0)
				cities[i].house[dp[5][1000].citysit[i][j]].whether_buy=1;

	cout<<dp[5][1000].area<<endl;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=cities[i].num;j++)
			cout<<cities[i].house[j].whether_buy;
		cout<<endl;
	}
	//cout<<dp[5][1000].citysit[2][0]<<' '<<dp[5][1000].citysit[2][1];
	return 0;



}


void input_area(city cities[])
{
	int tmp=0;
	for(int i=1;i<=5;i++)
	{
		cin>>tmp;
		int j=1;
		while(tmp!=-1)
		{
			cities[i].house[j].area=tmp;
			cities[i].house[j].whether_buy=0;
			cin>>tmp;
			j++;
		}
		cities[i].num=j-1;
	}
}


void input_price(city cities[])
{
	int tmp=0;
	for(int i=1;i<=5;i++)
	{
		cin>>tmp;
		int j=1;
		while(tmp!=-1)
		{
			cities[i].house[j].price=tmp;
			cin>>tmp;
			j++;
		}
		cities[i].num=j-1;
	}
}











void initialize(situation dp[6][1001])
{
	for(int i=1;i<=5;i++)
		for(int j=0;j<=1000;j++)
		{
			dp[i][j].area=0;
			for(int k=1;k<=5;k++)
			{
				for(int m=0;m<=1;m++)
					dp[i][j].citysit[k][m]=0;
			}
		}
		
}