#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double  s1,s2,s3,s4,average,deviation;

void process(void);
void output(void);
int main(void)
{
	while(cin>>s1>>s2>>s3>>s4)
	{
		process();
		output();
	}
}


void process(void)
{
	average=(s1+s2+s3+s4)/4;
	deviation=sqrt(((s1-average)*(s1-average)+(s2-average)*(s2-average)+(s3-average)*(s3-average)+(s4-average)*(s4-average))/4);
	return;
}

void output(void)
{
	cout<<fixed<<setprecision(2)<<average<<' '<<deviation<<endl;
	return;
}
