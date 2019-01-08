#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
#define MAXN 120
const double eps=1e-9;
double matrix[MAXN][MAXN];

void input() {
	scanf("%d%d",&n,&m);
	//printf("%d %d\n",n,m);
	memset(matrix,0,sizeof(matrix));
	int u,v,r;
	for(int i=0;i<m;i++) {

		scanf("%d%d%d",&u,&v,&r);
		//if(n==6 && m==8)
		//	printf("%d %d %d\n",u,v,r );
		double tmp=1.0/r;
		matrix[u][u]+=tmp;
		matrix[v][v]+=tmp;
		matrix[u][v]-=tmp;
		matrix[v][u]-=tmp;
	}

	
	
	matrix[1][n+1]=1;
	matrix[n][n+1]=-1;
	/*
	printf("初始值\n");
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n+1;j++)
			printf("%lf ",matrix[i][j]);
		printf("\n");
	}
	printf("\n");
	*/
	
}

void swapline(int a, int b) {
	double tmp;
	for(int i=1;i<=n+1;i++) {
		tmp=matrix[a][i];
		matrix[a][i]=matrix[b][i];
		matrix[b][i]=tmp;
	}
}


void Gauss(int line, int row) {
	for(int i=1;i<=n;i++) {


		
			int maxl=i;

			for(int j=i+1;j<=n;j++) {
				if(fabs(matrix[j][i])>fabs(matrix[maxl][i])) {
					maxl=j;
				}
			}
			if(fabs(matrix[maxl][i])<eps)
			return;


			swapline(i,maxl);
			
		
		
		

		/*
		printf("After sawp\n");
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n+1;j++)
				printf("%lf ",matrix[i][j]);
			printf("\n");
		}
		printf("\n");
		*/

		double frac=matrix[i][i];
		matrix[i][i]=1;
		for(int j=i+1;j<=n+1;j++) {
			matrix[i][j]=matrix[i][j]/frac;
		}

		for(int j=1;j<=n;j++) {
			if(i==j)
				continue;
			if(matrix[j][i]!=0) {
				double frac2=-matrix[j][i];
				matrix[j][i]=0;
				for(int k=i+1;k<=n+1;k++) {
					matrix[j][k]=frac2*matrix[i][k] + matrix[j][k];
				}
			}
		}
		/*
		for(int i=1;i<=n;i++) {
		for(int j=1;j<=n+1;j++)
			printf("%lf ",matrix[i][j]);
		printf("\n");
		}
		*/
	}

	
	
	
	/*
	for(int i=n;i>=2;i--) {
		for(int j=i-1;j>=1;j--) {
			if(matrix[j][i]!=0) {
				matrix[j][n+1]=-matrix[j][i]*matrix[i][n+1];
			}
		}
	}
	*/

}



void solve() {
	Gauss(n,n+1);
	printf("%.2f\n",matrix[1][n+1]);
}


int main() {
	input();
	solve();
}