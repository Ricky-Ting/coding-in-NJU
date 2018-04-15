#include<iostream>
using namespace std;

struct module
{
	bool southwall;
	bool northwall;
	bool eastwall;
	bool westwall;
	bool zhanling;
};
int n;
int m;
int room=0;
int maxi=0;
int num=0;
int value;
module castle[52][52];

void assignwall(int i, int j, int value);
void dp(int i,int j);

int main(void)
{
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>value;
			//cout<<value<<' ';
			//if(j==m) cout<<endl;
			//cout<<"Noerror()"<<"i="<<i<<"j="<<j<<endl;
			assignwall(i,j,value);
			castle[i][j].zhanling=false;
		}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!castle[i][j].zhanling)
			{
				room++;
				num=0;
				dp(i,j);
				maxi=max(maxi,num);
			}
		}
	cout<<room<<endl;
	cout<<maxi<<endl;
}


void assignwall(int i, int j, int value)
{
	if(value>=8)
	{
		castle[i][j].southwall=true;
		value=value-8;
	}
	else
	{
		castle[i][j].southwall=false;
	}
	if(value>=4)
	{
		castle[i][j].eastwall=true;
		value=value-4;
	}
	else
	{
		castle[i][j].eastwall=false;
	}
	if(value>=2)
	{
		castle[i][j].northwall=true;
		value=value-2;
	}
	else
	{
		castle[i][j].northwall=false;
	}
	if(value>=1)
	{
		castle[i][j].westwall=true;
		value=value-1;
	}
	else
	{
		castle[i][j].westwall=false;
	}

}




void dp(int i, int j)
{
	if(!castle[i][j].zhanling)
	{
		castle[i][j].zhanling=true;
		num++;
	}
	else
		return;
	if(!castle[i][j].eastwall)
		dp(i,j+1);
	if(!castle[i][j].southwall)
		dp(i+1,j);
	if(!castle[i][j].westwall)
		dp(i,j-1);
	if(!castle[i][j].northwall)
		dp(i-1,j);
	return;
}