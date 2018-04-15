#include<iostream>
#include<string>
#include<map>
using namespace std;

map<int,int> table;
int n;
int A[25];
string bones[26];
int bitcount(int x)
{
	return x==0 ? 0 : bitcount(x/2)+(x&1);
}

int main(void)
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>bones[i];

		A[i]=0;
		for(int j=0;j<bones[i].length();j++)
			A[i] ^=(1<<(bones[i][j]-'A'));
	}
	table.clear();
	int n1=n/2;
	int n2=n-n1;
	for(int i=0;i<(1<<n1);i++)
	{
		int x=0;
		for(int j=0;j<n1;j++)   //选择某些bones来计算
			if(i & (1<<j))
				x^=A[j];
		if(!table.count(x)||bitcount(table[x])<bitcount(i))
			table[x]=i;
	}
	int ans=0;
	for(int i=0;i<(1<<n2);i++)
	{
		int x=0;
		for(int j=0;j<n2;j++)
			if(i & (1<<j)) 
				x^=A[n1+j];
		if(table.count(x) && bitcount(ans)<bitcount(table[x])+bitcount(i))
			ans=(i<<n1)^table[x];
	}
	cout<<bitcount(ans)<<endl;
	for(int i=0;i<n;i++)
		if(ans & (1<<i))
			cout<<i+1<<' ';
	return 0;
}