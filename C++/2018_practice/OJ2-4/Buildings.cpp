#include<iostream>
#include<algorithm>
using namespace std;

struct floorss
{
	int w;
	int s;
	int sum;
	
};


bool compare(floorss floor1,floorss floor2)
{
	return floor1.sum>floor2.sum;
}



int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		long long sum=0;
		floorss floors[100002];
		for(int i=0;i<=n-1;++i)
		{
			cin>>floors[i].w;
			cin>>floors[i].s;
			floors[i].sum=floors[i].w+floors[i].s;
			sum+=floors[i].w;
		}
		
		sort(floors,floors+n,compare);
		long long maxi=0;
		

		for(int i=0;i<n;++i)
		{
			sum-=floors[i].w;
			if(sum-floors[i].s>maxi)
				maxi=sum-floors[i].s;
		}
		cout<<maxi<<endl;
	}
}
