#include<iostream>
#include<cmath>
using namespace std;
struct node {
	double x;
	double dot[4];
};
int n;
node b[21];  // barrier
double dp[100][4];

void solve();
void input();
int main() {
	input();
	solve();
}

void input() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%lf%lf%lf%lf%lf",&b[i].x,&b[i].dot[0],&b[i].dot[1],&b[i].dot[2],&b[i].dot[3]);
	for(int i=1;i<=n;i++) 
		for(int j=0;j<4;j++)
			dp[i][j]=10000000;

}

bool satisfy(int i, int l , int j, int k) {
	double line=(b[j].dot[k]-b[i].dot[l])/(b[j].x-b[i].x);
	for(int m=i-1;m>j;m--) {
		double tmp=line*(b[m].x-b[i].x);
		tmp= b[i].dot[l]+tmp;
		if(!( b[m].dot[0]<=tmp && tmp<=b[m].dot[1] )  && !(b[m].dot[2]<=tmp  && tmp<=b[m].dot[3] ) )
			return false;
	}
	return true;
}

bool satisfy2(int i, int l) {
	double line=(5-b[i].dot[l])/(0-b[i].x);
	for(int m=i-1;m>=1;m--) {
		double tmp=line*(b[m].x-b[i].x);
		tmp= b[i].dot[l]+tmp;
		if(!( b[m].dot[0]<=tmp && tmp<=b[m].dot[1] )  && !(b[m].dot[2]<=tmp  && tmp<=b[m].dot[3] ) )
			return false;
	}
	return true;
}

bool satisfy3() {
	for(int m=n;m>=1;m--) {
		double tmp=5;
		if(!( b[m].dot[0]<=tmp && tmp<=b[m].dot[1] )  && !(b[m].dot[2]<=tmp  && tmp<=b[m].dot[3] ) )
			return false;
	}
	return true;
}

bool satisfy4(int j, int k) {
	double line=(b[j].dot[k]-5)/(b[j].x-10);
	for(int m=n;m>j;m--) {
		double tmp=line*(b[m].x-10);
		tmp= 5+tmp;
		if(!( b[m].dot[0]<=tmp && tmp<=b[m].dot[1] )  && !(b[m].dot[2]<=tmp  && tmp<=b[m].dot[3] ) )
			return false;
	}
	return true;
}



double cal(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double mini(double a, double b) {
	return (a<b)?a:b;
}


void solve() {
	if(n==0) {
		printf("10.00\n");
		return;
	}
	dp[1][0]=cal(b[1].x,b[1].dot[0],0,5);
	dp[1][1]=cal(b[1].x,b[1].dot[1],0,5);
	dp[1][2]=cal(b[1].x,b[1].dot[2],0,5);
	dp[1][3]=cal(b[1].x,b[1].dot[3],0,5);
	for(int i=2;i<=n;i++) {
		for(int l=0;l<4;l++) {
			for(int j=i-1;j>=1;j--) {
				for(int k=0;k<4;k++) {
					if(satisfy(i,l,j,k))
						dp[i][l]=mini(dp[i][l],dp[j][k]+cal(b[i].x,b[i].dot[l],b[j].x,b[j].dot[k]));
				}
			}
			if(satisfy2(i,l)) {
				dp[i][l]=mini(dp[i][l],cal(b[i].x,b[i].dot[l],0,5));
			}
		}
	}
	double res=1000000;
	for(int j=1;j<=n;j++)
		for(int k=0;k<4;k++) {
			if(satisfy4(j,k) )
				res=mini(res,dp[j][k]+cal(10,5,b[j].x,b[j].dot[k]));
		}
	if(satisfy3() )
		res=mini(res,10);
	printf("%.2lf",res);
	return;
}


