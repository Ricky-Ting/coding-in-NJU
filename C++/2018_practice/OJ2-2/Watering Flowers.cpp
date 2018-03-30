#include<iostream>
using namespace std;

struct node
{
	long long r1;
	long long r2;
};
int n;
long long  x1,y1,x2,y2;
long long  r2_max;

long long minium;
node points[2001];
long long min(long long a, long long b);
long long max(long long a,long long b);
int main(void)
{
	cin>>n;
	cin>>x1>>y1>>x2>>y2;
	for(int i=1;i<=n;i++)
	{
		long long x,y;
		cin>>x>>y;
		points[i].r1=(x1-x)*(x1-x)+(y1-y)*(y1-y);
		points[i].r2=(x2-x)*(x2-x)+(y2-y)*(y2-y);

		if (i==1)
			;
		else
			for(int j=i;j>=2;j--)
			{
				if(points[j].r1>points[j-1].r1)
				{
					node tmp;
					tmp=points[j];
					points[j]=points[j-1];
					points[j-1]=tmp;
				}

				/*if(points2[j].r2>points2[j-1].r2)
				{
					node tmp;
					tmp=points2[j];
					points2[j]=points2[j-1];
					points2[j-1]=tmp;
				}*/
			}
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<points[i].r1<<' '<<points[i].r2<<endl;
	}
	*/


	r2_max=points[1].r2;
	minium=points[1].r1;
	for(int i=2;i<=n;i++)
	{
		r2_max=max(r2_max,points[i-1].r2);
		//cout<<r2_max<<endl;
		minium=min(minium,points[i].r1+r2_max);
		//cout<<minium<<endl;
	}
	r2_max=max(r2_max,points[n].r2);
	minium=min(minium,r2_max);
	//cout<<r2_max<<endl;

	

	cout<<minium;


}


long long min(long long a, long long b)
{
	if(a<b)
		return a;
	else 
		return b;
}

long long max(long long a,long long b)
{
	if(a>b)
		return a;
	else 
		return b;
}