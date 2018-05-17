#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int num;
	int key[11];
};
node maxi,mini;  // mini中的数组按照递减顺序 maxi中的数组按照递增顺序
double average;
int n1,n2,n;
int preprocess[22];
int tmp2;

void intial(void);
void solve(void);
void up_mini(int value);
void up_maxi(int value);
void update(int value);
int main(void)
{
	scanf("%d%d%d",&n1,&n2,&n);
	while(n1!=0)
	{
		intial();
		solve();
		printf("%.6lf\n",average);
		scanf("%d%d%d",&n1,&n2,&n);
	}
	
}

void intial(void)
{
	maxi.num=mini.num=0;
	average=0;
}

void solve(void)
{
	int tmp;
	for(int i=0;i<n1+n2;i++)
		scanf("%d",&preprocess[i]);
	sort(preprocess,preprocess+n1+n2);
	for(int i=0;i<n2;i++)
		mini.key[n2-i]=preprocess[i];
	for(int i=0;i<n1;i++)
		maxi.key[i+1]=preprocess[i+n2];
	for(int i=1;i<=n-n1-n2;i++)
	{
		scanf("%d",&tmp);
		if(tmp<mini.key[1])
		{
			up_mini(tmp);
		}
		else if(tmp>maxi.key[1])
		{
			up_maxi(tmp);
		}
		else
		{
			update(tmp);
		}
	}
}

void update(int value)
{
	average+=(double(value)/double((n-n1-n2)));
}

void up_maxi(int value)
{
	tmp2=maxi.key[1];
	int counter=1;
	while(value>maxi.key[counter+1] && counter<n1)
	{
		maxi.key[counter]=maxi.key[counter+1];
		counter++;
	}
	maxi.key[counter]=value;
	update(tmp2);
}

void up_mini(int value)
{
	tmp2=mini.key[1];
	int counter=1;
	while(value<mini.key[counter+1] && counter<n2)
	{
		mini.key[counter]=mini.key[counter+1];
		counter++;
	}
	mini.key[counter]=value;
	update(tmp2);
}
