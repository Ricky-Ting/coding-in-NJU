#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct DNA
{
	string a;
	int key;
};


bool cmp(const DNA &p, const DNA &q)
{
	return p.key<q.key;
}

DNA DNAs[101];
int n,m;

int main(void)
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>DNAs[i].a;
		getchar();
		DNAs[i].key=0;
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(DNAs[i].a[j]>DNAs[i].a[k])
					DNAs[i].key++;
	sort(DNAs,DNAs+m,cmp);
	for(int i=0;i<m;i++)
		cout<<DNAs[i].a<<endl;
}

