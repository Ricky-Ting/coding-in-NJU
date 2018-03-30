#include<iostream>
#include<string>
#include<stack>
using namespace std;

void process(string in, string out);

int main(void)
{
	int n;
	string in,out;

	while(cin>>n)
	{
		cin>>in>>out;
		process(in,out);
		cout<<"FINISH"<<endl;
	}
	return 0;
}


void process(string in, string out)
{
	string output[10000];
	int counter=0;
	stack<char> s;
	while(out.length()!=0)
	{
		if(s.size()!=0)
		{
			if(s.top()==out[0])
			{
				s.pop();
				out.erase(0,1);
				counter++;
				output[counter]="out";

			}
			else
			{
				if(in.length()!=0)
				{
					if(s.size()==9)
						break;
					s.push(in[0]);
					in.erase(0,1);
					counter++;
					output[counter]="in";
				}
				else
					break;
			}
		}
		else
		{
			if(in.length()!=0)
			{
				s.push(in[0]);
				in.erase(0,1);
				counter++;
				output[counter]="in";
			}
		}
	}
	if(out.length()!=0)
		cout<<"No."<<endl;
	else
	{
		cout<<"Yes."<<endl;
		for(int i=1;i<=counter;i++)
			cout<<output[i]<<endl;
	}
}
