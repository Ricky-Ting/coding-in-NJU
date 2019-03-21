#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN  50005

bool cmp(int a, int b) {
	return a>b;
}

int n,m;
int a[MAXN];
int sent[MAXN];

int bsearch(int d, int from , int to) {
	if(from>=n)
		return -1;
	if(from == to) {
		if(a[from]<=d && sent[from]==0)
			return from;
		else
			return -1;
	}
	int mid = (from + to)/2;
	if(a[mid]==d && sent[mid]==0)
		return mid;
	if(a[mid]>d)
		return bsearch(d,mid+1, to);
	else {
		int ret= bsearch(d,from,mid);
		if(ret!=-1)
			return ret;
		return bsearch(d,mid+1,to);
	}
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i]);
	memset(sent,0,sizeof(sent));
	sort(a,a+n,cmp);
	int counter=0;
	int bag=0;
	for(int i = 0; i<n; i++) {
		if(sent[i])
			continue;
		int tog = bsearch(m-a[i], i+1, n-1);
		if(tog == -1) {
			sent[i]=1;
			bag++;
			counter++;
		}
		else {
			sent[i]=sent[tog]=1;
			bag++;
			counter+=2;
		}
	}
	
	printf("%d\n",bag);
}