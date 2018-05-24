#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int a[3442952];
int k[10],p[10];
int counter,n,M;
int num=0;
int tmp=0;
void cal2(int deep, int value);
void cal1(int deep, int value);
void input(void);
void solve(void);
int main(void)
{
	input();
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	solve();
}

void input(void)
{
	scanf("%d",&n);
	scanf("%d",&M);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&k[i],&p[i]);
	counter=0;
}

void solve(void)
{
	int d=n/2;
	cal1(1,0);
	sort(a+1,a+num+1);
	cal2(n/2+1,0);
	printf("%d\n",counter);
}

void cal1(int deep,int value)
{
	if(deep==(n/2+1))
	{
		num++;
		a[num]=value;
		return;
	}
	tmp=0;
	for(int i=1;i<=M;i++)
	{
		tmp=k[deep]*pow(i,p[deep]);
		tmp+=value;
		cal1(deep+1,tmp);
	}
}

void cal2(int deep, int value)
{
	if(deep==(n+1))
	{
		value=-value;
		counter+=upper_bound(a+1,a+num+1,value)-lower_bound(a+1,a+num+1,value);
		return;
	}
	for(int i=1;i<=M;i++)
	{
		tmp=k[deep]*pow(i,p[deep]);
		tmp+=value;
		cal2(deep+1,tmp);
	}
}
