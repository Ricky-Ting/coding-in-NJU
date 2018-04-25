#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	string s;
	while(cin>>s)
	{
		int num=0;
		int num2=0;
		for(int i=0;i<s.length();i++)
			if(s[i]=='0')
			{
				num++;
				if(s[(i+1)%s.length()]=='0')
					num2++;
			}	
		if(num2*s.length()==num*num)
			cout<<"EQUAL"<<endl;
		else if(num2*s.length()>num*num)
			cout<<"SHOOT"<<endl;
		else
			cout<<"ROTATE"<<endl;
	}
	return 0;
}