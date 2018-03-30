#include<iostream>
#include<algorithm>
using namespace std;


 bool complare(int a,int b)
 {
    return a>b;
 }

int main(void)
{
	int n;
	int m;
	while(cin>>n)
	{
		int a[3001];
		int b[1001]={0};
		cin>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int length=1;
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(a[i]+a[j]>=b[length])
				{
					int counter=length;
					while(a[i]+a[j]>=b[counter] && counter>=1)
					{
						if(counter<m)
						{
							b[counter+1]=b[counter];
							if(counter==length)
								length++;
						}
						counter--;
					}
					b[counter+1]=a[i]+a[j];

				}
				else
				{
					if(length<m)
					{
						length++;
						b[length]=a[i]+a[j];
					}
				}
			}
		
		for(int i=1;i<=m-1;i++)
		{
			cout<<b[i]<<' ';
		}
		cout<<b[m];
		cout<<endl;

	}
	return 0;
}