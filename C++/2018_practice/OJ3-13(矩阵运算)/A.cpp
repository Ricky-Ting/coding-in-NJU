#include<cstdio>
#include<assert.h>
#include<cstring>
#include<cmath>
using namespace std;

int E[6][6] = {
	1, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 0,
	0, 0, 0, 1, 0, 0,
	0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 1
};

int H[6][6] = {
	1, 1, 0, 0, 0, 0,
	1, 1, 1, 0, 0, 0,
	0, 1, 1, 1, 0, 0,
	0, 0, 1, 1, 1, 0,
	0, 0, 0, 1, 1, 1,
	0, 0, 0, 0, 1, 1 
};



int A[30][31];

void init() {
	int line,row;
	for(int i=0;i<30;i++) {
		for(int j=0;j<30;j++) {
			line=i/6;
			row=j/6;
			if(line==row) {
				A[i][j]=H[i%6][j%6];
			}
			else if(line-row==1 || line-row==-1) {
				A[i][j]=E[i%6][j%6];
			}
			
			else
				A[i][j]=0;
		}
	}
	/*
	for(int i=0;i<30;i++) {
		for(int j=0;j<30;j++) 
			//if(j==29)
				printf("%d ",A[i][j]);
			//else
			//	printf("%d, ",A[i][j]);
		printf("\n");
	}
	*/
	
}

void input() {
	for(int i=0;i<30;i++) {
		scanf("%d",&A[i][30]);
		//printf("%d\n",A[i][30]);
	}
	/*
	for(int i=0;i<30;i++) {
		for(int j=0;j<31;j++) 
			printf("%d ",A[i][j]);
		printf("\n");
	}
	*/
}
void swapline(int a, int b) {
	int tmp;
	for(int i=0;i<31;i++)  {
		tmp=A[a][i];
		A[a][i]=A[b][i];
		A[b][i]=tmp;
	}
	return;
}

int Gauss(int n, int m) {

	for(int i=0;i<30;i++) {
		if(A[i][i]==0) {
			for(int j=i+1;j<30;j++) {
				if(A[j][i]!=0) {
					swapline(i,j);
					break;
				}
			}
		}

		for(int j=i+1;j<30;j++) {
			if(A[j][i]!=0) 
				for(int k=i;k<31;k++) 
					A[j][k]=A[i][k]^A[j][k];
		}
	}
	/*
	for(int i=0;i<30;i++) {
		for(int j=0;j<31;j++) 
			printf("%d ",A[i][j]);
		printf("\n");
	}
	*/
	

	/*
	for(int i=0;i<30;i++) {
		for(int j=0;j<31;j++) 
			printf("%d ",A[i][j]);
		printf("\n");
	}
	*/
	for(int i=29;i>0;i--) {   //按列遍历
		assert(A[i][i]!=0);
		for(int j=i-1;j>=0;j--) {
			if(A[j][i]!=0) {
				A[j][i]=0;
				A[j][30]=A[i][30]^A[j][30];
			}
		}
	}
	/*
	for(int i=0;i<30;i++) {
		for(int j=0;j<31;j++) 
			printf("%d ",A[i][j]);
		printf("\n");
	}
	*/

	return 0;
}

void solve() {
	Gauss(30,30+1);
}


int main() {
	int T;
	int ret;
	init();
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		init();
		input();
		solve();
		printf("PUZZLE #%d",i);
		for(int i=0;i<30;i++) {
			if(i%6 ==0)
				printf("\n");
			printf("%d ",A[i][30]);
		}
		printf("\n");
	}

}