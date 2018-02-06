
#include<iostream>
#include<cmath>
using namespace std;
char arr[22][80];
int n;
void input(void);
void solve(void);
int dfs(int i,int j);
void fchange(int k, int l);
void output(void);
int main(void)
{
	input();
	solve();
	output();
}

void input(void)
{
	cin>>n;
	getchar();
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<80;j++)
			arr[i][j]=getchar();
		getchar();
		
	}
	return;
}

void solve(void)
{
	int temp=1;
	while(temp<=n)
	{
		temp++;
		bool change[22][80]={false};
		for(int i=0;i<22;i++)
			for(int j=0;j<80;j++)
			{
				int value=dfs(i,j);
				if((value==1 || value==0|| value>3) && arr[i][j]=='*')
					change[i][j]=true;
				if(value==3 && arr[i][j]==' ')
					change[i][j]=true;
			}
		for(int i=0;i<22;i++)
			for(int j=0;j<80;j++)
				if(change[i][j])
					fchange(i,j);
	}
}

int dfs(int i,int j)
{
	int value=0;
	for(int k=-1;k<=1;k++)
		for(int l=-1;l<=1;l++)
			if((abs(k)+abs(l))!=0 && arr[(i+k+22)%22][(j+l+80)%80]=='*')
				value++;
	return value;
}

void fchange(int k, int l)
{
	if (arr[k][l]==' ')
		arr[k][l]='*';
	else
		arr[k][l]=' ';
}

void output(void)
{
	for(int i=0;i<22;i++)
	{
		for(int j=0;j<80;j++)
			cout<<arr[i][j];
		cout<<endl;

	}
}

