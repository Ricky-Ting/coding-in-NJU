#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#include <iomanip> 

bool compare(double a, double b)
{
	return a<b;
}

int main(void)
{
	cout.setf(ios::fixed);
	int C;
	cin>>C;
	for(int k=1;k<=C;k++)
	{
		double height[101];
		int N,H,T;
		double R;
		cin>>N>>H>>R>>T;
		R=R/100;
		for(int i=0;i<N;i++)
		{
			double tmp=T-i;
			if(tmp<=0)
			{
				height[i]=H;
				continue;
			}
			double Ti=2*sqrt(double(H)/double(5));
			while(tmp>0)
			{
				tmp-=Ti;
			}
			tmp+=Ti;
			if(tmp>Ti/2)
				tmp=Ti-tmp;
			height[i]=H-5*tmp*tmp;
		}
		sort(height,height+N,compare);

		for(int i=0;i<N;i++)
		{
			height[i]+=2*i*R;
			cout<<fixed<< setprecision(2)<<height[i]<<' ';
		}
		cout<<endl;
	}
}