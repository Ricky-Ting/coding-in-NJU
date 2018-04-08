#include<iostream>
using namespace std;

int f[101000];
int main(void)
{
	int n,k,m;
	cin>>n;
	while(n!=0)
	{
		cin>>k>>m;
		f[1]=0;
		for(int i=2;i<n;i++)
			f[i]=(f[i-1]+k)%i;
		f[n]=(f[n-1]+m)%n;
		cout<<f[n]+1<<endl;
		cin>>n;
	}
}