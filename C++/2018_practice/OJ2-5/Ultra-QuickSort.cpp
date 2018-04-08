#include<iostream>
using namespace std;
int a[500005];
int b[500005];
long long result;

void mergesort(int l,int r);
void merge(int start, int mid, int end);
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n!=0)
	{
		result=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		mergesort(1,n);
		cout<<result<<endl;
		cin>>n;
	}
}

void mergesort(int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}


void merge(int start, int mid, int end)
{
	int i=start;
	int k=start;
	int j=mid+1;
	while(i<=mid && j<=end)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else 
		{
			result+=j-k;
			b[k++]=a[j++];
		}
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=end)
		b[k++]=a[j++];
	for(int i=start;i<=end;i++)
		a[i]=b[i];
}