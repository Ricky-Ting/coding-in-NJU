#include<iostream>
using namespace std;

struct node
{
	int x;
	int y;
};

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	node nodes[701];
	while(1)
	{
		cin>>n;
		if(n==1)
			cout<<1<<endl;
		else if(n==2)
			cout<<2<<endl;
		else if(n==0)
			return 0;
		else
		{
			int maxi=2;
			for(int i=1;i<=n;i++)
				cin>>nodes[i].x>>nodes[i].y;
			for(int i=1;i<=n-1;i++)
				for(int j=i+1;j<=n;j++)
				{
					int inner=2;
					for(int k=j+1;k<=n;k++)
					{
						if((nodes[i].y-nodes[k].y)*(nodes[i].x-nodes[j].x)==(nodes[i].x-nodes[k].x)*(nodes[i].y-nodes[j].y))
							inner++;
					}
					maxi=max(maxi,inner);
				}
			cout<<maxi<<endl;
		}
	}
}