#include<iostream>
#include<cmath>

using namespace std;


bool is_a_prime(int t);

int main()
{
	int s;
	cin>>s;
	while(s!=0)
	{

		int count=0;
		if(s==4 || s==5)
		{
			cout<<1<<endl;
			cin>>s;
			continue;
		}
		for(int i=3;i<=s/2;i+=2)
		{
			if(is_a_prime(i)&&is_a_prime(s-i))
				count++;
		}
		cout<<count<<endl;
		cin>>s;
	}
}

bool is_a_prime(int t)
{	
	for(int i=2;i<=int(sqrt(t));i++)
	{

		if(t%i==0)
			return false;
	}
	return true;
}