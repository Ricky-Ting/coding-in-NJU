#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct child
{
	bool dead;
	string name;
};

int n;
int w,s;
int main(void)
{
	child children[66];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		children[i].dead=false;
		cin>>children[i].name;
	}
	cin>>w;
	getchar();
	cin>>s;
	int out=0;
	int current=w-1;
	int counter=0;
	while(out<n)
	{
		current=current%n;
		if(!children[current].dead)
		{
			counter++;
			if(counter==s)
			{
				cout<<children[current].name<<endl;
				children[current].dead=true;
				counter=0;
				out++;
			}
		}
		current++;
	}


}