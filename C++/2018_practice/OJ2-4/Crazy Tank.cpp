#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.1415926  

double solve_equation(double v, double theta,double H);

int main(void)
{
	double speed[207];
	double H,L1,R1,L2,R2;
	int n;
	cin>>n;
	while(n!=0)
	{
		int maxi=0;
		
		cin>>H>>L1>>R1>>L2>>R2;
		for(int i=1;i<=n;i++)
			cin>>speed[i];
		for(int i=0;i<=2000;i++)
		{
			int counter=0;
			for(int j=1;j<=n;j++)
			{
				double s=solve_equation(speed[j],double(double(i)/double(2000))*PI,H);
				if((s>=L1) && (s<=R1))
				{
					counter++;
				}
				if(s>=L2 && s<=R2)
				{
					counter=0;
					break;
				}
			}
			maxi=max(maxi,counter);
		}


		cout<<maxi<<endl;
		cin>>n;
	}
}


double solve_equation(double v, double theta,double H)
{
	double delta=sqrt(v*v*cos(theta)*cos(theta)+4*4.9*H);
	double t=(-v*cos(theta)+delta)/9.8;
	double s=v*sin(theta)*t;
	return s;
}