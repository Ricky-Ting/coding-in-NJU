#include<cstdio>
#include<algorithm>
using namespace std;

long long n,a[100005];

int main()
{
	long long i,j;
	while(~scanf("%I64d",&n))
	{
		for(i=1;i<=n;i++)
			scanf("%I64d",a+i);
		sort(a+1,a+n+1);
		long long l=0,r=a[n],mid,m=(n-1)*n/4,num;
		if((n*(n-1)/2)&1) 
			m++;
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		while(l<r)
		{
			mid=(l+r)>>1;
			j=1;
			num=0;
			for(i=2;i<=n;i++)
			{
				while(a[i]-a[j]>mid)
					j++;
				num += (i-j);
			}
			if(num>=m)
				r=mid;
			else
				l=mid+1;

		}
		printf("%I64d\n",l);
	}
	return 0;
}   //二分
