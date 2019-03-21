#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1005
struct node{
	double res;
	int a;
	int b;
} g[MAXN];
void solve();
int n,k;
int a[MAXN],b[MAXN];
double bsearch(double from, double to);
int f(double L);
int main() {
	while(1) {
		scanf("%d%d",&n,&k);
		if(n==0)
			return 0;

		for(int i=0; i<n; i++) {
			scanf("%d%d",&a[i],&b[i]);
		}
		solve();
	}
	return 0;
}

bool cmp(node x, node y) {
	return x.res>y.res;
}

void solve() {
	
	double res=bsearch(1,10);
	printf("%.2lf\n",res);
	return ;
}

int f(double L) {

	double sum=0;
	for(int i=0;i<n;i++) {
		g[i].res = double(b[i]) - double(a[i])*L;
		//g[i].a = a[i];
		//g[i].b = b[i];
	}

	//return 1;
	
	sort(g,g+n,cmp);
	for(int i=0;i<k;i++) {
		sum += g[i].res;
	}
	if(sum>=0)
		return 1;
	else
		return 0;
	
	// 1 for satisfy 0 for 
}

double bsearch(double from, double to) {
	double mid;
	while(to-from > 1e-10) {
		mid = (from +to)/2;
		if(f(mid))
			from = mid;
		else
			to =mid;
	}
	return mid;

}
