#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
int a[1000001];
int n,p;
int main(void)
{
	scanf("%d",&p);
	for(int i=0;i<p;i++)
		scanf("%d",&a[i]);
	set<int> all;
	for(int i=0;i<p;i++)
		all.insert(a[i]);
	int n=all.size(); //统计知识点数目
	int s=0,t=0,num=0;
	map<int,int>count;
	int res=p;
	while(1)
	{
		while(t<p && num<n)
			if(count[a[t++]]++==0)
				num++;
		if(num<n) break;
		res=min(res,t-s);
		if(--count[a[s++]]==0)
			num--;
	} //尺取法
	printf("%d\n",res);
}