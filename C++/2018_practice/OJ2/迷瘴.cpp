#include<iostream>
#include<iomanip>
using namespace std;
int n,V,W;
int cure[101];
int V_current=0;
double W_current=0;

void input(void);
void mysort(void);
int main(void)
{
	int C;
	cin>>C;
	for(int i=1;i<=C;i++)
	{
		input();
		mysort();
		if(cure[1]>W)
		{
			cout<<0<<' '<<setiosflags(ios::fixed)<<setprecision(2)<<0.00<<endl;
			continue;
		}
		V_current=V;
		W_current=cure[1];
		for(int j=2;j<=n;j++)
		{
			double tmp=(V_current*W_current+V*cure[j])/(V+V_current);
			if(tmp<=W)
			{
				W_current=tmp;
				V_current+=V;
			}
			else
				break;
		}
		cout<<V_current<<' '<<setiosflags(ios::fixed)<<setprecision(2)<<W_current/100.0<<endl;
	}

}

void input(void)
{
	cin>>n;
	cin>>V;
	cin>>W;
	for(int i=1;i<=n;i++)
	{
		cin>>cure[i];
	}
}

void mysort(void)
{
	for(int i=n;i>=2;i--)
		for(int j=1;j<=i-1;j++)
			if(cure[j]>cure[j+1])
			{
				int tmp=cure[j];
				cure[j]=cure[j+1];
				cure[j+1]=tmp;
			}
}