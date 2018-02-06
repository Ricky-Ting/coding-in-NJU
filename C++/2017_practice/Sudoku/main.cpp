#include<iostream>
using namespace std;
char sudoku[10][10];
int n;
struct node
{
	int x;
	int y;
};
node middle;
bool found;
void input(void);
void dfs(int s,int t);
bool satisfied(int s,int y,char i);
void output(void);
void whichcolumn(int s,int t);
int main(void)
{
	cin>>n;
	getchar();
	for(int i=1;i<=n;i++)
	{
		found=false;
		input();
		int l,k;
		l=k=1;
		while(sudoku[l][k]!='0')
			{
				if(k==9)
				{
					if(l==9)
					{
						found=true;
						break;
					}		
					else
					{
						l++;
						k=1;
					}
					
				}
				else
					k++;
			}
			if(found)
				output();
			else
				dfs(l,k);
			if(found)
				output();
			
		
	}
	return 0;
}


void input(void)
{
	for(int i=1;i<=9;i++)
	{
		for(int k=1;k<=9;k++)
			cin>>sudoku[i][k];
		getchar();
	}
	return;

}


void output(void)
{
	for(int i=1;i<=9;i++)
	{
		for(int k=1;k<=9;k++)
			cout<<sudoku[i][k];
		cout<<endl;
	}
	return;

}

void dfs(int s,int t)
{
	if(found)
		return;
	for(char i='1';i<='9';i++)
	{
		if(satisfied(s,t,i))
		{
			int l=s;
			int k=t;
			sudoku[s][t]=i;
			while(sudoku[l][k]!='0')
			{
				if(k==9)
				{
					if(l==9)
					{
						found=true;
						return;
					}		
					else
					{
						l++;
						k=1;
					}
					
				}
				else
					k++;
			}
			dfs(l,k);
			if(found)
				return;
		}
	}
	if(!found)
		sudoku[s][t]='0';
	return;
}

bool satisfied(int s,int t, char i)
{
	for(int j=1;j<=9;j++)
		if((sudoku[s][j]==i) && (j!=t))
			return false;
	for(int j=1;j<=9;j++)
		if((sudoku[j][t]==i) && (j!=s))
			return false;
	whichcolumn(s,t);
	for(int j=-1;j<=1;j++)
		for(int k=-1;k<=1;k++)
		{
			if((!(middle.x+j==s && middle.y+k==t)) && (sudoku[middle.x+j][middle.y+k]==i))
				return false;
		}
	return true;
}

void whichcolumn(int s,int t)
{
	middle.x=((s-1)/3)*3+2;
	middle.y=((t-1)/3)*3+2;
	return;
}


