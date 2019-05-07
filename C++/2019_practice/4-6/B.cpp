#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXT 105
#define MAXH 1005
#define MAXW 1005
#define MAXh 55
#define MAXw 55
using namespace std;

int h,w,H,W,T;




unsigned int S[MAXT][MAXh][MAXw];
unsigned int P[MAXH][MAXW];
unsigned long long vP[MAXH][MAXW];
unsigned long long vs[MAXT];
int isvis[MAXT];
void generate_vP() {
	
	for(int a=1; a<=H-h+1; a++) 
		for(int b=1; b<=W-w+1; b++) {
			if(b==1) {
				for(int i=a; i<a+h; i++) {
					unsigned long long tmp = 0;
					for(int j=b; j<b+w; j++) {
						tmp += ( (unsigned long long) (P[i][j])) << (j-b);
					}
					vP[a][b]+=tmp;
				}
			} else {
				vP[a][b] = vP[a][b-1];
				for(int k=a; k<a+h; k++) 
					vP[a][b] = vP[a][b] - P[k][b-1];
				vP[a][b] = ( (unsigned long long)vP[a][b]) >> 1;
				unsigned long long tmp = 0;
				for(int k=a; k<a+h; k++) 
					tmp += ( ( (unsigned long long) P[k][b+w-1]) << (w-1));
				vP[a][b] += tmp;
			}
		}
}

void generate_vs(int t) {
	vs[t] = 0;
	for(int i=1; i<=h; i++) {
		unsigned long long tmp = 0;
		for(int j=1; j<=w; j++) {
			tmp += ( (unsigned long long) S[t][i][j]) << (j-1);
		}
		vs[t]+=tmp;
	}


}

int ismatch(int a, int b, int t) {
	for(int i=0;i<h;i++) {
		for(int j=0; j<w; j++) {
			if(P[a+i][b+j] != S[t][i+1][j+1])
				return 0;
		}
	}
	return 1;
}


int main() {
	scanf("%d%d%d%d%d",&H,&W,&T,&h,&w);
	char s[MAXW];
	for(int i=1;i<=H;i++) {
		scanf("%s",s);
		for(int j=1; j<=W;j++) {
			P[i][j] = s[j-1] - '0';
		}
	}

	for(int k = 1; k<=T; k++) {
		for(int i=1;i<=h;i++) {
			scanf("%s",s);
			for(int j =1;j<=w;j++) {
				S[k][i][j] = s[j-1] - '0';
			}
		}
	}
	memset(isvis, 0, sizeof(isvis));
	memset(vP, 0, sizeof(vP));
	for(int i=1; i<=T;i++)
		generate_vs(i);

	generate_vP();




	for(int i=1;i<=H-h+1; i++) {
		for(int j=1; j<=W-w+1; j++) {
			//generate_vP(i,j);
			for(int k=1; k<=T; k++) {
				if(vs[k] == vP[i][j] && ismatch(i,j,k))
					isvis[k]=1;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=T;i++)
		ans += isvis[i];
	printf("%d\n",ans);


	
    
}
