#include<iostream>
#include<iomanip>
using namespace std;

struct person
{
	double prob;
	double andprob;
	double res;
};
double p1;

int N,r;
person people[22];


double dp(int index, int num);
double dp2(int index,int num,int inclu);
int main(void)
{
	cin>>N>>r;
	int counter=1;
	while(N!=0)
	{
		p1=0;
		for(int i=1;i<=N;i++)
		{
			cin>>people[i].prob;
		}
		cout<<"Case "<<counter<<":"<<endl;
		p1=dp(1,0);
		for(int i=1;i<=N;i++)
		{
			people[i].andprob=dp2(1,0,i);
			people[i].res=(people[i].andprob)/(p1);
			cout<<setiosflags(ios::fixed)<<setprecision(6)<<people[i].res<<endl;
		}
		cin>>N>>r;
		counter++;
	}
}

double dp(int index, int num)
{
	if(index==N+1)
	{
		if(num==r)
			return 1;
		else
			return 0;
	}
	return dp(index+1,num)*(1-people[index].prob)+dp(index+1,num+1)*people[index].prob;
}

double dp2(int index,int num,int inclu)
{
	if(index==N+1)
	{
		if(num==r)
			return 1;
		else
			return 0;
	}
	if(index==inclu)
	{
		return dp2(index+1,num+1,inclu)*people[index].prob;
	}
	return dp2(index+1,num,inclu)*(1-people[index].prob)+dp2(index+1,num+1,inclu)*people[index].prob;
}