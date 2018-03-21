#include<iostream>
#include<string>
using namespace std;

void process(string A);

int main(void)
{
	int n;
	cin>>n;
	string A;
	for(int i=1;i<=n;i++)
	{
		cin>>A;
		cout<<"String #"<<i<<endl;
		process(A); 
	}
	return 0;
}

void process(string A)
{
	for(int i=0;i<A.length();i++)
	{
		if(A[i]=='Z')
			A[i]='A';
		else
			A[i]=char(int(A[i])+1);
		
	}
	cout<<A<<endl<<endl;
}