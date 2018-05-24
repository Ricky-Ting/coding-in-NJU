#include<iostream>
#include<cstdio>
#include<algorithm>  
using namespace std;
long long A[4001],B[4001],C[4001],D[4001];
long long E[16008002];
int n,counter;
void solve();
void input(void);
int main(void)
{
	input();
	solve();
}
void input(void)
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		scanf("%lld",&C[i]);
		scanf("%lld",&D[i]);
	}
	counter=0;
}
void solve()
{
	int num=0;
	long long tmp=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			num++;
			E[num]=A[i]+B[j];
		}
	sort(E+1,E+1+num);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			tmp=-C[i]-D[j];
			counter+=(upper_bound(E+1,E+num+1,tmp)-lower_bound(E+1,E+num+1,tmp));
		}
	printf("%d",counter);
}