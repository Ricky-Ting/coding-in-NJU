#include<iostream>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;

struct node
{
	int weight;
};


int n;
node people[101];
int sum[101];

int main(void)
{
	srand(time(NULL));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>people[i].weight;

	}
	int s1,s2,differ;
	s1=s2=0;

	for(int i=1;i<=n/2;++i)
		s1+=people[i].weight;
	for(int i=n/2+1;i<=n;++i)
		s2+=people[i].weight;
	differ=abs(s1-s2);
	for(int i=1;i<=10000;i++)
	{
		if(differ==0) break;
		int x,y;
		x=(rand()%(int(n/2)))+1;
		y=(rand()%(n-n/2))+1+n/2;
		int tmp;
		tmp=abs(s1-s2-2*people[x].weight+2*people[y].weight);
		if(tmp<differ)
		{
			s1=s1-people[x].weight+people[y].weight;
			s2=s2+people[x].weight-people[y].weight;
			int tmp2=0;
			tmp2=people[x].weight;
			people[x].weight=people[y].weight;
			people[y].weight=tmp2;
			differ=tmp;

		}
	}

	cout<<min(s1,s2)<<" "<<max(s1,s2)<<endl;

}







