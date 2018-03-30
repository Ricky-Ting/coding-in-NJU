#include<iostream>
#include<vector>

using namespace std;



int main(void)
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n!=0)
	{
		vector<int> a;
		bool b[1000000]={true};
		for(int i=0;i<=n-1;i++)
		{
			int in;
			cin>>in;
			a.push_back(in);
			if(i>=1)
			{
				if(a[a.size()-1]<0)
				{
					while(a.size()>=2 && a[a.size()-1]+a[a.size()-2]<0)
					{
						a[a.size()-2]+=a[a.size()-1];
						a.pop_back();
					}
				}
			}
			
		}
		if(a.size()>1 && a[0]<0)
		{
			a.push_back(a[0]);
			a.erase(a.begin());
		}
		while(a.size()>=2 && a[a.size()-1]+a[a.size()-2]<0)
		{
						a[a.size()-2]+=a[a.size()-1];
						a.pop_back();
		}
		int counter=0;
		for(int i=0;i<a.size();i++)
			if(a[i]>=0)
				counter++;
		
		cout<<counter<<endl;
		cin>>n;
	}
	return 0;
}