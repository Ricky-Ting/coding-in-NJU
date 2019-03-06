#include<iostream>
#include<cstdio>
using namespace std;
#define eps 1e-8

int maxi(int a, int b) {
	return (a>b)?a:b;
}

int main() {
	int a,b,M;
	int x[1005],y[1005];
	int n;
	int mmax=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
	} 
	scanf("%d%d%d",&a,&b,&M);
	int currentx1=0;
	int currentx2=1;
	for(int i=1; i<=x[n-1]; i++){
		while(!( x[currentx1]<i && x[currentx2]>=i )) {
			currentx1++;
			currentx2++;

		}
		for(int j=1; j<=y[0]; j++){
			double d1 = (double(y[currentx1]-y[currentx2]))/ (double(x[currentx1]-x[currentx2]));
			double d2 = (double(y[currentx1]-j)) / (double(x[currentx1]-i) );
			if(d2<=d1+eps) {
				mmax=maxi((i*a+j*b)%M,mmax);
				//printf("%d %d\n",i,j);
			}
		}
	}
	printf("%d\n",mmax);

}