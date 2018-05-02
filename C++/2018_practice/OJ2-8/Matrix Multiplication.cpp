#include<iostream>
#include <ctime> 
using namespace std;
const int maxn=510;
int A[maxn][maxn];
int B[maxn][maxn];
int C[maxn][maxn];
int r[maxn];
int rA[maxn];
int rAB[maxn];
int rC[maxn];
int n;

void input(int c[maxn][maxn])
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c[i][j]);
}

bool ok()
{
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
		{
			rA[j]+=r[i]*A[i][j];
			rC[j]+=r[i]*C[i][j];
		}
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++)
				rAB[j]+=rA[i]*B[i][j];

		for(int i=1;i<=n;i++)
			if(rAB[i]!=rC[i])
				return false;
		return true;
}
int main(void)
{
	srand((unsigned)time(NULL));
	cin>>n;
	input(A);
	input(B);
	input(C);
	memset(rA,0,sizeof(rA));
	memset(rAB,0,sizeof(rAB));
	memset(rC,0,sizeof(rC));
	for(int i=1;i<=n;i++)
		r[i]=rand()%99+1;
	if(ok())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}







